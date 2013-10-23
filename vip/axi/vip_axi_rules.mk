

libvip_axi.a : $(VIP_AXI_SRC:.cpp=.o)
	rm -f $@
	$(AR) vcq $@ $^

%.o : $(VIP_AXI_ROOT)/%.cpp
	$(CXX) -c $(INCLUDES) $(VIP_AXI_ROOT)/$*.cpp
	
	
