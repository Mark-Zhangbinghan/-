#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include"..\Headers\���Ͷ���.h"

//����˵��
LinkQueue initQueue(LinkQueue Link);//��ʼ������
int IsUndefineQueue(LinkQueue Link);//�ж϶����Ƿ��ѳ�ʼ�� 
int IsEmptyQueue(LinkQueue Link);//�ж��Ƿ�Ϊ�ն���
void GetHeadQueue(LinkQueue Link);//�鿴��ͷԪ��
void LengthQueue(LinkQueue Link);//ȷ�����г���
LinkQueue PushQueue(LinkQueue Link, void *data, int type);//���
LinkQueue TypeQueue(LinkQueue Link);//�ж϶���Ԫ�ص���������
LinkQueue PopQueue(LinkQueue Link);//����
void DestroyQueue(LinkQueue Link);//���ٶ���
void ShowQueue(LinkQueue Link);//�������� 

int main(){
	int choice;
	LinkQueue Link; Link.Length=-1;
do{
	printf("*************************\n");
	printf("***  1. ��ʼ������    ***\n");
	printf("***  2. ���          ***\n");
	printf("***  3. ����          ***\n");
	printf("***  4. �õ���ͷԪ��  ***\n");
	printf("***  5. �����еĳ���***\n");
	printf("***  6. ���ٶ���      ***\n");
	printf("***  7. ��ӡ����      ***\n");
	printf("***  0. �˳�����      ***\n");
	printf("*************************\n");
	printf("����������ѡ��: ");
	
	scanf("%d", &choice);
	getchar();
	system("cls");
	switch (choice){
		case 1://��ʼ�� 
			printf("����Ϊ���Ķ��н��г�ʼ��...\n");
			Link = initQueue(Link);
			system("cls");
			break;
			
		case 2://��� 
			Link = TypeQueue(Link);
			system("cls");
			break;
			
		case 3://����
			printf("����Ϊ������...\n");
			Link = PopQueue(Link);
			system("cls");
			break;
			 
		case 4://�鿴��ͷԪ��
			GetHeadQueue(Link);
			system("cls");
			break;
			
		case 5://�����г���
			LengthQueue(Link);
			system("cls");
			break;
			
		case 6://���ٶ���
			DestroyQueue(Link);
			system("cls");
			break;
			
		case 7://��ӡ����
			ShowQueue(Link);
			system("cls");
			break;
			
		case 0://�˳�����
			exit(1);
			
		default:
			printf("����������������������");
			sleep(2);
			system("cls"); 
	}
}while(1);
	return 0;
}
