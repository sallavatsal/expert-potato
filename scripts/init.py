# generate_makefile.py

DEST_DIR = "/Users/vatsalsalla/Desktop/projects/practice/expert-potato/build"
SRC_DIR = "/Users/vatsalsalla/Desktop/projects/practice/expert-potato/src"

def generate_makefile():
    makefile_content = f"""
# This MakeFile is designed to compile C++ programs only
# Specify the output file name
OUTPUT_FILE = output

# Specify the source and destination folder
SRC_DIR = {SRC_DIR}
DEST_DIR = {DEST_DIR}

# Compile rule
$(OUTPUT_FILE): {SRC_DIR}/main.cpp
	g++ -o $(OUTPUT_FILE) {SRC_DIR}/main.cpp
	./$(OUTPUT_FILE)
	mv $(OUTPUT_FILE) $(DEST_DIR)/

# Default rule
all: $(OUTPUT_FILE)
""".strip()                 # Used strip to remove space top and bottom lines inside the Makefile

    with open("Makefile", "w") as makefile:
        makefile.write(makefile_content)

if __name__ == "__main__":
    generate_makefile()
    print("Makefile generated successfully.")