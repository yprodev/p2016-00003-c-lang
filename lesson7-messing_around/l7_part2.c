// Lesson seven on the C Language

#include <stdion.h> 	// I/O library
#include <stdbool.h> 	// Boolean library
#include <string.h> 	// String library
#include <ctype.h> 		// Character library

void main(){

	char theChar;

	// Let's say that we want to get from user the whole bunch of characters.
	// One way to do that is to use get character.

	while((theChar = getChar()) != '~'){
		// Next we are going to put individually put each of the characters on
		// the screen using putchar().
		putchar(theChar);

		// You will not see just one character. After compiling and execution
		// you may input the whole word, and putchar() will return this word.
		// Basiclly it occurs because of the LINE BUFFERING.
		// It stores the line of characters until the new line is entered.
		// Some compiler don't work this way.
		// But when we use a buffer getchar() is waiting until ENTER key is pressed.
		// And then putchar() is going to push all these characters on the screen.
		// And with the buffer the data is going to be stored as it was entered.
		// In essence the buffer is temporary storage area in memory.
		// The size of the buffer is going to depend on your specific compiler, your
		// specific system.
		// In essence it is just a POINTER to a place inside of memory WITHOUT A SPECIFIED
		// SIZE.
	}

}
