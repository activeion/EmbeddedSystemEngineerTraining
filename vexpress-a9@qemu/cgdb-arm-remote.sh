cgdb -d arm-none-eabi-gdb -- -ex "target remote localhost:1234"  out_vexpress/vmlinux
ps -ef |grep qemu-system-arm |awk '{print $2}'|xargs kill -9
