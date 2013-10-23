
#include "verilated_sc.h"
#include "verilated_vcd_sc.h"
#include "Vaxi_example_top.h"
#include "systemc.h"
#include "axi_master_bfm.h"

extern "C" void foobar()
{
	fprintf(stdout, "foobar: %s\n", svGetNameFromScope(svGetScope()));
}

class axi_example_top : sc_module {
	public:

		axi_example_top(const sc_module_name &inst_name);

	public:
		sc_signal<bool> reset;
		sc_clock		clk;
		Vaxi_example_top *top;

		axi_master_bfm *axi_bfm;

};

axi_example_top::axi_example_top(const sc_module_name &inst_name) :
		sc_module(inst_name), reset("reset"),
		clk("clk", 10, SC_NS, 0.5, 3, SC_NS, true) {

	top = new Vaxi_example_top("top");
	top->reset(reset);
	top->clk(clk);

	axi_bfm = new axi_master_bfm("axi_bfm", 0); // "top.v.master_bfm");

}

int sc_main(int argc, char **argv) {
	axi_example_top *axi_top;

	Verilated::commandArgs(argc, argv);

	axi_top = new axi_example_top("axi_top");

	// First step to get SystemC going
	sc_start(1, SC_NS);

	Verilated::traceEverOn(true);
	VerilatedVcdSc *tfp = new VerilatedVcdSc();

	axi_top->top->trace(tfp, 99);
	tfp->open("vlt_dump.vcd");


	while (!Verilated::gotFinish()) {
		if (tfp) {
			tfp->flush();
		}

		if (VL_TIME_Q() > 10) {
			axi_top->reset = 0;
		} else {
			axi_top->reset = 1;
		}

		if (VL_TIME_Q() == 10) {
			svScope scope = svGetScopeFromName("axi_top.top.v.master_bfm");
			fprintf(stdout, "scope=%p\n", scope);
			svSetScope(scope);
//			write32(0);
		}

		sc_start(1, SC_NS);

		if (VL_TIME_Q() > 10000) {
			break;
		}
	}

	axi_top->top->final();

	tfp->close();

	delete axi_top;

	return 0;
}
