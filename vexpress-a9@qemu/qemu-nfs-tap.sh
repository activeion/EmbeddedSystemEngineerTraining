KERN="./out_vexpress/arch/arm/boot/zImage"

sudo qemu-system-arm \
    -M vexpress-a9 \
    -m 1024M -smp 4 \
    -kernel $KERN -serial stdio \
    -dtb ./vexpress-v2p-ca9.dtb \
    -append "root=/dev/nfs rw console=ttyAMA0 \
    nfsroot=192.168.0.11:/srv/nfs/rootfs,proto=tcp,vers=3 \
    ip=192.168.0.110:192.168.0.11:192.168.0.1:255.255.255.0:::off \
    nfsrootdebug loglevel=8" \
    -net tap \
    -net nic \
    -s \
    #-netdev tap,id=n0 \
    #-device virtio-net-device,netdev=n0 \

    # -net tap是qemu进程为Arch主机新增的网卡，其ip有/etc/qemu-ifup配置 
    # -net nic是arm虚拟机内部网卡，其ip是由append参数配置的
