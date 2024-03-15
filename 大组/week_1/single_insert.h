#include<stdio.h>

slist *Link_insert(slist *head){
	int i, n=5;
	slist *p = head, *q;
	for(i=1; i<=n; i++){
		if(i==1){
			head->num = i;
			continue;
	}
		q = (slist *)malloc(sizeof(slist));
		p->next = q;
		p = q;
		p->num = i;
		p->next = NULL;
	}
	
	printf("有序单向链表构建完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	
	return head;
}
