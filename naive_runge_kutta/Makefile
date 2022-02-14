CC=g++
INCLUDE= -I ./
STANDARD= -std=c++14

FINAL_LINE= $(CC) $(STANDARD) $(INCLUDE)



all: build second_order main
	$(FINAL_LINE) ./build/*.o -o final.out
	mv *.out ./build

main:
	$(FINAL_LINE) main.cpp -c
	mv *.o ./build

second_order:
	$(FINAL_LINE) second/runge_second_order.h second/runge_second_order.cc -c
	mv *.o ./build


# Service targets

build:
	mkdir build

clean:
	rm -rf build