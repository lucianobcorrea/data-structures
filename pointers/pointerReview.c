#include <stdlib.h>
#include <stdio.h>

int main(){

    float nota = 9.00;
    float *p;
    p = &nota;
    printf("%u\n", &nota);
    printf("%u\n", p);
    printf("%u\n", p+1);
    printf("%f\n", *p);
    printf("%f\n", *p+1);
    printf("%f\n", *p*nota);
    printf("%f\n", *p/(*p));
    return 0;
}