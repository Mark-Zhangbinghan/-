#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//����˫������ṹ�� 
typedef struct double_Linklist{	
	int num;
	struct double_Linklist *next;
	struct double_Linklist  *prior;
}dlist;

//����.h�ļ� 
#include"..\Headers\dLinkedList.h"	

//����˵��
dlist *dLink_create(dlist *head);						//�������� 
dlist *dLink_insert(dlist *head, int pos, int num);		//������
dlist *dLink_delete(dlist *head, int pos);				//ɾ�����
dlist *dLink_reset(dlist *head, int pos, int num);		//�޸Ľ��
void dLink_check(dlist *head, int pos);				//���ҽ������ 
 

int main(){		//������ 
    int w=0;
    int x;		//���û�������Ŀѡ�� 
    int pos,num; //����λ�ú����� 
    dlist *double_head = NULL; 		//����ͷ��� 
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.����һ˫����������    ***\n"); 
		printf("*** 2.��ָ��λ����������    ***\n");
    	printf("*** 3.ɾ��ָ��λ�õ�����    ***\n");
    	printf("*** 4.�޸�ָ��λ�õ�����    ***\n");
    	printf("*** 5.����ָ��λ�õ�����    ***\n"); 
		printf("*** 6.�˳�����              ***\n"); 
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("\n����������ѡ��: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("����Ϊ�����ɣ����Ե�Ƭ��");
				sleep(3);
				system("cls");
				double_head = (dlist *)malloc(sizeof(dlist));	//����˫������ͷ��� 
    			double_head->next = NULL; 
    			double_head->prior = NULL;
				double_head = dLink_create(double_head);
				double_head->prior = NULL;
				sleep(3);
				system("cls");
				break;
				
			case 2:
				printf("��������������λ�ü�����(��:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(double_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ�����룬���Ե�Ƭ��");
				sleep(3);
				system("cls");
				double_head = dLink_insert(double_head,pos,num);
				double_head->prior = NULL;
				sleep(3);
				system("cls");
				break;
				
			case 3:
				printf("����������ɾ������λ��(��:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(double_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ��ɾ�������Ե�Ƭ��");
				sleep(3);
				system("cls"); 
				double_head = dLink_delete(double_head,pos);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				printf("�����������޸ĵ�λ�ü�����(��:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(double_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ���޸ģ����Ե�Ƭ��");
				sleep(3);
				system("cls");
				double_head = dLink_reset(double_head, pos, num);
				sleep(3);
				system("cls");				
				break; 
				
			case 5:
				printf("������������ҵ�λ�ü�����(��:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(double_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ�����ң����Ե�Ƭ��");
				sleep(3);
				system("cls");
				dLink_check(double_head, pos);
				sleep(3);
				system("cls");					
				break; 
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("����ѡ�������⣬���������룡"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
