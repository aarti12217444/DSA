#include <stdio.h>

int add_at_end(int a[], int b[], int n, int free_pos, int data) {
    int i;
    for (i = 0; i < n; i++) {
        b[i] = a[i];  // Copy elements from array `a` to array `b`
    }
    b[free_pos] = data;  // Add the new element at the free position
    free_pos++;  // Increment free_pos after adding the element
    return free_pos;
}

int main() {
    int a[3];  // Initial array
    int i, n, free_pos;

    printf("Enter the number of elements (up to 3): ");
    scanf("%d", &n);  // Correct format specifier

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);  // Input elements into the array
    }

    int size = sizeof(a) / sizeof(a[0]);  // Calculate the size of array `a`
    free_pos = n;  // free_pos starts from the current number of elements

    if (n == size) {
        int b[size + 2];  // Create a new array `b` with extra space
        free_pos = add_at_end(a, b, size, free_pos, 65);  // Add element 65 at the end of the array

        printf("Array after adding 65 at the end: ");
        for (i = 0; i < free_pos; i++) {
            printf("%d ", b[i]);  // Print the elements of array `b`
        }
    }

    return 0;
}
