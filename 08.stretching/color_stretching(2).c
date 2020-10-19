#include <stdio.h>
int main(int argc, char * argv[])    //argc는 외부에서 입력한 문자열 개수,
{                                   //argv[]는 외부에서 입력한 문자열들
 int image1[600][800*3];          //800x600 영상까지 처리가능
 int image2[600][800*3];          //800x600 영상까지 처리가능
 int x, y;                          //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;                        //문자 변수 M과 N 선언
 int XX, YY, MAX;                 //정수 변수 XX, YY, MAX 선언
 FILE *file1, *file2;                //파일 변수 file1과 file2 선언
                        //R, G, B 따로 명암도의 빈도를 체크할 배열 선언 후 초기화
 int frequency_R[256]={0}, frequency_G[256]={0}, frequency_B[256]={0};
 int bright_R, bright_G, bright_B;  //R, G, B 각각 밝기 값을 체크할 변수 선언  
 int min_R, min_G, min_B, max_R, max_G, max_B;  
                           //R, G, B 각각 밝기값의 최대값 최소값 넣을 변수 선언
 file1 = fopen(argv[1], "r");   //외부에서 입력한 두 번째 문자열을 읽기모드로 염
 fscanf(file1, "%c", &M);      //헤더의 매직넘버를 읽어 들임 ‘P'
 fscanf(file1, "%c", &N);      //헤더의 매직넘버를 읽어 들임 ‘3’
 fscanf(file1, "%d", &XX);     //입력영상의 가로크기 읽어 들임
 fscanf(file1, "%d", &YY);     //입력영상의 세로크기 읽어 들임
 fscanf(file1, "%d", &MAX);   //입력영상의 최대 명암도 읽어 들임

 for(y = 0; y < YY; y++)      //반복문을 사용하여 입력영상의 픽셀 값 읽어 들임
  for(x = 0; x < XX*3; x++)   //컬러영상은 가로픽셀 당 값을 3개 가지므로 x3
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = 0; x < XX*3; x+=3)    //컬러영상은 가로픽셀 당 값을 3개 가지므로 x3
  {                               //R, G, B 각각 구하기 위해 x+=3
   bright_R = image1[y][x];      //입력 영상의 R 밝기 값을 bright에 넣음
   bright_G = image1[y][x+1];   //입력 영상의 G 밝기 값을 bright에 넣음
   bright_B = image1[y][x+2];   //입력 영상의 B 밝기 값을 bright에 넣음
   frequency_R[bright_R] = frequency_R[bright_R] + 1;    //R 빈도수 체크
   frequency_G[bright_G] = frequency_G[bright_G] + 1;   //G 빈도수 체크
   frequency_B[bright_B] = frequency_B[bright_B] + 1;   //B 빈도수 체크
  }
 for(bright_R=255; bright_R >= 0;bright_R--)
  if(frequency_R[bright_R])       //R 밝기값 최대값 구하기
   { max_R = bright_R;          //빈도수가 0이 아닌 가장 밝기 값이 큰 수를 max_R
     break; }
 for(bright_G=255; bright_G >= 0;bright_G--)
  if(frequency_G[bright_G])      //G 밝기값 최대값 구하기
   { max_G = bright_G;          //빈도수가 0이 아닌 가장 밝기 값이 큰 수를 max_G
     break; }
 for(bright_B=255; bright_B >= 0;bright_B--)
  if(frequency_B[bright_B])      //B 픽셀 값 최대값 구하기
   { max_B = bright_B;         //빈도수가 0이 아닌 가장 픽셀 값이 큰 수를 max_G
     break; }
 for(bright_R=0;bright_R < 256;bright_R++)
  if(frequency_R[bright_R])     //R 밝기값 최소값 구하기
   { min_R = bright_R;         //빈도수가 0이 아닌 가장 픽셀 값이 작은 수를 min_R
     break; } 
 for(bright_G=0;bright_G < 256;bright_G++)
  if(frequency_G[bright_G])     //G 픽셀값 최소값 구하기
   { min_G = bright_G;        //빈도수가 0이 아닌 가장 픽셀 값이 작은 수를 min_G
     break; }
 for(bright_B=0;bright_B < 256;bright_B++)
  if(frequency_B[bright_B])    //B 밝기값 최소값 구하기
   { min_B = bright_B;        //빈도수가 0이 아닌 가장 픽셀 값이 작은 수를 min_B
     break; }

 for(y=0;y<YY;y++)
  for(x=0;x<XX*3;x+=3){      //R, G, B 각각 명암대비 스트레칭
   image2[y][x] = (float)(image1[y][x] - min_R)/(max_R - min_R) * 255;
   image2[y][x+1] = (float)(image1[y][x+1] - min_G)/(max_G - min_G) * 255;
   image2[y][x+2] = (float)(image1[y][x+2] - min_B)/(max_B - min_B) * 255;
  }
 file2 = fopen(argv[2], "w");   //외부에서 입력한 세 번째 문자열을 쓰기모드로 염
 fprintf(file2, "%c", M);        //읽어 들인 두 번째 문자열 파일의 헤더 매직넘버를
 fprintf(file2, "%c\n", N);      //세 번째 문자열 파일에 입력
 fprintf(file2, "%d %d\n", XX, YY);    //읽어 들인 가로축과 세로축 크기를 입력
 fprintf(file2, "%d\n", MAX);  //읽어 들인 최대 명암도를 입력

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX*3; x++){    //반복문을 이용하여 명암대비 스트레칭한 영상을
   fprintf(file2,"%4d", image2[y][x]);    //세 번째 문자열 파일에 입력
  }
  fprintf(file2, "\n");             //줄 내림 입력
 }

 return 0;
}

