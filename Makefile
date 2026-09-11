all:
	mkdir -p build
	gcc -Wall -Wextra -static src/*.c -o build/ksh
