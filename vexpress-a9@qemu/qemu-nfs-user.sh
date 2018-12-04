KERN="./out_vexpress/arch/arm/boot/zImage"

qemu-system-arm \
    -M vexpress-a9 \
    -m 1024M \
    -kernel $KERN -serial stdio \
    -dtb ./vexpress-v2p-ca9.dtb \
    -append "root=/dev/nfs rw console=ttyAMA0 \
    nfsroot=10.0.2.2:/srv/nfs/rootfs,proto=tcp,vers=3 rw \
    ip=dhcp \
    init=/sbin/init \
    nfsrootdebug" \
    -net nic \
    -net user \

    # -net user是qemu进程为Arch主机新增的网卡，其ip由qemu自动配置 
    # -net nic是arm虚拟机内部网卡，其ip由append参数中的ip参数配置
