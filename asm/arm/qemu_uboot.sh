# file: qemu_uboot.sh
# usage: ./qemu_uboot.sh


# 获取本脚本相对于当前目录的路径
#DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
S0="${BASH_SOURCE[0]}"
DIRNAME="$( dirname "$S0")"
DIR="$( cd "$DIRNAME" && pwd)"
echo "$S0"
echo "$DIRNAME"
echo "$DIR" #绝对地址

sudo qemu-system-arm \
    -machine vexpress-a9 \
    -m 1024 \
    -serial stdio \
    -net nic -net tap \
    -kernel $DIRNAME/u-boot \
    -s
