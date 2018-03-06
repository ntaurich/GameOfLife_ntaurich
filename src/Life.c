/*
 * Life.c
 *
 *  Created on: Jan 28, 2018
 *      Author: ntaurich
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "run.h"


/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 */
int main(int argc, char **argv){

	// See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}


	int nrows = atoi(argv[1]); //user input for number of rows in grid
	int ncolumns = atoi(argv[2]); // user input for number columns in grid
	int generations = atoi(argv[3]); // user input of generations
	char* inputFileName = argv[4]; // name of file with initial grid
	char print= 'n'; // initializing print value a no, y if user wants to print n if not
	char pause = 'n'; // initializing pause value as no, y if user wants to print n if not

	// if there are 6 arguments then check to see the value of the print argument
	if (argc==6){
		// if the argument is y then it will print all of the generations, if
		// n then it wont print
		print = (*argv[5]);
	}

	// see if there are 7 arguments/ if print an pause arguments were entered
	if (argc==7){
		// if there are then set both the print value and the pause value to the given input
		print = (*argv[5]);
		pause = (*argv[6]);// if pause is y then will wait for a keystroke to continue to the next generation
	}


	FILE *fp = fopen(inputFileName, "r"); //the file with the initial pattern
	char* file= inputFileName; // name of the file

	//sees if able to open the input file
	if (!fp) {
		// if not print faliure
		printf("Unable to open input file: %s\n", inputFileName);
		//printf("Unable to open input file:\n");
		return EXIT_FAILURE;
	}

	// sees if the given rows, columns, or generations are negative
	if (nrows<0 || ncolumns<0 || generations<0){
		// if they are negative then print error
		printf("Invalid input: negative values\n");
		return EXIT_FAILURE;
	}

	//calls run_life
	run_life(ncolumns, nrows, generations, file, print, pause);

	return 0;
}


