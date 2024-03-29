#include <stdio.h>
#include <stdlib.h>

/* This program was written by Michael Schlosbon 2/23/2024 */

int search(int numbers[], int low, int high, int value) 
{
   if (low > high) {
          return -1; // This is our base case, which just means our value isn't sorted
      }

  int mid = low + (high - low) / 2; // Formula for midpoint

  if (numbers[mid] == value) {
          return mid; // Base case: value found at mid index
      } else if (numbers[mid] < value) { //If our number is less than the value we want, we need to go to the right of the array
          // Search the right half of the array
          return search(numbers, mid + 1, high, value); // Recursive function using the right half of the array
      } else if (numbers[mid] > value){ //If our number is greater than the value we want, we need to go to the left of the array
          // Search the left half of the array
          return search(numbers, low, mid - 1, value); // Recursive function using the left half of the array
      }
        else{ 
          return mid; // Targets our low == high case
      }
      
  }


void printArray(int numbers[], int sz)
{
  int i;
  printf("Number array : ");
  for (i = 0;i<sz;++i)
  {
    printf("%d ",numbers[i]);
  }
  printf("\n");
}

int main(void)
{
  int i, numInputs;
  char* str;
  float average;
  int value;
  int index;
  int* numArray = NULL;
  int countOfNums;
  FILE* inFile = fopen("input.txt","r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &countOfNums);
    numArray = (int *) malloc(countOfNums * sizeof(int));
    average = 0;
    for (i = 0; i < countOfNums; i++)
    {
      fscanf(inFile," %d", &value);
      numArray[i] = value;
      average += numArray[i];
    }

    printArray(numArray, countOfNums);
    value = average / countOfNums;
    index = search(numArray, 0, countOfNums - 1, value);
    if (index >= 0)
    {
      printf("Item %d exists in the number array at index %d!\n",value, index);
    }
    else
    {
      printf("Item %d does not exist in the number array!\n", value);
    }

    free(numArray);
  }

  fclose(inFile);
}