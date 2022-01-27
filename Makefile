all: main

main: main.c
	@gcc main.c -o main

clean:
	@rm -rf main

test: main
	@./main; echo "Program returned: $$?"