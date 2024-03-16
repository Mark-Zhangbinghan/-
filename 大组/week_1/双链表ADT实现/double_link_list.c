#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//¹¹½¨Ë«ÏòÁ´±í½á¹¹Ìå 
typedef struct Double_Linklist{
	int num;
	struct Double_Linklist *next;
	struct Double_Linklist *prior;
}dlist;

//ÒıÈë.hÎÄ¼ş 
#include"dLinkedList.h" 

int main(){		//¿ªÊ¼ÊµÏÖADT 
    int w=0;
    int x;		//ÉèÖÃÑ¡ÔñÊı¾İ 
    dlist *double_head = NULL;
    
	do{
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("*** 1.¹¹½¨Ò»¸öË«ÏòÓĞĞòÁ´±í  ***\n"); 
		printf("*** 2.¶ÔË«ÏòÓĞĞòÁ´±í½øĞĞADT ***\n"); 
		printf("*** 6.ÍË³ö³ÌĞò              ***\n"); 
    	printf("*******************************\n");
    	printf("*******************************\n");
    	printf("\nÇëÊäÈëÄúµÄÑ¡Ôñ: ");
    	scanf("%d", &x);
    	getchar();
    	system("cls");

		switch (x){
			case 1:
				printf("ÕıÔÚÎªÄúÉú³É£¬ÇëÉÔµÈÆ¬¿Ì"); 
				sleep(3);
				system("cls");
				double_head = (dlist *)malloc(sizeof(dlist));	//ÉèÖÃ³õÊ¼Ìõ¼ş 
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 2:
				
			case 3:
				printf("æ­£åœ¨ä¸ºæ‚¨ç”Ÿæˆï¼Œè¯·ç¨ç­‰ç‰‡åˆ»"); 
				sleep(3);
				system("cls");
				dlist *double_head = (dlist *)malloc(sizeof(dlist));	//æ„å»ºåŒå‘é“¾è¡¨å¤´ç»“ç‚¹
				double_head->next = NULL; double_head->prior = NULL; double_head->num = 0;
				double_head = dLink_create(double_head);
				sleep(3);
				system("cls");
				break;
				
			case 4:
				
			case 6:
				exit(0); 
		
		 	default:
		 		printf("ÄúµÄÑ¡ÔñÓĞÎÊÌâ£¬ÇëÖØĞÂÊäÈë"); 
				sleep(2);
				system("cls");
		}
		
	}while(w!=1);
	return 0;
}
