# prevent printing of recipes
.SILENT:

# compile tests using CMake
.PHONY: default
default: dirs
	cd build && cmake .. && make

# run tests
.PHONY: test
test: dirs
	scripts/run_tests.sh

# create bin and build directories
.PHONY: dirs
dirs:
	mkdir -p bin build

# clean build files
.PHONY: clean
clean:
	cd build && make clean
