#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//����˫������ṹ�� 
typedef struct Double_Linklist{
	int num;
	struct Double_Linklist *next;
	struct Double_Linklist *prior;
}dlist;

//����.h�ļ� 
#include"dLinkedList.h" 

int main(){		//��ʼʵ��ADT 
    int w=0;
    int x;		//����ѡ������ 
    dlist *double_head = NULL;
    
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.����һ��˫����������  ***\n"); 
		printf("*** 2.��˫�������������ADT ***\n"); 
		printf("*** 6.�˳�����              ***\n"); 
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("\n����������ѡ��: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("����Ϊ�����ɣ����Ե�Ƭ��"); 
				sleep(3);
				system("cls");
				double_head = (dlist *)malloc(sizeof(dlist));	//���ó�ʼ���� 
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				
			case 3:
				printf("正在为您生成，请稍等片刻"); 
				sleep(3);
				system("cls");
				dlist *double_head = (dlist *)malloc(sizeof(dlist));	//构建双向链表头结点
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("����ѡ�������⣬����������"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
