// 函数声明
void Random(int len, int max);						//随机数组赋值

void Insert_sort(int *arr, int len);				//插入排序 

void Merge_sort(int *arr, int start, int end);		//归并排序 
void Merge(int *A, int start, int mid, int end);	//归并函数递归 

void Quick_sort(int *arr, int start, int end);		//快速排序 

void Count_sort(int *arr, int len);					//计数排序 

void CountRadix_sort(int *arr, int len, int exp);	//基数计数排序 
void Radix_sort(int *arr, int len);					//基数计数排序 

void Big_count(int len);							//查看每种排序方式在大数据量下的排序时间
void Small_count(int len);							//查看每种排序方式在大量小数据量下的排序时间

void Color_sort(int len);							//颜色排序

void Find_sort(int len, int k);						//在一个无序序列中找到第K大/小的数
int QuickFind_sort(int *arr, int start, int end, int k);//快速查找 
