/****************************************************************************
 * axi_example_top.sv
 ****************************************************************************/

/**
 * Module: axi_example_top
 * 
 * TODO: Add module documentation
 */
module axi_example_top(input clk, input reset);

	axi4_if			master_slave(clk, reset);

	/*
	axi_master master (
			.clk(clk),
			.resetn(reset),
			.aw_1(master_slave.aw_slave),
			.b_1(master_slave.b_slave),
			.ar_1(master_slave.ar_slave),
			.r_1(master_slave.r_slave)
			);
		
			 */
	
	axi_slave slave (
		.clk    (clk   ), 
		.reset  (reset ), 
		.aw_1   (master_slave.aw_master  ), 
		.b_1    (master_slave.b_master   ), 
		.ar_1   (master_slave.ar_master  ), 
		.r_1    (master_slave.r_master   ));

	axi_master_bfm master_bfm (
		.clk     (clk    ), 
		.resetn  (reset ), 
		.master	 (master_slave.slave));
	
endmodule

