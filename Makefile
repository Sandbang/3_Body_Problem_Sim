ifeq ($(OS),Windows_NT)
	LDFLAGS = -Llib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	OUT = sim.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL
	endif
	
	ifeq ($(UNAME_S), Linux)
		LDFLAGS = -Llib/ -lraylib -lGL
	endif
	OUT = sim
endif

CC = gcc
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces
BUILD = main.c body.c setup.c

all: sim

sim:
	$(CC) $(BUILD) -o $(OUT) $(CFlAGS) -Iinclude/ $(LDFLAGS)

clean:
	rm -f $(OUT)
