
CFLAG=-std=c++0x

SRC=1132.cpp

run: bin
	./bin
bin: $(SRC)
	c++ $(CFLAG) $(SRC) -o bin
