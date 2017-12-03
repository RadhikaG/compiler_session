name=woo

LLVM_BIN = #

all: $(name)

# According to output file

$(name).ll: $(name).c
	$(LLVM_BIN)/clang -S -c -emit-llvm -o $(name).ll $(name).c
	cat $(name).ll

$(name).o: $(name).c
	$(LLVM_BIN)/clang -c -o $(name).o $(name).c

$(name): $(name).c
	$(LLVM_BIN)/clang -o $(name) $(name).c
	# uncomment to see linker invocation and all the commands the $(LLVM_BIN)/clang frontend
	# internally calls
	#$(LLVM_BIN)/clang -v -o $(name) $(name).c

assemble_c: $(name).c
	$(LLVM_BIN)/clang -S -o $(name).s $(name).c
	cat $(name).s

assemble_ir: $(name).ll
	$(LLVM_BIN)/llc -o $(name).s $(name).ll
	cat $(name).s

# Frontend

preproc: $(name).c
	$(LLVM_BIN)/clang -E $(name).c

dump-ast: $(name).c
	$(LLVM_BIN)/clang -Xclang -ast-dump $(name).c

view_ast: $(name).c
	$(LLVM_BIN)/clang -Xclang -ast-view $(name).c

# Middle-end

ir: $(name).ll

cfg: $(name).ll
	$(LLVM_BIN)/opt -dot-cfg $(name).ll
	#Do `dot -Tpng file.dot -o file.png` to get the .png of the cfg

# Backend

machineinstr: $(name).ll
	$(LLVM_BIN)/llc -print-machineinstrs $(name).ll

mcinst: $(name).ll
	$(LLVM_BIN)/llc -asm-show-inst $(name).ll
	cat $(name).s

# Testing compiler pass

run_dumbo: $(name).ll
	$(LLVM_BIN)/opt -load ../DumboPass/_build/MyCFGPass/libMyCFGPass.so -mycfgpass $(name).ll -S

clean:
	-rm -rf $(name).o $(name) $(name).h.gch $(name).s $(name).ll *.png *.dot
