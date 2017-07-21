RM := rm -f
ECHO := /bin/echo -e
MKDIR := mkdir -p

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

# prevent printing of recipes
.SILENT:

all: dirs $(EXECUTABLES)

build/%.o: source/%.cpp
	@$(ECHO) -n "\e[94mCompiling source\e[0m: $@ ... "
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<
	@$(ECHO) "\e[92mDone!\e[0m"

build/%.o: test/%.cpp
	@$(ECHO) -n "\e[94mCompiling test\e[0m: $@ ... "
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<
	@$(ECHO) "\e[92mDone!\e[0m"

bin/%: build/%.o
	@$(ECHO) -n "\e[96mCreating binary\e[0m: $@ ... "
	$(CXX) $(CXXFLAGS) -o $@ $<
	@$(ECHO) "\e[92mDone!\e[0m"

-include $(DEPENDENCIES)

clean:
	@$(ECHO) -n "\e[91mRemoving all binaries and build files\e[0m ... "
	@$(RM) $(EXECUTABLES) $(OBJECTS) $(DEPENDENCIES)
	@$(ECHO) "\e[92mDone!\e[0m"

dirs:
	@$(MKDIR) $(patsubst %, build/%, $(DIRS)) $(patsubst %, bin/%, $(DIRS))

.PHONY: show dirs

.SECONDARY: $(OBJECTS)
