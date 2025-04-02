#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 10

bool isPerfectSquare(int n) {
    if (n < 0) return false;
    int root = (int)sqrt(n);
    return (root * root == n);
}

void rearrangePerfectSquares(int arr[], int n) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (isPerfectSquare(arr[i])) {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index++;
        }
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE] = {16, 3, 7, 9, 20, 25, 8, 4, 18, 5};
    
    printf("Original array:\n");
    displayArray(arr, SIZE);
    
    rearrangePerfectSquares(arr, SIZE);
    
    printf("Array after rearranging (perfect squares first):\n");
    displayArray(arr, SIZE);
    
    // Complexity:
    // isPerfectSquare: O(1) (assuming sqrt() is constant time)
    // rearrangePerfectSquares: O(n)
    
        return 0;
    }
