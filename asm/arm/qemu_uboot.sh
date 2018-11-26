sudo qemu-system-arm \
    -machine vexpress-a9 \
    -m 1024 \
    -serial stdio \
    -net nic -net tap \
    -kernel u-boot \
    -s
