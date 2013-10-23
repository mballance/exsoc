
TB_SRC = \



ALL_TARGETS += libtb.a

INCLUDES += -I$(EXSOC_ROOT)/tb 

libtb.a : $(TB_SRC:.cpp=.o)
	rm -f $@
	$(AR) vcq $@ $^
	

%.o : $(EXSOC_ROOT)/tb/%.cpp
	$(CXX) -c $(INCLUDES) $(EXSOC_ROOT)/tb/$*.cpp

