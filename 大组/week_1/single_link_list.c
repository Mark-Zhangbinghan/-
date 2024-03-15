#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Single_Linklist{	//构架单向链表结构体 
	int num;
	struct Single_Linklist *next;
}slist;

typedef struct Double_Linklist{	//构架双向链表结构体 
	int num;
	struct Double_Linklist *next;
	struct Double_Linklist *prior;
}dlist;

#include"single_insert.h"

int main(){		//主界面 
    int w=0;
    int x;		//供用户进行项目选择 
    slist *single_head = (slist *)malloc(sizeof(slist));	//构建单向链表头结点 
    single_head->next = NULL; 
    dlist *double_head = (dlist *)malloc(sizeof(dlist));	//构建双向链表头结点
	double_head->next = NULL; double_head->prior = NULL;
    
	do{
    	printf("******************************************************\n");
    	printf("******************************************************\n");
    	printf("*** 1.构建一个单向有序链表 2.对单向有序链表进行ADT ***\n");
    	printf("*** 3.构建一个双向有序链表 4.对双向有序链表进行ADT ***\n");
    	printf("*** 5.待添加 	           6.退出程序 		   ***\n");
    	printf("******************************************************\n");
    	printf("******************************************************\n");
    	printf("\n请输入您的选择: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("正在为您生成，请稍等片刻");
				sleep(3);
				system("cls");
				slist *head = Link_insert(single_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				
			case 3:
				printf("正在为您生成，请稍等片刻"); 
				sleep(3);
				system("cls");
				break;
				
			case 4:
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("您的选择有问题，请重新输入！"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
