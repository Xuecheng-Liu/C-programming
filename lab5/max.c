#include <stdio.h>

int Max(int *arr, int size){
	int i,result;
	result = *(arr + 0);
	for(i = 1; i < size; i++){
		if(*(arr + i) > result){
			result = *(arr +i);
		}
	}
	return result;
}
