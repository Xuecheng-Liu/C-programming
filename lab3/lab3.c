
/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT,I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATEDBY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THEINSTRUCTOR OF THIS COURSE
** OR ONE OF OUR UNDERGRADUATE GRADERS.
* 
*  A program that takes user input into a word bank and do the corresponding operations to each set of word.
** Author: Xuecheng Liu
*/

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"
#include <string.h>

int getLine(void);
void generateLine(int line, wordLine *sets);
void option1(char startLetter, wordLine*singleSet,int size);
void option2(char startLetter, wordLine *singleSet,int size);

int main(void){
    /**
    * declrare and initialize the variables
    */
	int line;
	int option;
	char startLetter;
	wordLine *sets;

	line = getLine();
	sets = (wordLine*) malloc(line*sizeof(wordLine));
	
	getchar();
	generateLine(line, sets);
	
	/**
	 * prompt the user for input
	 */
	do
	{
	  printf("Enter the starting letter of the word set on which you wish to do work: \n");
	  scanf("%c",&startLetter);
	  printf("1)Print out the words starting with a particular letter in the order entered.\n");
	  printf("2)Print out the words starting with a particular letter in reverse alphabetical order.\n");
	  printf("3)Exit the program.\n");
	  scanf("%i",&option);
		if(option==1){
			option1(startLetter,sets,line);
		}else{
			option2(startLetter,sets,line);
		}
		getchar();
	}while(option != 3);
	
	/**
	 * free the memory 
	 */
	free(sets -> ptr -> word);
	free(sets -> ptr);
	free(sets);
}

/**
 * get the total number of sets from the user
 */
int getLine(void){
	int line;
	printf("Please Enter the total number of word sets(greater than zero): \n");
	scanf("%i",&line);
	return line;
}
/**
 * construct each wordLine from the user input
 */
void generateLine(int line, wordLine *sets){
     /**
      * declrare and initialize the variables
      */
	int setIndex;
	int count;
	int position;
	int strlen;
	char current;
	oneWord *words;

	setIndex = 0;
	count = 0;	
	strlen = 0;
	position = 0;

	while(line>0)
	{		
		printf("Enter your set: \n");		
		while((current=getchar())!=' ')
		{ 
		  /**
		   * update the count member
		   */
			count*=10;
			count+=(current - '0');
		}		
		(*(sets+setIndex)).count = count;
		
		/**
		 * update the startLetter member
		 */
		current = getchar();		
		(*(sets+setIndex)).startLetter = current;	
		
		/**
		 * allocate the memory from the heap to the structures
		 */
		words = (oneWord*)malloc(count*sizeof(oneWord));	
		(words+position) -> word = (char*)malloc(21*sizeof(char));
		
		while(current!='\n')
		{ 
			if(current!=' ' && current!='\n')
			{
			  /**
			   * update the word in the same position through pointer arithmetic
			   */
				*(((words+position)->word)+strlen) = current;
				strlen++;
				current = getchar();
			}else
			{
			  /**
			   * move to the next position in the structure array
			   */
				position++;
				strlen = 0;
				(words+position) -> word = (char*)malloc(21*sizeof(char));
				current = getchar();
			}
		}

		(sets+setIndex) -> ptr = words;
		count = 0;
		position = 0;
		strlen = 0;		
		setIndex++;
		line--;
	}
}

/**
 * output for option1
 */
void option1(char startLetter, wordLine *sets, int size){
    /**
     * declrare and initialize the variables
     */
	int index;
	int count;

	index = 0;
	count = 0;
	/**
	 * print out each word through pointer arithmetic
	 */
	while(index < size)
	{
		if((*(sets+index)).startLetter == startLetter)
		{
				printf("Vocabulary words that start with '%c' are: ",toupper(startLetter));
				while(count < (*(sets+index)).count)
				{
				  /**
				   * print the word in the next potision
				   */
					printf("%s ", (((sets+index)-> ptr)+ count) -> word);
					count++;
				}
				printf(" \n");
			
		}	
		index++;
	}
}

/**
 * output for option2
 */
void option2(char startLetter, wordLine *sets, int size){
    /**
     * declrare and initialize the variables
     */
	int index;
	int len;
	char *temp;
	int i;

	index = 0;
	len = 0;
	i = 0;
	
	while(index < size)
	{
		if((*(sets+index)).startLetter == startLetter)
		{
				printf("Vocabulary words that start with '%c' in alphabetical reverse order are: ",toupper(startLetter));
				while(i < (*(sets+index)).count)
				{
					temp = (((sets+index)-> ptr)+i) -> word;
					len = i+1;
					while(len < (*(sets+index)).count)
					{
					  /**
					   * compare two strings 
					   */
						if(strcasecmp((((sets+index)-> ptr)+len) -> word,temp) > 0)
						{
							temp = (((sets+index)-> ptr)+len) -> word;
							/**
							 * exchange the value of two words
							 */
							(((sets+index)-> ptr) + len) -> word = (((sets+index)-> ptr)+i) -> word;
							(((sets+index)-> ptr) + i) -> word = temp;
						}
						len++;
					}
					printf("%s ",temp);
				i++;
				}
				printf(" \n");
			
		}	
		index++;
	}
}
