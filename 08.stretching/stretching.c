#include <stdio.h>

 

int main()

{
	
	int i, temp;

	int arr[6] = {1, 2, 3, 4, 5, 6};
	
	int *ptr1 = &arr[0];
	int *ptr2 = &arr[5];
	
	for(i=0; i<3; i++){
		temp = arr[5-i];
		arr[5-i] = arr[i];
		arr[i] = temp;
	}
	

	
	for(i=0; i<6; i++){
		printf("%d ", arr[i]);
	}

    return 0;

}
