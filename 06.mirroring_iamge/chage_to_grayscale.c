#include <stdio.h>
int main(int argc, char * argv[])   //argc는 외부에서 입력한 문자열 개수,
{                                  //argv[]는 외부에서 입력한 문자열들
 int image1[600][800*3];          //800x600 영상까지 처리가능 컬러영상
 int image2[600][800];            //800x600 영상까지 처리가능
 int x, y;                          //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;                       //문자 변수 M과 N 선언
 int XX, YY, MAX;                //정수 변수 XX, YY, MAX 선언
 FILE *file1, *file2;               //파일 변수 file1과 file2 선언
 file1 = fopen(argv[1], "r");      //외부에서 입력한 두 번째 문자열을 읽기모드로 염
 fscanf(file1, "%c", &M);          //헤더의 매직넘버를 읽어 들임 ‘P'
 fscanf(file1, "%c", &N);          //헤더의 매직넘버를 읽어 들임 ‘3’ 
 fscanf(file1, "%d", &XX);         //입력영상의 가로크기 읽어 들임
 fscanf(file1, "%d", &YY);         //입력영상의 세로크기 읽어 들임
 fscanf(file1, "%d", &MAX);       //입력영상의 최대 명암도 읽어 들임

 for(y = 0; y < YY; y++)        //반복문을 사용하여 입력영상의 픽셀 값 읽어 들임
  for(x = 0; x < XX*3; x++)    //컬러영상은 가로픽셀 당 값을 3개 가지므로 x3
     fscanf(file1, "%d", &image1[y][x]);


 for(y = 0; y < YY; y++)        //반복문을 이용하여
  for(x = 0; x < XX; x++)       //영상을 흑백화 시킴
   image2[y][x] = (image1[y][3*x]+image1[y][3*x+1]+image1[y][3*x+2])/3;
 //그레이 스케일 영상을 쓰자
 N='2'; // 컬러영상 N은 3, 그레이영상은 2 그레이영상 출력이므로 2
 file2 = fopen(argv[2], "w");   //외부에서 입력한 세 번째 문자열을 쓰기모드로 염
 fprintf(file2, "%c", M);        //읽어 들인 두 번째 문자열 파일의 헤더 매직넘버 ‘P'
 fprintf(file2, "%c\n", N);     //N에 2를 집어넣었기 때문에 2 입력
 fprintf(file2, "%d %d\n", XX, YY); //읽어 들인 가로축과 세로축 크기를 입력
 fprintf(file2, "%d\n", MAX);  //읽어 들인 최대 명암도를 입력

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){   //반복문을 이용하여 흑백화 시킨 픽셀 값을
   fprintf(file2,"%4d", image2[y][x]);   //세 번째 문자열 파일에 입력
  }
  fprintf(file2, "\n");           //줄 내림 입력
 }
 return 0;
}

