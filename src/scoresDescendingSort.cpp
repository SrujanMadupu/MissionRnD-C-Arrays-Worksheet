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
void merge_sort(struct student A[], int p, int r);
void merge(struct student A[], int p, int q, int r);
#include <stdio.h>
#include <malloc.h>
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students != NULL&&len > 0){
		merge_sort(students, 0, len - 1);
		return students;
	}
	else{
		return NULL;
	}
}
void merge_sort(struct student A[], int p, int r){
	int q;
	if (p<r){  //Anchor condition
		q = ((p + r) / 2);  //finding midpoint
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void merge(struct student A[], int p, int q, int r){
	int le = q - p + 2;
	int ri = r - q + 1;
	struct student *left,*right;
	left = (struct student*)malloc(sizeof(struct student)*le);
	right = (struct student*)malloc(sizeof(struct student)*ri);
	for (int i = 0; i<le - 1; i++){
		left[i] = A[i + p];
	}
	
	left[le - 1].score = -9999;
	for (int i = 0; i<ri - 1; i++){
		right[i] = A[i + q + 1];
	}

	right[ri - 1].score = -9999;
	int i = 0, j = 0;
	for (int k = p; k <= r; k++){
		if (left[i].score >= right[j].score){
			A[k] = left[i];
			i++;
		}
		else{
			A[k] = right[j];
			j++;
		}
	}
}
