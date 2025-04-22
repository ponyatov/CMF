HW ?= pc
# HW ?= iskra
# HW ?= f429disco

ELF = bin/$(BINFILE).elf
DFU = bin/$(BINFILE).dfu

include   hw/$(HW)/$(HW).mk
include  cpu/$(CPU)/$(CPU).mk
include arch/$(ARCH)/$(ARCH).mk
include   os/$(OS)/$(OS).mk

.PHONY: elf
elf: $(ELF)

.PHONY: dfu
dfu: $(DFU)
$(DFU): $(ELF)
	~/elf2dfuse/bin/elf2dfuse $< $@

.PHONY: qemu
qemu: $(ELF)
	$(QEMU) $(QEMU_CFG) -S -s -kernel $<
