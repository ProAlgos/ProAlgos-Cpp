RM  := rm -f
MD  := mkdir -p

# C++ version
CXXFLAGS += -std=c++14

# warning flags
CXXFLAGS += -Wall -Wextra -pedantic-errors

# flags for dependencies
CXXFLAGS += -MMD -MP

# include directories
INCLUDES += -Iinclude -I.

DIRS := $(patsubst source/%, %, $(wildcard source/*))
DIRS += $(patsubst   test/%, %, $(wildcard   test/*))
PROG_SOURCES := $(wildcard source/*/*.cpp)
TEST_SOURCES := $(wildcard   test/*/*.cpp)
OBJECTS := $(patsubst source/%.cpp, build/%.o, $(PROG_SOURCES))
OBJECTS += $(patsubst   test/%.cpp, build/%.o, $(TEST_SOURCES))
EXECUTABLES := $(patsubst source/%.cpp, bin/%, $(PROG_SOURCES))
EXECUTABLES += $(patsubst   test/%.cpp, bin/%, $(TEST_SOURCES))
DEPENDENCIES := $(patsubst source/%.cpp, build/%.d, $(PROG_SOURCES))
DEPENDENCIES += $(patsubst   test/%.cpp, build/%.d, $(TEST_SOURCES))

all: dirs $(EXECUTABLES)

build/%.o: source/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

build/%.o: test/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

bin/%: build/%.o
	$(CXX) $(CXXFLAGS) -o $@ $<

-include $(DEPENDENCIES)

clean:
	@echo Removing binaries and build files
	@$(RM) $(EXECUTABLES) $(OBJECTS) $(DEPENDENCIES)

dirs:
	@$(MD) $(patsubst %, build/%, $(DIRS)) $(patsubst %, bin/%, $(DIRS))

.PHONY: show dirs

.SECONDARY: $(OBJECTS)
