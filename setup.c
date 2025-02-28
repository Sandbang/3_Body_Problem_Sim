#include "include/raylib.h"
#include "include/body.h"
void setup(struct Body *red, struct Body *green, struct Body *blue) {
    int shape = 0;
    Vector2 cursorPos;


    Rectangle textBox = { 0, 0, 225, 50 };    
    bool mouseOnText = false;
    char massRed[4] = "\0";
    int letterCount = 0;


    while (!WindowShouldClose() && shape < 3){
        /*
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;
        if (mouseOnText){
            int key = GetCharPressed();

            while (key > 0){
                if ((key > 0) && (key < 10) && (letterCount < 4))
                {
                    massRed[letterCount] = (char)key;
                    massRed[letterCount+1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }
                key = GetCharPressed(); 
            }
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                massRed[letterCount] = '\0';
            }

        }
        */
        BeginDrawing();
        //DrawRectangleRec(textBox, LIGHTGRAY);
        //DrawText(massRed, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);






        if (shape == 0) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            //DrawTexture(red->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            DrawCircle(cursorPos.x/mtp, cursorPos.y/mtp, 16, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                red->pos.x = (double)cursorPos.x; red->pos.y = (double)cursorPos.y; 
                shape += 1;
            }

            green->pos.x = (double)cursorPos.x; green->pos.y = (double)cursorPos.y;
        }
        else if (shape == 1) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            //DrawTexture(blue->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            DrawCircle(cursorPos.x/mtp, cursorPos.y/mtp, 16, BLUE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                blue->pos.x = (double)cursorPos.x; blue->pos.y = (double)cursorPos.y;
                shape += 1;
            }
            //DrawTexture(red->color, red->pos.x/mtp, red->pos.y/mtp, WHITE);
            DrawCircle(red->pos.x/mtp, red->pos.y/mtp, 16, RED);
        }
        else if (shape == 2) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            //DrawTexture(green->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            DrawCircle(cursorPos.x/mtp, cursorPos.y/mtp, 16, GREEN);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                green->pos.x = (double)cursorPos.x; green->pos.y = (double)cursorPos.y;
                shape += 1;
            }
            //DrawTexture(red->color, red->pos.x/mtp, red->pos.y/mtp, WHITE);
            DrawCircle(red->pos.x/mtp, red->pos.y/mtp, 16, RED);
            //DrawTexture(blue->color, blue->pos.x/mtp, blue->pos.y/mtp, WHITE);
            DrawCircle(blue->pos.x/mtp, blue->pos.y/mtp, 16, BLUE);
        }
        DrawText(TextFormat("BETA"), 480, 10, 30, RAYWHITE);
        DrawText(TextFormat("CLICK TO POSITION SOLAR BODY"), 0, 700, 30, RAYWHITE);
        ClearBackground(BLACK);
        
        EndDrawing();
    }
}

void textInput(double *m){

}