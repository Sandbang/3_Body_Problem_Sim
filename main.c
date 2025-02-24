#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "body.c"
//#include "include/body.h"

#include "include/raylib.h"




int main() {
    InitWindow(1920, 1080, "Three Body Problem");
    struct Body red;
    struct Body blue;
    struct Body green;
    green.color = LoadTexture("assets/green.png");
    red.color = LoadTexture("assets/red.png");
    blue.color = LoadTexture("assets/blue.png");
    //Defining Mass:
    red.m = moonmass;
    blue.m = 1.5* moonmass;
    green.m = 2 * moonmass;
    //Defining Momentum:
    red.p.x = 0; red.p.y = 0;
    blue.p.x = 0; blue.p.y = 0;
    green.p.x = 0; green.p.y = 0;
    //initial t and dt:
    double dt = 3600;
    double t = 3600;
    //position
    red.pos.x = rem; red.pos.y = rem;
    blue.pos.x = 2*rem; blue.pos.y = 2*rem;
    green.pos.x = 4*rem; green.pos.y = 3*rem;
    Vector2 rRB;
    Vector2 rRG;
    Vector2 rBG;

    Vector2 FRB;
    Vector2 FRG;
    Vector2 FBG;

    while(!WindowShouldClose()){
        rRB = vectorSubtract(blue.pos, red.pos);
        rRG = vectorSubtract(green.pos, red.pos);
        rBG = vectorSubtract(green.pos, blue.pos);

        FRB = getForce(rRB, red.m, blue.m);
        FRG = getForce(rRG, red.m, green.m);
        FBG = getForce(rBG, blue.m, green.m);

        red.p = vectorAdd(red.p, vectorMultDouble(vectorSubtract(vectorNegate(FRB), FRG), dt));
        blue.p = vectorAdd(blue.p, vectorMultDouble(vectorSubtract(FRB, FBG), dt));
        green.p = vectorAdd(green.p, vectorMultDouble(vectorAdd(FBG, FRG), dt));
        
        red.pos = vectorAdd(red.pos, vectorMultDouble(red.p, dt/red.m));
        blue.pos = vectorAdd(blue.pos, vectorMultDouble(blue.p, dt/blue.m));
        green.pos = vectorAdd(green.pos, vectorMultDouble(green.p, dt/green.m));
        BeginDrawing();
            DrawTexture(red.color, red.pos.x/mtp, red.pos.y/mtp, WHITE);
            DrawTexture(green.color, green.pos.x/mtp, green.pos.y/mtp, WHITE);
            DrawTexture(blue.color, blue.pos.x/mtp, blue.pos.y/mtp, WHITE);
        EndDrawing();
        Sleep(10);
    }
    CloseWindow();
    return 0;
}