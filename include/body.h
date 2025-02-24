#include "raylib.h"

const double moonmass = 7.348e22;
const double rem = 384.4e6;
const double G = 6.57e-11;
const double mtp = 1e6;

//struct Vector2 {
 //   double x;
 //   double y;
//};
typedef struct Body {
    Vector2 pos;
    Vector2 p;
    double m;
    Texture2D color;
};
Vector2 vectorSubtract(Vector2 a, Vector2 b);
Vector2 vectorAdd(Vector2 a, Vector2 b);
Vector2 vectorNegate(Vector2 a);
Vector2 vectorMultDouble(Vector2 a, double b);
Vector2 vectorDivDouble(Vector2 a, double b);
Vector2 getForce(Vector2 AB, double mA, double mB);
