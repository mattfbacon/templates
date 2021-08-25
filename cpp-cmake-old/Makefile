.PHONY: cmake debug release clean distclean install

BUILD_DIR := build

CMAKE := cmake

CMAKE_FLAGS := \
	-DCMAKE_C_COMPILER=$(shell which clang) \
	-DCMAKE_CXX_COMPILER=$(shell which clang++) \
	-DCMAKE_LINKER=$(shell which lld) \
	--no-warn-unused-cli

$(BUILD_DIR): CMakeLists.txt
	$(CMAKE) $(CMAKE_FLAGS) -S. -H. -B$(BUILD_DIR)
cmake: $(BUILD_DIR)

debug release: %: $(BUILD_DIR)
# hacky support for multiconfig generators
	$(CMAKE) --build $(BUILD_DIR) --target $@ \
		|| $(CMAKE) --build $(BUILD_DIR) --config $(shell echo $@ | python -c "print(input().capitalize())")
clean distclean install: %: $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) --target $@

.DEFAULT_GOAL = release
