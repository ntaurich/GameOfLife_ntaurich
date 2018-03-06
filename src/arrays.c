/*
 * arrays.c
 *
 *  Created on: Jan 28, 2018
 *      Author: ntaurich
 */

#include <stdio.h>
#include <stdlib.h>

/** creates an array and initializes all values as zero
 * @param r Number of rows in array
 * @param c Number of Columns in array
 * @return B The created array
 */
int** arrays(int r, int c){
		int **B; // pointer to an array of pointers to arrays of integers
		unsigned int i, j, k;

	    //creating array with r number of elements
		B = malloc(r * sizeof(int *));
		if (B) {
			for (i =0; i<r; i++){
				//i is current row
				B[i] = malloc(c*sizeof (int));
				if (!B[i]) exit(-1);
			}
		}
		else exit(-1);

		//initializing array
		for (j=0; j<r; j++){
			//j is current row, k is current column being initialized
			for (k=0; k<c; k++){
				B[j][k]= 0;
			}
		}

		return B;
}

/** reads the file with the pattern and puts the pattern into the given array
 * @param A The array
 * @param file The location of the file
 * @param row Size of rows given by the user
 * @return 1
 */
int read_file(int** A, char* file, int row){
	int j=0; //initializing j
	int k=0; //initializing k
	char line[row]; // string the length of the rows
	FILE *fp = fopen( file, "r"); //the file with the pattern

	//
	while (fscanf(fp, "%s",line) ==1){
		// while the value of the character does not = NULL
		while(line[j]!= '\000'){
			//j is current character, k is the current row
			//checks if the current character is an x meaning occupied cell
			if (line[j]=='X'|| line[j]=='x'){
				//if occupied sets cell equal to one
				A[k][j]=1;
			}
			j++; //goes to next character
		}
		k++; //reads next line
		j=0; //sets character of line back to zero
	}

	return 1;
}


/** prints out the given array
 * @param A The array
 * @param nrows Number of rows given by the user
 * @param ncolumns Number of columns given by the user
 * @return 0
 */
int print_array(int** A, int nrows, int ncolumns){
	for (int i=0; i<nrows; i++){
		//i is the current down position
		for (int j=0; j<ncolumns; j++){
			//j is the current across position
			//if cell is empty print a space
			if (A[i][j]==0){
				printf(" ");
			}
			//if cell is not empty print an x
			else printf("x");
		}
		printf("\n"); // when beginning a new row start a new line
	}
	return 0;
}


/** prints out the given array
 * @param A The first array
 * @param B The second array
 * @param nrows Number of rows given by the user
 * @param ncolumns Number of columns given by the user
 * @return same Returns 0 if they are different and 1 if they are the same
 */
int compare_array(int** A, int** B, int nrows, int ncolumns){
	int same =1;
	for (int i=0; i<nrows; i++){
		// i is the current down position
		for (int j=0; j<ncolumns; j++){
			//j is the current across position
			//if the cells are not equal change same to 0 and end loop
			if (A[i][j]!=B[i][j]){
				same =0;
				break;
			}
		}
		//check if same equals zero
		if (same == 0){
			//if it does break out of the for loop
			break;
		}
	}
	return same; //return if arrays are the same or not
}




