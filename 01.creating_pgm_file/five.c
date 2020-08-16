#include <stdio.h>

int main(void)
{
        int x, y;                    //반복문에서 사용할 변수 x, y 선언
        FILE *fp = NULL;          //파일 변수 fp를 선언하고 초기화함
        char M = 'P';               //문자 변수 P 선언
        char N = '2';               //문자 변수 2 선언
        int XX = 4;                 //정수 변수 XX 선언하고 4를 넣음
        int YY = 5;                 //정수 변수 YY 선언하고 5를 넣음
        int MAX = 255;            //정수변수 MAX를 선언하고 255을 넣음
        int image[5][4] = {{255, 255, 255, 255},   //정수배열변수를 선언하고
                            {255, 0, 0, 0},          //값을 넣음
                            {255, 255, 255, 0},
                            {0, 0, 0, 255},
                            {255, 255, 255, 0}};

        fp = fopen("five.txt", "wt");        //hw2.txt를 텍스트쓰기모드로 염
        fprintf(fp, "%c", M);               //PGM 아스키코드포맷을 사용하기 위해
        fprintf(fp, "%c\n", N);            //P2를 씀
        fprintf(fp, "%d ", XX);             //가로축의 크기가 4이므로 4입력
        fprintf(fp, "%d\n", YY);           //세로축의 크기가 5이므로 5입력
        fprintf(fp, "%d\n", MAX);         //최대명암도 255 입력
        for(y=0; y<YY; y++){            //반복문을 사용해서 학번 끝자리에 맞게
         for(x=0; x<XX; x++)            //0과 255를 정렬
                fprintf(fp, "%4d", image[y][x]);  //칸 간격을 맞추기 위해 %4d사용
         fprintf(fp, "\n");                 //한줄 입력 후 다음 줄로 넘어감
        }
        fclose(fp);                        //쓰기모드로 열었던 파일을 닫음
return 0;
}

