#include <stdio.h>

int Sort(int *arr, int size){
	int i,j,temp;
	
	for(i = 0; i<size-1; i++){
		temp = *(arr+i);
		for(j = i+1; j<size;j++){
		if(*(arr+j)<temp){
			*(arr + i) = *(arr + j);
			*(arr + j) = temp;
			temp = *(arr+i);
		}
		
		}
	}
}
