#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
#include<time.h>
#include<windows.h>
#include"../Headers/排序算法.h"

//颜色排序
void Color_sort(int len)
{
	int i;
	int value;//中间值 
	int start=0, end=len-1; 
	FILE *ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]);
		
	int p1=start, p2=end;
	for (i = 0; i <= p2; )
    {
        if (arr[i] == 0)
        {
            value = arr[i];
            arr[i] = arr[p1];
            arr[p1] = value;
            p1++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else if (arr[i] == 2)
        {
            value = arr[i];
            arr[i] = arr[p2];
            arr[p2] = value;
            p2--;
        }
    }
	 
	 for (i=0; i<len; i++)
	 	printf("%d", arr[i]);
	 	
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
} 

//在一个无序序列中找到第K大/小的数
void Find_sort(int len, int k)
{	 
	int i,j;
	int start=0, end=len-1;
	int num;//查找到的数值 
	FILE *ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]);
		
	num = QuickFind_sort(arr, start, end, k);
	printf("第%d个数是: %d\n", k, num);
	
	printf("下面展示该数组:\n");
	for (i=0;i<len;i++)
		printf("%d ", arr[i]);	
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr); 
}

//快速查找 
int QuickFind_sort(int *arr, int start, int end, int k)
{
	if (start < end)
    {
        int i = start, j = end;//设置索引值 
        int base = arr[(start+end)/2 + 1]; // 以中间值为基准
        while (i <= j)//遍历数组，使中间值两侧数据都小于或大于基准值 
        {
            while (arr[i] < base)
                i++;
            while (arr[j] > base)
                j--;
            if (i <= j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (start + k - 1 <= j)
        {
            return QuickFind_sort(arr, start, j, k);//小于基准值，继续递归 
        }
        if (start + k - 1 >= i)
        {
            return QuickFind_sort(arr, i, end, k - (i - start));//大于基准值，继续递归 
        }
        return arr[j + 1];//返回基准值 
    }
    return arr[start];//数据太少，直接返回唯一值 
}

//随机数组赋值
void Random(int len, int max) 
{
	int i;
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	srand((unsigned)time(NULL));
	for (i=0; i<len; i++){
		arr[i]=rand()%(max+1);
	}
	FILE *ptr = fopen("DATA.txt", "w");
	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");
    	free(arr);
 		exit(1);
	}
	for (i=0; i<len; i++)
	{
		fprintf(ptr, "%d ", arr[i]);					
	}
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
	else
    	printf("文件已经成功关闭\n");
    free(arr);
}

//插入排序
void Insert_sort(int *arr, int len) 
{
	int value=0;//用来存放不在已排序区的数据 
	int i,j;
	//开始排序 
	for(i=1; i<len; i++)
	{
		value = arr[i];
		j = i-1;
		while( (j>=0) && (arr[j]>value) )
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = value;
	} 
} 

//归并排序
void Merge_sort(int *arr, int start, int end)
{
    if(start < end) //设置递归条件 
	{	
		int mid;
        mid = (start+end)/2;
        Merge_sort(arr, start, mid);
        Merge_sort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
}

//归并函数递归 
void Merge(int *A, int start, int mid, int end)
{
	int i=start, j=mid+1, k=0;//设置索引 
	int *B = (int*)malloc(sizeof(int)*(end-start+1));
	
	while (i<=mid && j<=end){
		if (A[i]<A[j])
			B[k++] = A[i++];
		else 
			B[k++] = A[j++];
	}
	
	while (i<=mid)
		B[k++] = A[i++];
	
	while (j<=end)
		B[k++] = A[j++];	
	
	for (i=start, k=0; i<=end; i++)                     
		A[i] = B[k++];
	 
	free(B); 
}

//快速排序 
void Quick_sort(int *arr, int start, int end)
{
	if (start<end)
	{
		int i = start; int j = end;//设置索引
		int base;//设置基准值
		int mid = (start+end)/2 + 1;//以中间量作为枢轴 
		base = arr[mid];
		while (i<j)
		{
			while (arr[j]>=base && i<j)//右排头开始寻找 
				j--;
			arr[i] = arr[j];//当右边找到比基准值小的数时 
			
			while (arr[i]<=base && i<j)//左排头开始寻找 
				i++;
			arr[j] = arr[i];//当左边找到比基准值大的数时 
		}
		arr[i] = base;
		Quick_sort(arr, start, i-1);
		Quick_sort(arr, i+1, end);
	}
}

//计数排序
void Count_sort(int *arr, int len) 
{
	int i,j;
	int max = arr[0],min =arr[0];
	for (i=0; i<len; i++)//先找到最大最小值来设置最佳数组 
	{
		if (arr[i]>max)
			max = arr[i];
		if (arr[i]<min)
			min = arr[i];
	}
	
	int *Count = (int*)calloc((max-min+1), sizeof(int));
	for (i=0; i<len; i++)//计算每一个数的数量 
		Count[arr[i]-min]++; 
	
	i = j = 0;
	int num;
	for (num=0; num<(max-min+1); num++)//开始将所有数转移回原数组中 
	{
		for (j=0; j<Count[num]; j++, i++)
		{
			arr[i] = min+num; 
		}	
	}
	free(Count);
}

//基数计数排序 
void CountRadix_sort(int *arr, int len, int exp)
{
	int i,j;
	int value;//用来收入基数值 
	int *Count = (int*)calloc(10, sizeof(int));
	for (i=0; i<len; i++)
	{
		value = (arr[i]/exp) % 10;
		Count[value]++; 
	}
	for (i=1; i<10; i++)
		Count[i] += Count[i-1];
		
	int *arr_T = (int*)malloc(sizeof(int)*len);
	if (arr_T == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	for (i = len - 1; i >= 0; i--) 
	{
        value = (arr[i]/exp) % 10;
        j = Count[value] - 1; 
        arr_T[j] = arr[i];      
        Count[value]--;           
    }
	
	for (i=0; i<len; i++)
	{
		arr[i] = arr_T[i];
	}
	free(Count);
	free(arr_T);
}

//基数计数排序
void Radix_sort(int *arr, int len) 
{
	int i,j;
	int exp;//设置位数 
	int max = arr[0];
	for (i=0; i<len; i++)//先找到最大最小值来设置最佳数组 
	{
		if (arr[i]>max)
			max = arr[i];
	}
	
	for (exp=1; max>=exp; exp*=10)
	{
		CountRadix_sort(arr, len, exp);
	}
} 

//查看每种排序方式在大数据量下的排序时间
void Big_count(int len)
{
	int i,j;
	int *arr;
	FILE *ptr = NULL; 
	clock_t start;//用来计算时间 
	//插入排序算法
	ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len)); 
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Insert_sort(arr, len);
				
	clock_t time_insert = clock() - start;	//计算用时
	printf("插入排序算法用时%d ms\n", time_insert);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
    //归并排序算法 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Merge_sort(arr, 0, len-1);
				
	clock_t time_merge = clock() - start;	//计算用时
	printf("归并排序算法用时%d ms\n", time_merge);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);

	//快速排序算法 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
		printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Quick_sort(arr, 0, len-1);
				
	clock_t time_quick = clock() - start;	//计算用时
	printf("快速排序算法用时%d ms\n", time_quick);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
   	//计数排序算法 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Count_sort(arr, len);
				
	clock_t time_count = clock() - start;	//计算用时
	printf("计数排序算法用时%d ms\n", time_count);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
    //基数计数排序算法 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Radix_sort(arr, len);
				
	clock_t time_radix = clock() - start;	//计算用时
	printf("基数计数排序算法用时%d ms\n", time_radix);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
} 

//查看每种排序方式在大量小数据量下的排序时间
void Small_count(int len)
{
	int i,j,k;
	int *arr;
	FILE *ptr = NULL; 
	clock_t start;//用来计算时间 
	printf("请输入您想要排序的次数(100^k): ");
	scanf("%d", &k);
	getchar();
	
	//插入排序算法
	start = clock();
	for (j=0;j<(100*k);j++){
	ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len)); 
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Insert_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_insert = clock() - start;	//计算用时
	printf("插入排序算法用时%d ms\n", time_insert);
    			
    //归并排序算法 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Merge_sort(arr, 0, len-1);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_merge = clock() - start;	//计算用时
	printf("归并排序算法用时%d ms\n", time_merge);

	//快速排序算法 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
		printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Quick_sort(arr, 0, len-1);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_quick = clock() - start;	//计算用时
	printf("快速排序算法用时%d ms\n", time_quick);
    			
   	//计数排序算法 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Count_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_count = clock() - start;	//计算用时
	printf("计数排序算法用时%d ms\n", time_count);
    			
    //基数计数排序算法
	start = clock();
	for (j=0;j<(100*k);j++){ 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("文件无法正常打开\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("内存分配失败\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Radix_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("文件无法正常关闭\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_radix = clock() - start;	//计算用时
	printf("基数计数排序算法用时%d ms\n", time_radix);
}
