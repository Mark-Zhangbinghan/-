#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h> 
#include<time.h>
#include<windows.h>
#include"../Headers/�����㷨.h"

//��ɫ����
void Color_sort(int len)
{
	int i;
	int value;//�м�ֵ 
	int start=0, end=len-1; 
	FILE *ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
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
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
} 

//��һ�������������ҵ���K��/С����
void Find_sort(int len, int k)
{	 
	int i,j;
	int start=0, end=len-1;
	int num;//���ҵ�����ֵ 
	FILE *ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]);
		
	num = QuickFind_sort(arr, start, end, k);
	printf("��%d������: %d\n", k, num);
	
	printf("����չʾ������:\n");
	for (i=0;i<len;i++)
		printf("%d ", arr[i]);	
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr); 
}

//���ٲ��� 
int QuickFind_sort(int *arr, int start, int end, int k)
{
	if (start < end)
    {
        int i = start, j = end;//��������ֵ 
        int base = arr[(start+end)/2 + 1]; // ���м�ֵΪ��׼
        while (i <= j)//�������飬ʹ�м�ֵ�������ݶ�С�ڻ���ڻ�׼ֵ 
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
            return QuickFind_sort(arr, start, j, k);//С�ڻ�׼ֵ�������ݹ� 
        }
        if (start + k - 1 >= i)
        {
            return QuickFind_sort(arr, i, end, k - (i - start));//���ڻ�׼ֵ�������ݹ� 
        }
        return arr[j + 1];//���ػ�׼ֵ 
    }
    return arr[start];//����̫�٣�ֱ�ӷ���Ψһֵ 
}

//������鸳ֵ
void Random(int len, int max) 
{
	int i;
	int *arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	}
	srand((unsigned)time(NULL));
	for (i=0; i<len; i++){
		arr[i]=rand()%(max+1);
	}
	FILE *ptr = fopen("DATA.txt", "w");
	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");
    	free(arr);
 		exit(1);
	}
	for (i=0; i<len; i++)
	{
		fprintf(ptr, "%d ", arr[i]);					
	}
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
	else
    	printf("�ļ��Ѿ��ɹ��ر�\n");
    free(arr);
}

//��������
void Insert_sort(int *arr, int len) 
{
	int value=0;//������Ų����������������� 
	int i,j;
	//��ʼ���� 
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

//�鲢����
void Merge_sort(int *arr, int start, int end)
{
    if(start < end) //���õݹ����� 
	{	
		int mid;
        mid = (start+end)/2;
        Merge_sort(arr, start, mid);
        Merge_sort(arr, mid+1, end);
        Merge(arr, start, mid, end);
    }
}

//�鲢�����ݹ� 
void Merge(int *A, int start, int mid, int end)
{
	int i=start, j=mid+1, k=0;//�������� 
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

//�������� 
void Quick_sort(int *arr, int start, int end)
{
	if (start<end)
	{
		int i = start; int j = end;//��������
		int base;//���û�׼ֵ
		int mid = (start+end)/2 + 1;//���м�����Ϊ���� 
		base = arr[mid];
		while (i<j)
		{
			while (arr[j]>=base && i<j)//����ͷ��ʼѰ�� 
				j--;
			arr[i] = arr[j];//���ұ��ҵ��Ȼ�׼ֵС����ʱ 
			
			while (arr[i]<=base && i<j)//����ͷ��ʼѰ�� 
				i++;
			arr[j] = arr[i];//������ҵ��Ȼ�׼ֵ�����ʱ 
		}
		arr[i] = base;
		Quick_sort(arr, start, i-1);
		Quick_sort(arr, i+1, end);
	}
}

//��������
void Count_sort(int *arr, int len) 
{
	int i,j;
	int max = arr[0],min =arr[0];
	for (i=0; i<len; i++)//���ҵ������Сֵ������������� 
	{
		if (arr[i]>max)
			max = arr[i];
		if (arr[i]<min)
			min = arr[i];
	}
	
	int *Count = (int*)calloc((max-min+1), sizeof(int));
	for (i=0; i<len; i++)//����ÿһ���������� 
		Count[arr[i]-min]++; 
	
	i = j = 0;
	int num;
	for (num=0; num<(max-min+1); num++)//��ʼ��������ת�ƻ�ԭ������ 
	{
		for (j=0; j<Count[num]; j++, i++)
		{
			arr[i] = min+num; 
		}	
	}
	free(Count);
}

//������������ 
void CountRadix_sort(int *arr, int len, int exp)
{
	int i,j;
	int value;//�����������ֵ 
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
    	printf("�ڴ����ʧ��\n");
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

//������������
void Radix_sort(int *arr, int len) 
{
	int i,j;
	int exp;//����λ�� 
	int max = arr[0];
	for (i=0; i<len; i++)//���ҵ������Сֵ������������� 
	{
		if (arr[i]>max)
			max = arr[i];
	}
	
	for (exp=1; max>=exp; exp*=10)
	{
		CountRadix_sort(arr, len, exp);
	}
} 

//�鿴ÿ������ʽ�ڴ��������µ�����ʱ��
void Big_count(int len)
{
	int i,j;
	int *arr;
	FILE *ptr = NULL; 
	clock_t start;//��������ʱ�� 
	//���������㷨
	ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len)); 
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Insert_sort(arr, len);
				
	clock_t time_insert = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_insert);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
    //�鲢�����㷨 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Merge_sort(arr, 0, len-1);
				
	clock_t time_merge = clock() - start;	//������ʱ
	printf("�鲢�����㷨��ʱ%d ms\n", time_merge);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);

	//���������㷨 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
		printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Quick_sort(arr, 0, len-1);
				
	clock_t time_quick = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_quick);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
   	//���������㷨 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Count_sort(arr, len);
				
	clock_t time_count = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_count);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
    			
    //�������������㷨 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	start = clock();
	Radix_sort(arr, len);
				
	clock_t time_radix = clock() - start;	//������ʱ
	printf("�������������㷨��ʱ%d ms\n", time_radix);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
} 

//�鿴ÿ������ʽ�ڴ���С�������µ�����ʱ��
void Small_count(int len)
{
	int i,j,k;
	int *arr;
	FILE *ptr = NULL; 
	clock_t start;//��������ʱ�� 
	printf("����������Ҫ����Ĵ���(100^k): ");
	scanf("%d", &k);
	getchar();
	
	//���������㷨
	start = clock();
	for (j=0;j<(100*k);j++){
	ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len)); 
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	}
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Insert_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_insert = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_insert);
    			
    //�鲢�����㷨 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Merge_sort(arr, 0, len-1);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_merge = clock() - start;	//������ʱ
	printf("�鲢�����㷨��ʱ%d ms\n", time_merge);

	//���������㷨 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
		printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Quick_sort(arr, 0, len-1);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_quick = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_quick);
    			
   	//���������㷨 
	start = clock();
	for (j=0;j<(100*k);j++){
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Count_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_count = clock() - start;	//������ʱ
	printf("���������㷨��ʱ%d ms\n", time_count);
    			
    //�������������㷨
	start = clock();
	for (j=0;j<(100*k);j++){ 
    ptr = fopen("DATA.txt", "r");
 	if(ptr == NULL) 
	{
    	printf("�ļ��޷�������\n");     				
    	exit(1);
	}
	arr = (int*)malloc(sizeof(int)*(len));
	if (arr == NULL)
	{
    	printf("�ڴ����ʧ��\n");
    	exit(1);
	} 
	for (i=0;i<len;i++)
		fscanf(ptr, "%d", &arr[i]); 
	Radix_sort(arr, len);
	if(fclose(ptr)!=0) 
	{
		printf("�ļ��޷������ر�\n");
		free(arr); 
		exit(1); 
	} 
    free(arr);
	}
	clock_t time_radix = clock() - start;	//������ʱ
	printf("�������������㷨��ʱ%d ms\n", time_radix);
}
