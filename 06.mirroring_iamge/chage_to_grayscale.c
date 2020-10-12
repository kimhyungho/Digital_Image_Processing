#include <stdio.h>
int main(int argc, char * argv[])   //argc�� �ܺο��� �Է��� ���ڿ� ����,
{                                  //argv[]�� �ܺο��� �Է��� ���ڿ���
 int image1[600][800*3];          //800x600 ������� ó������ �÷�����
 int image2[600][800];            //800x600 ������� ó������
 int x, y;                          //�ݺ������� ����� ���� ���� x, y ����
 char M, N;                       //���� ���� M�� N ����
 int XX, YY, MAX;                //���� ���� XX, YY, MAX ����
 FILE *file1, *file2;               //���� ���� file1�� file2 ����
 file1 = fopen(argv[1], "r");      //�ܺο��� �Է��� �� ��° ���ڿ��� �б���� ��
 fscanf(file1, "%c", &M);          //����� �����ѹ��� �о� ���� ��P'
 fscanf(file1, "%c", &N);          //����� �����ѹ��� �о� ���� ��3�� 
 fscanf(file1, "%d", &XX);         //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &YY);         //�Է¿����� ����ũ�� �о� ����
 fscanf(file1, "%d", &MAX);       //�Է¿����� �ִ� ���ϵ� �о� ����

 for(y = 0; y < YY; y++)        //�ݺ����� ����Ͽ� �Է¿����� �ȼ� �� �о� ����
  for(x = 0; x < XX*3; x++)    //�÷������� �����ȼ� �� ���� 3�� �����Ƿ� x3
     fscanf(file1, "%d", &image1[y][x]);


 for(y = 0; y < YY; y++)        //�ݺ����� �̿��Ͽ�
  for(x = 0; x < XX; x++)       //������ ���ȭ ��Ŵ
   image2[y][x] = (image1[y][3*x]+image1[y][3*x+1]+image1[y][3*x+2])/3;
 //�׷��� ������ ������ ����
 N='2'; // �÷����� N�� 3, �׷��̿����� 2 �׷��̿��� ����̹Ƿ� 2
 file2 = fopen(argv[2], "w");   //�ܺο��� �Է��� �� ��° ���ڿ��� ������� ��
 fprintf(file2, "%c", M);        //�о� ���� �� ��° ���ڿ� ������ ��� �����ѹ� ��P'
 fprintf(file2, "%c\n", N);     //N�� 2�� ����־��� ������ 2 �Է�
 fprintf(file2, "%d %d\n", XX, YY); //�о� ���� ������� ������ ũ�⸦ �Է�
 fprintf(file2, "%d\n", MAX);  //�о� ���� �ִ� ���ϵ��� �Է�

 for(y = 0; y < YY; y++){
  for(x = 0; x < XX; x++){   //�ݺ����� �̿��Ͽ� ���ȭ ��Ų �ȼ� ����
   fprintf(file2,"%4d", image2[y][x]);   //�� ��° ���ڿ� ���Ͽ� �Է�
  }
  fprintf(file2, "\n");           //�� ���� �Է�
 }
 return 0;
}
