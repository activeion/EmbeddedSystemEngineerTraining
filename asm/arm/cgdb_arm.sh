# file: cgdb_arm.sh
# usage: ./cgdb_arm.sh debugee


# 获取本脚本相对于当前目录的路径
#DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
S0="${BASH_SOURCE[0]}"
DIRNAME="$( dirname "$S0")"
DIR="$( cd "$DIRNAME" && pwd)"
echo "$S0"
echo "$DIRNAME"
echo "$DIR" #绝对地址

cgdb -d arm-none-eabi-gdb -- -x $DIRNAME/script_gdb_arm  $1
