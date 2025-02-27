
output:
	gcc main.c body.c setup.c -o sim.exe -O1 -Wall -std=c99 -Wno-missing-braces -Include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm