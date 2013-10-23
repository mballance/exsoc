/*
 * svf_component.h
 *
 *  Created on: Oct 15, 2013
 *      Author: ballance
 */

#ifndef SVF_COMPONENT_H_
#define SVF_COMPONENT_H_
#include "svf_string.h"

class svf_component {

	public:
		svf_component(const svf_string &inst_name, svf_component *parent);
		virtual ~svf_component();

	protected:

	private:
		svf_string							m_inst_name;
		svf_component						*m_parent;
};

#endif /* SVF_COMPONENT_H_ */
