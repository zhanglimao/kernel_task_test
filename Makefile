obj-m := demo.o
CURRENT_PATH := $(shell pwd)
LINUX_KERNEL := $(shell uname -r)
LINUX_KERNEL_PATH := /usr/src/linux-headers-$(LINUX_KERNEL)
#LINUX_KERNEL_PATH := /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules
clean:
	rm *.ko -rf
	rm *.o -rf
	rm modules.order  Module.symvers *.mod.c -rf .*.ko.cmd  .*.mod.o.cmd  .*.o.cmd .tmp_versions -rf
