#include <stdio.h>
int main(int argc, char * argv[])    //argc�� �ܺο��� �Է��� ���ڿ� ����,
{                                   //argv[]�� �ܺο��� �Է��� ���ڿ���
 int image1[600][800*3];          //800x600 ������� ó������
 int image2[600][800*3];          //800x600 ������� ó������
 int x, y;                          //�ݺ������� ����� ���� ���� x, y ����
 char M, N;                        //���� ���� M�� N ����
 int XX, YY, MAX;                 //���� ���� XX, YY, MAX ����
 FILE *file1, *file2;                //���� ���� file1�� file2 ����
                        //R, G, B ���� ��ϵ��� �󵵸� üũ�� �迭 ���� �� �ʱ�ȭ
 int frequency_R[256]={0}, frequency_G[256]={0}, frequency_B[256]={0};
 int bright_R, bright_G, bright_B;  //R, G, B ���� ��� ���� üũ�� ���� ����  
 int min_R, min_G, min_B, max_R, max_G, max_B;  
                           //R, G, B ���� ��Ⱚ�� �ִ밪 �ּҰ� ���� ���� ����
 file1 = fopen(argv[1], "r");   //�ܺο��� �Է��� �� ��° ���ڿ��� �б���� ��
 fscanf(file1, "%c", &M);      //����� �����ѹ��� �о� ���� ��P'
 fscanf(file1, "%c", &N);      //����� �����ѹ��� �о� ���� ��3��
 fscanf(file1, "%d", &XX);     //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &YY);     //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &MAX);   //�Է¿����� �ִ� ��ϵ� �о� ����

 for(y = 0; y < YY; y++)      //�ݺ����� ����Ͽ� �Է¿����� �ȼ� �� �о� ����
  for(x = 0; x < XX*3; x++)   //�÷������� �����ȼ� �� ���� 3�� �����Ƿ� x3
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = 0; x < XX*3; x+=3)    //�÷������� �����ȼ� �� ���� 3�� �����Ƿ� x3
  {                               //R, G, B ���� ���ϱ� ���� x+=3
   bright_R = image1[y][x];      //�Է� ������ R ��� ���� bright�� ����
   bright_G = image1[y][x+1];   //�Է� ������ G ��� ���� bright�� ����
   bright_B = image1[y][x+2];   //�Է� ������ B ��� ���� bright�� ����
   frequency_R[bright_R] = frequency_R[bright_R] + 1;    //R �󵵼� üũ
   frequency_G[bright_G] = frequency_G[bright_G] + 1;   //G �󵵼� üũ
   frequency_B[bright_B] = frequency_B[bright_B] + 1;   //B �󵵼� üũ
  }
 for(bright_R=255; bright_R >= 0;bright_R--)
  if(frequency_R[bright_R])       //R ��Ⱚ �ִ밪 ���ϱ�
   { max_R = bright_R;          //�󵵼��� 0�� �ƴ� ���� ��� ���� ū ���� max_R
     break; }
 for(bright_G=255; bright_G >= 0;bright_G--)
  if(frequency_G[bright_G])      //G ��Ⱚ �ִ밪 ���ϱ�
   { max_G = bright_G;          //�󵵼��� 0�� �ƴ� ���� ��� ���� ū ���� max_G
     break; }
 for(bright_B=255; bright_B >= 0;bright_B--)
  if(frequency_B[bright_B])      //B �ȼ� �� �ִ밪 ���ϱ�
   { max_B = bright_B;         //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ū ���� max_G
     break; }
 for(bright_R=0;bright_R < 256;bright_R++)
  if(frequency_R[bright_R])     //R ��Ⱚ �ּҰ� ���ϱ�
   { min_R = bright_R;         //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ���� ���� min_R
     break; } 
 for(bright_G=0;bright_G < 256;bright_G++)
  if(frequency_G[bright_G])     //G �ȼ��� �ּҰ� ���ϱ�
   { min_G = bright_G;        //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ���� ���� min_G
     break; }
 for(bright_B=0;bright_B < 256;bright_B++)
  if(frequency_B[bright_B])    //B ��Ⱚ �ּҰ� ���ϱ�
   { min_B = bright_B;        //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ���� ���� min_B
     break; }

 for(y=0;y<YY;y++)
  for(x=0;x<XX*3;x+=3){      //R, G, B ���� ��ϴ�� ��Ʈ��Ī
   image2[y][x] = (float)(image1[y][x] - min_R)/(max_R - min_R) * 255;
   image2[y][x+1] = (float)(image1[y][x+1] - min_G)/(max_G - min_G) * 255;
   image2[y][x+2] = (float)(image1[y][x+2] - min_B)/(max_B - min_B) * 255;
  }
 file2 = fopen(argv[2], "w");   //�ܺο��� �Է��� �� ��° ���ڿ��� ������� ��
 fprintf(file2, "%c", M);        //�о� ���� �� ��° ���ڿ� ������ ��� �����ѹ���
 fprintf(file2, "%c\n", N);      //�� ��° ���ڿ� ���Ͽ� �Է�
 fprintf(file2, "%d %d\n", XX, YY);    //�о� ���� ������� ������ ũ�⸦ �Է�
 fprintf(file2, "%d\n", MAX);  //�о� ���� �ִ� ��ϵ��� �Է�

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX*3; x++){    //�ݺ����� �̿��Ͽ� ��ϴ�� ��Ʈ��Ī�� ������
   fprintf(file2,"%4d", image2[y][x]);    //�� ��° ���ڿ� ���Ͽ� �Է�
  }
  fprintf(file2, "\n");             //�� ���� �Է�
 }

 return 0;
}

