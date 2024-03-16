#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//���ܵ�������ṹ�� 
typedef struct Single_Linklist{	
	int num;
	struct Single_Linklist *next;
}slist;

//����.h�ļ� 
#include"..\Headers\sLinkedList.h"	

//����˵��
slist *sLink_create(slist *head);						//�������� 
slist *sLink_insert(slist *head, int pos, int num);		//������
slist *sLink_delete(slist *head, int pos);				//ɾ�����
slist *sLink_reset(slist *head, int pos, int num);		//�޸Ľ��
void sLink_check(slist *head, int pos);				//���ҽ������ 
 

int main(){		//������ 
    int w=0;
    int x;		//���û�������Ŀѡ�� 
    int pos,num; //����λ�ú����� 
    slist *single_head = NULL; 		//����ͷ��� 
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.����һ��������������  ***\n"); 
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
				single_head = (slist *)malloc(sizeof(slist));	//������������ͷ��� 
    			single_head->next = NULL; 
				single_head = sLink_create(single_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				printf("��������������λ�ü�����(��:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ�����룬���Ե�Ƭ��");
				sleep(3);
				system("cls");
				single_head = sLink_insert(single_head,pos,num);
				sleep(3);
				system("cls");
				break;
				
			case 3:
				printf("����������ɾ������λ��(��:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ��ɾ�������Ե�Ƭ��");
				sleep(3);
				system("cls"); 
				single_head = sLink_delete(single_head,pos);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				printf("�����������޸ĵ�λ�ü�����(��:1 22): ");
				scanf("%d %d", &pos, &num);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ���޸ģ����Ե�Ƭ��");
				sleep(3);
				system("cls");
				single_head = sLink_reset(single_head, pos, num);
				sleep(3);
				system("cls");				
				break; 
				
			case 5:
				printf("������������ҵ�λ�ü�����(��:3): ");
				scanf("%d", &pos);
				getchar();
				system("cls");
				if(single_head==NULL){
					printf("����δ�������������²���");
					sleep(3);
					system("cls");
				 	break;
				}
				printf("����Ϊ�����ң����Ե�Ƭ��");
				sleep(3);
				system("cls");
				sLink_check(single_head, pos);
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
