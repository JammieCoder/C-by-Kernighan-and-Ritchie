SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, build/%.o, $(SOURCES)) # Object files go into the build directory
EXECUTABLES = $(patsubst $(SRCDIR)/%.c, build/%, $(SOURCES)) # Executables go into the build directory
CFLAGS = -lm

all: $(EXECUTABLES)

build/%.o: $(SRCDIR)/%.c
	$(shell mkdir -p build)
	clang $(CFLAGS) -c $< -o $@ 

build/%: build/%.o
	$(shell mkdir -p build)
	clang $(CFLAGS) $< -o $@ 

clean:
	rm -rf build
