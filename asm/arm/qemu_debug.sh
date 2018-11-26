# file: qemu_debug
# usage: ./qemu_debug debugee


# 获取本脚本相对于当前目录的路径
#DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
S0="${BASH_SOURCE[0]}"
DIRNAME="$( dirname "$S0")"
DIR="$( cd "$DIRNAME" && pwd)"
echo "$S0"
echo "$DIRNAME"
echo "$DIR" #绝对地址

qemu-system-arm -machine vexpress-a9 -m 1024 -serial stdio -net nic -kernel $1 -S -s &
# cgdb -d arm-none-eabi-gdb -- -ex "target remote localhost:1234"  $1
cgdb -d arm-none-eabi-gdb -- -x $DIRNAME/script_gdb_arm  $1
ps -ef |grep qemu-system-arm |awk '{print $2}'|xargs kill -9
