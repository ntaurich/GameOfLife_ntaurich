# Set CFLAGS to activate all warnings and enable debugger
CFLAGS = -Wall -g

# Default rule is to build the executable called life
all: life

# Rule for building the executable.
life: Life.o arrays.o run.o
	gcc $(CFLAGS) Life.o arrays.o run.o -o life

# Rules for building each object file.
life.o: Life.c arrays.h run.h
	gcc $(CFLAGS) -c Life.c

arrays.o: arrays.c arrays.h
	gcc $(CFLAGS) -c arrays.c

run.o: run.c arrays.h run.h
	gcc $(CFLAGS) -c run.c

# Give command "make clean" to remove object files,
#  executable, and documentation.
clean:
	rm -f *.o life
	rm -f -r html latex

# Give command "make docs" to create documentation.	
docs:
	doxygen
