#ifndef INCLUDED_SVF_MACROS_H
#define INCLUDED_SVF_MACROS_H

#define svf_component_utils(component_t) \
	public: \
		static svf_component_ctor<component_t>	svf_type;

#define svf_component_utils_def(component_t) \
	svf_component_ctor<component_t> component_t :: svf_type(#component_t);


#endif /* INCLUDED_SVF_MACROS_H */
