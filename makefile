CC = clang

HPP_FILES = $(wildcard ./src/*.hpp) $(wildcard ./src/*/*.cpp)
CPP_FILES = $(wildcard ./src/*.cpp) $(wildcard ./src/*/*.cpp)
OBJ_FILES = $(subst .cpp,.o,$(subst src,build,$(CPP_FILES)))

CPP_TESTS = $(wildcard ./tests/*.cpp)
OBJ_TESTS = $(subst .cpp,.o,$(subst tests,build,$(CPP_TESTS)))

DIRECTORIES = build $(subst src,build,$(wildcard ./src/*/)) 
$(shell mkdir -p $(DIRECTORIES))

# This forces some phonys to be recompiled
.FORCE:
.PHONY: lib clean tests

lib: $(OBJ_FILES)
	$(CC) -o build/libzoio.so $^ -shared -lstdc++ 

format:
	clang-format -i $(CPP_FILES) $(HPP_FILES)
	clang-format -i $(CPP_TESTS)

tests: lib $(OBJ_TESTS)

clean:
	@ rm -rf ./build/*

build/test_%.o: tests/test_%.cpp .FORCE
	@ echo
	@ echo $@
	@ $(CC) $< -o $@ -I src/ build/libzoio.so -lstdc++
	@ ./$@ --time

build/%.o: src/%.cpp
	$(CC) $< -o $@ -c -Wfatal-errors -fPIC
