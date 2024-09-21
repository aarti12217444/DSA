#include <stdio.h>

struct code {
    int i;
    char c;
    struct code *ptr;
};

int main() {
    struct code var1;
    struct code var2;

    var1.i = 65;      // Assigning values to var1
    var1.c = 'A';
    var1.ptr = NULL;

    var2.i = 166;     // Correct assignment for var2
    var2.c = 'B';
    var2.ptr = NULL;

    var1.ptr = &var2; // Point var1's ptr to var2

    printf("%d %c", var1.ptr->i, var1.ptr->c);  // Correct syntax for printf

    return 0;
}
