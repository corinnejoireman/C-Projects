/*
Author: Rinn Joireman
This program prints info related to a set of input integers.
*/
#include <stdio.h>
#include "numbers.h"

int sum(int nums[], int count){
  int total = 0;
  for (int i = 0; i < count -1; i++){
      total += nums[i];
  }
  return total;
}

float average(int nums[], int count){
  return (sum(nums, count)*1.0)/((count -1)*1.0);
}

int getNumbers(int nums[], int max){
  int i = 0;
  while(1){
    printf("Enter a number or 0 to stop: ");
    scanf("%d", &nums[i]);
    if (nums[i] == 0){
      break;
    }
    i ++;
    if (i == max){
      printf("You have entered the maximum number of values. ");
      break;
    }
  }
  return(i + 1);
}

void printNumbers(int nums[], int count){
  for (int i = 0; i < count - 1; i++){
    printf("%d\n", nums[i]);
  }

}
