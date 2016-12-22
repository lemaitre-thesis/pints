test: main.cpp pints-cpp.h pints-cpp-funcs.h pints-cpp-sse.h pints-cpp-avx.h
	g++ -std=c++11 -march=native -fabi-version=6 -O3 main.cpp -o test

test-dbg: main.cpp pints-cpp.h pints-cpp-funcs.h pints-cpp-sse.h pints-cpp-avx.h
	g++ -std=c++11 -march=native -fabi-version=6 -O0 -g main.cpp -o test-dbg

asm: test
	objdump -dC test | vim -R -c 'set ft=asm' -

run: test
	./test

dbg: test-dbg
	gdb ./test-dbg

asm-dbg: test-dbg
	objdump -dSC test-dbg | vim -R -c 'set ft=asm' -
