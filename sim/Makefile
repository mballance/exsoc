
ifeq (,$(EXSOC_ROOT))
	EXSOC_ROOT=$(shell dirname `pwd`)
endif
SVF_ROOT=$(EXSOC_ROOT)/svf
VIP_AXI_ROOT=$(EXSOC_ROOT)/vip/axi

INCLUDES = -I$(SYSTEMC)/include -I$(SVF_ROOT)

include $(SVF_ROOT)/svf_defs.mk
include $(VIP_AXI_ROOT)/vip_axi_defs.mk

all : libs.a

include $(EXSOC_ROOT)/tb/tb.mk

libs.a : $(ALL_TARGETS)
	rm -rf obj_tmp
	mkdir obj_tmp
	cd obj_tmp ; for lib in $(ALL_TARGETS); do \
		ar xvf ../$$lib ; \
	done ; \
	rm -f libs.a ;
	cd obj_tmp ; ar vcq ../libs.a *.o
	rm -rf obj_tmp
	

include $(SVF_ROOT)/svf_rules.mk
include $(VIP_AXI_ROOT)/vip_axi_rules.mk


clean :
	rm -rf *.o *.a obj_dir obj_tmp


