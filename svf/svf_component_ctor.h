/*
 * svf_component_ctor.h
 *
 *  Created on: Oct 15, 2013
 *      Author: ballance
 */

#ifndef SVF_COMPONENT_CTOR_H_
#define SVF_COMPONENT_CTOR_H_
#include "svf_string.h"

class svf_component;
template <class COMP_T> class svf_component_ctor {

	public:
		svf_component_ctor(const svf_string &type_name) {
			// TODO: register with factory
		}

		static COMP_T *create(const svf_string &inst_name, svf_component *parent) {
			return new COMP_T(inst_name, parent);
		}

};




#endif /* SVF_COMPONENT_CTOR_H_ */
