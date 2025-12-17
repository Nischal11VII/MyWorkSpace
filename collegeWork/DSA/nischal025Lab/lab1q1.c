

// Q1. WAP to calculate the sum of n numbers entered by user using diff methods
// of dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main() {
  // using malloc;
  int n;
  int sum = 0;
  printf("From Malloc\n");
  printf("Enter the number of elements to add : ");
  scanf("%d", &n);

  int *ptr = malloc(n * sizeof(int));

  printf("Enter the numbers : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", (ptr + i));
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", *(ptr + i));
  }
//  printf("\n");

  for (int i = 0; i < n; i++) {
    sum += *(ptr + i);
  }

  printf("Sum = %d\n", sum);

  free(ptr);

  printf("\nFrom calloc");

  // from calloc
    
    sum = 0;
  ptr = calloc(n, sizeof(int));

  printf("\nEnter the numbers : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", (ptr + i));
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", *(ptr + i));
  }
//  printf("\n");

  for (int i = 0; i < n; i++) {
    sum += *(ptr + i);
  }

  printf("Sum = %d\n\n", sum);

  //free(ptr);

  printf("From realloc \n");
  // from realloc
  int resize;
sum = 0;
  printf("Total number of element : ");
  scanf("%d", &resize);

 int* temp = realloc(ptr, resize * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr);  // Free the original memory
        return 1;   // Exit after realloc failure
    }
    ptr = temp;  // Update the original pointer only if realloc succeeds


 // ptr = realloc(ptr, resize * sizeof(int));

 // ptr = temp;
  printf("Enter the Additional numbers : ");
  for (int i = n; i < resize; i++) {
    scanf("%d", (ptr + i));
  }

  for (int i = 0; i < resize; i++) {
    printf("%d\n", *(ptr + i));
  }

  for (int i = 0; i < resize; i++) {
    sum += *(ptr + i);
  }
    printf("Sum = %d\n",sum);

  free(ptr);

  return 0;
}
