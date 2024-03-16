//�������� 
slist *sLink_create(slist *head){		
	int i, n=5;		//����ѭ������ 
	slist *p = head, *q;
	
	if (head==NULL){	//�ж��Ƿ񴴽�ͷ������� 
		printf("����ʧ�ܣ�"); 
		return NULL;
	}
	
	//��ʼ���� 
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
	
	printf("��������������ɣ����ڽ���չʾ...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
}

//������
slist *sLink_insert(slist *head, int pos, int num){
	int i,n=0;	//�����ж������� 
	slist vhead; vhead.next=head;	//��������ͷ��� 
	slist *p = head, *q;
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
	q = (slist *)malloc(sizeof(slist));
	q->num = num;
	q->next = p->next;
	p->next = q;
	
	printf("��������ɣ����ڽ���չʾ...\n");
	p = head;
	while(p!=NULL){
		printf("%d ", p->num);
		p = p->next;
	}
	return head;
}

//ɾ�����
slist *sLink_delete(slist *head, int pos){
	int i,n=0;	//�����ж������� 
	slist vhead; vhead.next=head;	//��������ͷ��� 
	slist *p = head, *q;
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
	p->next = q->next;
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
slist *sLink_reset(slist *head, int pos, int num){
	int i,n=0;	//�����ж������� 
	slist vhead; vhead.next=head;	//��������ͷ��� 
	slist *p = head, *q;
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
void sLink_check(slist *head, int pos){
	int i,n=0;	//�����ж������� 
	slist vhead; vhead.next=head;	//��������ͷ��� 
	slist *p = head;
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
