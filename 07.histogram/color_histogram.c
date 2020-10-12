#include <stdio.h>
#include <stdlib.h>         //입력받은 4번째 문자열을 정수화 시키기 위해
int main(int argc, char * argv[])    //argc는 외부에서 입력한 문자열 개수,
{                                   //argv[]는 외부에서 입력한 문자열들 
 int image1[600][800*3];  //800x600 영상까지 처리가능 컬러영상
 int image2[256][256*3];  //256x256 히스토그램 컬러영상
 int image3[256][256*3];  //256x256 거꾸로 히스토그램 컬러영상

 int x, y;                  //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;               //문자 변수 M과 N 선언
 int XX, YY, MAX;        //정수 변수 XX, YY, MAX 선언
 int n = atoi(argv[3]);    //입력받은 4번째 문자열을 정수화 시켜 n에 넣음
 FILE *file1, *file2;       //파일 변수 file1과 file2 선언

 int frequency[256]={0}; //명암도의 빈도를 체크할 변수 선언후 초기화
 int bright, height;       //명암도 정수변수 bright와 높이 정수 변수 height 선언

 file1 = fopen(argv[1], "r");  //외부에서 입력한 두 번째 문자열을 읽기모드로 염
 fscanf(file1, "%c", &M);     //헤더의 매직넘버를 읽어 들임 ‘P'
 fscanf(file1, "%c", &N);     //헤더의 매직넘버를 읽어 들임 ‘3’
 fscanf(file1, "%d", &XX);    //입력영상의 가로크기 읽어 들임
 fscanf(file1, "%d", &YY);    //입력영상의 세로크기 읽어 들임
 fscanf(file1, "%d", &MAX);  //입력영상의 최대 명암도 읽어 들임

 for(y = 0; y < YY; y++)   //반복문을 사용하여 입력영상의 픽셀 값 읽어 들임
  for(x = 0; x < XX*3; x++)    //컬러영상은 가로픽셀 당 값을 3개 가지므로 x3
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = n; x < XX*3; x+=3)  //n = 0 이면 R, n = 1 이면 G, n = 2이면 B
  {
   bright = image1[y][x];      //픽셀 값을 bright에 넣음
   frequency[bright] = frequency[bright] + 1;  //같은 픽셀 값이 나오면
  }                                             //해당 픽셀 값의 빈도수 증가

 for(bright=0; bright<256; bright++)
  {
  frequency[bright] = frequency[bright] / 4;   //히스토그램의 높이를 낮춰줌
  if(frequency[bright]>256) frequency[bright] = 256; //255보다 높으면 255로 고정
  for(height=0; height < frequency[bright]; height++)
   image2[height][bright*3+n] = 255;   //해당하는 픽셀 값에 빈도수 높이만큼 채워줌
  }                                      //R, G, B에 맞게 값을 분배

 XX=256;                                //히스토그램의 가로 크기
 YY=256;                                //히스토그램의 세로 크기

 for(y = 0; y < YY; y++) 
 for(x = 0; x < XX*3; x++)   //컬러영상은 가로픽셀 당 값을 3개 가지므로 x3         
  image3[(YY-1)-y][x] = image2[y][x];  //히스토그램을 X축 대칭 시킴

 file2 = fopen(argv[2], "w");   //외부에서 입력한 세 번째 문자열을 쓰기모드로 염
 fprintf(file2, "%c", M);         //읽어 들인 두 번째 문자열 파일의 헤더 매직넘버를
 fprintf(file2, "%c\n", N);      //세 번째 문자열 파일에 입력
 fprintf(file2, "%d %d\n", XX, YY);  //읽어 들인 가로축과 세로축 크기를 입력
 fprintf(file2, "%d\n", MAX);   //읽어 들인 최대 명암도를 입력

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX*3; x++){   //반복문을 이용하여 컬러 히스토그램을
   fprintf(file2,"%4d", image3[y][x]);   //세 번째 문자열 파일에 입력
  }
  fprintf(file2, "\n");      //줄 내림 입력
 }

 return 0;
}

