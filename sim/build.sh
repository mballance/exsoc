#!/bin/sh

try()
{
	$*
	status=$?
	if test $status -ne 0; then
		echo "Failed: $*"
		exit $status
	fi
}

cwd=`pwd`
export EXSOC_ROOT=`dirname $cwd`

#try verilator --trace -cc -F ../rtl/axi/axi.F --top-module axi_example_top \
#  --exe ../tb/axi_example_top.cpp 

make -j6


CPPFLAGS="${CPPFLAGS} -I${EXSOC_ROOT}/vip/axi"
CPPFLAGS="${CPPFLAGS} -I${EXSOC_ROOT}/svf"
#CPPFLAGS="${CPPFLAGS} -I${EXSOC}/obj_dir"
#CPPFLAGS="${CPPFLAGS} -I${VERILATOR_ROOT}/include"
#CPPFLAGS="${CPPFLAGS} -I${VERILATOR_ROOT}/include/vltstd"

FILES="$FILES vip/axi/axi_master_bfm.cpp"
FILES="$FILES tb/axi_example_top.cpp"
OBJS=""

#for file in $FILES; do
#	echo "g++ -c $CPPFLAGS -I${SYSTEMC}/include ${EXSOC_ROOT}/$file"
#	g++ -c $CPPFLAGS -I${SYSTEMC}/include ${EXSOC_ROOT}/$file
#	BASENAME=`basename $file`
#	OBJS="$OBJS `echo $BASENAME | sed -e 's/\.cpp/.o/g'`"
#done

try verilator -O3 --trace -sc -DDLLISPEC \
  -F ../rtl/axi/axi.F \
  -F ../vip/vip.F \
  -F ../tb/tb.F \
  --top-module axi_example_top \
  --exe ../tb/axi_example_top.cpp \
  -LDFLAGS "-L/c/tools/systemc/2.3.0/lib-mingw" \
  -CFLAGS "-I${EXSOC_ROOT}/vip/axi" \
  -CFLAGS "-I${EXSOC_ROOT}/svf" \
  -LDFLAGS ../libs.a


#-prefix axi_example_top

try make -j6 -C obj_dir -f Vaxi_example_top.mk VM_TRACE=1



