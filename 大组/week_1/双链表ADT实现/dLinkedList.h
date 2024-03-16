dlist *dLink_create(dlist *head){
	int i, n=5;		//设置循环条件 
	dlist *p = head, *q;
	
	if (head==NULL){	//判断是否创建头结点有误 
		printf("创建失败！"); 
		return NULL;
	}
	
	//开始构建 
	for(i=1; i<=n; i++){	
		if(i==1){
			head->num = i;
		} else {
			q = (dlist *)malloc(sizeof(dlist));
			q->prior = p;
			q->num = i;
			q->next = NULL;
			p->next = q;
			p = q;
		}
	}
	
	printf("有序双向链表构建完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	
	return head;
}
