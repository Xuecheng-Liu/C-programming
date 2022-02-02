#include <stdio.h>

int Sum(int *arr, int size){
	int i,result;
	result = 0;
	for(i = 0; i < size; i++){
		result += *(arr +i);
		
	}
	return result;
}
