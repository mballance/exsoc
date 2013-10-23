/*
 * axi_master_bfm.h
 *
 *  Created on: Oct 14, 2013
 *      Author: ballance
 */

#ifndef AXI_MASTER_BFM_H_
#define AXI_MASTER_BFM_H_

#include "svf.h"
#include <string>
#include <stdint.h>
//#include "svdpi.h"

extern "C" {
	void axi_master_bfm_set_wdata(int data_idx, uint64_t data);
	void axi_master_bfm_write(uint64_t addr, int burst_sz, int burst_len);
}

class axi_master_bfm: public svf_component {
	svf_component_utils(axi_master_bfm)

	public:
		axi_master_bfm(
				const svf_string 		&inst_name,
				svf_component			*parent);

		virtual ~axi_master_bfm();

	private:
		void						*m_bfm_scope;
};

#endif /* AXI_MASTER_BFM_H_ */
