#include <stdio.h>
int main(int argc, char * argv[])    //argc�� �ܺο��� �Է��� ���ڿ� ����,
{                                   //argv[]�� �ܺο��� �Է��� ���ڿ��� 
 int image1[600][800];             //800x600 ������� ó������
 int image2[256][256];            //256x256 ������׷�
 int image3[256][256];            //256x256 �Ųٷ� ������׷�

 int x, y;                         //�ݺ������� ����� ���� ���� x, y ����
 char M, N;                      //���� ���� M�� N ����
 int XX, YY, MAX;               //���� ���� XX, YY, MAX ����
 FILE *file1, *file2;              //���� ���� file1�� file2 ����

 int frequency[256]={0};        //��ϵ��� �󵵸� üũ�� ���� ������ �ʱ�ȭ
 int bright, height;              //��ϵ� �������� bright�� ���� ���� ���� height ����

 file1 = fopen(argv[1], "r");     //�ܺο��� �Է��� �� ��° ���ڿ��� �б���� ��
 fscanf(file1, "%c", &M);        //����� �����ѹ��� �о� ���� ��P'
 fscanf(file1, "%c", &N);        //����� �����ѹ��� �о� ���� ��2��
 fscanf(file1, "%d", &XX);       //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &YY);       //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &MAX);     //�Է¿����� �ִ� ��ϵ� �о� ����

 for(y = 0; y < YY; y++)      //�ݺ����� ����Ͽ� �Է¿����� �ȼ� �� �о� ����
  for(x = 0; x < XX; x++)   
     fscanf(file1, "%d", &image1[y][x]);

 for(y = 0; y < YY; y++)
  for(x = 0; x < XX; x++)
  {
   bright = image1[y][x];       //�̹����� �ȼ� ���� bright�� ����
   frequency[bright] = frequency[bright] + 1;  //���� �ȼ� ���� ������ 
  }                                             //�ش� �ȼ� ���� �󵵼� ����
 for(bright=0; bright<256; bright++)
  {
  frequency[bright] = frequency[bright] / 4;    //���̸� ������
  if(frequency[bright] > 256) frequency[bright] = 256; //255���� ������ 255�� ����
  for(height=0; height < frequency[bright]; height++)
   image2[height][bright] = 255;     //�ش��ϴ� �ȼ� ���� �󵵼� ���̸�ŭ ä����
  }
 XX=256;                       //������׷��� ������ ũ��
 YY=256;                       //������׷��� ������ ũ��

 for(y = 0; y < YY; y++)      
  for(x = 0; x < XX; x++)
   image3[(YY-1)-y][x] = image2[y][x];  //������׷��� X�� ��Ī ��Ŵ

 file2 = fopen(argv[2], "w");   //�ܺο��� �Է��� �� ��° ���ڿ��� ������� ��
 fprintf(file2, "%c", M);        //�о� ���� �� ��° ���ڿ� ������ ��� �����ѹ���
 fprintf(file2, "%c\n", N);     //�� ��° ���ڿ� ���Ͽ� �Է�
 fprintf(file2, "%d %d\n", XX, YY);  //�о� ���� ������� ������ ũ�⸦ �Է�
 fprintf(file2, "%d\n", MAX);   //�о� ���� �ִ� ��ϵ��� �Է�

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){    //�ݺ����� �̿��Ͽ� ������׷���
   fprintf(file2,"%4d", image3[y][x]);  //�� ��° ���ڿ� ���Ͽ� �Է�
  }
  fprintf(file2, "\n");          //�� ���� �Է�
 }

 return 0;
}

