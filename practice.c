#include <stdio.h>

int main(void){
	
	int data[10]={9,11,3,5,7,8,15,13,2,20};
	int i, j, key, temp;
	
	for(i=1; i<10; i++){
		temp = data[i];
		j = i - 1;
		while(j >= 0 && data[j] > temp) {
			data[j+1] = data[j];
			j = j - 1;
		}
		data[j+1] = temp;
	}
	
	printf("정렬 완료:");
	for(i=0; i<10; i++) printf(" %d", data[i]);
	
	return 0;
}
