#include<stdio.h>
#include<stdlib.h>
#define size 20 
#include"..\Headers\��-ADTʵ��.h"


int main(){
	int choice, data;
	BiTree T;
	int make = 0;//�ж��Ƿ��ѽ��������� 
	do
	{
		printf("****************************\n");
		printf("***  1. ��������������   ***\n");
		printf("***  2. ������ֵ         ***\n");
		printf("***  3. ɾ����ֵ         ***\n");
		printf("***  4. ������ֵ         ***\n");
		printf("***  5. ����������       ***\n");
		printf("***  0. �˳�����         ***\n");
		printf("****************************\n");
		
		printf("����������ѡ��: ");
		scanf("%d", &choice); 
		getchar();
		system("cls");
		
		switch (choice)
		{
			//��������������
			case 1:
				T = CreateTree();
				make = 1;
				break;
				
			//������ֵ 
			case 2:
				if (make == 0)
				{
					printf("����û�д���������������\n");
					system("pause");
					system("cls");
					break;
				}
				printf("����������������ֵ: ");
				scanf("%d", &data);
				getchar(); 
				InsertNode(T, data);
				break;
				
			//ɾ����ֵ 
			case 3:
				if (make == 0)
				{
					printf("����û�д���������������\n");
					system("pause");
					system("cls");
					break;
				}
				printf("����������ɾ������ֵ: ");
				scanf("%d", &data);
				getchar(); 
				InsertNode(T, data);
				printf("��Ϊ��ɾ�����...\n");
				system("pause");
				system("cls");
				break;
				
			//������ֵ 
			case 4:
				if (make == 0)
				{
					printf("����û�д���������������\n");
					system("pause");
					system("cls");
					break;
				}
				printf("������������ҵ���ֵ: ");
				scanf("%d", &data);
				getchar(); 
				SearchNode(T, data);
				system("pause");
				system("cls");
				break;
			
			//����������
			case 5:
				 if (make == 0)
				{
					printf("����û�д���������������\n");
					system("pause");
					system("cls");
					break;
				}
				//�ݹ� 
				printf("�ݹ��������������:\n"); 
				Preorder_Traverse(T); 
				printf("\n�ݹ��������������:\n"); 
				Inorder_Traverse(T); 
				printf("\n�ݹ�������������:\n"); 
 				Postorder_Traverse(T);
 				//�ǵݹ� 
				printf("\n�ǵݹ��������������:\n"); 
				PreorderTraversal(T); 
				printf("\n�ǵݹ��������������:\n"); 
				InorderTraversal(T); 
				printf("\n�ǵݹ�������������:\n"); 
 				PostorderTraversal(T);
 				printf("\n"); 
 				system("pause");
				system("cls");
				break;
 				
 			case 0:
 				exit(1);
 				
 			default:
 				printf("���������������ٴ�����");
 				system("pause");
				system("cls");
		}
	}while(1); 
	return 0;
} 
