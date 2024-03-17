//�������� 
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
			p->next = q;
			q->prior = p;
			p = q;
			p->num = i;
			p->next = NULL;
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

//������
dlist *dLink_insert(dlist *head, int pos, int num){
	int i,n=0;	//�����ж������� 
	dlist vhead; vhead.next=head; vhead.prior=NULL;	//��������ͷ��� 
	dlist *p = head, *q;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//�ж��Ƿ��ܹ��������� 
		printf("�������λ�ó�������Χ������������");
		sleep(2);
		system("cls"); 
		return head;
	}
	//��ʼ���� 
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
	
	printf("��������ɣ����ڽ���չʾ...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return vhead.next;
}

//ɾ�����
dlist *dLink_delete(dlist *head, int pos){
	int i,n=0;	//�����ж������� 
	dlist vhead; vhead.next=head;	//��������ͷ��� 
	dlist *p = head, *q, *t;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//�ж��Ƿ��ܹ�����ɾ�� 
		printf("�������λ�ó�������Χ������������");
		sleep(2);
		system("cls"); 
		return head;
	}
	//��ʼɾ��
	p = &vhead;
	for(i=1; i<pos; i++){
		p=p->next;
	}
	q = p->next;
	t = q->next;
	p->next = q->next;
	t->prior = q->prior;
	free(q);

	printf("���ɾ����ɣ����ڽ���չʾ...\n");
	p = vhead.next;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return vhead.next;
} 

//���½��
dlist *dLink_reset(dlist *head, int pos, int num){
	int i,n=0;	//�����ж������� 
	dlist vhead; vhead.next=head;	//��������ͷ��� 
	dlist *p = head, *q;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//�ж��Ƿ��ܹ�����ɾ�� 
		printf("�������λ�ó�������Χ������������");
		sleep(2);
		system("cls"); 
		return head;
	}
	//��ʼ�޸�
	p = &vhead;
	for(i=1; i<=pos; i++){
		p=p->next;
	}
	p->num = num;
	
	printf("����޸���ɣ����ڽ���չʾ...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
} 

//����ѯ 
void dLink_check(dlist *head, int pos){
	int i,n=0;	//�����ж������� 
	dlist vhead; vhead.next=head;	//��������ͷ��� 
	dlist *p = head;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(pos>n+1){		//�ж��Ƿ��ܹ�����ɾ�� 
		printf("�������λ�ó�������Χ������������");
		sleep(2);
		system("cls"); 
		return;
	}
	//��ʼ��ѯ
	p = &vhead;
	for(i=1; i<=pos; i++){
		p=p->next;
	}
	printf("��λ�õ�����ֵΪ%d", p->num); 
}

