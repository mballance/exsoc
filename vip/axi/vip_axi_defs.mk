
ifeq (,VIP_AXI_ROOT)
	VIP_AXI_ROOT=.
endif

ALL_TARGETS += libvip_axi.a
INCLUDES += -I$(VIP_AXI_ROOT)

VIP_AXI_SRC = \
	axi_master_bfm.cpp

	
	
