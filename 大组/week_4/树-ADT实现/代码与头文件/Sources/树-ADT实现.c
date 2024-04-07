#include<stdio.h> 
#include<stdlib.h>
#define size 20 
#include"..\Headers\��-ADTʵ��.h"

/*�ж�ջ�Ƿ�Ϊ��*/
int isEmptyStack(Stack* Link){
	return Link->top == -1;
}

/*��ʼ��ջ*/
void initStack(Stack* Link)
{
	Link->top = -1;
} 

/*��ջ*/
void pushStack(Stack* Link, BiTree T)
{
	if (Link->top < size - 1) 
	{
        Link->data[++(Link->top)] = T;
    } 
}

/*��ջ */
BiTree StackPop(Stack *Link) 
{
	int data;
    if (!isEmptyStack(Link)) 
	{
        return Link->data[(Link->top)--];
    } 
	else 
		return NULL;
}

// ��ȡջ��Ԫ��
BiTree StackTop(Stack *Link) 
{
    if (!isEmptyStack(Link)) 
	{
        return Link->data[Link->top];
    } 
	else 
        return NULL;
}

/*�������(�ݹ�)*/
	/*������������� */
	void Preorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		visit(T);
		Preorder_Traverse(T->left);
		Preorder_Traverse(T->right);
	}
	/*������������� */
	void Inorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		Inorder_Traverse(T->left);
		visit(T);
		Inorder_Traverse(T->right);
	}
	/*������������� */
	void Postorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		Postorder_Traverse(T->left);
		Postorder_Traverse(T->right);
		visit(T);
	}
	
	
/*�������(�ǵݹ�)*/
	/*�������������*/
	void PreorderTraversal(BiTree T)
	{
    	if (T == NULL)
        	return;
    
    	Stack Link;
    	BiTree p = T;
    	initStack(&Link);
    	while (p != NULL || !isEmptyStack(&Link))
    	{
        	while (p != NULL)
        	{
            	printf("%d ", p->data);
            	if (p->right != NULL)
            	{
                	pushStack(&Link, p->right);
            	}
            	p = p->left;
        	}
        	while (!isEmptyStack(&Link))
        	{
            	p = StackPop(&Link);
        	}
    	}
	} 
	/*������������� */
	void InorderTraversal(BiTree T)
	{
    	if (T == NULL)
    	    return;
    
    	Stack Link;
    	initStack(&Link);
    	BiTree p = T;
    	while (p != NULL || !isEmptyStack(&Link))
    	{
     	   while (p != NULL)
    	    {
  	          pushStack(&Link, p);     
  	          p = p->left;           
   	     	}

    	    if (!isEmptyStack(&Link))
    	    {
    	        p = StackPop(&Link);     
    	        printf("%d ", p->data);  
    	        p = p->right;             
    	    }
    	}
	}
	/*������������� */
	void PostorderTraversal(BiTree T)
	{
   		if (T == NULL)
    	    return;

    	Stack Link;
    	initStack(&Link);
    	BiTree p = T;
    	BiTree lastVisited = NULL;
	
    	while (p != NULL || !isEmptyStack(&Link))
    	{
    	    while (p != NULL)
    	    {
     	       pushStack(&Link, p);
    	        p = p->left;
    	    }
    	    BiTree topNode = StackTop(&Link);
    	    if (topNode->right == NULL || topNode->right == lastVisited)
    	    {
    	        printf("%d ", topNode->data);
     	       lastVisited = StackPop(&Link);
    	    }
    	    else
   	     	{
    	        p = topNode->right;
    	    }
    	}
	}


/*��������*/
void visit(BiTree T)
{
	printf("%d ", T->data);
}
	
/*��������������*/
BiTree CreateTree()
{
    int data;
    printf("����������ҪΪ�����õ�ֵ: ");
    scanf("%d", &data);
    getchar();

    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    if (T == NULL)
    {
        printf("�ڴ����ʧ��\n");
        system("pause");
        exit(1);
    }
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    printf("��Ϊ�������ɹ�!\n");
	system("pause");
	system("cls"); 
    return T;
}

/*������ֵ*/
void InsertNode(BiTree T, int data)
{
	if (T == NULL)	return;
	
	if (data < T->data)//С�ڽ����� 
	{
		if (T->left == NULL)
		{
			T->left = (BiTree)malloc(sizeof(BiTNode));
			T->left->data = data;
			T->left->left = NULL;
			T->left->right = NULL;
		}
		else
		{
			InsertNode(T->left, data);
		}
	}
	else//���ڽ����� 
	{
		if (T->right == NULL)
		{
			T->right = (BiTree)malloc(sizeof(BiTNode));
			T->right->data = data;
			T->right->left = NULL;
			T->right->right = NULL;
		}
		else
		{
			InsertNode(T->right, data);
		}
	}
	printf("��Ϊ���������...\n");
	system("pause");
	system("cls"); 
}

/*ɾ����ֵ*/
BiTree DeleteNode(BiTree T, int data)
{
	if (T == NULL)
	{
		printf("�����ڸ���ֵ...");
		return T;
	}
	
	if (data < T->data)//���ڽ�� ɾ�� 
	{
		T->left = DeleteNode(T->left, data);	
	}
	else if (data > T->data)//С�ڽ�� ɾ�� 
	{
		T->right = DeleteNode(T->right, data);
	}
	else//���ڽ�� ɾ�� 
	{
		if (T->left == NULL)//����Ϊ�� 
        {
            BiTree p = T->right;
            free(T);
            return p;
        }
        else if (T->right == NULL)//�ҽ��Ϊ�� 
        {
            BiTree p = T->left;
            free(T);
            return p;
        }
        else//�����ӽ�㶼��Ϊ�� 
        {
        	BiTree p = MinValueNode(T->right);
        	T->data = p->data;
        	T->right = DeleteNode(T->right, p->data);
		}
	}
} 
/*ɾ��ʱ������С���*/
BiTree MinValueNode(BiTree T)
{
    BiTree current = T;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/*������ֵ*/
void SearchNode(BiTree T, int data)
{
	BiTree p = T;
	while(p != NULL)
	{
		if (p->data == data)
		{
			printf("���ҵ�������ֵ\n");
			return;
		}
		else if(data < p->data)	
			p = p->left;
		else
			p = p->right;
	}
	if (p == NULL)
	{
		printf("δ�ҵ�����ֵ...\n");
		return; 
	}
} 
