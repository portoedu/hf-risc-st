APPNAME = sort

#do not change below
APPDIR = ../../
IAPI = -I$(APPDIR)/include
SIMDIR = ../../../tools/sim/hf_riscv_sim/
SIMANEM = a.out

include $(APPDIR)/makefile

sort_test:
	$(GCC_$(ARCH)) -o sort_test.o sort_test.c $(IAPI) #constroi testador
	cp sort_test.o $(APPDIR)                          #coloca o testador na mesma pasta da applicacao
	make -C $(APPDIR) $(APPNAME) IFTEST="-DTEST" -i   #constroi applicacao que vai ser testada
	gcc -o a.out $(SIMDIR)/*.c                        #compila simulador
	./a.out $(APPDIR)/code.bin
