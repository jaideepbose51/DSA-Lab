#include <stdio.h>

void createArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("Enter element at index %d: ", i);
    scanf("%d", &arr[i]);
  }
}

void insertElement(int *arr, int n, int element, int position) {
  if (position > n) {
    printf("Invalid position\n");
    return;
  }

  for (int i = n - 1; i >= position; i--) {
    arr[i + 1] = arr[i];
  }

  arr[position] = element;
}

void deleteElement(int *arr, int n, int position) {
  if (position > n) {
    printf("Invalid position\n");
    return;
  }

  for (int i = position; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
}

int linearSearch(int *arr, int n, int element) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == element) {
      return i;
    }
  }

  return -1;
}

void traverseArray(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n, element, position, option;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  createArray(arr, n);

  do {
    printf("\n***MENU***\n");
    printf("1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n5. Exit\n");
    printf("Select an operation: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        printf("Enter the position of the element: ");
        scanf("%d", &position);
        insertElement(arr, n, element, position);
        break;
      case 2:
        printf("Enter the position of the element to be deleted: ");
        scanf("%d", &position);
        deleteElement(arr, n, position);
        break;
      case 3:
        printf("Enter the element to be searched: ");
        scanf("%d", &element);
        position = linearSearch(arr, n, element);
        if (position == -1) {
          printf("Element not found\n");
        } else {
          printf("Element found at position %d\n", position);
        }
        break;
      case 4:
        traverseArray(arr, n);
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  } while (option != 5);

  return 0;
}
