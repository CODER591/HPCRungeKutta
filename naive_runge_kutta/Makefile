CC=g++
INCLUDE= -I ./
STANDARD= -std=c++14

FINAL_LINE= $(CC) $(STANDARD) $(INCLUDE)



all: mk_build_dir final_build

final_build: main
	$(FINAL_LINE) ./BUILD/*.o -o final.out
	mv *.out ./BUILD/

main: prepared_tests
	$(FINAL_LINE) main.cpp -c
	mv *.o ./BUILD/

prepared_tests: second_order forth_order
	$(FINAL_LINE) tests/tests.h tests/tests.cc -c
	mv *.o ./BUILD/

second_order:
	$(FINAL_LINE) second/runge_second_order.h second/runge_second_order.cc -c
	mv *.o ./BUILD/

forth_order:
	$(FINAL_LINE) forth/equation/runge_forth_order.h forth/equation/runge_forth_order.cc -c
	$(FINAL_LINE) forth/system/sys_runge_forth_order.h forth/system/sys_runge_forth_order.cc -c
	mv *.o ./BUILD/

# Service targets
mk_build_dir:
	mkdir -p BUILD

run: mk_build_dir final_build
	./BUILD/final.out

clean:
	rm -rf ./BUILD/
	rm -rf ./*/*.gch
	rm -rf ./*/*/*.gch