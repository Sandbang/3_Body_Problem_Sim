ifeq ($(OS),Windows_NT)
	OPENGLFLAG = -lopengl32
	WINLIBS = -lgdi32 -lwinmm
	OUT = sim.exe
	LDFLAGS = -Llib/ -lraylib
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		OPENGLFLAG = -framework OpenGL
		WINLIBS = 
		LDFLAGS = -L/opt/homebrew/lib -lraylib
		OUT = sim
	endif
	
	ifeq ($(UNAME_S), Linux)
		OPENGLFLAG = -lGL
		WINLIBS = 
		LDFLAGS = -Llib/ -lraylib
		OUT = sim
	endif
endif

CC = gcc

all: sim

sim:
	$(CC) main.c body.c setup.c -o $(OUT) -O1 -Wall -std=c99 -Wno-missing-braces -Iinclude/ $(LDFLAGS) $(OPENGLFLAG) $(WINLIBS)

clean:
	rm -f $(OUT)
