/* 
Explanation:
the game is played on a rectangular grid of cells, so that each cell has eight neighbors
(adjacent cells). Each cell is either occupied by an organism or not. A pattern of 
occupied and unoccupied cells in a grid is called a generation. The rules for deriving
a new generation from the previous generation are these:

1.Death. If an occupied cell has 0, 1, 4, 5, 6, 7, or 8 occupied neighbors, the organism dies
(0 or 1 of loneliness; 4 thru 8 of overcrowding).

2. survival. if an occupied cell has two or three neighbors, the organism survives to
the next generation

3. birth. if an unoccupied cell has precisely three occupied neighbors, it becomes occupied
by a new organism


/*

/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 */
The main function checks the arguments given by the user and assigns them to the correct variables. It then checks for improper input. It checks to see if it can open the given file and if values for number of rows, columns, and generations are positive. Then it calls run_life()


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
The function run_life() defines 4 arrays A, B, C, and an empty array. A is the old generation, B is the current generation, and C is the new generation. It reads the given file into array A and B so they both start as generation 0.

The for loop prints the current generation if requested then finds the new generation. It checks to see if any of the terminating conditions have been met. Then it changes round the pointers to the arrays. The current generation becomes the old generation and the new generation becomes the current generation. Loop contintues till either terminating condition is met or number of specified generations is reached. 

It prints te final generation and number of generations 


/** creates the new generation
 *  a condition of termination is met
 * @param A The current generation
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @param pr Value for printing generations
 * @return 0
 */
The function algorithm() goes through each cell in the grid and calls neighbors() for each cell to calculate the number of neighbors each has. Then it decides if each cell survives, dies or is born based on the number of neighbors and its occupancy. If the cell is alive and has 2 or 3 neighbors then survives, if cell is empty and has 3 neighbors then is born, otherwise is dead.


/** calculates number of neighbors for given cell
 *  a condition of termination is met
 * @param r row of current cell's location
 * @param column of current cell's location
 * @param A current array
 * @param rows Rows in the grid
 * @param columns Columns in the grid
 * @return neighbors Number of neighbors for given cell
 */
Function neighbors() checks cells surrounding given cell, if occupied adds one to the number of neighbors for that cell. Counts cells off of the grid as empty.


/** creates an array and initializes all values as zero
 * @param r Number of rows in array
 * @param c Number of Columns in array
 * @return B The created array
 */
Function arrays() creates an array of pointers to an array of integers. Uses given number of rows. Initializes all the values of the array as zero.


/** reads the file with the pattern and puts the pattern into the given array
 * @param A The array
 * @param file The location of the file
 * @param row Size of rows given by the user
 * @return 1
 */
Function read_file() opens the file and reads each line one by one. For each line it relpaces each cell of the array with the value in the file.


/** prints out the given array
 * @param A The array
 * @param nrows Number of rows given by the user
 * @param ncolumns Number of columns given by the user
 * @return 0
 */
Function print_array() prints out the array. If the value is 0, prints a space. Else prints a x.


/** prints out the given array
 * @param A The first array
 * @param B The second array
 * @param nrows Number of rows given by the user
 * @param ncolumns Number of columns given by the user
 * @return same Returns 0 if they are different and 1 if they are the same
 */
Function compare_array() compares to arrays by comparing each cell one at a time. If one pair of cells are different exits the loop and returns that they are different.

DOCUMENTATION
to see documentation use this link
https://htmlpreview.github.io/?https://raw.githubusercontent.com/ntaurich/GameOfLife_ntaurich/master/src/html/files.html


