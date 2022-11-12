CXX       := gcc
CXX_FLAGS := -ggdb
#-std=c++17

BIN     := bin
SRC     := src
INCLUDE := include
RESULTS := Resultados

LIBRARIES   := -lm
EXECUTABLE  := programa-principal
TESTPROGRAM := programa-testes

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $(BIN)/$(TESTPROGRAM) $(LIBRARIES) -DTEST

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)	

clean: 
	-rm $(BIN)/*
	-rm $(RESULTS)/*

test:
	$(BIN)/$(TESTPROGRAM) inputs inputs/input.txt
