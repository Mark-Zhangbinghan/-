//创建链表 
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
			p->next = q;
			q->prior = p;
			p = q;
			p->num = i;
			p->next = NULL;
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

//插入结点
dlist *dLink_insert(dlist *head, int pos, int num){
	int i,n=0;	//用来判断链表长度 
	dlist vhead; vhead.next=head; vhead.prior=NULL;	//构建虚拟头结点 
	dlist *p = head, *q;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//判断是否能够正常插入 
		printf("您输入的位置超出链表范围，请重新设置");
		sleep(2);
		system("cls"); 
		return head;
	}
	//开始插入 
	p = &vhead;
	for(i=1; i<pos; i++){
		p=p->next;
	}
	q = (dlist *)malloc(sizeof(dlist));
	q->num = num;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	p = q;
	q = q->next;
	q->prior = p;
	
	printf("结点插入完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return vhead.next;
}

//删除结点
dlist *dLink_delete(dlist *head, int pos){
	int i,n=0;	//用来判断链表长度 
	dlist vhead; vhead.next=head;	//构建虚拟头结点 
	dlist *p = head, *q, *t;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//判断是否能够正常删除 
		printf("您输入的位置超出链表范围，请重新设置");
		sleep(2);
		system("cls"); 
		return head;
	}
	//开始删除
	p = &vhead;
	for(i=1; i<pos; i++){
		p=p->next;
	}
	q = p->next;
	t = q->next;
	p->next = q->next;
	t->prior = q->prior;
	free(q);

	printf("结点删除完成，现在进行展示...\n");
	p = vhead.next;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return vhead.next;
} 

//更新结点
dlist *dLink_reset(dlist *head, int pos, int num){
	int i,n=0;	//用来判断链表长度 
	dlist vhead; vhead.next=head;	//构建虚拟头结点 
	dlist *p = head, *q;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//判断是否能够正常删除 
		printf("您输入的位置超出链表范围，请重新设置");
		sleep(2);
		system("cls"); 
		return head;
	}
	//开始修改
	p = &vhead;
	for(i=1; i<=pos; i++){
		p=p->next;
	}
	p->num = num;
	
	printf("结点修改完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
} 

//结点查询 
void dLink_check(dlist *head, int pos){
	int i,n=0;	//用来判断链表长度 
	dlist vhead; vhead.next=head;	//构建虚拟头结点 
	dlist *p = head;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//判断是否能够正常删除 
		printf("您输入的位置超出链表范围，请重新设置");
		sleep(2);
		system("cls"); 
		return;
	}
	//开始查询
	p = &vhead;
	for(i=1; i<=pos; i++){
		p=p->next;
	}
	printf("该位置的数据值为%d", p->num); 
}

