/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i,temp,p=0,q=0;
	if (Arr==NULL || len<0)
	return NULL;
	if (Arr[0]>Arr[len-2] && Arr[len - 1] < Arr[1])
		{
			temp = Arr[0];
			Arr[0] = Arr[len - 1];
			Arr[len - 1] = temp;
		}
	else{
		for (i = 1; i < len-1; i++)
		{
			if (Arr[i]>Arr[i - 1] && Arr[i]>Arr[i + 1])
				p = i;
			if (Arr[i] < Arr[i - 1] && Arr[i] < Arr[i + 1])
				q = i;
		}
		temp = Arr[p]; Arr[p] = Arr[q]; Arr[q] = temp;
	}
	
	return Arr;
}