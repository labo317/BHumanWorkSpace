# 词典

### watchdog 

watchdog是Linux看门狗。

Linux 自带了一个 watchdog 的实现，用于监视系统的运行，包括一个内核 watchdog module 和一个用户空间的 watchdog 程序。

内核 watchdog 模块通过 /dev/watchdog 这个字符设备与用户空间通信。用户空间程序一旦打开 /dev/watchdog 设备，就会导致在内核中启动一个 1分钟的定时器，此后，用户空间程序需要保证在 1分钟之内向这个设备写入数据，每次写操作会导致重新设定定时器。如果用户空间程序在 1分钟之内没有写操作，定时器到期会导致一次系统 reboot 操作。

### DCM

设备通信管理器。

---

# EOF