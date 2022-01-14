main: main.c
	gcc ./main.c -o ./build/main

run: ./build/main
	./build/main

trace: ./build/main
	strace -o strace.txt ./build/main