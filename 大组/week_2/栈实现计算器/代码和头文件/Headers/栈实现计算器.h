//�ṹ�嶨��
typedef struct StackNode
{
	Elemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;//ջ��ָ�� 
	int Stacksize;//Ŀǰջ��Ԫ�ظ��� 
}LinkStack;

//�ж�ջ�� 
int EmptyStack(LinkStack Link) {
    return (Link.Stacksize == 0 && Link.top == NULL);
}

LinkStack push(LinkStack Link, int data) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (p == NULL) {
        printf("�ռ俪�ٳ���");
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
        printf("ջΪ��\n");
        sleep(2);
        return 0;
    }
    return Link.top->data;
}

LinkStack pop(LinkStack Link, int *data) {
    if (EmptyStack(Link)) {
        printf("ջΪ��\n");
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


