#include <stdio.h>
void somaprod(int a, int b, int *ponteiro1, int *ponteiro2)
{
    *ponteiro1 = a + b;
    *ponteiro2 = a * b;
}
int main(void)
{
    int s, p;
    somaprod(3, 5, &s, &p);
    printf("Soma = %d Produto = %d\n", s, p);
    return 0;
}