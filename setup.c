#include "include/raylib.h"
#include "include/body.h"
void setup(struct Body *red, struct Body *green, struct Body *blue) {
    int shape = 0;
    Vector2 cursorPos;
    while (!WindowShouldClose() && shape < 3){
        BeginDrawing();

        printf("%i\n", shape);
        if (shape == 0) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(red->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                red->pos.x = (double)cursorPos.x; red->pos.y = (double)cursorPos.y; 
                shape += 1;
            }

            green->pos.x = (double)cursorPos.x; green->pos.y = (double)cursorPos.y;
        }
        else if (shape == 1) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(blue->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                blue->pos.x = (double)cursorPos.x; blue->pos.y = (double)cursorPos.y;
                shape += 1;
            }
            DrawTexture(red->color, red->pos.x/mtp, red->pos.y/mtp, WHITE);
        }
        else if (shape == 2) {
            cursorPos.x = GetMousePosition().x * mtp;
            cursorPos.y = GetMousePosition().y * mtp;
            DrawTexture(green->color, cursorPos.x/mtp, cursorPos.y/mtp, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                green->pos.x = (double)cursorPos.x; green->pos.y = (double)cursorPos.y;
                shape += 1;
            }
            DrawTexture(red->color, red->pos.x/mtp, red->pos.y/mtp, WHITE);
            DrawTexture(blue->color, blue->pos.x/mtp, blue->pos.y/mtp, WHITE);
        }
        ClearBackground(BLACK);
        EndDrawing();
    }
}