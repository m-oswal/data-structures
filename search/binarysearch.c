#include <stdio.h>

int bubble(int arr[], int n, int target) {
  if (n == 0) {
    return -1;
  }

  if (arr[n - 1] == target) {
    return n - 1;
  }


  if (target > arr[n - 1]) {
    return -1;
  }

  return bubble(arr, n - 1, target);
}


int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 1;

  int index = bubble(arr, n, target);

  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index: %d\n", index);
  }

  return 0;
}
