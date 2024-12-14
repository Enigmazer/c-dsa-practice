#include <stdio.h>

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_idx])  // Descending order
                max_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

int main() {
    int experimental_results[] = {42, 32, 60, 15, 89};
    int size = sizeof(experimental_results) / sizeof(experimental_results[0]);
    selection_sort(experimental_results, size);
    for (int i = 0; i < size; i++)
        printf("%d ", experimental_results[i]);
    return 0;
}
