#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//构架单向链表结构体 
typedef struct Single_Linklist{	
	int num;
	struct Single_Linklist *next;
}slist;

//链接.h文件 
#include"..\Headers\sLinkedList.h"	

//函数说明
slist *sLink_create(slist *head);						//创建链表 
slist *sLink_insert(slist *head, int pos, int num);		//插入结点
slist *sLink_delete(slist *head, int pos);				//删除结点
slist *sLink_reset(slist *head, int pos, int num);		//修改结点
void sLink_check(slist *head, int pos);				//查找结点数据 
 

int main(){		//主界面 
    int w=0;
    int x;		//供用户进行项目选择 
    int pos,num; //设置位置和数字 
    slist *single_head = NULL; 		//设置头结点 
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.构建一个单向有序链表  ***\n"); 
		printf("*** 2.向指定位置增加数据    ***\n");
    	printf("*** 3.删除指定位置的数据    ***\n");
    	printf("*** 4.修改指定位置的数据    ***\n");
    	printf("*** 5.查找指定位置的数据    ***\n"); 
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
				single_head = (slist *)malloc(sizeof(slist));	//构建单向链表头结点 
    			single_head->next = NULL; 
				single_head = sLink_create(single_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				printf("请输入您想插入的位置及数字(如:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("您还未生成链表，请重新操作");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("正在为您插入，请稍等片刻");
				sleep(3);
				system("cls");
				single_head = sLink_insert(single_head,pos,num);
				sleep(3);
				system("cls");
				break;
				
			case 3:
				printf("请输入您想删除结点的位置(如:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("您还未生成链表，请重新操作");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("正在为您删除，请稍等片刻");
				sleep(3);
				system("cls"); 
				single_head = sLink_delete(single_head,pos);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				printf("请输入您想修改的位置及数字(如:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("您还未生成链表，请重新操作");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("正在为您修改，请稍等片刻");
				sleep(3);
				system("cls");
				single_head = sLink_reset(single_head, pos, num);
				sleep(3);
				system("cls");				
				break; 
				
			case 5:
				printf("请输入您想查找的位置及数字(如:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("您还未生成链表，请重新操作");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("正在为您查找，请稍等片刻");
				sleep(3);
				system("cls");
				sLink_check(single_head, pos);
				sleep(3);
				system("cls");					
				break; 
				
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
