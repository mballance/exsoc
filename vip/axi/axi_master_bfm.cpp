/*
 * axi_master_bfm.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: ballance
 */

#include "axi_master_bfm.h"

axi_master_bfm::axi_master_bfm(
		const svf_string 	&inst_name,
		svf_component		*parent) : svf_component(inst_name, parent) {

//	m_bfm_scope = svGetScopeFromName(bfm_inst_name.c_str());

//	fprintf(stdout, "bfm_scope: %p\n", m_bfm_scope);
}

axi_master_bfm::~axi_master_bfm() {
	// TODO Auto-generated destructor stub

}

svf_component_utils_def(axi_master_bfm)
