# This MakeFile is designed to compile C++ programs only
# Specify the output file name
OUTPUT_FILE = output

# Specify the source and destination folder
SRC_DIR = /Users/vatsalsalla/Desktop/test/practice/expert-potato/tests
DEST_DIR = /Users/vatsalsalla/Desktop/test/practice/expert-potato/build

# Compile rule
$(OUTPUT_FILE): /Users/vatsalsalla/Desktop/test/practice/expert-potato/tests/main.cpp
	g++ -o $(OUTPUT_FILE) /Users/vatsalsalla/Desktop/test/practice/expert-potato/tests/main.cpp
	./$(OUTPUT_FILE)
	mv $(OUTPUT_FILE) $(DEST_DIR)/

# Default rule
all: $(OUTPUT_FILE)