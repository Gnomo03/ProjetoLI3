CXX       := gcc
CXX_FLAGS := -ggdb
#-std=c++17

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := -lm
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)
	
$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	

clean:
	-rm $(BIN)/*
