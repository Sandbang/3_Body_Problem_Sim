#include "raylib.h"
/*
const double moonmass = 7.348e22;
const double dist = 384.4e7;
const double G = 6.67e-11;
const double mtp = 1e7;
*/
#define moonmass 7.348e22
#define dist 384.4e7
#define G 6.67e-11
#define mtp 1e7
struct MyVector2 {
   double x;
   double y;
};
typedef struct Body {
    struct MyVector2 pos;
    struct MyVector2 p;
    double m;
    Texture2D color;
};

struct MyVector2 vectorSubtract(struct MyVector2 a, struct MyVector2 b);
struct MyVector2 vectorAdd(struct MyVector2 a, struct MyVector2 b);
struct MyVector2 vectorNegate(struct MyVector2 a);
struct MyVector2 vectorMult(struct MyVector2 A, struct MyVector2 B);
struct MyVector2 vectorMultDouble(struct MyVector2 a, double b);
struct MyVector2 vectorDivDouble(struct MyVector2 a, double b);
struct MyVector2 getForce(struct MyVector2 AB, double mA, double mB);
double mag(struct MyVector2 A);