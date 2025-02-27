#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/body.h"
//#include "body.c"
#include "include/raylib.h"
#include "include/setup.h"
//#include "include/setup.h"
//#include "setup.c"



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
    //position
    //red.pos.x = 4.2 * dist; red.pos.y = dist;
    //blue.pos.x = 3.1*dist; blue.pos.y = 2.2 * dist;
    //green.pos.x = 4.3 * dist; green.pos.y = 2.3 * dist;
    struct MyVector2 rRB;
    struct MyVector2 rRG;
    struct MyVector2 rBG;

    struct MyVector2 FRB;
    struct MyVector2 FRG;
    struct MyVector2 FBG;

    Vector2 cursorPos;


    SetTargetFPS(30);

    int shape = 0;
    setup(&red, &blue, &green);
    //red.pos.x = 2000 * dist; red.pos.y = 2000 * dist;
    //blue.pos.x = 2000*dist; blue.pos.y = 2000 * dist;
    //green.pos.x = 2000 * dist; green.pos.y = 2000 * dist;
    /*
    while (!WindowShouldClose() && shape < 3){
        BeginDrawing();

        printf("%i\n", shape);
        if (shape == 0) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(red.color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                red.pos.x = (double)cursorPos.x; red.pos.y = (double)cursorPos.y; 
                shape += 1;
            }

            green.pos.x = (double)cursorPos.x; green.pos.y = (double)cursorPos.y;
        }
        else if (shape == 1) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(blue.color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                blue.pos.x = (double)cursorPos.x; blue.pos.y = (double)cursorPos.y;
                shape += 1;
            }
            DrawTexture(red.color, red.pos.x/mtp, red.pos.y/mtp, WHITE);
        }
        else if (shape == 2) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(green.color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                green.pos.x = (double)cursorPos.x; green.pos.y = (double)cursorPos.y;
                shape += 1;
            }
            DrawTexture(red.color, red.pos.x/mtp, red.pos.y/mtp, WHITE);
            DrawTexture(blue.color, blue.pos.x/mtp, blue.pos.y/mtp, WHITE);
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
    */


    SetTargetFPS(20000);
    while(!WindowShouldClose()){

        //printf("The value of my_bool is: %d\n", pause);
 
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

                DrawText(TextFormat("Red Speed: %.2e m/s", mag(vectorMultDouble(red.p, dt/red.m))), 5, 250, 30, RED);
                struct MyVector2 redDir = vectorDivDouble(vectorMultDouble(blue.p, dt/blue.m), mag(vectorMultDouble(blue.p, dt/blue.m)));
                //printf("%.4e", acos(redDir.x));
                DrawText(TextFormat("Blue Speed: %.2e m/s", mag(vectorMultDouble(blue.p, dt/blue.m))), 5, 500, 30, BLUE);
                DrawText(TextFormat("Green Speed %.2e m/s", mag(vectorMultDouble(green.p, dt/green.m))), 5, 750, 30, GREEN);

                DrawText(TextFormat("Red Impulse: %.2e N*s", mag(red.p)), 5, 280, 30, RED);
                DrawText(TextFormat("Blue Impulse: %.2e N*s", mag(blue.p)), 5, 530, 30, BLUE);
                DrawText(TextFormat("Green Impulse %.2e N*s", mag(green.p)), 5, 780, 30, GREEN);

                DrawText(TextFormat("Red Direction: %.2e m/s", mag(vectorMultDouble(red.p, dt/red.m))), 5, 250, 30, RED);



                ClearBackground(BLACK);
            EndDrawing();
    }
    CloseWindow();
    return 0;
}