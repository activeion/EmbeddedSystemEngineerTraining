# file: qemu_debug-kernel.sh
# usage: ./qemu_debug-kernel.sh 


# 获取本脚本相对于当前目录的路径
#DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
S0="${BASH_SOURCE[0]}"
DIRNAME="$( dirname "$S0")"
DIR="$( cd "$DIRNAME" && pwd)"
echo "$S0"
echo "$DIRNAME"
echo "$DIR" #绝对地址

KERN="./out_vexpress/arch/arm/boot/zImage"

qemu-system-arm \
    -M vexpress-a9 \
    -m 1024M \
    -kernel $DIRNAME/$KERN -serial stdio \
    -dtb $DIRNAME/vexpress-v2p-ca9.dtb \
    -append "root=/dev/nfs rw console=ttyAMA0 \
        nfsroot=10.0.2.2:/srv/nfs/rootfs,proto=tcp,vers=3 rw \
        ip=dhcp \
        init=/sbin/init \
        nfsrootdebug loglevel=8" \
    -net nic \
    -net user \
    -S -s  
