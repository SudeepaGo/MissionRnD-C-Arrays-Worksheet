/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
void sort_student_scores(struct student *, int);
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 0) return NULL;
	sort_student_scores(students, len);
}
void swap_student_scores(struct student *students, int k1, int k2)
{
	struct student temp;
	temp = students[k1];
	students[k1] = students[k2];
	students[k2] = temp;
}
void sort_student_scores(struct student *students, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (students[j + 1].score > students[j].score)
				swap_student_scores(students, j + 1, j);
		}

	}

}