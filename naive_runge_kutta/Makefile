CC=g++
INCLUDE= -I ./
STANDARD= -std=c++14

FINAL_LINE= $(CC) $(STANDARD) $(INCLUDE)



all: final_build

final_build: main
	mkdir -p build
	$(FINAL_LINE) ./build/*.o -o final.out
	mv *.out ./build

main: examples
	$(FINAL_LINE) main.cpp -c
	mv *.o ./build

examples: second_order forth_order
	$(FINAL_LINE) examples/examples.h examples/examples.cc -c
	mv *.o ./build

second_order:
	$(FINAL_LINE) second/runge_second_order.h second/runge_second_order.cc -c
	mv *.o ./build

forth_order:
	$(FINAL_LINE) forth/equation/runge_forth_order.h forth/equation/runge_forth_order.cc -c
	mv *.o ./build

# Service targets

run: final_build
	./build/final.out

clean:
	rm -rf build