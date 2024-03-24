//结构体定义
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

//判断栈空 
int EmptyStack(LinkStack Link) {
    return (Link.Stacksize == 0 && Link.top == NULL);
}

LinkStack push(LinkStack Link, int data) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (p == NULL) {
        printf("空间开辟出错");
        free(p);
        return Link;
    }
    p->data = data;
    p->next = Link.top;
    Link.top = p;
    Link.Stacksize++;
    return Link;
}

int GetTop(LinkStack Link) {
    if (EmptyStack(Link)) {
        printf("栈为空\n");
        sleep(2);
        return 0;
    }
    return Link.top->data;
}

LinkStack pop(LinkStack Link, int *data) {
    if (EmptyStack(Link)) {
        printf("栈为空\n");
        sleep(2);
        return Link;
    }
    LinkStackPtr p = Link.top;
    *data = p->data;
    Link.top = Link.top->next;
    free(p);
    Link.Stacksize--;
    return Link;
}


