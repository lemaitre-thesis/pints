test: main.cpp pints-cpp.h pints-cpp-sse.h pints-cpp-avx.h
	g++ -std=c++11 -mfma -fabi-version=6 -O3 main.cpp -o test

asm: test
	objdump -dC test | vim -R -c 'set ft=asm' -
