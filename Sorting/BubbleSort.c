#include <stdio.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int roll_numbers[] = {5, 3, 8, 1, 2};
    int size = sizeof(roll_numbers) / sizeof(roll_numbers[0]);
    bubble_sort(roll_numbers, size);
    for (int i = 0; i < size; i++)
        printf("%d ", roll_numbers[i]);
    return 0;
}
