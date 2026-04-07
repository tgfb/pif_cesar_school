#include <stdio.h>

struct S {
    int i;
    float f;
    double d;
};

union U {
    int i;
    float f;
    double d;
};

int main() {
    struct S s;
    union U u;

    printf("Struct: %lu bytes\n", sizeof(s));
    printf("Union: %lu bytes\n", sizeof(u));

    return 0;
}