dlist *dLink_create(dlist *head){
	int i, n=5;		//����ѭ������ 
	dlist *p = head, *q;
	
	if (head==NULL){	//�ж��Ƿ񴴽�ͷ������� 
		printf("����ʧ�ܣ�"); 
		return NULL;
	}
	
	//��ʼ���� 
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
	
	printf("����˫����������ɣ����ڽ���չʾ...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	
	return head;
}
