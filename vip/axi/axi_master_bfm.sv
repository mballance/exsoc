/****************************************************************************
 * axi_master_bfm.sv
 ****************************************************************************/

/**
 * Module: axi_master_bfm
 * 
 * TODO: Add module documentation
 */
module axi_master_bfm #(
		parameter int	DATA_WIDTH=64) 
		(
		input					clk,
		input					resetn,
		axi4_if.master			master
		);
	bit[(DATA_WIDTH-1):0]		data_buf[16];
	
	initial begin
		repeat (20) 
		$display("sizeof(aw.data): %0d", $size(master.AWADDR));
	end
	
	task axi_master_bfm_set_wdata(int data_idx, longint unsigned data);
		data_buf[data_idx] = data;
	endtask
	export "DPI-C" task axi_master_bfm_set_wdata;

	task axi_master_bfm_write(
		longint unsigned 	addr,
		int					burst_sz,
		int					burst_len);
	endtask
	export "DPI-C" task axi_master_bfm_write;
	
	task axi_master_bfm_read(
		longint unsigned	addr,
		int					burst_sz,
		int					burst_len);
		
	endtask
	export "DPI-C" task axi_master_bfm_read;

endmodule

