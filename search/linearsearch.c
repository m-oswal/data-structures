#include <stdio.h>

int linear_search(int arr[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {5, 1, 3, 9, 0,7,2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 3;

  int index = linear_search(arr, n, target);

  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index: %d\n", index);
  }

  return 0;
}
