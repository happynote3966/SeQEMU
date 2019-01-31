#!/bin/bash

array=("format" "buffer" "df" "relro" "dangerous" "nx" "uaf" "syscall" "honeypot")


mkdir ~/Demo
cd build_i386_linux_user/i386-linux-user/
cp ./qemu-i386 ~/Demo/
cp ./flag.txt ~/Demo/
cp -r ./resources ~/Demo/
cp ../test-* ~/Demo/

cd ~/Demo/

# name change
mv ./test-dangerous-disable-sec test-dangerous
mv ./test-normal.c test-honeypot.c
mv ./test-normal test-honeypot
mv ./test-open.c test-syscall.c
mv ./test-open test-syscall

for i in `seq 1 1 9`
do

cat <<EOF > ${i}-${array[$i - 1]}-normal.sh
echo "[DEMO] Demo start"
./test-${array[$i - 1]}
echo "[DEMO] Demo end"
EOF
chmod +x ${i}-${array[$i - 1]}-normal.sh

done


for i in `seq 1 1 9`

do

cat <<EOF > ${i}-${array[$i - 1]}-seqemu.sh
echo "[DEMO] Demo start"
./qemu-i386 ./test-${array[$i - 1]} 2>log.txt
echo "[DEMO] Demo end"
EOF
chmod +x ${i}-${array[$i - 1]}-seqemu.sh

done
