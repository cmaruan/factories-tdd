INCDIR=./include
CFLAGS= -g

all: main

type.o: type.c $(INCDIR)/type.h
	gcc $(CFLAGS) -I$(INCDIR) -c type.c -o type.o

main.o: main.c
	gcc $(CFLAGS) -I$(INCDIR) -c main.c -o main.o

product.o: models/product.c $(INCDIR)/models/product.h
	gcc $(CFLAGS) -I$(INCDIR) -c models/product.c -o product.o

factories.o: factories/factories.c $(INCDIR)/factories/factories.h
	gcc $(CFLAGS) -I$(INCDIR) -c factories/factories.c -o factories.o

product_factory.o: factories/product_factory.c $(INCDIR)/factories/product_factory.h
	gcc $(CFLAGS) -I$(INCDIR) -c factories/product_factory.c -o product_factory.o

main: main.o product_factory.o factories.o product.o type.o
	gcc $(CFLAGS) -I$(INCDIR) main.o product_factory.o factories.o product.o type.o -o main 

clean:
	rm -rf main **/*.o *.o

test: main
	@echo "---------------------------------"
	@echo "Running tests ..."
	@./main; echo "Tests that failed: $$?"
	@echo "---------------------------------"