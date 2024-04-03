# This MakeFile is designed to compile C++ programs only
# Specify the output file name
OUTPUT_FILE = output

# Specify the destination folder
DEST_FOLDER = /Users/vatsalsalla/Desktop/test/practice/expert-potato/build

# Compile rule
$(OUTPUT_FILE): main.cpp
	g++ -o $(OUTPUT_FILE) main.cpp
	./$(OUTPUT_FILE)
	mv $(OUTPUT_FILE) $(DEST_FOLDER)/

# Default rule
all: $(OUTPUT_FILE)