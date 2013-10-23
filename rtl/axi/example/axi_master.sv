/****************************************************************************
 * axi_master.sv
 ****************************************************************************/

/**
 * Module: axi_master
 * 
 * TODO: Add module documentation
 */
module axi_master(
		input					clk,
		input					resetn,
		axi4_if.aw_master		aw_1,
		axi4_if.b_master		b_1,
		axi4_if.ar_master		ar_1,
		axi4_if.r_master		r_1);

	always @(posedge clk) begin
		$display("ax_master: clk");
	end

endmodule

