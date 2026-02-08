.PHONY: setup build run

# Configure the project with CMake
# -S specifies the source directory (where CMakeLists.txt is located)
# -B specifies the build directory where generated files will be placed
# -DCMAKE_BUILD_TYPE=Debug enables debug symbols for debugging
setup:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

# Build the project using the generated Makefiles in the build directory
build:
	cmake --build build

# Run the compiled executable from the build directory
run:
	./build/Raytracer
