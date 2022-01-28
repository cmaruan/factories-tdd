all: main

main: main.c
	@gcc -g main.c -o main -I./include

clean:
	@rm -rf main

test: main
	@./main; echo "Program returned: $$?"