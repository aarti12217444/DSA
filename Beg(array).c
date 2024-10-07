#include <stdio.h>

// Function to insert a new element at the beginning of the array
int add_beg(int arr[], int n, int data) {
    int i;
    // Shift all elements to the right by 1 position to make space for the new element
    for (i = n - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    // Insert the new element at the beginning (index 0)
    arr[0] = data;
    // Return the new size of the array
    return n + 1;
}

int main() {
    int arr[10], i, n, data = 10;

    // Input the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insert the new data at the beginning
    n = add_beg(arr, n, data);

    // Print the updated array
    printf("Array after insertion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
