#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef int Elemtype;
#include"..\Headers\��ջʵ��.h"

//��������
LinkStack initStack(LinkStack Link);//��ʼ��ջ
int undefineStack(LinkStack Link);//�ж�ջ�Ƿ�δ��ʼ��
int isEmptyStack(LinkStack Link);//�ж�ջ�Ƿ�Ϊ��
void getTopStack(LinkStack Link, Elemtype *data);//�õ�ջ��Ԫ��
void ClearStack(LinkStack Link);//���ջ
LinkStack destoryStack(LinkStack Link);//����ջ
void stackLength(LinkStack Link);//���ջ�ĳ��� 
LinkStack pushStack(LinkStack Link, Elemtype data);//��ջ
LinkStack popStack(LinkStack Link, Elemtype *data);//��ջ 
void PrintStack(LinkStack Link);//��ӡջ 


int main(){
	Elemtype data;
	LinkStack Link; Link.Stacksize = -1;
	do{
		printf("*************************\n");
		printf("***  1. ��ʼ��ջ      ***\n");
		printf("***  2. ��ջ          ***\n");
		printf("***  3. ��ջ          ***\n");
		printf("***  4. �õ�ջ��Ԫ��  ***\n");
		printf("***  5. ���ջ�ĳ���  ***\n");
		printf("***  6. ���ջ        ***\n");
		printf("***  7. ����ջ        ***\n");
		printf("***  8. ��ӡջ        ***\n");
		printf("***  0. �˳�����      ***\n");
		printf("*************************\n");
		int choice;
		printf("����������ѡ���ѡ��: ");
		scanf("%d", &choice);
		getchar();
		system("cls");
		
//��ʼִ�г��� 
		switch (choice){
			case 1://��ʼ�� 
				printf("����Ϊ����ʼ��...");
				sleep(2);
				system("cls");
				Link = initStack(Link);
				system("cls");
				break;
				
			case 2://��ջ 
				printf("������������ջ������: ");
				scanf("%d", &data);
				Link = pushStack(Link, data);
				system("cls");
				break;
				
			case 3://��ջ 
				printf("����Ϊ�����г�ջ����...");
				Link =  popStack(Link, &data);
				printf("��ջ������ֵΪ: %d", data);
				system("cls");
				break;
				
		 	case 4://ջ��Ԫ�� 
		 		getTopStack(Link, &data);
		 		printf("ջ����Ԫ��Ϊ: %d", data);
		 		sleep(2);
		 		system("cls");
		 		break;
		 		
		 	case 5://ջ�� 
		 		stackLength(Link);
		 		system("cls");
		 		break;
		 		
		 	case 6://���ջ 
		 		printf("����Ϊ�����ջ...");
		 		ClearStack(Link);
		 		system("cls");
		 		break;
		 		
		 	case 7://����ջ 
		 		printf("����Ϊ������ջ...");
				Link = destoryStack(Link);
				system("cls");
				break;
				
			case 8://ջչʾ 
				printf("ջ��Ԫ������:\n");
				PrintStack(Link);
				system("cls");
				break;
				
			case 0://�˳����� 
				exit(0);
			
			default:
				printf("����������������������");
				sleep(2);
				system("cls");
				break;
		}
	} while(1);
	return 0;
}
