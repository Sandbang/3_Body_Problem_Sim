#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/body.h"


Vector2 vectorSubtract(Vector2 a, Vector2 b){
    Vector2 out;
    out.x = a.x - b.x;
    out.y = a.y - b.y;
    return out;
};
Vector2 vectorAdd(Vector2 a, Vector2 b){
    Vector2 out;
    out.x = a.x + b.x;
    out.y = a.y + b.y;
    return out;
};
Vector2 vectorNegate(Vector2 a){
    Vector2 out;
    out.x = -a.x;
    out.y = -a.y;
    return out;
}
Vector2 vectorMultDouble(Vector2 a, double b){
    Vector2 out;
    out.x = a.x * b;
    out.y = a.y * b;
    return out;
}
Vector2 vectorDivDouble(Vector2 a, double b){
    Vector2 out;
    out.x = a.x / b;
    out.y = a.y / b;
    return out;
}
Vector2 getForce(Vector2 AB, double mA, double mB){
    Vector2 F;
    F.x = G * mA * mB / (AB.x * AB.x);
    F.y = G * mA * mB / (AB.y * AB.y);
    return F;
};