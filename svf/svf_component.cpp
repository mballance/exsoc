/*
 * svf_component.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: ballance
 */

#include "svf_component.h"

svf_component::svf_component(const svf_string &inst_name, svf_component *parent) {
	m_inst_name = inst_name;
	m_parent = parent;
}

svf_component::~svf_component() {
	// TODO Auto-generated destructor stub
}

