#include <stdio.h>
int main()
{
 char M, N;                          //문자 변수 M과 N 선언
 int XX, YY, MAX;                   //정수 변수 XX, YY, MAX 선언
 FILE *file1;                         //파일 변수 file1 선언
 file1 = fopen("five.pgm", "r");       //five.pgm을 읽기모드로 염
 fscanf(file1, "%c", &M);             //five.pgm에서 PGM 아스키코드 포맷의 P와
 fscanf(file1, "%c", &N);             //2를 읽어 들임
 fscanf(file1, "%d", &XX);            //입력영상의 가로크기를 읽어 들임
 fscanf(file1, "%d", &YY);            //입력영상의 세로크기를 읽어 들임
 fscanf(file1, "%d", &MAX);          //입력영상의 최대 명암도를 읽어 들임
                                     //제대로 읽었는지 화면에 출력
 printf("%c", M);                     //PGM 아스키코드포맷의 'P' 출력
 printf("%c\n", N);                  //PGM 아스키코드포맷의 '2' 출력
 printf("%d ", XX);                   //가로축의 크기 5 출력
 printf("%d\n", YY);                 //세로축의 크기 7 출력
 printf("%d\n", MAX);               //최대 명암도 255 출력
 return 0;
}

