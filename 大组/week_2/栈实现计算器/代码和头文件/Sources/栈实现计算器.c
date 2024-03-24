#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

typedef int Elemtype;
#include"..\Headers\栈实现计算器.h"

//函数定义
LinkStack push(LinkStack Link, int data);
int GetTop(LinkStack Link);
LinkStack pop(LinkStack Link, int *data);
int EmptyStack(LinkStack Link);
int priority(char ch);
 
 
 
int priority (char ch){//判断符号优先级 
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
	char string[30]; int i=0,num=0;//设置字符串和用来遍历字符串的变量 
	int num1,num2;//设置两个在运算中的值 
	printf("欢迎您使用\'泥人牌计算器\'\n");
	printf("请输入表达式: ");
	scanf("%s", string);
	system("cls");
	
	while( string[i]!='\0' || !EmptyStack(Symbol) ){
		num=0;
		if ( string[i]>='0' && string[i]<='9' )//数字类型 
		{
			
			if(num!=0) num *= 10;//若是数字则求出其值，并将下一项累加到num中 
			num += (int)(string[i] - '0');
			i++;
			
			if( string[i]<'0' || string[i]>'9' ) //若再下一项不是数字则将前面数压入栈中 
			{
				Number = push(Number, num);
				num = 0;
			}
		}
		
		else//字符类型 
		{
			if ( EmptyStack(Symbol) || abs(priority(string[i])) > abs(GetTop(Symbol)) || //将字符压入栈 
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
	printf("最后结果为：%d\n", GetTop(Number));
	getchar();
	return 0;
}
