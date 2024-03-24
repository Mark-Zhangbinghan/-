#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

typedef int Elemtype;
#include"..\Headers\ջʵ�ּ�����.h"

//��������
LinkStack push(LinkStack Link, int data);
int GetTop(LinkStack Link);
LinkStack pop(LinkStack Link, int *data);
int EmptyStack(LinkStack Link);
int priority(char ch);
 
 
 
int priority (char ch){//�жϷ������ȼ� 
	switch (ch){
		case '(':
			return 4;
			
		case '*':
			return 3;
			
		case '/':
			return -3;
		
		case '+':
			return 2;
			
		case '-':
			return -2;
			
		case ')':
			return 1;
			
		default:
			return 0;
	}
}


int main(){
	LinkStack Number; Number.Stacksize=0 ; Number.top=NULL;
	LinkStack Symbol; Symbol.Stacksize=0 ; Symbol.top=NULL;
	char string[30]; int i=0,num=0;//�����ַ��������������ַ����ı��� 
	int num1,num2;//���������������е�ֵ 
	printf("��ӭ��ʹ��\'�����Ƽ�����\'\n");
	printf("��������ʽ: ");
	scanf("%s", string);
	system("cls");
	
	while( string[i]!='\0' || !EmptyStack(Symbol) ){
		num=0;
		if ( string[i]>='0' && string[i]<='9' )//�������� 
		{
			
			if(num!=0) num *= 10;//���������������ֵ��������һ���ۼӵ�num�� 
			num += (int)(string[i] - '0');
			i++;
			
			if( string[i]<'0' || string[i]>'9' ) //������һ���������ǰ����ѹ��ջ�� 
			{
				Number = push(Number, num);
				num = 0;
			}
		}
		
		else//�ַ����� 
		{
			if ( EmptyStack(Symbol) || abs(priority(string[i])) > abs(GetTop(Symbol)) || //���ַ�ѹ��ջ 
				(abs(GetTop(Symbol)) == 4) && (abs(string[i]) != 1) ) 
			{
			    	Symbol = push(Symbol, priority(string[i]));
					i++;
					continue; 
			}
			
			if ( (abs(GetTop(Symbol))== 4) && abs(priority(string[i]))==1 )
			{
				Symbol = pop(Symbol, &num);
				num = 0;
				i++;
				continue;
			}
			
			if ( abs(priority(string[i])) <= abs(GetTop(Symbol)) || ((string[i] == ')') && abs(GetTop(Symbol)) != 1) ||
				string[i] == '\0' && EmptyStack(Symbol) != 1) 
			{
				Symbol = pop(Symbol, &num);
				switch(num)
				{
					case 2:
						Number = pop(Number, &num1);
						Number = pop(Number, &num2);
						Number = push(Number, num1 + num2);
						break;
					case -2:
						Number = pop(Number, &num1);
						Number = pop(Number, &num2);
						Number = push(Number, num2 - num1);
						break;
					case 3:
						Number = pop(Number, &num1);
						Number = pop(Number, &num2);
						Number = push(Number, num1 * num2);
						break;
					case -3:
						Number = pop(Number, &num1);
						Number = pop(Number, &num2);
						Number = push(Number, num2 / num1);
						break;
				}
			}
		}
	}
	printf("�����Ϊ��%d\n", GetTop(Number));
	getchar();
	return 0;
}
