//��ʽ�ṹ�嶨��
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


//����ջ
LinkStack destoryStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return Link;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
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
	printf("����ջ���������\n");
	sleep(2);
	return Link;
}

//��ʼ��ջ
LinkStack initStack(LinkStack Link){
	Link = destoryStack(Link);
	Link.top = NULL;
	Link.Stacksize = 0;
	printf("ջ�ѳɹ���ʼ��\n");
	sleep(2);
	return Link;
} 

//�ж�ջ�Ƿ�δ��ʼ��
int undefineStack(LinkStack Link){
	return (Link.Stacksize==-1);
}

//�ж�ջ�Ƿ�Ϊ��
int isEmptyStack(LinkStack Link){
	return (Link.top==NULL && Link.Stacksize==0);
}

//�õ�ջ��Ԫ��
void getTopStack(LinkStack Link, Elemtype *data){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
		sleep(2);
		return;
	}
	*data = Link.top->data;
}

//���ջ
void ClearStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
		sleep(2);
		return;
	}
	LinkStackPtr p = Link.top;
	while(p!=NULL){
		p->data = 0;
		p = p->next;
	}
	printf("���ջ���������\n");
	sleep(2);
	return;
}

//���ջ�ĳ��� 
void stackLength(LinkStack Link){
	int count=0;
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
		sleep(2);
		return;
	}
	LinkStackPtr p = Link.top;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	printf("ջ�ĳ���Ϊ%d\n", count);
	sleep(2);
	return;
}

//��ջ
LinkStack pushStack(LinkStack Link, Elemtype data){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return Link;
	}
	LinkStackPtr p = (LinkStackPtr) malloc(sizeof(StackNode));
	p->data = data;
	p->next = Link.top;
	Link.top = p;
	Link.Stacksize++;
	printf("��ջ���������\n");
	sleep(2);
	return Link;
}

//��ջ 
LinkStack popStack(LinkStack Link, Elemtype *data){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return Link;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
		sleep(2);
		return Link;
	}
	LinkStackPtr p = Link.top;
	*data = Link.top->data;
	Link.top = Link.top->next;
	Link.Stacksize--;
	free(p);
	printf("��ջ���������\n");
	sleep(2);
	return Link;
}

//��ӡջ 
void PrintStack(LinkStack Link){
	if(undefineStack(Link)){
		printf("ջ��δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (isEmptyStack(Link)){
		printf("ջΪ��\n");
		sleep(2);
		return;
	}
	int i;
	LinkStackPtr p = Link.top;
	for (i=Link.Stacksize; i>=1; i--){
		printf("��%d��:%d  ", i,p->data);
		p = p->next;
	}
	sleep(2);
}
