//链式结构体定义
typedef struct StackNode
{
	Elemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;//栈顶指针 
	int Stacksize;//目前栈中元素个数 
}LinkStack;


//销毁栈
LinkStack destoryStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return Link;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return Link;
	}
	LinkStackPtr p = Link.top, q;
	while(p!=NULL){
		q = p;
		p = p->next;
		free(q);
	}
	Link.top = NULL;
	Link.Stacksize = -1;
	printf("销毁栈操作已完成\n");
	sleep(2);
	return Link;
}

//初始化栈
LinkStack initStack(LinkStack Link){
	Link = destoryStack(Link);
	Link.top = NULL;
	Link.Stacksize = 0;
	printf("栈已成功初始化\n");
	sleep(2);
	return Link;
} 

//判断栈是否还未初始化
int undefineStack(LinkStack Link){
	return (Link.Stacksize==-1);
}

//判断栈是否为空
int isEmptyStack(LinkStack Link){
	return (Link.top==NULL && Link.Stacksize==0);
}

//得到栈顶元素
void getTopStack(LinkStack Link, Elemtype *data){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return;
	}
	*data = Link.top->data;
}

//清空栈
void ClearStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return;
	}
	LinkStackPtr p = Link.top;
	while(p!=NULL){
		p->data = 0;
		p = p->next;
	}
	printf("清空栈操作已完成\n");
	sleep(2);
	return;
}

//检测栈的长度 
void stackLength(LinkStack Link){
	int count=0;
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return;
	}
	LinkStackPtr p = Link.top;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	printf("栈的长度为%d\n", count);
	sleep(2);
	return;
}

//入栈
LinkStack pushStack(LinkStack Link, Elemtype data){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return Link;
	}
	LinkStackPtr p = (LinkStackPtr) malloc(sizeof(StackNode));
	p->data = data;
	p->next = Link.top;
	Link.top = p;
	Link.Stacksize++;
	printf("入栈操作已完成\n");
	sleep(2);
	return Link;
}

//出栈 
LinkStack popStack(LinkStack Link, Elemtype *data){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return Link;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return Link;
	}
	LinkStackPtr p = Link.top;
	*data = Link.top->data;
	Link.top = Link.top->next;
	Link.Stacksize--;
	free(p);
	printf("出栈操作已完成\n");
	sleep(2);
	return Link;
}

//打印栈 
void PrintStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("栈还未初始化\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("栈为空\n");
		sleep(2);
		return;
	}
	int i;
	LinkStackPtr p = Link.top;
	for (i=Link.Stacksize; i>=1; i--){
		printf("第%d项:%d  ", i,p->data);
		p = p->next;
	}
	sleep(2);
}
