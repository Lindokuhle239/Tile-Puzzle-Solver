#Compiler
CXX = g++
CXXFLAGS = -Wall -g

#Folders
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test_files

#Source files
SRCS = $(SRC_DIR)/PGMimage.cpp $(SRC_DIR)/Tile.cpp $(SRC_DIR)/TileManager.cpp
OBJS = $(SRC:.cpp=.o)

#Executables
TARGET = $(BIN_DIR)/program

#Build Executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

#Compiler source files into obj file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(SRC_DIR)/*.o

run: $(TARGET)
	$(TARGET)