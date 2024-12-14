#include <stdio.h>

int sequential_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;  // Found at index
    }
    return -1;  // Not found
}

int main() {
    int books[] = {1, 2, 3, 4};
    int index = sequential_search(books, 4, 3);
    printf("Found at index: %d\n", index);
    return 0;
}
