KERN="./out_vexpress/arch/arm/boot/zImage"

qemu-system-arm \
    -M vexpress-a9 \
    -dtb ./vexpress-v2p-ca9.dtb \
    -m 1024M \
    -kernel $KERN -serial stdio \
    -append "root=/dev/mmcblk0 rw console=ttyAMA0 \
    ip=dhcp" \
    -sd ./a9rootfs.ext3 \
    -net nic \
    -net user \

    # -net user是qemu进程为Arch主机新增的网卡，其ip由qemu自动配置 
    # -net nic是arm虚拟机内部网卡，其ip由append参数中的ip参数配置
