CXX := g++
CXX_FLAGS := -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lenet -lprotobuf -std=c++17

BIN := bin
SRC := src
INCLUDE := include/enet-plus/include -I./src
LIB := lib

LIBRARIES := 
EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)


run: clean all
	clear
	@echo "СТАРТУЕМ!!"
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	@echo "Молись что бы скомпилилось."
	$(CXX) -I$(INCLUDE)  -L$(LIB) $^ -o $@ $(LIBRARIES) $(CXX_FLAGS)

clean:
	@echo "Идет чиска твоего гов.. мусора."
	-rm $(BIN)/*
