/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <malloc.h>
int removeArrayDuplicates(int *Arr, int len)
	{
		int nums[20] = { 0 };
		int i, j = 0, newleng = 0;
		if (Arr == NULL || len < 1){
			return -1;
		}
		else{
			for (i = 0; i < len; i++){
				int x = Arr[i];
				if (nums[x] == 0){
					newleng++;
					Arr[j] = x;
					j++;
				}
				nums[x]++;
			}
			if (len == newleng){
				return len;
			}
		}
		return newleng;
	}
