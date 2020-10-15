#include <stdio.h>


int main(void) {
	
	int i, j;
	int arr[5][5];
	int sum1 = 0, sum2 = 0;
	
	
	for(i=0; i<4; i++){
		printf("%d번 학생의 국어 영어 수학 국사 : ", i+1);
		for(j=0; j<4; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(i=0; i<4; i++){
		
		sum1 = sum2 = 0;
		
		for(j=0; j<4; j++){
			
			sum1 += arr[i][j];
			sum2 += arr[j][i];
		}

		arr[i][4] = sum1;
		arr[4][i] = sum2;
	}
	
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
