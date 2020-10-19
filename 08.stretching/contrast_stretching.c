#include <stdio.h>
int main(int argc, char * argv[])    //argc�� �ܺο��� �Է��� ���ڿ� ����,
{                                   //argv[]�� �ܺο��� �Է��� ���ڿ���
 int image1[600][800];             //800x600 ������� ó������
 int image2[600][800];             //800x600 ������� ó������
 int x, y;                           //�ݺ������� ����� ���� ���� x, y ����
 char M, N;                        //���� ���� M�� N ����
 int XX, YY, MAX;                 //���� ���� XX, YY, MAX ����
 FILE *file1, *file2;                 //���� ���� file1�� file2 ����

 int frequency[256]={0};           //��ϵ��� �󵵸� üũ�� ���� ������ �ʱ�ȭ
 int bright, height;                 //���� ���� bright�� ���� ���� height ����
 int min, max;       //�ּ� �ȼ� �� ���� ���� min�� �ִ� �ȼ� �� ���� ���� max ����

 file1 = fopen(argv[1], "r");        //�ܺο��� �Է��� �� ��° ���ڿ��� �б���� ��
 fscanf(file1, "%c", &M);           //����� �����ѹ��� �о� ���� ��P'
 fscanf(file1, "%c", &N);           //����� �����ѹ��� �о� ���� ��2��
 fscanf(file1, "%d", &XX);         //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &YY);         //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &MAX);       //�Է¿����� �ִ� ��ϵ� �о� ����

 for(y = 0; y < YY; y++)          //�ݺ����� ����Ͽ� �Է¿����� �ȼ� �� �о� ����
  for(x = 0; x < XX; x++)
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = 0; x < XX; x++)
  {
   bright = image1[y][x];          //�Է� ������ �ȼ� ���� bright�� ����
   frequency[bright] = frequency[bright] + 1;     //���� �ȼ� ���� ������ 
  }                                                //�ش� �ȼ� ���� �󵵼� ����
 for(bright=255; bright >= 0;bright--)
  if(frequency[bright])              //������׷��� �ִ밪 ���ϱ�
   { max = bright;                  //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ū ���� max
     break; }
 for(bright=0;bright < 256;bright++)
  if(frequency[bright])              //������׷��� �ּڰ� ���ϱ�
   { min = bright;                  //�󵵼��� 0�� �ƴ� ���� �ȼ� ���� ���� ���� min
     break; }
 for(y=0;y<YY;y++)
  for(x=0;x<XX;x++)               //��ϴ�� ��Ʈ��Ī
   image2[y][x] = (float)(image1[y][x] - min)/(max - min) * 255;
                               //float�� ����/������ 0�� �Ǵ� ���� �����ϱ� ���� cast
 file2 = fopen(argv[2], "w");   //�ܺο��� �Է��� �� ��° ���ڿ��� ������� ��
 fprintf(file2, "%c", M);         //�о� ���� �� ��° ���ڿ� ������ ��� �����ѹ���
 fprintf(file2, "%c\n", N);      //�� ��° ���ڿ� ���Ͽ� �Է�
 fprintf(file2, "%d %d\n", XX, YY);   //�о� ���� ������� ������ ũ�⸦ �Է�
 fprintf(file2, "%d\n", MAX);         //�о� ���� �ִ� ��ϵ��� �Է�

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){     //�ݺ����� �̿��Ͽ� ��ϴ�� ��Ʈ��Ī�� ������
   fprintf(file2,"%4d", image2[y][x]);   //�� ��° ���ڿ� ���Ͽ� �Է�
  }
  fprintf(file2, "\n");             //�� ���� �Է�
 }
 return 0;
}

