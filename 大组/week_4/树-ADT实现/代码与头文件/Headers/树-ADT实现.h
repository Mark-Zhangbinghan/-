#define size 20 
//结构体定义 
typedef struct BiTNode
{
	int data;
	struct BiTNode* left, * right;
}BiTNode, *BiTree;

//栈结构体定义
typedef struct Stack{
    BiTree data[size];
    int top;
}Stack;


int isEmptyStack(Stack* Link);//判断栈是否为空
void initStack(Stack* Link);//初始化栈 
void pushStack(Stack* Link, BiTree T);//入栈
BiTree StackPop(Stack *Link);//出栈 
BiTree StackTop(Stack *Link);// 获取栈顶元素


//三序遍历（递归）
void Preorder_Traverse(BiTree T);//先序遍历二叉树 
void Inorder_Traverse(BiTree T);//中序遍历二叉树 
void Postorder_Traverse(BiTree T);//后序遍历二叉树 

//三序遍历(非递归)
void PreorderTraversal(BiTree T);//先序遍历二叉树
void InorderTraversal(BiTree T);//中序遍历二叉树 
void PostorderTraversal(BiTree T);//后序遍历二叉树 

void visit(BiTree T);//输出树结点的值
BiTree CreateTree();//创建二叉排序树
void InsertNode(BiTree T, int data);//插入数值 
BiTree DeleteNode(BiTree T, int data);//删除数值
BiTree MinValueNode(BiTree T);//删除时查找最小结点
void SearchNode(BiTree T, int data);//查找数值
