#include <unistd.h>	// pread,fstat
#include <elf.h>	// ELF structure
#include <string.h>	// memcpy
#include <stdint.h>
#include <sys/types.h>	// fstat,open
#include <sys/stat.h>	// fstat,open
#include <fcntl.h>	// open
#include <stdlib.h>	// rand,srand
#include <time.h>	// time
#include <regex.h>	// reg
#include <dirent.h>	// opendir,readdir

#include "seqemu.h"

unsigned long seqemu_guest_base;
struct image_info seqemu_image_info;
// feature-011 add options of security feature
int seqemu_disable_dangerous = 0;
int seqemu_format_level = SEQEMU_FEATURE_MITIGATION;
int seqemu_disable_buffer = 0;
int seqemu_disable_heap = 0;

int seqemu_disable_syscall = 0;
int seqemu_disable_honeypot = 0;
int seqemu_disable_selfnx = 0;
int seqemu_disable_uaf = 0;
// feature-012 Checking System Call
int seqemu_execute_libc_start_main = 0;


void seqemu_save_guest_base(unsigned long base){
    seqemu_guest_base = base;
}

void seqemu_print_guest_base(void){
    fprintf(stderr,"[DEBUG] GUEST BASE = %lx\n",seqemu_guest_base);
}


void seqemu_save_image_info(struct image_info *info){
	memcpy(&seqemu_image_info,info,sizeof(struct image_info));
}

void seqemu_print_image_info(void){
	unsigned long b = seqemu_guest_base;
	fprintf(stderr,"load_bias   =0x%lx [0x%x]\n",seqemu_image_info.load_bias + b, seqemu_image_info.load_bias);
	fprintf(stderr,"load_addr   =0x%lx [0x%x]\n",seqemu_image_info.load_addr + b, seqemu_image_info.load_addr);
	fprintf(stderr,"start_code  =0x%lx [0x%x]\n",seqemu_image_info.start_code + b, seqemu_image_info.start_code);
	fprintf(stderr,"end_code    =0x%lx [0x%x]\n",seqemu_image_info.end_code + b, seqemu_image_info.end_code);
	fprintf(stderr,"start_data  =0x%lx [0x%x]\n",seqemu_image_info.start_data + b, seqemu_image_info.start_data);
	fprintf(stderr,"end_data    =0x%lx [0x%x]\n",seqemu_image_info.end_data + b, seqemu_image_info.end_data);
	fprintf(stderr,"start_brk   =0x%lx [0x%x]\n",seqemu_image_info.start_brk + b, seqemu_image_info.start_brk);
	fprintf(stderr,"brk         =0x%lx [0x%x]\n",seqemu_image_info.brk + b, seqemu_image_info.brk);
	fprintf(stderr,"start_mmap  =0x%lx [0x%x]\n",seqemu_image_info.start_mmap + b, seqemu_image_info.start_mmap);
	fprintf(stderr,"start_stack =0x%lx [0x%x]\n",seqemu_image_info.start_stack + b, seqemu_image_info.start_stack);
	fprintf(stderr,"stack_limit =0x%lx [0x%x]\n",seqemu_image_info.stack_limit + b, seqemu_image_info.stack_limit);
	fprintf(stderr,"entry       =0x%lx [0x%x]\n",seqemu_image_info.entry + b, seqemu_image_info.entry);
	fprintf(stderr,"code_offset =0x%lx [0x%x]\n",seqemu_image_info.code_offset + b, seqemu_image_info.code_offset);
	fprintf(stderr,"data_offset =0x%lx [0x%x]\n",seqemu_image_info.data_offset + b, seqemu_image_info.data_offset);
	fprintf(stderr,"saved_auxv  =0x%lx [0x%x]\n",seqemu_image_info.saved_auxv + b, seqemu_image_info.saved_auxv);
	fprintf(stderr,"auxv_len    =0x%lx [0x%x]\n",seqemu_image_info.auxv_len + b, seqemu_image_info.auxv_len);
	fprintf(stderr,"argv_start  =0x%lx [0x%x]\n",seqemu_image_info.arg_start + b, seqemu_image_info.arg_start);
	fprintf(stderr,"argv_end    =0x%lx [0x%x]\n",seqemu_image_info.arg_end + b, seqemu_image_info.arg_end);


	fprintf(stderr,"arg_strings =0x%lx [0x%x]\n",seqemu_image_info.arg_strings + b, seqemu_image_info.arg_strings);
	fprintf(stderr,"env_strings =0x%lx [0x%x]\n",seqemu_image_info.env_strings + b, seqemu_image_info.env_strings);
	fprintf(stderr,"file_string =0x%lx [0x%x]\n",seqemu_image_info.file_string + b, seqemu_image_info.file_string);

	fprintf(stderr,"start_stack =0x%lx [0x%x]\n",seqemu_image_info.start_stack + b, seqemu_image_info.start_stack);
	fprintf(stderr,"env_start   =0x%lx [0x%x]\n",seqemu_image_info.arg_end + (abi_ulong)sizeof(abi_ulong) + b, seqemu_image_info.arg_end + (abi_ulong)sizeof(abi_ulong));
	fprintf(stderr,"auxv_start  =0x%lx [0x%x]\n",seqemu_image_info.saved_auxv + b, seqemu_image_info.saved_auxv);
}


/////////////////////////////////////////////////////////////////
// OPTIONS
/////////////////////////////////////////////////////////////////

// feature-011 add options of security feature

void handle_arg_disable_dangerous(const char *arg){
	seqemu_disable_dangerous = 1;
}

void handle_arg_format_level(const char *arg){
	if(strcmp(arg,"mitigation") == 0){
		seqemu_format_level = SEQEMU_FEATURE_MITIGATION;
	}else if(strcmp(arg,"abort") == 0){
		seqemu_format_level = SEQEMU_FEATURE_ABORT;
	}else if(strcmp(arg,"disable") == 0){
		seqemu_format_level = SEQEMU_FEATURE_DISABLE;
	}else{
		fprintf(stderr,"[FORMAT] %s is not support level. Exiting.\n",arg);
		exit(EXIT_FAILURE);
	}
}

void handle_arg_disable_buffer(const char *arg){
	seqemu_disable_buffer = 1;
}

void handle_arg_disable_heap(const char *arg){
	seqemu_disable_heap = 1;
}

void handle_arg_disable_syscall(const char *arg){
	seqemu_disable_syscall = 1;
}

void handle_arg_disable_honeypot(const char *arg){
	seqemu_disable_honeypot = 1;
}

void handle_arg_disable_selfnx(const char *arg){
	seqemu_disable_selfnx = 1;
}

void handle_arg_disable_uaf(const char *arg){
	seqemu_disable_uaf = 1;
}

void handle_arg_disable_all(const char *arg){
	seqemu_disable_dangerous = 1;
	seqemu_format_level = SEQEMU_FEATURE_DISABLE;
	seqemu_disable_buffer = 1;
	seqemu_disable_heap = 1;
	seqemu_disable_syscall = 1;
	seqemu_disable_honeypot = 1;
	seqemu_disable_selfnx = 1;
	seqemu_disable_uaf = 1;
}

void handle_arg_abort_all(const char *arg){
	seqemu_disable_dangerous = SEQEMU_FEATURE_ABORT;
	seqemu_format_level = SEQEMU_FEATURE_ABORT;
	seqemu_disable_buffer = SEQEMU_FEATURE_ABORT;
	seqemu_disable_heap = SEQEMU_FEATURE_ABORT;
	seqemu_disable_syscall = SEQEMU_FEATURE_ABORT;
	seqemu_disable_honeypot = SEQEMU_FEATURE_ABORT;
	seqemu_disable_selfnx = SEQEMU_FEATURE_ABORT;
	seqemu_disable_uaf = SEQEMU_FEATURE_ABORT;
}

void handle_arg_seqemu(const char *arg){
	fprintf(stderr,SEQEMU_VERSION_STRING);
}


///////////////////////////////////////////////////////////
// OPTIONS END
///////////////////////////////////////////////////////////

// feature-002 Filtering the Dangerous Functions
// feature-012 Checking System Call


char **dangerous_func;
char **format_func;
char **malloc_func;
char **buffer_func;
char **libc_start_main;

Seqemu_target_func *target_func;
unsigned int seqemu_target_func_num;

// feature-016 Add self NX
target_ulong seqemu_self_nx_entry;

void seqemu_read_elf(int fd){
	Elf32_Ehdr *elfh;
	Elf32_Shdr *sh,*sh_relplt,*sh_dynstr,*sh_shstrtab,*sh_dynsym,*sh_plt;
	Elf32_Rel *rels;
	Elf32_Sym *syms;
	uint8_t buf[sizeof(Elf32_Ehdr)];
	uint8_t *shstrtab,*dynstr;
	int i,j,istyped;
	//Seqemu_target_func *target_func;

	/////////////////////////////////////////////////
	// Step 1. Get ELF Header, and Checking the MAGIC
	/////////////////////////////////////////////////

	elfh = g_malloc(sizeof(Elf32_Ehdr));
	pread(fd,buf,sizeof(Elf32_Ehdr),0x0);
	if(!(buf[EI_MAG0] == ELFMAG0 &&
		buf[EI_MAG1] == ELFMAG1 &&
		buf[EI_MAG2] == ELFMAG2 &&
		buf[EI_MAG3] == ELFMAG3)){
		fprintf(stderr,"[!] This is not ELF!\n");
		exit(-1);
	}

	memcpy(elfh,buf,sizeof(Elf32_Ehdr));

	seqemu_self_nx_entry = (target_ulong)elfh->e_entry;
	fprintf(stderr,"[NX] %x is entry code\n",seqemu_self_nx_entry);

	/////////////////////////////
	// Step 2. Find the .shstrtab
	/////////////////////////////

	sh = g_malloc(sizeof(Elf32_Shdr));
	sh_shstrtab = g_malloc(sizeof(Elf32_Shdr));


	// Find the .shstrtab
	// .shstrtab is string table of section header.
	// It is starts 0x00,0x2e,0x(first char of section header), so checking that first byte and second byte.
	for(i = 0; i < elfh->e_shnum; i++){
		pread(fd,sh_shstrtab,sizeof(Elf32_Shdr),elfh->e_shoff + sizeof(Elf32_Shdr) * i);
		uint8_t bytes[2];
		pread(fd,bytes,sizeof(uint8_t) * 2,sh_shstrtab->sh_offset);
		if(bytes[0] == 0x0 && bytes[1] == 0x2e){
			fprintf(stderr,"[+] Find .shstrtab! In %d section.\n",i);
			break;
		}
	}

	if(i == elfh->e_shnum){
		fprintf(stderr,"[!] .shstrtab is not found! Exiting...\n");
		exit(-1);
	}

	// Read the Contents of .shstrtab
	shstrtab = g_malloc(sizeof(uint8_t) * sh_shstrtab->sh_size);
	pread(fd,shstrtab,sh_shstrtab->sh_size,sh_shstrtab->sh_offset);


	/////////////////////////////////////////////////////////
	// Step 3. Find the Sections (.rel.plt, .dynsym, .dynstr)
	/////////////////////////////////////////////////////////

	for(i = 0; i < elfh->e_shnum; i++){
		pread(fd,sh,sizeof(Elf32_Shdr),elfh->e_shoff + sizeof(Elf32_Shdr) * i);
		//fprintf(stderr,"[%02x] %x Addr:%x Off:%x Size:%x Es:%x Flg:%x Lk:%x Inf:%x Al:%x\n",i,sh->sh_type,sh->sh_addr,sh->sh_offset,sh->sh_size,sh->sh_entsize,sh->sh_flags,sh->sh_link,sh->sh_info,sh->sh_addralign);


		// Get Section of .rel.plt
		if(sh->sh_type == SHT_REL){
			if(strcmp((char *)&shstrtab[sh->sh_name],".rel.plt") == 0){
				fprintf(stderr,"[OK] .rel.plt is EXIST!\n");
				sh_relplt = g_malloc(sizeof(Elf32_Shdr));
				memcpy(sh_relplt,sh,sizeof(Elf32_Shdr));
			}
		}

		if(sh->sh_type == SHT_PROGBITS){
			if(strcmp((char *)&shstrtab[sh->sh_name],".plt") == 0){
				fprintf(stderr,"[OK] .plt is EXIST!\n");
				sh_plt = g_malloc(sizeof(Elf32_Shdr));
				memcpy(sh_plt,sh,sizeof(Elf32_Shdr));
			}
		}

		// Get Section of .dynsym
		if(sh->sh_type == SHT_DYNSYM){
			fprintf(stderr,"[OK] .dynsym is EXIST!\n");
			sh_dynsym = g_malloc(sizeof(Elf32_Shdr));
			memcpy(sh_dynsym,sh,sizeof(Elf32_Shdr));
		}

		// Get Section of .dynstr
		if(sh->sh_type == SHT_STRTAB && sh->sh_addr != 0x0){
			fprintf(stderr,"[OK] .dynstr is EXIST!\n");
			sh_dynstr = g_malloc(sizeof(Elf32_Shdr));
			memcpy(sh_dynstr,sh,sizeof(Elf32_Shdr));
		}

	}

	// Checking .rel.plt and .dynstr is exists
	if(sh_relplt == NULL || sh_dynsym == NULL || sh_dynstr == NULL){
		fprintf(stderr,"[Error] .rel.plt or .dynsym or .dynstr is not EXIST!\n");
	}

	///////////////////////////////////////
	// Step 4. Get Contents of Each Section
	///////////////////////////////////////

	// Get the dynstr
	dynstr = g_malloc(sizeof(uint8_t) * sh_dynstr->sh_size);
	pread(fd,dynstr,sizeof(uint8_t) * sh_dynstr->sh_size,sh_dynstr->sh_offset);

	// Get .rel.plt Contents
	rels = g_malloc(sh_relplt->sh_size);
	pread(fd,rels,sh_relplt->sh_size,sh_relplt->sh_offset);

	// Get .dynsym Contents
	syms = g_malloc(sh_dynsym->sh_size);
	pread(fd,syms,sh_dynsym->sh_size,sh_dynsym->sh_offset);


	/////////////////////////////////////////////////
	// Step 5. Construct The Dangerous Function Table
	/////////////////////////////////////////////////
	// sh_plt_addr = sh_plt->sh_addr;
	seqemu_target_func_num = sh_relplt->sh_size / sizeof(Elf32_Rel);
	target_func = g_malloc(sizeof(Seqemu_target_func) * seqemu_target_func_num);

	for(i = 0; i < sh_relplt->sh_size / sizeof(Elf32_Rel); i++){
		istyped = 0;
		target_func[i].got_addr = rels[i].r_offset;
		target_func[i].plt_addr = sh_plt->sh_addr + (i * 0x10) + 0x10;
		target_func[i].name = strdup((char *)&dynstr[syms[rels[i].r_info >> 8].st_name]);
		for(j = 0; dangerous_func[j] != NULL; j++){
			if(strcmp(dangerous_func[j],target_func[i].name) == 0){
				target_func[i].type = SEQEMU_FUNC_TYPE_DANGEROUS;
				istyped = 1;
			}
		}

		for(j = 0; format_func[j] != NULL; j++){
			if(strcmp(format_func[j],target_func[i].name) == 0){
				target_func[i].type = SEQEMU_FUNC_TYPE_FORMAT;
				istyped = 1;
			}
		}

		for(j = 0; malloc_func[j] != NULL; j++){
			if(strcmp(malloc_func[j],target_func[i].name) == 0){
				target_func[i].type = SEQEMU_FUNC_TYPE_MALLOC;
				istyped = 1;
			}
		}

		for(j = 0; buffer_func[j] != NULL; j++){
			if(strcmp(buffer_func[j],target_func[i].name) == 0){
				target_func[i].type = SEQEMU_FUNC_TYPE_BUFFER;
				istyped = 1;
			}
		}

		for(j = 0; libc_start_main[j] != NULL; j++){
			if(strcmp(libc_start_main[j],target_func[i].name) == 0){
				target_func[i].type = SEQEMU_FUNC_TYPE_LIBC_START_MAIN;
				istyped = 1;
			}
		}

		if(istyped == 0){
			target_func[i].type = SEQEMU_FUNC_TYPE_OTHER;
		}

	}

	for(i = 0; i < sh_relplt->sh_size / sizeof(Elf32_Rel); i++){
		fprintf(stderr,"[%d] name : %s, got_addr = 0x%x, plt_addr = 0x%x, type = %x\n",i,target_func[i].name,target_func[i].got_addr,target_func[i].plt_addr,target_func[i].type);
	}


	// If DANGEROUS FUNCTION is EXISTS, display Miho Kohinata
	
	if(!seqemu_disable_dangerous){

		for(i = 0; i < sh_relplt->sh_size / sizeof(Elf32_Rel); i++){
			if(target_func[i].type == SEQEMU_FUNC_TYPE_DANGEROUS){
				seqemu_random_output_of_characters();
			}
		}
	}


}

// Feature-015 Function List from Files
static const char SEQEMU_ELF_DANGEROUS_FUNC_LIST_PATH[] = "resources/general/dangerous.txt";
static const char SEQEMU_ELF_FORMAT_FUNC_LIST_PATH[] = "resources/general/format.txt";
static const char SEQEMU_ELF_MALLOC_FUNC_LIST_PATH[] = "resources/general/malloc.txt";
static const char SEQEMU_ELF_BUFFER_FUNC_LIST_PATH[] = "resources/general/buffer.txt";
static const char SEQEMU_ELF_LIBC_FUNC_LIST_PATH[] = "resources/general/libc.txt";

static const char *SEQEMU_ELF_FUNC_PATHS[] = {
	SEQEMU_ELF_DANGEROUS_FUNC_LIST_PATH,
	SEQEMU_ELF_FORMAT_FUNC_LIST_PATH,
	SEQEMU_ELF_MALLOC_FUNC_LIST_PATH,
	SEQEMU_ELF_BUFFER_FUNC_LIST_PATH,
	SEQEMU_ELF_LIBC_FUNC_LIST_PATH,
	NULL
};

void seqemu_elf_open_func_list(void){
	char *func_name;
	char **list;
	char ****all;
	char buf[100];
	unsigned int line_num;
	int i,j;
	FILE *fp;
	all = (char ****)g_malloc(sizeof(char ***) * 5);
	memset(all,0x0,sizeof(char ***) * 5);

	all[0] = &dangerous_func;
	all[1] = &format_func;
	all[2] = &malloc_func;
	all[3] = &buffer_func;
	all[4] = &libc_start_main;

	for(i = 0; SEQEMU_ELF_FUNC_PATHS[i] != NULL; i++){
		fp = fopen(SEQEMU_ELF_FUNC_PATHS[i],"r");
		line_num = 0;
		while(fgets(buf,sizeof(buf),fp) != NULL){
			line_num++;
		}

		fclose(fp);

		list = (char **)g_malloc(sizeof(char *) * (line_num + 1));
		memset(list,0x0,sizeof(char *) * (line_num + 1));

		fp = fopen(SEQEMU_ELF_FUNC_PATHS[i],"r");

		for(j = 0; j < line_num; j++){
			fscanf(fp,"%[^\n]\n",buf);
			func_name = strdup(buf);
			list[j] = func_name;
		}

		fclose(fp);

		*(all[i]) = list;
	}
}


// Feature-010 Random output of Characters
void seqemu_random_output_of_characters(void){
	// Open dame.txt and get the file size
	struct stat stbuf;
	int character_fd;
	long file_size;
	char *output_buffer;
	int file_number;
	char file_name_buf[30] = {0};
	DIR *dir;
	unsigned int count_of_files = 0;
	struct dirent *dp;
	// open DIR and count of files in the DIR
	dir = opendir("resources/characters");
	if(dir == NULL){
		fprintf(stderr,"[ERROR] No such Directory");
	}

	for(dp = readdir(dir); dp != NULL; dp = readdir(dir)){
		if((strncmp(dp->d_name,".",strlen(".")) == 0) || (strncmp(dp->d_name,"..",strlen("..")) == 0)){
			continue;
		}
		count_of_files++;
	}
	closedir(dir);

	
	// make filename
	strcpy(file_name_buf,"resources/characters/");
	dir = opendir("resources/characters");
	if(dir == NULL){
		fprintf(stderr,"[ERROR] No such Directory");
	}

	srand((unsigned)time(NULL));
	file_number = rand() % count_of_files;

	for(dp = readdir(dir); dp != NULL; dp = readdir(dir)){
		if((strncmp(dp->d_name,".",strlen(".")) == 0) || (strncmp(dp->d_name,"..",strlen("..")) == 0)){
			continue;
		}

		if(file_number == 0){
			strcat(file_name_buf,dp->d_name);
			break;
		}
		
		file_number--;
	}

	
	// open and read and write file
	character_fd = open(file_name_buf,O_RDONLY);
	
	if(character_fd == -1){
		fprintf(stderr,"[ERROR!] Can't open \"%s\" !\n",file_name_buf);
		exit(-1);
	}

	if(fstat(character_fd,&stbuf) == -1){
		fprintf(stderr,"[ERROR!] Can't get the file size!\n");
		exit(-1);
	}

	file_size = stbuf.st_size;

	output_buffer = (char *)g_malloc(sizeof(char) * file_size);

	if(output_buffer == NULL){
		fprintf(stderr,"[ERROR!] Can't get the output_buffer memory!\n");
	}

	read(character_fd,output_buffer,file_size);
	fprintf(stderr,"\n\n%s\n",output_buffer);
	fprintf(stderr,"\n[ABORT!] Dangerous function is EXIST!\n");
	exit(-1);
}

// feature-019 Refactoring
Seqemu_target_func *seqemu_util_get_target_func(unsigned int addr,int t){
	int i;
	Seqemu_target_func *f = NULL;
	for(i = 0; i < seqemu_target_func_num; i++){
		if(target_func[i].plt_addr == addr){
			if(t == 0 || target_func[i].type == t){
				f = (Seqemu_target_func *)calloc(1,sizeof(Seqemu_target_func));
				memcpy(f,&target_func[i],sizeof(Seqemu_target_func));
				break;
			}
		}
	}

	return f;
}

uint32_t seqemu_util_get_arg_n(CPUArchState *env, unsigned int n){
	return *(uint32_t *)(env->regs[R_ESP] + (n * 4) + seqemu_guest_base);
}


// Feature-005 Restricting Format String
// Feature-009 PowerUp the Restricting Format String feature

#define SEQEMU_FORMAT_REPLACE_CHAR 'x'

void seqemu_check_format_string(CPUArchState *env){
	target_ulong eip = env->eip;
	int i,j;
	unsigned int count_of_format_parameter = 0;
	char *string;
	uint32_t arg;
	
	regmatch_t *pmatch;
	Seqemu_target_func *f;

	if(seqemu_format_level == SEQEMU_FEATURE_DISABLE){
		return;
	}

	f = seqemu_util_get_target_func(eip,SEQEMU_FUNC_TYPE_FORMAT);

	if(f == NULL){
		return;
	}

	arg = seqemu_util_get_arg_n(env,1);

	char *format_string = (char *)(arg + seqemu_guest_base);
	count_of_format_parameter = seqemu_util_count_format_string_parameter(format_string);

	fprintf(stderr,"[DEBUG] FORMAT : format parameter is %d\n",count_of_format_parameter);

	string = format_string;
	for(i = 0; i < count_of_format_parameter; i++){
		pmatch = seqemu_util_get_pointer_of_format_string_parameter(string);
		if(seqemu_util_is_n_format(&string[pmatch[0].rm_so],pmatch[0].rm_eo - pmatch[0].rm_so)){
			fprintf(stderr,"[DEBUG] FORMAT : n parameter is number %d\n", i + 1);
			for(j = 0; j < pmatch[0].rm_eo - pmatch[0].rm_so; j++){
				string[pmatch[0].rm_so + j] = SEQEMU_FORMAT_REPLACE_CHAR;
			}
			seqemu_util_adjust_stack_args((unsigned int)i + 1,count_of_format_parameter,env->regs[4]+4);
		}
		string = &string[pmatch[0].rm_eo];
	}

	free(f);

}

unsigned int seqemu_util_count_format_string_parameter(char *format_string){
	unsigned int count = 0;
	char *str = format_string;
	regmatch_t *pmatch;

	pmatch = seqemu_util_get_pointer_of_format_string_parameter(str);

	while(pmatch != NULL){
		count++;
		str = &str[(int)pmatch[0].rm_eo];
		pmatch = seqemu_util_get_pointer_of_format_string_parameter(str);
	}

	g_free(pmatch);

	return count;

}


regmatch_t *seqemu_util_get_pointer_of_format_string_parameter(char *format_string){
	int match_number = 2;
	regmatch_t *pmatch;
	regex_t preg;
	pmatch = (regmatch_t *)g_malloc(sizeof(regmatch_t) * match_number);


	// regular expression compile
	if(regcomp(&preg,"%[ ,#+-]?([1-9][0-9]*|[\*])?(([.]([1-9][0-9]*)|[*$]))?([hlLFN])?[diuXxoqbpscSCfeEgGn]",REG_EXTENDED | REG_NEWLINE) != 0){
		fprintf(stderr,"[FORMAT] regcomp error\n");
		exit(-1);
	}

	// if regular expression is matching, return regmatch_t struct.
	if(regexec(&preg,format_string,match_number,pmatch,0) != 0){
		regfree(&preg);
		return NULL;
	}else{
		regfree(&preg);
		return pmatch;
	}

}

unsigned int seqemu_util_is_n_format(char *s, unsigned int len){
	int i;

	for(i = 0; i < len; i++){
		if(s[i] == 'n'){
			return 1;
		}
	}

	return 0;
}

void seqemu_util_adjust_stack_args(unsigned int erase_arg_index, unsigned int number_of_args,target_ulong first_arg){
	int i;
	uint32_t tmp_value;
	for(i = erase_arg_index; i < number_of_args; i++){
		tmp_value = *(uint32_t *)(((i + 1) * 4) + first_arg + seqemu_guest_base);
		*(uint32_t *)((i * 4) + first_arg + seqemu_guest_base) = tmp_value;
	}
}

// feature-006 Checking Control Flow

int checking_state = 0;
target_ulong protect_return_address = 0x0;
target_ulong checking_return_address_pointer = 0x0;

void seqemu_check_control_flow(CPUArchState *env){
	target_ulong eip = env->eip;
	int i;

	if(seqemu_disable_buffer){
		return;
	}


	//fprintf(stderr,"[DEBUG] EIP = 0x%x: ESP = 0x%x EBP = 0x%x\n",env->eip,env->regs[4],env->regs[5]);

	if(checking_state){
		fprintf(stderr,"[STACK] env->regs[4] + 4 = 0x%x , checking_return_address_pointer = 0x%x\n",env->regs[4] - 4,checking_return_address_pointer);
		if(env->regs[4] - 4 == checking_return_address_pointer){
			fprintf(stderr,"[STACK] Address Checking...\n");
			target_ulong tmp_return_address = *(uint32_t *)(checking_return_address_pointer + seqemu_guest_base);
			fprintf(stderr,"[STACK] Address is 0x%x\n",tmp_return_address);
			if(tmp_return_address != protect_return_address){
				env->eip = protect_return_address;
				fprintf(stderr,"[!!!!!] Modify RA Detected!\n");
				fprintf(stderr,"[!!!!!] tmp = 0x%x\n",tmp_return_address);
				fprintf(stderr,"[!!!!!] Protected Address = 0x%x\n",env->eip);
			}
			protect_return_address = 0x0;
			checking_return_address_pointer = 0x0;
			checking_state = 0x0;
		}
	}else{


		for(i = 0; i < seqemu_target_func_num; i++){
			if(target_func[i].plt_addr == eip && target_func[i].type == SEQEMU_FUNC_TYPE_BUFFER){
				checking_return_address_pointer = env->regs[5] + 4;
				protect_return_address = *(uint32_t *)(checking_return_address_pointer + seqemu_guest_base);
				//checking_function_address = target_func[i].plt_addr;
				checking_state = 1;
				fprintf(stderr,"[STACK] RA = 0x%x\n",protect_return_address);
				break;
			}
		}
	}
}

// feature-007 Checking Heap Chunk
#define SEQEMU_HEAP_MALLOC 1
#define SEQEMU_HEAP_FREE 2

target_ulong heap_func_return_address;
target_ulong heap_func_arg_value;
target_ulong heap_func_allocated_address[100] = {0};
target_ulong heap_func_freed_address[100] = {0};
int checking_return_address = 0;

void seqemu_check_heap_metadata(CPUArchState *env){
	target_ulong eip = env->eip;
	Seqemu_target_func *f;

	if(seqemu_disable_heap){
		return;
	}

	if(!checking_return_address){
		f = seqemu_util_get_target_func(eip,SEQEMU_FUNC_TYPE_MALLOC);

		if(f == NULL){
			return;
		}

		heap_func_arg_value = seqemu_util_get_arg_n(env,1);
		heap_func_return_address = seqemu_util_get_arg_n(env,0);

		if(strcmp(f->name,"malloc") == 0){
			fprintf(stderr,"[MALLOC] malloc(0x%x) is called!\n",heap_func_arg_value);
			checking_return_address = 1;
		}else if(strcmp(f->name,"free") == 0){
			fprintf(stderr,"[MALLOC] free(0x%x) is called!\n",heap_func_arg_value);

			if(seqemu_heap_check_freed_list(heap_func_arg_value)){
				fprintf(stderr,"[!!!!!!] DOUBLE FREE detected! free arg is already freed! Overwrite zero!\n");
				*(uint32_t *)((env->regs[R_ESP] + 4) + seqemu_guest_base) = 0x0;
				return;
			}

			if(!seqemu_heap_check_allocated_list(heap_func_arg_value)){
				fprintf(stderr,"[!!!!!!] Not allocated memory freed! Overwrite zero!\n");
				*(uint32_t *)((env->regs[R_ESP] + 4) + seqemu_guest_base) = 0x0;
			}

			seqemu_heap_add_freed_list(heap_func_arg_value);
			seqemu_heap_remove_malloced_list(heap_func_arg_value);

			checking_return_address = 2;

		}

		fprintf(stderr,"[MALLOC] return address is 0x%x\n",heap_func_return_address);

	}else if(eip == heap_func_return_address){
		switch(checking_return_address){
			// malloc
			case 1:
				seqemu_heap_add_malloced_list(env->regs[R_EAX]);
				seqemu_heap_remove_freed_list(env->regs[R_EAX]);
				fprintf(stderr,"[MALLOC] malloc(0x%x) -> 0x%x\n",heap_func_arg_value,env->regs[R_EAX]);
				break;
			// free
			case 0x2:
				fprintf(stderr,"[MALLOC] free(0x%x) -> 0x%x\n",heap_func_arg_value,env->regs[R_EAX]);
				break;
		}

		heap_func_arg_value = 0x0;
		heap_func_return_address = 0x0;
		checking_return_address = 0x0;
	}
}

void seqemu_heap_add_malloced_list(target_ulong malloc_addr){
	int i;
	for(i = 0; i < 100; i++){
		if(heap_func_allocated_address[i] == 0){
			heap_func_allocated_address[i] = malloc_addr;
			return;
		}
	}

	// malloced list is full
	fprintf(stderr,"[HEAP] malloc-ed list is FULL! Exiting...\n");
	exit(EXIT_FAILURE);
}

void seqemu_heap_add_freed_list(target_ulong freed_addr){
	int i;
	for(i = 0; i < 100; i++){
		if(heap_func_freed_address[i] == 0){
			heap_func_freed_address[i] = freed_addr;
			return;
		}
	}

	// freed list is full
	fprintf(stderr,"[HEAP] free-ed list is FULL! Exiting...\n");
	exit(EXIT_FAILURE);
}

void seqemu_heap_remove_malloced_list(target_ulong free_addr){
	int i;
	for(i = 0; i < 100; i++){
		if(heap_func_allocated_address[i] == free_addr){
			heap_func_allocated_address[i] = 0;
		}
	}
}

void seqemu_heap_remove_freed_list(target_ulong malloc_addr){
	int i;
	for(i = 0; i < 100; i++){
		if(heap_func_freed_address[i] == malloc_addr){
			heap_func_freed_address[i] = 0;
		}
	}
}

int seqemu_heap_check_freed_list(target_ulong free_addr){
	int i;

	for(i = 0; i < 100; i++){
		if(heap_func_freed_address[i] == free_addr){
			return 1;
		}
	}

	return 0;
}


int seqemu_heap_check_allocated_list(target_ulong malloc_addr){
	int i;

	for(i = 0; i < 100; i++){
		if(heap_func_allocated_address[i] == malloc_addr){
			return 1;
		}
	}

	return 0;
}

/*
void seqemu_heap_update_heap_list(target_ulong addr, int type){
	if(type == SEQEMU_HEAP_MALLOC){
		seqemu_heap_add_malloced_list(addr);
		seqemu_heap_remove_freed_list(addr);
	}

	if(type == SEQEMU_HEAP_FREE){
		seqemu_heap_add_freed_list(addr);
		seqemu_heap_remove_malloced_list(addr);
	}

}
*/

// feature-012 Checking System Call
//

Seqemu_syscall_filtering_list *filter;
int seqemu_execute_entry_point = 0;
void seqemu_check_entry_point(CPUArchState *env){
	target_ulong eip = env->eip;
	static int initialized = 0;

	if(initialized){
		return;
	}

	if(seqemu_self_nx_entry == eip){
		fprintf(stderr,"EIP is entry point!\n");
		seqemu_execute_entry_point = 1;
		initialized = 1;
	}
}


void seqemu_check_libc_start_main(CPUArchState *env){
	target_ulong eip = env->eip;
	static int initialized = 0;
	int i;

	if(initialized){
		return;
	}

	for(i = 0; i < seqemu_target_func_num; i++){
		if(target_func[i].plt_addr == eip && target_func[i].type == SEQEMU_FUNC_TYPE_LIBC_START_MAIN){
			fprintf(stderr,"EIP is LIBC_START_MAIN!\n");
			initialized = 1;
			seqemu_execute_libc_start_main = 1;
		}
	}
}

void seqemu_check_system_call(CPUArchState *env){
	int i;
	int syscall_arg_table[5];
	syscall_arg_table[0] = R_EBX;
	syscall_arg_table[1] = R_ECX;
	syscall_arg_table[2] = R_EDX;
	syscall_arg_table[3] = R_ESI;
	syscall_arg_table[4] = R_EDI;

	if(seqemu_disable_syscall){
		return;
	}


	// Adding System Call Trace
	fprintf(stderr,"[SYSCALL] EAX = %x EBX = %x ECX = %x EDX = %x ESI = %x EDI = %X EBP = %x ESP = %x\n",
		env->regs[R_EAX],env->regs[R_EBX],env->regs[R_ECX],env->regs[R_EDX],env->regs[R_ESI],env->regs[R_EDI],env->regs[R_EBP],env->regs[R_ESP]);

	i = 0;
	while(filter[i].syscall_number != 0){
		if(filter[i].syscall_number == env->regs[R_EAX]){
			if(filter[i].has_arg == 0){
				fprintf(stderr,"[SYSCALL] Number %x system call is prohibited!\n",filter[i].syscall_number);
				exit(-1);
			}else{
				if(filter[i].arg_type == 0){
					if(filter[i].u.num == env->regs[syscall_arg_table[filter[i].arg_index - 1]]){
						fprintf(stderr,"[SYSCALL] Number %x system call index %x with %x is prohibited!\n",filter[i].syscall_number,filter[i].arg_index,filter[i].u.num);
						exit(-1);
					}
				}else{
					if(strcmp(filter[i].u.str,(char *)(env->regs[syscall_arg_table[filter[i].arg_index - 1]] + seqemu_guest_base)) == 0){
						fprintf(stderr,"[SYSCALL] Number %x system call index %x with %s is prohibited!\n",filter[i].syscall_number,filter[i].arg_index,filter[i].u.str);
						exit(-1);
					}
				}
			}
		}
		i++;
	}
}

void seqemu_load_syscall_filtering_list(void){
	int ret,line_num,filter_index;
	FILE *fp;
	unsigned int num1,num2,num3;
	char buf1[100],buf2[100];

	// counting line
	line_num = 0;

	fp = fopen("resources/syscall/filter.txt","r");
	while(fgets(buf1,100,fp) != NULL){
		line_num++;
	}

	fclose(fp);

	// allocating system call filter list

	filter = (Seqemu_syscall_filtering_list *)g_malloc(sizeof(Seqemu_syscall_filtering_list) * (line_num + 1));
	memset(filter,0x0,sizeof(Seqemu_syscall_filtering_list) * (line_num + 1));
	fp = fopen("resources/syscall/filter.txt","r");


	//test variable
	memset(buf1,0x0,100);
	memset(buf2,0x0,100);


	filter_index = 0;

	while((ret = fscanf(fp,"%u,%u,%u,%[^,],%s",&num1,&num2,&num3,buf1,buf2)) != EOF){
		filter[filter_index].syscall_number = num1;
		filter[filter_index].has_arg = num2;
		if(num2 == 0){
			filter_index++;
			continue;
		}
		filter[filter_index].arg_index = num3;
		if(strncmp("num",buf1,3) == 0){
			filter[filter_index].arg_type = 0;
		}else if(strncmp("str",buf1,3) == 0){
			filter[filter_index].arg_type = 1;
		}else{
			fprintf(stderr,"[SYSCALL] NO DEFINE TYPE is recognized!\n");
			exit(-1);
		}
		if(filter[filter_index].arg_type == 0){
			filter[filter_index].u.num = atoi(buf2);
		}else{
			filter[filter_index].u.str = strdup(buf2);
		}

		filter_index++;
		memset(buf1,0x0,100);
		memset(buf2,0x0,100);
	}


	////// DEBUG

	fprintf(stderr,"[SYSCALL] SYSCALL TALBE is below\n");
	int i;

	for(i = 0; i < line_num; i++){
		if(filter[i].arg_type == 0){
			fprintf(stderr,"%u %u %u %u %u\n",filter[i].syscall_number,filter[i].has_arg,filter[i].arg_index,filter[i].arg_type,filter[i].u.num);
		}else{
			fprintf(stderr,"%u %u %u %u %s\n",filter[i].syscall_number,filter[i].has_arg,filter[i].arg_index,filter[i].arg_type,filter[i].u.str);

		}
	}

	////// DEBUG END
	
	fclose(fp);

}


///////////////////////
// HONEYPOT
///////////////////////

const char SEQEMU_HONEYPOT_LIST_FILE[] = "resources/honeypot/function_list.txt";
const char SEQEMU_HONEYPOT_LOG_FILE[] = "honeypot.log";
const char SEQEMU_HONEYPOT_TIME_FORMAT[] = "%Y/%m/%d %H:%M:%S";

FILE *seqemu_honeypot_logfile;
int honeypot_checking_state = 0;
char *seqemu_honeypot_current_target_func = NULL;
uint32_t seqemu_honeypot_ra;
uint32_t *seqemu_honeypot_buffer_address;
Seqemu_honeypot_function_list *honeypot_list;

void seqemu_function_honey_pot(CPUArchState *env){
	target_ulong eip = env->eip;
	int i;
	int buffer_index;
	int honeypot_index;
	if(seqemu_disable_honeypot){
		return;
	}

	//fprintf(stderr,"[HONEY] EIP = 0x%x: ESP = 0x%x\n",env->eip,env->regs[4]);


	// after execute library function
	if(honeypot_checking_state){
		if(eip == seqemu_honeypot_ra){
			seqemu_honeypot_write_log(seqemu_honeypot_current_target_func,(char *)seqemu_honeypot_buffer_address);
			seqemu_honeypot_current_target_func = NULL;
			honeypot_checking_state = 0;
		}
	}else{
	// before execute library function
		// get RA and pointer of RA
		honeypot_index = 0;
		buffer_index = 0;
		for(i = 0; i < seqemu_target_func_num; i++){
			if(target_func[i].plt_addr == eip){
				while(honeypot_list[honeypot_index].name != NULL){
					if(strcmp(honeypot_list[honeypot_index].name,target_func[i].name) == 0){
						seqemu_honeypot_current_target_func = strdup(target_func[i].name);
						// get RA
						seqemu_honeypot_ra = *(uint32_t *)(env->regs[R_ESP] + seqemu_guest_base);
						// get buffer address
						buffer_index = honeypot_list[honeypot_index].arg_index;
						seqemu_honeypot_buffer_address = (uint32_t *)((*(uint32_t *)(env->regs[R_ESP] + (buffer_index * 4) + seqemu_guest_base)) + seqemu_guest_base);
						honeypot_checking_state = 1;
						break;
					}
					honeypot_index++;
				}
			}
			if(buffer_index != 0){
				break;
			}

		}
	}
}


void seqemu_open_honeypot_logfile(void){
	if(seqemu_disable_honeypot){
		return;
	}

	seqemu_honeypot_logfile = fopen(SEQEMU_HONEYPOT_LOG_FILE,"w");
}

void seqemu_honeypot_open_function_list(void){
	char buf[100] = {0};
	int num_of_function = 0;
	int index_of_arg;
	int i;
	FILE *fp;

	if(seqemu_disable_honeypot){
		return;
	}

	fp = fopen(SEQEMU_HONEYPOT_LIST_FILE,"r");
	
	while(fgets(buf,sizeof(buf),fp) != NULL){
		num_of_function++;
	}

	fclose(fp);

	honeypot_list = (Seqemu_honeypot_function_list *)g_malloc(sizeof(Seqemu_honeypot_function_list) * (num_of_function + 1));
	memset(honeypot_list,0x0,sizeof(Seqemu_honeypot_function_list) * (num_of_function + 1));


	fp = fopen(SEQEMU_HONEYPOT_LIST_FILE,"r");

	for(i = 0; i < num_of_function; i++){
		fscanf(fp,"%[^,],%d\n",buf,&index_of_arg);
		honeypot_list[i].name = strdup(buf);
		honeypot_list[i].arg_index = index_of_arg;
	}

	fclose(fp);
}

void seqemu_honeypot_write_log(char *func, char *log){
	int buffer_length;
	char *ptr;
	char date[64] = {0};
	time_t t;

	buffer_length = strlen(log);

	ptr = (char *)g_malloc(sizeof(char) * buffer_length);
	memset(ptr,0x0,sizeof(char) * buffer_length);

	strncpy(ptr,log,buffer_length);
	ptr[buffer_length] = '\0';

	t = time(NULL);
	strftime(date,sizeof(date),SEQEMU_HONEYPOT_TIME_FORMAT,localtime(&t));

	fprintf(seqemu_honeypot_logfile,"%s:[%s] %s\n",date,func,ptr);
	fflush(seqemu_honeypot_logfile);
}


// feature-016 Add self NX

uint32_t seqemu_self_nx_ra;
uint32_t seqemu_self_nx_libc_ra;
int seqemu_self_nx_check_start = 0;
void seqemu_self_nx(CPUArchState *env){
	static int is_lib_executing = 0;
	int i;

	if(seqemu_disable_selfnx){
		return;
	}


	if(seqemu_execute_entry_point != 1){
		return;
	}


	target_ulong eip = env->eip;

	fprintf(stderr,"[NX] %x (%d) is now executing\n",eip,is_lib_executing);

	if(is_lib_executing == 0){
		if(eip == seqemu_self_nx_libc_ra){
			seqemu_self_nx_check_start = 1;
			return;
		}

		if(!(seqemu_image_info.start_code <= eip && eip <= seqemu_image_info.end_code) && seqemu_self_nx_check_start == 1){
			fprintf(stderr,"[NX] %x Self NX is Enabled!\n",eip);
			exit(-1);
		}

		for(i = 0; i < seqemu_target_func_num; i++){
			if(target_func[i].plt_addr == eip){
				if(strcmp("__libc_start_main",target_func[i].name) == 0){
					seqemu_self_nx_libc_ra = *(uint32_t *)(env->regs[R_ESP] + 4 + seqemu_guest_base);
					break;
				}
				is_lib_executing = 1;
				// Get RA
				seqemu_self_nx_ra = *(uint32_t *)(env->regs[R_ESP] + seqemu_guest_base);
				fprintf(stderr,"[NX] %x is lib return address\n",seqemu_self_nx_ra);
				break;
			}
	
		}
	}else{
		if(eip == seqemu_self_nx_ra){
			is_lib_executing = 0;
		}
	}
}

// feature-018 Adding UAF prevention

const char SEQEMU_UAF_LIST_FILE[] = "resources/uaf/function.txt";
Seqemu_uaf_function_list *uaf_list;
void seqemu_uaf_prevention(CPUArchState *env){
	target_ulong eip = env->eip;
	int i,uaf_index,j;


	if(seqemu_disable_uaf){
		return;
	}

	uaf_index = 0;

	for(i = 0; i < seqemu_target_func_num; i++){
		if(target_func[i].plt_addr == eip){
			while(uaf_list[uaf_index].name != NULL){
				if(strcmp(uaf_list[uaf_index].name,target_func[i].name) == 0){
					for(j = 0; j < 100; j++){
						if(heap_func_freed_address[j] == 0){
							continue;
						}
						fprintf(stderr,"[UAF] address is %x\n",(unsigned int)heap_func_freed_address[j]);
						seqemu_uaf_check_arg(env,uaf_list[uaf_index].arg_num,(uint32_t)heap_func_freed_address[j]);
					}
				}
				uaf_index++;
			}
		}
	}
}


uint32_t seqemu_uaf_get_arg_n(CPUArchState *env, unsigned int n){
	return *(uint32_t *)(env->regs[R_ESP] + (n * 4) + seqemu_guest_base);
}

void seqemu_uaf_check_arg(CPUArchState *env, unsigned int n, uint32_t value){
	int i;

	for(i = 0; i < n; i++){
		if(value == seqemu_uaf_get_arg_n(env,i)){
			fprintf(stderr,"[UAF] Use After Free Detected! Exiting...\n");
			exit(-1);
		}
	}
}


void seqemu_uaf_open_function_list(void){
	FILE *fp;
	char buf[100] = {0};
	int num_of_function = 0;
	int num_of_arg;
	int i;

	if(seqemu_disable_uaf){
		return;
	}

	fp = fopen(SEQEMU_UAF_LIST_FILE,"r");

	
	while(fgets(buf,sizeof(buf),fp) != NULL){
		num_of_function++;
	}

	fclose(fp);

	uaf_list = (Seqemu_uaf_function_list *)g_malloc(sizeof(Seqemu_uaf_function_list) * (num_of_function + 1));
	memset(uaf_list,0x0,sizeof(Seqemu_uaf_function_list) * (num_of_function + 1));


	fp = fopen(SEQEMU_UAF_LIST_FILE,"r");

	for(i = 0; i < num_of_function; i++){
		fscanf(fp,"%[^,],%d\n",buf,&num_of_arg);
		uaf_list[i].name = strdup(buf);
		uaf_list[i].arg_num = num_of_arg;
	}

	fclose(fp);

	fprintf(stderr,"[UAF] here is list of functions\n");
	for(i = 0; i < num_of_function; i++){
		fprintf(stderr,"[%d] %s %d\n",i,uaf_list[i].name,uaf_list[i].arg_num);
	}

}

