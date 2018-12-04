sudo qemu-system-arm \
    -M vexpress-a9 \
    -m 1024M \
    -kernel ./out_vexpress_3_16/arch/arm/boot/zImage \
    -serial stdio \
    -dtb ./vexpress-v2p-ca9.dtb \
    -append "ip=dhcp,root=/dev/nfs rw console=ttyAMA0 \
    nfsroot=192.168.2.127:/home/jizh/git/busybox/rootfs rw \
    nfsrootdebug" \
    -netdev bridge,id=n0 \
    -device netdev=n0 \
    #-device virtio-net-device,netdev=n0 \
    #-sd ./a9rootfs.ext3 \
    # qemu-system-arm -M vexpress-a9 -net nic,model=\?

    # bridge方式下，qemu依然会产生一个tap0网卡
    # 我们需要手动配置/etc/systemd/network/br0.network
    # 来为ArchLinux产生一个bridge，即br0
    # br0负责桥接ArchLinux的enp0s3网卡和tap0网卡，
    # 前者可以访问外网，因此tap0也可以访问外网
    # 奇怪的是，配置完成后，发现Win/Mac都没有ssh到ArchLinux了。
    # 可惜这种方式没有配置成功
