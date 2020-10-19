#include <stdio.h>
int main(int argc, char * argv[])    //argc는 외부에서 입력한 문자열 개수,
{                                   //argv[]는 외부에서 입력한 문자열들
 int image1[600][800];             //800x600 영상까지 처리가능
 int image2[600][800];             //800x600 영상까지 처리가능
 int x, y;                           //반복문에서 사용할 정수 변수 x, y 선언
 char M, N;                        //문자 변수 M과 N 선언
 int XX, YY, MAX;                 //정수 변수 XX, YY, MAX 선언
 FILE *file1, *file2;                 //파일 변수 file1과 file2 선언

 int frequency[256]={0};           //명암도의 빈도를 체크할 변수 선언후 초기화
 int bright, height;                 //정수 변수 bright와 정수 변수 height 선언
 int min, max;       //최소 픽셀 값 정수 변수 min와 최대 픽셀 값 정수 변수 max 선언

 file1 = fopen(argv[1], "r");        //외부에서 입력한 두 번째 문자열을 읽기모드로 염
 fscanf(file1, "%c", &M);           //헤더의 매직넘버를 읽어 들임 ‘P'
 fscanf(file1, "%c", &N);           //헤더의 매직넘버를 읽어 들임 ‘2’
 fscanf(file1, "%d", &XX);         //입력영상의 가로크기 읽어 들임
 fscanf(file1, "%d", &YY);         //입력영상의 세로크기 읽어 들임
 fscanf(file1, "%d", &MAX);       //입력영상의 최대 명암도 읽어 들임

 for(y = 0; y < YY; y++)          //반복문을 사용하여 입력영상의 픽셀 값 읽어 들임
  for(x = 0; x < XX; x++)
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = 0; x < XX; x++)
  {
   bright = image1[y][x];          //입력 영상의 픽셀 값을 bright에 넣음
   frequency[bright] = frequency[bright] + 1;     //같은 픽셀 값이 나오면 
  }                                                //해당 픽셀 값의 빈도수 증가
 for(bright=255; bright >= 0;bright--)
  if(frequency[bright])              //히스토그램의 최대값 구하기
   { max = bright;                  //빈도수가 0이 아닌 가장 픽셀 값이 큰 수를 max
     break; }
 for(bright=0;bright < 256;bright++)
  if(frequency[bright])              //히스토그램의 최솟값 구하기
   { min = bright;                  //빈도수가 0이 아닌 가장 픽셀 값이 작은 수를 min
     break; }
 for(y=0;y<YY;y++)
  for(x=0;x<XX;x++)               //명암대비 스트레칭
   image2[y][x] = (float)(image1[y][x] - min)/(max - min) * 255;
                               //float는 정수/정수가 0이 되는 것을 방지하기 위한 cast
 file2 = fopen(argv[2], "w");   //외부에서 입력한 세 번째 문자열을 쓰기모드로 염
 fprintf(file2, "%c", M);         //읽어 들인 두 번째 문자열 파일의 헤더 매직넘버를
 fprintf(file2, "%c\n", N);      //세 번째 문자열 파일에 입력
 fprintf(file2, "%d %d\n", XX, YY);   //읽어 들인 가로축과 세로축 크기를 입력
 fprintf(file2, "%d\n", MAX);         //읽어 들인 최대 명암도를 입력

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){     //반복문을 이용하여 명암대비 스트레칭한 영상을
   fprintf(file2,"%4d", image2[y][x]);   //세 번째 문자열 파일에 입력
  }
  fprintf(file2, "\n");             //줄 내림 입력
 }
 return 0;
}

