# prevent printing of recipes
.SILENT:

# compile tests using CMake
.PHONY: test
test: dirs
	cd build && cmake .. && make

# create bin and build directories
.PHONY: dirs
dirs:
	mkdir -p bin build

# clean build files
.PHONY: clean
clean:
	cd build && make clean
