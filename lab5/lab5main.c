#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

int i,j, sum,current;
int *dynamic_array;
int min, max;

if (argc <= 2){		/* must have at least one number	*/
	printf("Usage: %s <num1>....<numX>\n", argv[0]);
	return;
}


if((dynamic_array=malloc((argc-1)*sizeof(int))) == NULL){
	printf("Could not allocate dynamic memory\n");
	return;
}

for (i =1; i<argc; i++){
	current = atoi(argv[i]);
	*(dynamic_array + (i-1)) = current;	
}

min = Min(dynamic_array,argc-1);
printf("The minimum value is %d\n",min);
max = Max(dynamic_array, argc-1);
printf("The maximum value is %d\n",max);
sum = Sum(dynamic_array, argc-1);
printf("The sum  is %d\n",sum);
Sort(dynamic_array, argc-1);

printf("The input received has a span of %d units.\n", max-min);

printf("The average value is %f\n", (sum *1.0)/(argc-1));

printf("The values in ascending order are:\n");

for(i=0; i<argc-1; i++){
	printf("%d\n",*(dynamic_array+i));
}

free(dynamic_array);
return;
}

