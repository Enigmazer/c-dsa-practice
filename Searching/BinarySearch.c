#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;  // Found at index
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Not found
}

int main() {
    int isbn_list[] = {1001, 1010, 1020, 1030, 1040};
    int index = binary_search(isbn_list, 5, 1030);
    printf("Found at index: %d\n", index);
    return 0;
}
