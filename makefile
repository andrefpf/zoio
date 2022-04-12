CPP_FILES = $(wildcard ./src/*.cpp)
OBJ_FILES = $(subst .cpp,.o,$(subst src,build,$(CPP_FILES)))

CPP_TESTS = $(wildcard ./tests/*.cpp)
OBJ_TESTS = $(subst .cpp,.o,$(subst tests,build,$(CPP_TESTS)))

DIRS=build
$(shell mkdir -p $(DIRS))

# This forces some phonys to be recompiled
.FORCE:

tests: lib $(OBJ_TESTS)

lib: $(OBJ_FILES)
	g++ -o build/libzoio.so $^ -shared

build/test_%.o: tests/test_%.cpp .FORCE
	@echo
	@g++ $< -o $@ -I include/ build/libzoio.so
	@./$@ --time

build/%.o: src/%.cpp
	g++ $< -o $@ -I include/ -c -Wfatal-errors

clean:
	@rm -rf ./build/*
