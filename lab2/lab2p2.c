/*BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT,
**I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED
**BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE
**INSTRUCTOR OF THIS COURSE
**OR ONE OF OUR UNDERGRADUATE GRADERS.
*/
/*
 * A program takes the user input character by character and convert upper case
 * letters to lower case letters, lower case letters to upper case letters, and
 * let other characters remain unchanged. The program is supposed to run forever
 * if the user do not use indrections to run the program.
 * Author:Xuecheng Liu
 */
#include <stdio.h>

int main()
{
    int ch; /* declare the ch*/
    printf("Enter the input line by line and press enter to complete a line\n");
    while((ch = getchar())!=EOF)
    {	/* keep getchar() until encountering EOF */
        if(ch >= 65 && ch <= 90)
	{ /*convert upper case to lower case*/
            ch = ch + 32;
        }else if( ch >=97 && ch <= 122)
	{ /*convert lower case to upper case*/
            ch = ch - 32;
        }
        /* print out the character */
        putchar(ch);
    }

    return 0;
}

