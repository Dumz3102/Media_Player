# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -Iheader -Iview -Icontroller -Imodule

# Directories
SRC_DIR_VIEW = view
SRC_DIR_CONTROLLER = controller
SRC_DIR_MODULE = module
BUILD_DIR = build

# Source files
VIEW_SRC = $(wildcard $(SRC_DIR_VIEW)/*.cpp)
CONTROLLER_SRC = $(wildcard $(SRC_DIR_CONTROLLER)/*.cpp)
MODULE_SRC = $(wildcard $(SRC_DIR_MODULE)/*.cpp)

# Header files
HEADER_FILES = $(wildcard header/*.hpp) \
               $(wildcard $(SRC_DIR_VIEW)/*.hpp) \
               $(wildcard $(SRC_DIR_CONTROLLER)/*.hpp) \
               $(wildcard $(SRC_DIR_MODULE)/*.hpp)

# Object files
OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(VIEW_SRC))) \
      $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(CONTROLLER_SRC))) \
      $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(MODULE_SRC)))

# Target executable
TARGET = program

# Libraries
LIBS = -ltag -lncurses -lSDL2 -lSDL2_mixer -lpthread

# Build target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR_VIEW)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR_CONTROLLER)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR_MODULE)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

# Clean up
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
