/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
void sort(struct student *, int);
struct student {
	char *name;
	int score;
};
struct student  **topKStudents(struct student *students, int len, int K) {
	int l;
	struct student **result = (struct student **)calloc(sizeof(struct student **),K);
	if (students == NULL || len < 0 || K <= 0) return NULL;
		sort(students, len);
		for (l = 0; l < K; l++)
		{
			result[l] = &students[l];
		}
	return result;
}
void swap(struct student *students, int k1,int k2)
{
	struct student temp;
	temp = students[k1];
	students[k1] = students[k2];
	students[k2] = temp;
}
void sort(struct student *students, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (students[j + 1].score > students[j].score)
				swap(students,j+1,j);
		}

	}
	
}