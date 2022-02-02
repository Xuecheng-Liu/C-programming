/*BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT,
**I CERTIFY THAT
** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED
**BY ME WITH NO
** ASSISTANCE FROM ANY PERSON OTHER THAN THE
**INSTRUCTOR OF THIS COURSE
**OR ONE OF OUR UNDERGRADUATE GRADERS.
*/
/* This program takes the user input character by character and computes
 * the result of a floating point from it under the assumption that the 
 * user will enter the input in the correct format.
 * 
 * Author:Xuecheng Liu
 */

#include <stdio.h>

double combine (int left, int right);
double oneLine ();
int main ()
{ 
  /*declare the variables*/    
  int line;
  double result;
  /*prompt user for input*/
  printf("Enter the amount of lines: ");
  scanf("%d",&line);
  getchar();
  result = 0.0;
  /*process the user input*/
  while(line > 0)
    {
      printf("Enter two numbers separated with tab: ");
      result += oneLine ();
      line--;
    }
  printf ("Total:\t%7.3f\n", result);
}

double oneLine ()
{
  /*declare the variables*/
  int left;
  int right;
  double difference;
  double current;
  char ch;
  /*initialize the variables*/
  left = 0;
  right = 0;
  difference = 0.0;
  current = 0.0;
  ch = getchar ();
  /* keep processing the input until encounting \n*/
  while (ch != '\n')
    {
      while (ch != '.' && ch != '\t' && ch != '\n')
	{ /*process the integer part of each number*/
	  left *= 10;
	  left += ch - '0';
	  ch = getchar ();
	}
      if (ch == '.')
	{ /* go to the next character if encounting the decimal point */
	  ch = getchar ();
	}


      while (ch != '\t' && ch != '\n')
	{ /* process the fraction part of each number*/
	  right *= 10;
	  right += ch - '0';
	  ch = getchar (); /*update the value of ch*/
	}
      if (ch == '\t')
	{ /*go to the next character if encounting the tab character*/
	  ch = getchar ();
	}

      current = combine (left, right); /* combine to get the result*/
      printf ("%7.3f   ", current); /*print one float following by <tab>*/
      difference = current - difference; /*update the difference*/
      /* reset values of left and right */
      left = 0;
      right = 0;
    }
  printf ("%7.3f\n", difference); /*	print the difference in the end*/
  /* return statement */
  return difference;
}

/*
 * Combine the results from two sides of the decimal point into one float.
 */
double combine (int left, int right)
{
  double result; /* declare the result*/
  result = 0.0;  /* initialize the result*/
  if (right < 10)
    { /*divide the right side by 10 if it is less than 10*/
      result = left + (double) right / 10;
    }
  else if (right >= 10 && right < 100)
    { /*divide the right side by 100 if it is less than 100*/
      result = left + (double) right / 100;
    }
  else if (right >= 100 && right < 1000)
    { /*divide the right side by 1000 if it is less than 1000*/
      result = left + (double) right / 1000;
    }
    /*return statement*/
  return result;
}
