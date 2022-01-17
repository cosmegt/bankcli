main: main.c
	gcc ./main.c -o ./build/main

run: ./build/main
	./build/main

trace: ./build/main
	strace -o strace.txt ./build/main

debug: ./build/main
	gcc -g ./main.c -o ./build/maind; gdb -s ./build/maind
