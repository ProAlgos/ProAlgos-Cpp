# c++ version
CXXFLAGS += -std=c++14

# warning flags
CXXFLAGS += -Wall -Wextra -pedantic-errors

# flags for dependency generation
CXXFLAGS += -MMD -MP

# include directories
INCLUDES += -Iinclude -I.

PROG_DIRS := $(patsubst source/%, %, $(wildcard source/*))
TEST_DIRS := $(patsubst   test/%, %, $(wildcard   test/*))

PROG_SOURCES := $(wildcard source/*/*.cpp)
TEST_SOURCES := $(wildcard   test/*/*.cpp)
SOURCES := $(PROG_SOURCES)
SOURCES += $(TEST_SOURCES)

PROG_OBJECTS := $(patsubst source/%.cpp, build/%.o, $(PROG_SOURCES))
TEST_OBJECTS := $(patsubst   test/%.cpp, build/%.o, $(TEST_SOURCES))
OBJECTS := $(PROG_OBJECTS)
OBJECTS += $(TEST_OBJECTS)

PROG_EXECUTABLES := $(patsubst source/%.cpp, bin/%, $(PROG_SOURCES))
TEST_EXECUTABLES := $(patsubst   test/%.cpp, bin/%, $(TEST_SOURCES))
EXECUTABLES := $(PROG_EXECUTABLES)
EXECUTABLES += $(TEST_EXECUTABLES)

PROG_DEPENDENCIES := $(patsubst source/%.cpp, build/%.d, $(PROG_SOURCES))
TEST_DEPENDENCIES := $(patsubst   test/%.cpp, build/%.d, $(TEST_SOURCES))
DEPENDENCIES := $(PROG_DEPENDENCIES)
DEPENDENCIES += $(TEST_DEPENDENCIES)

# prevent printing of recipes
.SILENT:

# keep intermediate object files after compilation
.SECONDARY: $(OBJECTS)

# include generated dependencies
-include $(DEPENDENCIES)

.PHONY: all
all: dirs $(PROG_EXECUTABLES)

.PHONY: test
test: test-dirs $(TEST_EXECUTABLES)
	find * -name *.test -exec sh -c "echo {}:; ./{}" \;

build/%.o: source/%.cpp
	printf '\e[94m%s\e[0m%s' 'Compiling source' ': $@ ... '
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<
	printf '\e[92m%s\e[0m\n' 'Done!'

build/%.o: test/%.cpp
	printf '\e[94m%s\e[0m%s' 'Compiling test  ' ': $@ ... '
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<
	printf '\e[92m%s\e[0m\n' 'Done!'

bin/%: build/%.o
	printf '\e[96m%s\e[0m%s' 'Creating binary ' ': $@ ... '
	$(CXX) $(CXXFLAGS) -o $@ $<
	printf '\e[92m%s\e[0m\n' 'Done!'

.PHONY: dirs
dirs:
	mkdir -p $(patsubst %, build/%, $(PROG_DIRS)) $(patsubst %, bin/%, $(PROG_DIRS))

.PHONY: test-dirs
test-dirs:
	mkdir -p $(patsubst %, build/%, $(TEST_DIRS)) $(patsubst %, bin/%, $(TEST_DIRS))

.PHONY: clean
clean:
	printf "\e[91m%s\e[0m%s" 'Removing all binaries and build files' ' ... '
	rm -f $(EXECUTABLES) $(OBJECTS) $(DEPENDENCIES)
	printf '\e[92m%s\e[0m\n' 'Done!'
