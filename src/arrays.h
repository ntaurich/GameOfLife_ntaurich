/*
 * arrays.h
 *
 *  Created on: Jan 28, 2018
 *      Author: ntaurich
 */


/** creates an array and initializes all values as zero
 * @param r Number of rows in array
 * @param c Number of Columns in array
 * @return B The created array
 */
int** arrays(int x, int y);


/** reads the file with the pattern and puts the pattern into the given array
 * @param A The array
 * @param file The location of the file
 * @param row Number of rows given by the user
 * @return 1
 */
int read_file(int** A, char* file, int row);


/** prints out the given array
 * @param A The array
 * @param columns Size of columns given by the user
 * @param rows Size of rows given by the user
 * @return 0
 */
int print_array(int** A, int columns, int rows);


/** prints out the given array
 * @param A The first array
 * @param B The second array
 * @param columns Size of columns given by the user
 * @param rows Size of rows given by the user
 * @return same Returns 0 if they are different and 1 if they are the same
 */
int compare_array(int** A, int** B, int columns, int rows);


