.PHONY: all

all: libbbenchmark.a benchmark.o

libbbenchmark.a: benchmark.o
	ar -r libbenchmark.a benchmark.o

benchmark.o: benchmark.c benchmark.h

clean:
	rm -f benchmark.o libbbenchmark.a benchmark