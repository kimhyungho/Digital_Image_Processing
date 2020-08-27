#include <stdio.h>
int main()
{
 int image[600][800];                //800x600 영상까지 처리가능
 int x, y;                             //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;                          //문자 변수 M과 N선언
 int XX, YY, MAX;                   //정수 변수 XX, YY, MAX 선언
 FILE *file1;                         //파일 변수 file1 선언
 file1 = fopen("five.pgm", "r");       //five.pgm을 읽기모드로 염
 fscanf(file1, "%c", &M);             //five.pgm에서 PGM 아스키코드 포맷의 P와
 fscanf(file1, "%c", &N);             //2를 읽어 들임
 fscanf(file1, "%d", &XX);            //입력영상의 가로크기를 읽어 들임
 fscanf(file1, "%d", &YY);            //입력영상의 세로크기를 읽어 들임
 fscanf(file1, "%d", &MAX);          //입력영상의 최대 명암도를 읽어 들임

 for(y = 0; y < YY; y++)           //반복문을 이용하여, 0과 255로 나타낸
  for(x = 0; x < XX; x++)          //나타낸 학번의 끝자리 5를 읽어 들임
     fscanf(file1, "%d", &image[y][x]);
                                   //읽은 영상의 데이터를 ‘@’와 ‘ ’을 통해서 출력함
 for(y=0;y<YY;y++) {              
  for(x=0;x<XX;x++) {             
   if(image[y][x]==255)            //255(흰색)으로 나타낸 학번의 끝자리를 부분을  
    printf("@");                     //특수문자 ‘@’를 통해서 출력           
   else                             //0(검은색)으로 나타낸 배경부분을
    printf(" ");                      //공백으로 출력
  }
  printf("\n");
 }

 return 0;
}

