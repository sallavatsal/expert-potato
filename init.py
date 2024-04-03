# generate_makefile.py

DEST_FOLDER = "/Users/vatsalsalla/Desktop/test/practice/expert-potato/build"

def generate_makefile():
    makefile_content = f"""
# This MakeFile is designed to compile C++ programs only
# Specify the output file name
OUTPUT_FILE = output

# Specify the destination folder
DEST_FOLDER = {DEST_FOLDER}

# Compile rule
$(OUTPUT_FILE): main.cpp
g++ -o $(OUTPUT_FILE) source.cpp
mv $(OUTPUT_FILE) $(DEST_FOLDER)/

# Default rule
all: $(OUTPUT_FILE)
""".strip()                 # Used strip to remove space top and bottom lines inside the Makefile

    with open("Makefile", "w") as makefile:
        makefile.write(makefile_content)

if __name__ == "__main__":
    generate_makefile()
    print("Makefile generated successfully.")