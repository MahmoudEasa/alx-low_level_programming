# C - Static libraries

## Creating A Static "C" Library 

### Rnu `create_static_lib.sh`

	That will create a static library called liball.a
	from all the .c files that are in the current directory

	`gcc -c *.c` create object files `.o` from all the `.c` files

	`ar -rcs liball.a *.o` create a static library called liball.a from all the `.o` files and index it

	`ar -t liball.a` Display a table listing the contents of archive

	`nm liball.a` list symbols from object files

## Using A "C" Library In A Program

### Run `gcc main.c -L. -lall -o <program_name>`

	Use `./program_name` to run the program

