#define size 20 
//�ṹ�嶨�� 
typedef struct BiTNode
{
	int data;
	struct BiTNode* left, * right;
}BiTNode, *BiTree;

//ջ�ṹ�嶨��
typedef struct Stack{
    BiTree data[size];
    int top;
}Stack;


int isEmptyStack(Stack* Link);//�ж�ջ�Ƿ�Ϊ��
void initStack(Stack* Link);//��ʼ��ջ 
void pushStack(Stack* Link, BiTree T);//��ջ
BiTree StackPop(Stack *Link);//��ջ 
BiTree StackTop(Stack *Link);// ��ȡջ��Ԫ��


//����������ݹ飩
void Preorder_Traverse(BiTree T);//������������� 
void Inorder_Traverse(BiTree T);//������������� 
void Postorder_Traverse(BiTree T);//������������� 

//�������(�ǵݹ�)
void PreorderTraversal(BiTree T);//�������������
void InorderTraversal(BiTree T);//������������� 
void PostorderTraversal(BiTree T);//������������� 

void visit(BiTree T);//���������ֵ
BiTree CreateTree();//��������������
void InsertNode(BiTree T, int data);//������ֵ 
BiTree DeleteNode(BiTree T, int data);//ɾ����ֵ
BiTree MinValueNode(BiTree T);//ɾ��ʱ������С���
void SearchNode(BiTree T, int data);//������ֵ
