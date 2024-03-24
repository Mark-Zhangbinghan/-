#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef int Elemtype;
#include"..\Headers\链栈实现.h"

//函数定义
LinkStack initStack(LinkStack Link);//初始化栈
int undefineStack(LinkStack Link);//判断栈是否还未初始化
int isEmptyStack(LinkStack Link);//判断栈是否为空
void getTopStack(LinkStack Link, Elemtype *data);//得到栈顶元素
void ClearStack(LinkStack Link);//清空栈
LinkStack destoryStack(LinkStack Link);//销毁栈
void stackLength(LinkStack Link);//检测栈的长度 
LinkStack pushStack(LinkStack Link, Elemtype data);//入栈
LinkStack popStack(LinkStack Link, Elemtype *data);//出栈 
void PrintStack(LinkStack Link);//打印栈 


int main(){
	Elemtype data;
	LinkStack Link; Link.Stacksize = -1;
	do{
		printf("*************************\n");
		printf("***  1. 初始化栈      ***\n");
		printf("***  2. 入栈          ***\n");
		printf("***  3. 出栈          ***\n");
		printf("***  4. 得到栈顶元素  ***\n");
		printf("***  5. 检测栈的长度  ***\n");
		printf("***  6. 清空栈        ***\n");
		printf("***  7. 销毁栈        ***\n");
		printf("***  8. 打印栈        ***\n");
		printf("***  0. 退出程序      ***\n");
		printf("*************************\n");
		int choice;
		printf("请输入您想选择的选项: ");
		scanf("%d", &choice);
		getchar();
		system("cls");
		
//开始执行程序 
		switch (choice){
			case 1://初始化 
				printf("正在为您初始化...");
				sleep(2);
				system("cls");
				Link = initStack(Link);
				system("cls");
				break;
				
			case 2://入栈 
				printf("请输入您想入栈的数据: ");
				scanf("%d", &data);
				Link = pushStack(Link, data);
				system("cls");
				break;
				
			case 3://出栈 
				printf("正在为您进行出栈操作...");
				Link =  popStack(Link, &data);
				printf("出栈的数据值为: %d", data);
				system("cls");
				break;
				
		 	case 4://栈顶元素 
		 		getTopStack(Link, &data);
		 		printf("栈顶的元素为: %d", data);
		 		sleep(2);
		 		system("cls");
		 		break;
		 		
		 	case 5://栈长 
		 		stackLength(Link);
		 		system("cls");
		 		break;
		 		
		 	case 6://清空栈 
		 		printf("真在为您清空栈...");
		 		ClearStack(Link);
		 		system("cls");
		 		break;
		 		
		 	case 7://销毁栈 
		 		printf("正在为您销毁栈...");
				Link = destoryStack(Link);
				system("cls");
				break;
				
			case 8://栈展示 
				printf("栈中元素如下:\n");
				PrintStack(Link);
				system("cls");
				break;
				
			case 0://退出程序 
				exit(0);
			
			default:
				printf("您的输入有误，请重新输入");
				sleep(2);
				system("cls");
				break;
		}
	} while(1);
	return 0;
}
