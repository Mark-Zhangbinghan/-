#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
#include<time.h>
#include<windows.h>
#include"..\Headers\�����㷨.h"

int main()
{
	int i,j;
	int len;//���鳤�� 
	int max=0;//����Ԫ��ȡֵ��Χ 
	int choice, make=0;//�û�������ѡ��
	int *arr;//����������� 
	int k;//�����û��鿴�ź�ĵ� k λ���� 
	FILE *ptr = NULL; 
	int time_insert, time_merge, time_quick, time_count, time_radix;
	do
	{
		printf("********************************************\n");
		printf("***  1. �����������                     ***\n");
		printf("***  2. �鿴����������                   ***\n");
		printf("***  3. �鿴���������µ�����ʱ��         ***\n");
		printf("***  4. �鿴����С�����µ�����ʱ��       ***\n");
		printf("***  5. ��ɫ����                         ***\n");
		printf("***  6. ��һ�������������ҵ���K��/С���� ***\n");
		printf("***  0. �˳�����                         ***\n");
		printf("********************************************\n");
		
		printf("����������ѡ��: ");
		scanf("%d", &choice); 
		getchar();
		system("cls");
		
		switch (choice)
		{
			case 1://����������� 
				make = 1;
				printf("����������Ҫ�������ĳ�: ");
				scanf("%d", &len);
				getchar();
				printf("����������Ҫ�������ķ�Χ(���ֵ): ");
				scanf("%d", &max);
				getchar();
				system("cls");
				Random(len, max);
    			system("pause");
    			system("cls");
				break;
				
				
			case 2://�鿴������ɵ����� 
				if (!make)
				{
					printf("���ȴ�������\n");
					system("pause");
					system("cls");
					break;
				}
				ptr = fopen("DATA.txt", "r");
 				if(ptr == NULL) 
				{
    				printf("�ļ��޷�������\n");			
    				exit(1);
				}
				arr = (int*)malloc(sizeof(int)*(len)); 
				for (i=0;i<len;i++)
					fscanf(ptr, "%d", &arr[i]);
				for (i=0;i<len;i++)
					printf("%d ", arr[i]);
				system("pause");
				system("cls");
				if(fclose(ptr)!=0) 
				{
					printf("�ļ��޷������ر�\n"); 
					exit(1); 
				} 
				else
    				printf("�ļ��Ѿ��ɹ��ر�\n");
    			free(arr);
    			system("pause");
    			system("cls");
				break; 	
			
			
			case 3://�鿴ÿ������ʽ�ڴ��������µ�����ʱ��
				if (!make)
				{
					printf("���ȴ�������\n");
					system("pause");
					system("cls");
					break;
				}
				Big_count(len);
				system("pause");
				system("cls");
				break;
			
			case 4://�鿴ÿ������ʽ�ڴ���С�������µ�����ʱ��
				if (!make)
				{
					printf("���ȴ�������\n");
					system("pause");
					system("cls");
					break;
				}
				if (len>100)
				{
					printf("��������������������´���\n");
					system("pause");
					system("cls");
					break;
				}				
				Small_count(len);
				system("pause");
				system("cls");
				break;	
				
			case 5://��ɫ����
				if (!make)	
				{
					printf("���ȴ�������\n");
					system("pause");
					system("cls");
					break;
				}
				if (max>2)
				{
					printf("������������Ԫ�ش���2�������´�����������Ԫ�����ֵ��Ϊ2\n");
					system("pause");
					system("cls");
					break;
				}
				Color_sort(len);
				system("pause");
				system("cls");
				break;
				
			case 6://��һ�������������ҵ���K��/С����
				if (!make)	
				{
					printf("���ȴ�������\n");
					system("pause");
					system("cls");
					break;
				}
				printf("����������Ҫ���ҵڼ�����: ");
				scanf("%d", &k);
				getchar();
				Find_sort(len, k);
				system("pause");
				system("cls");
				break;
									
			case 0://�˳�����		
				exit(1); 
			
			default:
				printf("�������������������������...");
				system("pause");
				system("cls"); 
		}
	}while(1); 
	return 0;
}
