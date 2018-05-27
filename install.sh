#!/bin/sh

#lib for QEMU build
apt-get update
apt-get install -y git-email
apt-get install -y libaio-dev libbluetooth-dev libbrlapi-dev libbz2-dev
apt-get install -y libcap-dev libcap-ng-dev libcurl4-gnutls-dev libgtk-3-dev
apt-get install -y libibverbs-dev libjpeg8-dev libncurses5-dev libnuma-dev
apt-get install -y librbd-dev librdmacm-dev
apt-get install -y libsasl2-dev libsdl1.2-dev libseccomp-dev libsnappy-dev libssh2-1-dev
apt-get install -y libvde-dev libvdeplug-dev libvte-2.90-dev libxen-dev liblzo2-dev
apt-get install -y valgrind xfslibs-dev
apt-get install -y libnfs-dev libiscsi-dev

#lib for x86 binary on x64
dpkg --add-architecture i386
apt-get update
apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386
apt-get install -y vim
apt-get install -y gcc-multilib g++-multilib
apt-get install -y binutils

#git config
git config --global user.email "01ssrmikururudevice01@gmail.com"
git config --global user.name "happynote3966"

#peda install
git clone https://github.com/longld/peda.git ~/peda
echo "source ~/peda/peda.py" >> ~/.gdbinit
echo "set disassembly-flavor intel" >> ~/.gdbinit

#copy tmux conf
cp .tmux.conf ~/
