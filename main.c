#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "include/body.h"
#include "body.c"


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
    green.m = moonmass;
    //Defining Momentum:
    red.p.x = 0; red.p.y = 0;
    blue.p.x = 0; blue.p.y = 0;
    green.p.x = 0; green.p.y = 0;
    //initial t and dt:
    double dt = 3600;
    double t = 3600;
    //position
    red.pos.x = 4 * rem; red.pos.y = rem;
    blue.pos.x = 3.1*rem; blue.pos.y = 2 * rem;
    green.pos.x = 4 * rem; green.pos.y = 2 * rem;
    struct MyVector2 rRB;
    struct MyVector2 rRG;
    struct MyVector2 rBG;

    struct MyVector2 FRB;
    struct MyVector2 FRG;
    struct MyVector2 FBG;

    while(!WindowShouldClose()){
        rRB = vectorSubtract(blue.pos, red.pos);
        //printf("Here is rRB.x: %f\n", rRB.x/mtp); printf("Here is rRB.y: %f\n", rRB.y/mtp);
        rRG = vectorSubtract(green.pos, red.pos);
        //printf("Here is rRG.x: %f\n", rRG.x/mtp); printf("Here is rRG.y: %f\n", rRG.y/mtp);
        rBG = vectorSubtract(green.pos, blue.pos);
        //printf("Here is rBG.x: %f\n", rBG.x/mtp); printf("Here is rBG.y: %f\n", rBG.y/mtp);

        FRB = getForce(rRB, red.m, blue.m);
        //printf("Here is FRB.x: %f\n", FRB.x); printf("Here is FRB.y: %f\n", FRB.y);
        FRG = getForce(rRG, red.m, green.m);
        //printf("Here is FRG.x: %f\n", FRG.x); printf("Here is FRG.y: %f\n", FRG.y);
        FBG = getForce(rBG, blue.m, green.m);
        //printf("Here is FBG.x: %f\n", FBG.x); printf("Here is FBG.y: %f\n", FBG.y);




        red.p = vectorAdd(red.p, vectorMultDouble(vectorSubtract(vectorNegate(FRB), FRG), dt));
        blue.p = vectorAdd(blue.p, vectorMultDouble(vectorSubtract(FRB, FBG), dt));
        green.p = vectorAdd(green.p, vectorMultDouble(vectorAdd(FBG, FRG), dt));



        
        red.pos = vectorSubtract(red.pos, vectorMultDouble(red.p, dt/red.m));
        //printf("Here is red.pos.x: %f\n", red.pos.x/mtp); printf("Here is red.pos.y: %f\n", red.pos.y/mtp);
        blue.pos = vectorSubtract(blue.pos, vectorMultDouble(blue.p, dt/blue.m));
        //printf("Here is blue.pos.x: %f\n", blue.pos.x/mtp); printf("Here is blue.pos.y: %f\n", blue.pos.y/mtp);
        green.pos = vectorSubtract(green.pos, vectorMultDouble(green.p, dt/green.m));
        //printf("Here is green.pos.x: %f\n", green.pos.x/mtp); printf("Here is green.pos.y: %f\n", green.pos.y/mtp);






        BeginDrawing();
            DrawTexture(red.color, red.pos.x/mtp, red.pos.y/mtp, WHITE);
            DrawTexture(green.color, green.pos.x/mtp, green.pos.y/mtp, WHITE);
            DrawTexture(blue.color, blue.pos.x/mtp, blue.pos.y/mtp, WHITE);
        EndDrawing();
        Sleep(1);
    }
    CloseWindow();
    return 0;
}