/*
 * run.c
 *
 *  Created on: Jan 28, 2018
 *      Author: ntaurich
 */

#include "arrays.h"
#include "run.h"
#include <stdio.h>
#include <stdlib.h>

/** copies the pattern from the file into an array, prints each generation until
 *  a condition of termination is met
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @param gen Generations given by user
 * @param file Name of file with pattern
 * @param pr Value for printing generations
 * @param pa Value for pausing generations
 * @return 0
 */
int run_life(int ncolumns, int nrows, int gen, char* file, char pr, char pa){
	int** A = arrays(nrows,ncolumns); // old generation
	int** B = arrays(nrows,ncolumns); // current generation
	int** C = arrays(nrows,ncolumns); // new generation
	int** emptya= arrays(nrows,ncolumns); // empty array
	int curr_g=0; // the current generation being printed/found

	//reading the file
	read_file(B, file, ncolumns);
	read_file(A, file, ncolumns);


	for(curr_g=0; curr_g<gen;curr_g++){
		//B is the current generation, C is the new generation, A is the old
		// (the generation before B)

		// if user wants generations printed print generation
		if (pr == 'y'){
			printf("generation: %d\n", curr_g);
			print_array(B,nrows,ncolumns);
		}
		// find the new generation
		algorithm(B, ncolumns, nrows, C, pr);

		//if the new generation is empty break out of the loop
		if (compare_array(C,emptya, nrows, ncolumns)==1){
			printf("TERMINATED: because all organisms are dead\n");
			curr_g++;
			break;
		}

		//if the new generation is the same as the old generation
		// break out of the loop
		if (compare_array(A,C, nrows, ncolumns)==1){
			printf("TERMINATED: because pattern was repeated\n");
			curr_g++;
			break;
		}

		// if user wants to pause after each generation then wait for keystroke
		if (pa=='y'){
			getchar();
		}

		//shuffle arrays around once
		int** T= A;
		A=B; // old generation points to current generation
		B=C; // current generation points to new generation
		C=T; // new generation changes
	}

	// prints final array
	printf("final generation: %d\n", curr_g);
	print_array(C,nrows,ncolumns);

	// see if goes through all requested generations before finishing
	if (curr_g == gen){
		// if it does then tell user
		printf("FINISHED: because specified generations reached\n");
	}

	// print number of generations
	printf("number of generations: %d\n", curr_g);
	return 0;


}

/** calculates number of neighbors for given cell
 *  a condition of termination is met
 * @param a across placement of current cell's location
 * @param d down of current cell's location
 * @param A current array
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @return neighbors Number of neighbors for given cell
 */
int neighbors(int a, int d, int** A, int columns, int rows){
	int neighbors=0; // initializes neighbors
	int j=0; //initializes j
	int k=0; // initializes k
	int l, m; // initializes l and m
	for (j=0; j<3; j++){
		l= d -1 +j; // the row of a cell around current cell

		// the cell if off the grid then continue for loop
		if (l<0 || l>=columns){
			continue;
		}

		for(k=0; k<3; k++){
			m= a-1+ k; //the column of the cell around the center cell

			//if it is the center cell or off the grid then continue for loop
			if (m<0 || m>= rows || (l==d && m==a)){
				continue;
			}

			//if cell is occupied then add 1 to neighbors
			if (A[l][m]==1){
				neighbors++;
			}
		}
	}
		return neighbors; //returns the number of neighbors for the cell
	}

/** creates the new generation
 *  a condition of termination is met
 * @param A The current generation
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @param pr Value for printing generations
 * @return 0
 */
int algorithm (int** A,int rows, int columns, int** B, char pr){
	int i; // current down position
	int h=0; // current across position

	// calculates number of neighbors for each cell and if in survives,
	// dies, or is born
	for (i=0; i<columns; i++){
		for (h=0; h<rows; h++){
			int n= neighbors(h,i, A, columns, rows);

			// if cell is alive and has 2 or 3 neighbors then survives
			if (A[i][h]==1 && (n==2 || n==3)){ //survival
				B[i][h]=1;
				continue;
			}

			// if cell is empty and has 3 neighbors then is born
			if (A[i][h]==0 && n==3){//birth
				B[i][h]=1;
			}

			//otherwise cell is made empty
			else { //death
				B[i][h]=0;
			}
		}

	}
	return 0;
}



