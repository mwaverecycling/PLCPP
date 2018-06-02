PACKAGE_NAME = plcpp

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
CXX = clang++ -std=c++11 -stdlib=libc++
endif

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
TESTS = $(patsubst $(TEST_OBJ)/%.o, $(TARGET_DIR)/test/%, $(TEST_OBJECTS))

INC_FLAGS = -I$(INC_DIR)
CXXFLAGS += -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
ifdef DEBUG
CXXFLAGS += -g
endif

$(TARGET_LIB): build
	@mkdir -p $(TARGET_DIR)
	$(AR) rcs $(TARGET_LIB) $(OBJECTS)
build: $(OBJECTS) $(HEADERS)

buildtests: $(TARGET_LIB) $(TESTS)
test: buildtests
	@echo "Running Test...\n"
	@$(TARGET_DIR)/test/test

	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo Making $<
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

$(TARGET_DIR)/test/%: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	@echo Making $<
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) $< $(TARGET_LIB) -o $@


info:
	@echo $(SOURCES)
	@echo $(OBJECTS)
	@echo $(HEADERS)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ)
	rm -rf $(TARGET_DIR)