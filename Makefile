# Define build directory and executable name
BUILD_DIR = build
EXECUTABLE = libuniversesim
CMAKE_GENERATOR = Ninja
CMAKE_BUILD_TYPE = Debug

# Default target: Build the executable
.PHONY: all
all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G $(CMAKE_GENERATOR) -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) .. && cmake --build . --verbose

# Run target: Build and then run the executable
.PHONY: run
run: all
	./$(BUILD_DIR)/$(EXECUTABLE)

# Clean target: Remove the build directory
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Convenience target for building only
.PHONY: build
build: all

.PHONY: format
format:
	rg --files --glob '*.c' --glob '*.h' --glob '!src/3rdparty/**' | xargs clang-format -i

.PHONY: watch
watch:
	rg --files --glob "*.c" --glob "*.h"  | entr make build

.PHONY: debug
debug: all
	lldb ./$(BUILD_DIR)/$(EXECUTABLE)
