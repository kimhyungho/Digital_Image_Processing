#include <stdio.h>
int main()
{
 int image[600][800];                //800x600 영상까지 처리가능
 int x, y;                             //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;                          //문자 변수 M과 N선언
 int XX, YY, MAX;                   //정수 변수 XX, YY, MAX 선언
 FILE *file1, *file2;                  //파일 변수 file1과 file2 선언
 file1 = fopen("five.pgm", "r");       //five.pgm을 읽기모드로 염
 fscanf(file1, "%c", &M);            //five.pgm에서 PGM 아스키코드 포맷의 P와
 fscanf(file1, "%c", &N);             //2를 읽어 들임
 fscanf(file1, "%d", &XX);            //입력영상의 가로크기를 읽어 들임
 fscanf(file1, "%d", &YY);            //입력영상의 세로크기를 읽어 들임
 fscanf(file1, "%d", &MAX);          //입력영상의 최대 명암도를 읽어 들임

 for(y = 0; y < YY; y++)           //반복문을 이용하여, 0과 255로 나타낸
  for(x = 0; x < XX; x++)          //학번의 끝자리 5를 읽어 들임
     fscanf(file1, "%d", &image[y][x]);

 //디지털 영상 처리 알고리즘
 file2 = fopen("out.pgm", "w");       //out.pgm을 쓰기 모드로 염
 fprintf(file2, "%c", M);              //읽어 들인 PGM 아스키코드 포맷의 ‘P'와
 fprintf(file2, "%c\n", N);           //‘2’를 out.pgm에 입력
 fprintf(file2, "%d %d\n", XX, YY);  //읽어 들인 가로축과 세로축 크기를 입력
 fprintf(file2, "%d\n", MAX);        //읽어 들인 최대 명암도를 입력

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){         //반복문을 이용하여 0과 255로 나타낸
   fprintf(file2,"%4d", image[y][x]);  //학번의 끝자리 5를 out.pgm에 입력
  }
  fprintf(file2, "\n");
 }

 return 0;
}

