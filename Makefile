CXX = g++
CPPFLAGS = -std=c++17
RM = rm -f
EXECUTABLE_FILENAME = main
REMOVE_FILE = main.exe
ALL_SRCS := $(wildcard src/class/*/*.cpp)

# Compile all cpp files
compile:
	$(CXX) $(CPPFLAGS) -o $(EXECUTABLE_FILENAME) src/core/main.cpp ${ALL_SRCS}

# run the program
run:
	./$(EXECUTABLE_FILENAME)

clean:
	$(RM) ./$(REMOVE_FILE)

# abilityDriver
ability:
	$(CXX) $(CPPFLAGS) -o ability $(wildcard src/class/ability/*.cpp)
