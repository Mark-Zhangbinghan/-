//队列结构体定义 
typedef struct QNode
{
	int type;
	void *data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr head;
	QueuePtr tail;
	int Length;
}LinkQueue;


//初始化队列
LinkQueue initQueue(LinkQueue Link){
	Link.head = NULL;
	Link.tail = Link.head;
	Link.Length = 0;
	printf("队列已初始化成功\n");
	sleep(2);
	return Link;	
}

//判断队列是否已初始化
int IsUndefineQueue(LinkQueue Link){
	return (Link.Length==-1);
}

//判断是否为空队列
int IsEmptyQueue(LinkQueue Link){
	return  (Link.head==NULL&&Link.Length==0);
}

//查看队头元素
void GetHeadQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("队列还未初始化\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("队列为空\n");
		sleep(2);
		return;
	}
	switch (Link.head->type){
		case 1://整形 
			printf("队头元素值为%d", *((int*)Link.head->data)); 
			break;
			
		case 2://字符型 
			printf("队头元素值为%c", *((char*)Link.head->data)); 
			break;
			
		case 3://浮点型 
			printf("队头元素值为%f", *((float*)Link.head->data)); 
			break;
			
		case 4://字符串 
			printf("队头元素值为%s", *((char*)Link.head->data)); 
			break;
	}
	sleep(2);
}

//确定队列长度
void LengthQueue(LinkQueue Link){
	int count=0;
	QueuePtr p = Link.head;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	printf("队列的长度为%d\n", count);
	sleep(2);
}

//入队
LinkQueue PushQueue(LinkQueue Link, void *data, int type){
	if (IsUndefineQueue(Link)){
		system("cls");
		printf("队列还未初始化\n");
		return Link;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
// 根据数据类型分配内存并复制数据
switch (type) {
    case 1: // 整型
        p->data = malloc(sizeof(int));
        *(int *)p->data = *(int *)data;
        break;
        
    case 2: // 字符型
        p->data = malloc(sizeof(char));
        *(char *)p->data = *(char *)data;
        break;
        
    case 3: // 浮点型
        p->data = malloc(sizeof(float));
        *(float *)p->data = *(float *)data;
        break;
        
    case 4: // 字符串
        p->data = strdup((char *)data); // 使用strdup复制字符串
        break;
        
    default:
        printf("不支持的数据类型\n");
        free(p);
        return Link;
}
	p->type = type;
	p->next = NULL;
	
	if (IsEmptyQueue(Link)){
		Link.head = p;
		Link.tail = p;
	}
	else {
		Link.tail->next = p;
		Link.tail = p;
	}
	Link.Length++;
	return Link;
}

//判断队列元素的数据类型
LinkQueue TypeQueue(LinkQueue Link){
	int type;
	printf("请输入您想要入队的数据类型:\n");
	printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
	scanf("%d", &type);
	getchar();
	while (1>type || 4<type){
		system("cls");
		printf("您输入的数字出错，请重新输入: ");
		scanf("%d", &type);
		getchar();
	}
	switch (type){
		case 1:{//整形 
			int data;
			printf("请输入您想入队的数据：");
			scanf("%d", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 2:{//字符型 
			char data;
			printf("请输入您想入队的数据：");
			scanf(" %c", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 3:{//浮点型 
			float data;
			printf("请输入您想入队的数据：");
			scanf("%f", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 4:{//字符串 
			char data[21];
			printf("请输入您想入队的数据：(不超过20位)");
			scanf("%20s", data);
			getchar();
			Link = PushQueue(Link, data, type);
			break;
		}
	}
	system("cls");
	printf("已为您入队完毕");
	sleep(2); 
	return Link; 
} 

//出队
LinkQueue PopQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("队列还未初始化\n");
		sleep(2);
		return Link;
	}
	else if (IsEmptyQueue(Link)){
		printf("队列为空\n");
		sleep(2);
		return Link;
	}
	QueuePtr p = Link.head;
	Link.head = Link.head->next;
	Link.Length--;
	free(p->data);
	free(p);
	printf("已为您出列完毕");
	sleep(2);
	return Link;
} 

//销毁队列
void DestroyQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("队列还未初始化\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("队列为空\n");
		sleep(2);
		return;
	}
	QueuePtr p = Link.head, q;
	while (p!=NULL){
		q = p;
		p = p->next;
		free(q->data);
		free(q);
	}
	Link.head = NULL;
	Link.tail = NULL;
	Link.Length = -1;
	printf("队列已销毁完成");
	sleep(2);
}

//遍历队列 
void ShowQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("队列还未初始化\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("队列为空\n");
		sleep(2);
		return;
	}
	printf("遍历数列如下:\n");
	int i=1;
	QueuePtr p = Link.head;
	while(p!=NULL){
		switch (p->type){
			case 1://整形 
				printf("第%d个：%d ", i, *((int*)p->data)); 
				break;
				
			case 2://字符型 
				printf("第%d个：%c ", i, *((char*)p->data)); 
				break;
				
			case 3://浮点型 
				printf("第%d个：%f ", i, *((float*)p->data)); 
				break;
				
			case 4://字符串 
				printf("第%d个：%s ", i, p->data); 
				break;
		}
		i++;
		p = p->next;
	}
	sleep(2);
}
