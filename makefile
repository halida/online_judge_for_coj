
CFLAG=-std=c++0x
PROFILE= -pg -v 
## -ftime-report
# CFLAG+=$(PROFILE)

SRC=1132_other.cpp

run: bin
	./bin

bin: $(SRC)
	c++ $(CFLAG) $(SRC) -o bin
