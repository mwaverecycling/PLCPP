PACKAGE_NAME = i2cdevices

SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj
TARGET_DIR = ./bin

LIB_NAME = lib$(PACKAGE_NAME).a
TARGET_LIB = $(TARGET_DIR)/$(LIB_NAME)


SOURCES = $(shell find $(SRC_DIR) -type f -name *.cpp)
HEADERS = $(shell find $(INC_DIR) -type f -name *.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

TEST_DIR = ./test
TEST_OBJ = ./test/obj
TEST_SOURCES = $(shell find $(TEST_DIR) -type f -name *.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(TEST_OBJ)/%.o, $(TEST_SOURCES))

INC_FLAGS = -I$(INC_DIR)
CXXFLAGS += -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

$(TARGET_LIB): build
	$(AR) rcs $(TARGET_LIB) $(OBJECTS)
build: $(OBJECTS) $(HEADERS)

buildtest: $(TEST_OBJECTS) $(TARGET_LIB)
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $(TARGET_DIR)/test $(TEST_OBJECTS) $(TARGET_LIB)
test: buildtest
	@echo "Running Test...\n"
	@$(TARGET_DIR)/test

	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo Making $<
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

$(TEST_OBJ)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo Making $<
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) $(TARGET_LIB) -c $< -o $@



info:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(HEADERS)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET_LIB)