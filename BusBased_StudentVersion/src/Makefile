CC = g++
OPT = -O3
OPT = -g
WARN = -Wall
ERR = -Werror

CFLAGS = $(OPT) $(WARN) $(ERR) $(INC) $(LIB)

SIM_SRC = main.cc cache.cc io_function.cc msi.cc msiup.cc mesi.cc moesi.cc firefly.cc write_through.cc
SIM_OBJ = main.o cache.o io_function.o msi.o msiup.o mesi.o moesi.o firefly.o write_through.o

all: simulate_cache
	@echo "Compilation Done ---> nothing else to make :) "

simulate_cache: $(SIM_OBJ)
	$(CC) -o simulate_cache $(CFLAGS) $(SIM_OBJ) -lm
	@echo "---------------------------------------------------------------"
	@echo "-----------SP2015-506 BUS BASED CACHE SIMULATOR     -----------"
	@echo "---------------------------------------------------------------"
 
.cc.o:
	$(CC) $(CFLAGS)  -c $*.cc

clean:
	rm -f *.o simulate_cache
