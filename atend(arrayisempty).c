#include <stdio.h>

int add_at_end(int a[], int pos, int value) {
    a[pos] = value;
    pos++;  // Increment the position after adding the element
    return pos;  // Return the new position
}

int main() {
    int a[100];  // Assuming an array size of 100
    int i, n, free_pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);  // Correct format specifier for scanf

    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);  // Correct format specifier for scanf
    }

    free_pos = n;  // free_pos is set to the number of elements

    // Adding element 65 at the end
    free_pos = add_at_end(a, free_pos, 65);

    printf("Array after adding 65 at the end: ");
    for(i = 0; i < free_pos; i++) {
        printf("%d ", a[i]);  // Print the array elements
    }

    return 0;
}
