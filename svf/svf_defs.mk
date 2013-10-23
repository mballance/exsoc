
ifeq (,$(SVF_ROOT))
	SVF_ROOT=.
endif

SVF_INCLUDES=-I$(SVF_ROOT) -I$(SYSTEMC)/include

INCLUDES += -I$(SVF_ROOT)

SVF_LIBS=libsvf_sc.a libsvf.a

ALL_TARGETS += $(SVF_LIBS)

SVF_SC_SRC = \
	svf_env_primitives_sc.cpp

SVF_SRC = \
		svf_component.cpp \
		svf_condition.cpp \
		svf_mutex.cpp \
		svf_string.cpp \
		svf_thread.cpp
	
