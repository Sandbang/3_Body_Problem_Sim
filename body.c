#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/body.h"
#include <math.h>


struct MyVector2 vectorSubtract(struct MyVector2 a, struct MyVector2 b){
    struct MyVector2 out;
    out.x = a.x - b.x;
    out.y = a.y - b.y;
    return out;
};
struct MyVector2 vectorAdd(struct MyVector2 a, struct MyVector2 b){
    struct MyVector2 out;
    out.x = a.x + b.x;
    out.y = a.y + b.y;
    return out;
};
struct MyVector2 vectorNegate(struct MyVector2 a){
    struct MyVector2 out;
    out.x = -a.x;
    out.y = -a.y;
    return out;
}
struct MyVector2 vectorMult(struct MyVector2 A, struct MyVector2 B){
    struct MyVector2 out;
    out.x = A.x * B.x;
    out.y = A.y * B.y;
    return out;
}
struct MyVector2 vectorMultDouble(struct MyVector2 a, double b){
    struct MyVector2 out;
    out.x = a.x * b;
    out.y = a.y * b;
    return out;
}
struct MyVector2 vectorDivDouble(struct MyVector2 a, double b){
    struct MyVector2 out;
    out.x = a.x / b;
    out.y = a.y / b;
    return out;
}
double mag(struct MyVector2 A){
    return sqrt((A.x* A.x) + (A.y * A.y));
}
struct MyVector2 getForce(struct MyVector2 AB, double mA, double mB){
    struct MyVector2 F;
    double magF = G * mA * mB / (mag(AB) * mag(AB));
    struct MyVector2 dirAB = vectorDivDouble(AB, mag(AB));
    F = vectorMultDouble(dirAB, magF);
    return F;
};