#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include"..\Headers\泛型队列.h"

//函数说明
LinkQueue initQueue(LinkQueue Link);//初始化队列
int IsUndefineQueue(LinkQueue Link);//判断队列是否已初始化 
int IsEmptyQueue(LinkQueue Link);//判断是否为空队列
void GetHeadQueue(LinkQueue Link);//查看队头元素
void LengthQueue(LinkQueue Link);//确定队列长度
LinkQueue PushQueue(LinkQueue Link, void *data, int type);//入队
LinkQueue TypeQueue(LinkQueue Link);//判断队列元素的数据类型
LinkQueue PopQueue(LinkQueue Link);//出队
void DestroyQueue(LinkQueue Link);//销毁队列
void ShowQueue(LinkQueue Link);//遍历队列 

int main(){
	int choice;
	LinkQueue Link; Link.Length=-1;
do{
	printf("*************************\n");
	printf("***  1. 初始化队列    ***\n");
	printf("***  2. 入队          ***\n");
	printf("***  3. 出队          ***\n");
	printf("***  4. 得到队头元素  ***\n");
	printf("***  5. 检测队列的长度***\n");
	printf("***  6. 销毁队列      ***\n");
	printf("***  7. 打印队列      ***\n");
	printf("***  0. 退出程序      ***\n");
	printf("*************************\n");
	printf("请输入您的选择: ");
	
	scanf("%d", &choice);
	getchar();
	system("cls");
	switch (choice){
		case 1://初始化 
			printf("正在为您的队列进行初始化...\n");
			Link = initQueue(Link);
			system("cls");
			break;
			
		case 2://入队 
			Link = TypeQueue(Link);
			system("cls");
			break;
			
		case 3://出队
			printf("正在为您出队...\n");
			Link = PopQueue(Link);
			system("cls");
			break;
			 
		case 4://查看队头元素
			GetHeadQueue(Link);
			system("cls");
			break;
			
		case 5://检测队列长度
			LengthQueue(Link);
			system("cls");
			break;
			
		case 6://销毁队列
			DestroyQueue(Link);
			system("cls");
			break;
			
		case 7://打印队列
			ShowQueue(Link);
			system("cls");
			break;
			
		case 0://退出程序
			exit(1);
			
		default:
			printf("您的输入有误，请重新输入");
			sleep(2);
			system("cls"); 
	}
}while(1);
	return 0;
}
