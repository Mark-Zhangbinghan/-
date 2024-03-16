#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//构建双向链表结构体 
typedef struct Double_Linklist{
	int num;
	struct Double_Linklist *next;
	struct Double_Linklist *prior;
}dlist;

//引入.h文件 
#include"dLinkedList.h" 

int main(){		//开始实现ADT 
    int w=0;
    int x;		//设置选择数据 
    dlist *double_head = NULL;
    
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.构建一个双向有序链表  ***\n"); 
		printf("*** 2.对双向有序链表进行ADT ***\n"); 
		printf("*** 6.退出程序              ***\n"); 
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("\n请输入您的选择: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("正在为您生成，请稍等片刻"); 
				sleep(3);
				system("cls");
				double_head = (dlist *)malloc(sizeof(dlist));	//设置初始条件 
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				
			case 3:
				printf("姝ｅ湪涓烘偍鐢熸垚锛岃绋嶇瓑鐗囧埢"); 
				sleep(3);
				system("cls");
				dlist *double_head = (dlist *)malloc(sizeof(dlist));	//鏋勫缓鍙屽悜閾捐〃澶寸粨鐐�
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("您的选择有问题，请重新输入"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
