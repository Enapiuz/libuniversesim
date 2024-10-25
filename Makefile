# Define build directory and executable name
BUILD_DIR = cmake-build-debug
EXECUTABLE = libuniversesim
CMAKE_GENERATOR = Ninja
CMAKE_BUILD_TYPE = Debug

# Default target: Build the executable
.PHONY: all
all: build-shared

# Run target: Build and then run the executable
.PHONY: run
run: all
	./$(BUILD_DIR)/$(EXECUTABLE)

# Clean target: Remove the build directory
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: build-shared
build-shared:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G $(CMAKE_GENERATOR) -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) .. && cmake --build . --verbose

.PHONY: build-static
build-static:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G $(CMAKE_GENERATOR) -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) .. && cmake --build . --verbose

.PHONY: format
format:
	rg --files --glob '*.c' --glob '*.h' --glob '!src/3rdparty/**' | xargs clang-format -i

.PHONY: watch
watch:
	rg --files --glob "*.c" --glob "*.h"  | entr make build-shared

.PHONY: debug
debug: all
	lldb ./$(BUILD_DIR)/$(EXECUTABLE)
