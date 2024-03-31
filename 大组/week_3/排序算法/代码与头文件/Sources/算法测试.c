#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
#include<time.h>
#include<windows.h>
#include"..\Headers\排序算法.h"

int main()
{
	int i,j;
	int len;//数组长度 
	int max=0;//数组元素取值范围 
	int choice, make=0;//用户做出的选择
	int *arr;//设置随机数组 
	int k;//用来用户查看排后的第 k 位数字 
	FILE *ptr = NULL; 
	int time_insert, time_merge, time_quick, time_count, time_radix;
	do
	{
		printf("********************************************\n");
		printf("***  1. 创建随机数组                     ***\n");
		printf("***  2. 查看创建的数组                   ***\n");
		printf("***  3. 查看大数据量下的排序时间         ***\n");
		printf("***  4. 查看大量小数据下的排序时间       ***\n");
		printf("***  5. 颜色排序                         ***\n");
		printf("***  6. 在一个无序序列中找到第K大/小的数 ***\n");
		printf("***  0. 退出程序                         ***\n");
		printf("********************************************\n");
		
		printf("请输入您的选择: ");
		scanf("%d", &choice); 
		getchar();
		system("cls");
		
		switch (choice)
		{
			case 1://创建随机数组 
				make = 1;
				printf("请输入您想要随机数组的长: ");
				scanf("%d", &len);
				getchar();
				printf("请输入您想要随机数组的范围(最大值): ");
				scanf("%d", &max);
				getchar();
				system("cls");
				Random(len, max);
    			system("pause");
    			system("cls");
				break;
				
				
			case 2://查看随机生成的数组 
				if (!make)
				{
					printf("请先创建数组\n");
					system("pause");
					system("cls");
					break;
				}
				ptr = fopen("DATA.txt", "r");
 				if(ptr == NULL) 
				{
    				printf("文件无法正常打开\n");			
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
					printf("文件无法正常关闭\n"); 
					exit(1); 
				} 
				else
    				printf("文件已经成功关闭\n");
    			free(arr);
    			system("pause");
    			system("cls");
				break; 	
			
			
			case 3://查看每种排序方式在大数据量下的排序时间
				if (!make)
				{
					printf("请先创建数组\n");
					system("pause");
					system("cls");
					break;
				}
				Big_count(len);
				system("pause");
				system("cls");
				break;
			
			case 4://查看每种排序方式在大量小数据量下的排序时间
				if (!make)
				{
					printf("请先创建数组\n");
					system("pause");
					system("cls");
					break;
				}
				if (len>100)
				{
					printf("您创建的数组过大，请重新创建\n");
					system("pause");
					system("cls");
					break;
				}				
				Small_count(len);
				system("pause");
				system("cls");
				break;	
				
			case 5://颜色排序
				if (!make)	
				{
					printf("请先创建数组\n");
					system("pause");
					system("cls");
					break;
				}
				if (max>2)
				{
					printf("您创建的数组元素大于2，请重新创建并将数组元素最大值设为2\n");
					system("pause");
					system("cls");
					break;
				}
				Color_sort(len);
				system("pause");
				system("cls");
				break;
				
			case 6://在一个无序序列中找到第K大/小的数
				if (!make)	
				{
					printf("请先创建数组\n");
					system("pause");
					system("cls");
					break;
				}
				printf("请输入您想要查找第几个数: ");
				scanf("%d", &k);
				getchar();
				Find_sort(len, k);
				system("pause");
				system("cls");
				break;
									
			case 0://退出程序		
				exit(1); 
			
			default:
				printf("您输入的数据有误，请重新输入...");
				system("pause");
				system("cls"); 
		}
	}while(1); 
	return 0;
}
