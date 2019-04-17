/* read a character
while (character is not end-of-file indicator)
	output the character just read
	read a character */

#include <stdio.h>

/* copy input to output; 1st version */
int main()
{
	int c;
  
	while((c = getchar()) != EOF) 
		putchar(c); 
	
}
