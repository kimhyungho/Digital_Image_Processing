#include <stdio.h>

int main(void) {

	int arr[12] = {3, 2, 4, 1, 1, 2, 5, 7, 2, 1, 10 ,20};
	int i, j, temp;
	
	int len = sizeof(arr)/sizeof(int);
	
	for(i=0; i<len; i++){
		for(j=0; j<len-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
