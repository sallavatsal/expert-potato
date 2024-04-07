# generate_makefile.py

DEST_DIR = "/Users/vatsalsalla/Desktop/projects/practice/expert-potato/c_src/build"
SRC_DIR = "/Users/vatsalsalla/Desktop/projects/practice/expert-potato/c_src"

def generate_makefile(makefile_location):
    makefile_content = f"""
# This MakeFile is designed to compile C programs only
# Specify the output file name
OUTPUT_FILE = output

# Specify the source and destination folder
SRC_DIR = {SRC_DIR}
DEST_DIR = {DEST_DIR}

# Compile rule
$(OUTPUT_FILE): {SRC_DIR}/main.c
	gcc -o $(OUTPUT_FILE) {SRC_DIR}/main.c
	./$(OUTPUT_FILE)
	mv $(OUTPUT_FILE) $(DEST_DIR)/

# Default rule
all: $(OUTPUT_FILE)
""".strip()                 # Used strip to remove space top and bottom lines inside the Makefile

    with open(makefile_location, "w") as makefile:
        makefile.write(makefile_content)

if __name__ == "__main__":
    makefile_location = "/Users/vatsalsalla/Desktop/projects/practice/expert-potato/c_src/Makefile"
    generate_makefile(makefile_location)
    print("Makefile generated successfully.")