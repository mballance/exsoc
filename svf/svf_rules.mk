
libsvf_sc.a : $(SVF_SC_SRC:.cpp=.o)
	rm -f $@
	$(AR) vcq $@ $^
	
libsvf.a : $(SVF_SRC:.cpp=.o)
	rm -f $@
	$(AR) vcq $@ $^

%.o : $(SVF_ROOT)/%.cpp	
	$(CXX) -c $(SVF_INCLUDES) $(CXXFLAGS) $(SVF_ROOT)/$*.cpp

%.o : $(SVF_ROOT)/sc/%.cpp
	$(CXX) -c $(SVF_INCLUDES) -I$(SVF_ROOT)/sc $(CXXFLAGS) $(SVF_ROOT)/sc/$*.cpp

