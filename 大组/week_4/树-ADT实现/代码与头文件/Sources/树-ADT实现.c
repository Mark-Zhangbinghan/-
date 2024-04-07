#include<stdio.h> 
#include<stdlib.h>
#define size 20 
#include"..\Headers\树-ADT实现.h"

/*判断栈是否为空*/
int isEmptyStack(Stack* Link){
	return Link->top == -1;
}

/*初始化栈*/
void initStack(Stack* Link)
{
	Link->top = -1;
} 

/*入栈*/
void pushStack(Stack* Link, BiTree T)
{
	if (Link->top < size - 1) 
	{
        Link->data[++(Link->top)] = T;
    } 
}

/*出栈 */
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

// 获取栈顶元素
BiTree StackTop(Stack *Link) 
{
    if (!isEmptyStack(Link)) 
	{
        return Link->data[Link->top];
    } 
	else 
        return NULL;
}

/*三序遍历(递归)*/
	/*先序遍历二叉树 */
	void Preorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		visit(T);
		Preorder_Traverse(T->left);
		Preorder_Traverse(T->right);
	}
	/*中序遍历二叉树 */
	void Inorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		Inorder_Traverse(T->left);
		visit(T);
		Inorder_Traverse(T->right);
	}
	/*后序遍历二叉树 */
	void Postorder_Traverse(BiTree T)
	{
		if (T == NULL)	return;
	
		Postorder_Traverse(T->left);
		Postorder_Traverse(T->right);
		visit(T);
	}
	
	
/*三序遍历(非递归)*/
	/*先序遍历二叉树*/
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
	/*中序遍历二叉树 */
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
	/*后序遍历二叉树 */
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


/*输出树结点*/
void visit(BiTree T)
{
	printf("%d ", T->data);
}
	
/*创建二叉排序树*/
BiTree CreateTree()
{
    int data;
    printf("请输入您想要为根设置的值: ");
    scanf("%d", &data);
    getchar();

    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    if (T == NULL)
    {
        printf("内存分配失败\n");
        system("pause");
        exit(1);
    }
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    printf("已为您创建成功!\n");
	system("pause");
	system("cls"); 
    return T;
}

/*插入数值*/
void InsertNode(BiTree T, int data)
{
	if (T == NULL)	return;
	
	if (data < T->data)//小于结点插入 
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
	else//大于结点插入 
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
	printf("已为您插入完毕...\n");
	system("pause");
	system("cls"); 
}

/*删除数值*/
BiTree DeleteNode(BiTree T, int data)
{
	if (T == NULL)
	{
		printf("不存在该数值...");
		return T;
	}
	
	if (data < T->data)//大于结点 删除 
	{
		T->left = DeleteNode(T->left, data);	
	}
	else if (data > T->data)//小于结点 删除 
	{
		T->right = DeleteNode(T->right, data);
	}
	else//等于结点 删除 
	{
		if (T->left == NULL)//左结点为空 
        {
            BiTree p = T->right;
            free(T);
            return p;
        }
        else if (T->right == NULL)//右结点为空 
        {
            BiTree p = T->left;
            free(T);
            return p;
        }
        else//两个子结点都不为空 
        {
        	BiTree p = MinValueNode(T->right);
        	T->data = p->data;
        	T->right = DeleteNode(T->right, p->data);
		}
	}
} 
/*删除时查找最小结点*/
BiTree MinValueNode(BiTree T)
{
    BiTree current = T;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

/*查找数值*/
void SearchNode(BiTree T, int data)
{
	BiTree p = T;
	while(p != NULL)
	{
		if (p->data == data)
		{
			printf("已找到您该数值\n");
			return;
		}
		else if(data < p->data)	
			p = p->left;
		else
			p = p->right;
	}
	if (p == NULL)
	{
		printf("未找到该数值...\n");
		return; 
	}
} 
