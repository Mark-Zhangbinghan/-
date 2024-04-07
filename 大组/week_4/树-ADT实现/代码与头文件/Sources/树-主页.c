#include<stdio.h>
#include<stdlib.h>
#define size 20 
#include"..\Headers\树-ADT实现.h"


int main(){
	int choice, data;
	BiTree T;
	int make = 0;//判断是否已建立二叉树 
	do
	{
		printf("****************************\n");
		printf("***  1. 创建二叉排序树   ***\n");
		printf("***  2. 插入数值         ***\n");
		printf("***  3. 删除数值         ***\n");
		printf("***  4. 查找数值         ***\n");
		printf("***  5. 遍历二叉树       ***\n");
		printf("***  0. 退出程序         ***\n");
		printf("****************************\n");
		
		printf("请输入您的选择: ");
		scanf("%d", &choice); 
		getchar();
		system("cls");
		
		switch (choice)
		{
			//创建二叉排序树
			case 1:
				T = CreateTree();
				make = 1;
				break;
				
			//插入数值 
			case 2:
				if (make == 0)
				{
					printf("您还没有创建二叉树！！！\n");
					system("pause");
					system("cls");
					break;
				}
				printf("请输入您想插入的数值: ");
				scanf("%d", &data);
				getchar(); 
				InsertNode(T, data);
				break;
				
			//删除数值 
			case 3:
				if (make == 0)
				{
					printf("您还没有创建二叉树！！！\n");
					system("pause");
					system("cls");
					break;
				}
				printf("请输入您想删除的数值: ");
				scanf("%d", &data);
				getchar(); 
				InsertNode(T, data);
				printf("已为您删除完毕...\n");
				system("pause");
				system("cls");
				break;
				
			//查找数值 
			case 4:
				if (make == 0)
				{
					printf("您还没有创建二叉树！！！\n");
					system("pause");
					system("cls");
					break;
				}
				printf("请输入您想查找的数值: ");
				scanf("%d", &data);
				getchar(); 
				SearchNode(T, data);
				system("pause");
				system("cls");
				break;
			
			//遍历二叉树
			case 5:
				 if (make == 0)
				{
					printf("您还没有创建二叉树！！！\n");
					system("pause");
					system("cls");
					break;
				}
				//递归 
				printf("递归先序遍历二叉树:\n"); 
				Preorder_Traverse(T); 
				printf("\n递归中序遍历二叉树:\n"); 
				Inorder_Traverse(T); 
				printf("\n递归后序遍历二叉树:\n"); 
 				Postorder_Traverse(T);
 				//非递归 
				printf("\n非递归先序遍历二叉树:\n"); 
				PreorderTraversal(T); 
				printf("\n非递归中序遍历二叉树:\n"); 
				InorderTraversal(T); 
				printf("\n非递归后序遍历二叉树:\n"); 
 				PostorderTraversal(T);
 				printf("\n"); 
 				system("pause");
				system("cls");
				break;
 				
 			case 0:
 				exit(1);
 				
 			default:
 				printf("您的输入有误，请再次输入");
 				system("pause");
				system("cls");
		}
	}while(1); 
	return 0;
} 
