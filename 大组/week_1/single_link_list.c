#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Single_Linklist{	//���ܵ�������ṹ�� 
	int num;
	struct Single_Linklist *next;
}slist;

typedef struct Double_Linklist{	//����˫������ṹ�� 
	int num;
	struct Double_Linklist *next;
	struct Double_Linklist *prior;
}dlist;

#include"single_insert.h"

int main(){		//������ 
    int w=0;
    int x;		//���û�������Ŀѡ�� 
    slist *single_head = (slist *)malloc(sizeof(slist));	//������������ͷ��� 
    single_head->next = NULL; 
    dlist *double_head = (dlist *)malloc(sizeof(dlist));	//����˫������ͷ���
	double_head->next = NULL; double_head->prior = NULL;
    
	do{
    	printf("******************************************************\n");
    	printf("******************************************************\n");
    	printf("*** 1.����һ�������������� 2.�Ե��������������ADT ***\n");
    	printf("*** 3.����һ��˫���������� 4.��˫�������������ADT ***\n");
    	printf("*** 5.����� 	           6.�˳����� 		   ***\n");
    	printf("******************************************************\n");
    	printf("******************************************************\n");
    	printf("\n����������ѡ��: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("����Ϊ�����ɣ����Ե�Ƭ��");
				sleep(3);
				system("cls");
				slist *head = Link_insert(single_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				
			case 3:
				printf("����Ϊ�����ɣ����Ե�Ƭ��"); 
				sleep(3);
				system("cls");
				break;
				
			case 4:
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("����ѡ�������⣬���������룡"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
