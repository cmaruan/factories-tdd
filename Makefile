INCDIR=./include
CFLAGS= -g

all: main

main.o: main.c
	gcc $(CFLAGS) -I$(INCDIR) -c main.c -o main.o

product.o: models/product.c
	gcc $(CFLAGS) -I$(INCDIR) -c models/product.c -o product.o

factories.o: factories/factories.c
	gcc $(CFLAGS) -I$(INCDIR) -c factories/factories.c -o factories.o

product_factory.o: factories/product_factory.c
	gcc $(CFLAGS) -I$(INCDIR) -c factories/product_factory.c -o product_factory.o

main: main.o product_factory.o factories.o product.o
	gcc $(CFLAGS) -I$(INCDIR) main.o product_factory.o factories.o product.o -o main 

clean:
	rm -rf main **/*.o *.o

test: main
	@./main; echo "Program returned: $$?"