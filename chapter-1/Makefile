SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, build/%.o, $(SOURCES)) # Object files go into the build directory
EXECUTABLES = $(patsubst %.c, build/%, $(SOURCES)) # Executables go into the build directory
CFLAGS = 

all: $(EXECUTABLES)

build/%.o: %.c | build
    $(CC) $(CFLAGS) -c $< -o $@

build/%: build/%.o | build
    $(CC) $(CFLAGS) $< -o $@

build:
    mkdir -p build

clean:
    rm -rf build