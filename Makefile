all:
	mkdir -p build
	gcc -Wall -Wextra -static src/*.c -o build/ksh

clean:
	rm -fr build/
