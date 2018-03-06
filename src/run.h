/*
 * run.h
 *
 *  Created on: Jan 28, 2018
 *      Author: ntaurich
 */

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
int run_life(int rows, int columns, int gen, char* file, char pr, char pa);


/** copies the pattern from the file into an array, prints each generation until
 *  a condition of termination is met
 * @param r row of current cell's location
 * @param column of current cell's location
 * @param A current array
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @return neighbors Number of neighbors for given cell
 */
int neighbors(int r, int c, int** A, int columns, int rows);


/** creates the new generation
 *  a condition of termination is met
 * @param A The current generation
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @param pr Value for printing generations
 * @return 0
 */
int algorithm (int** A,int rows, int columns, int** B, char pr);

