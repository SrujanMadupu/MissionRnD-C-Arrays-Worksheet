/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr != NULL&&len >= 0){
		int newlen = len + 1;
		int i;
		Arr = (int*)realloc(Arr, sizeof(int)*newlen);
		for (i = newlen-2; i >=-1; i--){
			if (i == -1){
				Arr[i + 1] = num;
			}
			else if (num < Arr[i]){
				Arr[i + 1] = Arr[i];
			}
			else{
				Arr[i + 1] = num;
			}
		}
		return Arr;
	}
	else{
		return NULL;
	}
}