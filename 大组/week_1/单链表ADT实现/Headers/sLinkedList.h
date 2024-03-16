//创建链表 
slist *sLink_create(slist *head){		
	int i, n=5;		//设置循环条件 
	slist *p = head, *q;
	
	if (head==NULL){	//判断是否创建头结点有误 
		printf("创建失败！"); 
		return NULL;
	}
	
	//开始构建 
	for(i=1; i<=n; i++){	
		if(i==1){
			head->num = i;
		} else {
			q = (slist *)malloc(sizeof(slist));
			p->next = q;
			p = q;
			p->num = i;
			p->next = NULL;
		}
	}
	
	printf("有序单向链表构建完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
}

//插入结点
slist *sLink_insert(slist *head, int pos, int num){
	int i,n=0;	//用来判断链表长度 
	slist vhead; vhead.next=head;	//构建虚拟头结点 
	slist *p = head, *q;
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
	q = (slist *)malloc(sizeof(slist));
	q->num = num;
	q->next = p->next;
	p->next = q;
	
	printf("结点插入完成，现在进行展示...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
}

//删除结点
slist *sLink_delete(slist *head, int pos){
	int i,n=0;	//用来判断链表长度 
	slist vhead; vhead.next=head;	//构建虚拟头结点 
	slist *p = head, *q;
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
	p->next = q->next;
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
slist *sLink_reset(slist *head, int pos, int num){
	int i,n=0;	//用来判断链表长度 
	slist vhead; vhead.next=head;	//构建虚拟头结点 
	slist *p = head, *q;
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
void sLink_check(slist *head, int pos){
	int i,n=0;	//用来判断链表长度 
	slist vhead; vhead.next=head;	//构建虚拟头结点 
	slist *p = head;
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
