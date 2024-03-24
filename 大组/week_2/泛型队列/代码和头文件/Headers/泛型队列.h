//���нṹ�嶨�� 
typedef struct QNode
{
	int type;
	void *data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr head;
	QueuePtr tail;
	int Length;
}LinkQueue;


//��ʼ������
LinkQueue initQueue(LinkQueue Link){
	Link.head = NULL;
	Link.tail = Link.head;
	Link.Length = 0;
	printf("�����ѳ�ʼ���ɹ�\n");
	sleep(2);
	return Link;	
}

//�ж϶����Ƿ��ѳ�ʼ��
int IsUndefineQueue(LinkQueue Link){
	return (Link.Length==-1);
}

//�ж��Ƿ�Ϊ�ն���
int IsEmptyQueue(LinkQueue Link){
	return  (Link.head==NULL&&Link.Length==0);
}

//�鿴��ͷԪ��
void GetHeadQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("���л�δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("����Ϊ��\n");
		sleep(2);
		return;
	}
	switch (Link.head->type){
		case 1://���� 
			printf("��ͷԪ��ֵΪ%d", *((int*)Link.head->data)); 
			break;
			
		case 2://�ַ��� 
			printf("��ͷԪ��ֵΪ%c", *((char*)Link.head->data)); 
			break;
			
		case 3://������ 
			printf("��ͷԪ��ֵΪ%f", *((float*)Link.head->data)); 
			break;
			
		case 4://�ַ��� 
			printf("��ͷԪ��ֵΪ%s", *((char*)Link.head->data)); 
			break;
	}
	sleep(2);
}

//ȷ�����г���
void LengthQueue(LinkQueue Link){
	int count=0;
	QueuePtr p = Link.head;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	printf("���еĳ���Ϊ%d\n", count);
	sleep(2);
}

//���
LinkQueue PushQueue(LinkQueue Link, void *data, int type){
	if (IsUndefineQueue(Link)){
		system("cls");
		printf("���л�δ��ʼ��\n");
		return Link;
	}
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
// �����������ͷ����ڴ沢��������
switch (type) {
    case 1: // ����
        p->data = malloc(sizeof(int));
        *(int *)p->data = *(int *)data;
        break;
        
    case 2: // �ַ���
        p->data = malloc(sizeof(char));
        *(char *)p->data = *(char *)data;
        break;
        
    case 3: // ������
        p->data = malloc(sizeof(float));
        *(float *)p->data = *(float *)data;
        break;
        
    case 4: // �ַ���
        p->data = strdup((char *)data); // ʹ��strdup�����ַ���
        break;
        
    default:
        printf("��֧�ֵ���������\n");
        free(p);
        return Link;
}
	p->type = type;
	p->next = NULL;
	
	if (IsEmptyQueue(Link)){
		Link.head = p;
		Link.tail = p;
	}
	else {
		Link.tail->next = p;
		Link.tail = p;
	}
	Link.Length++;
	return Link;
}

//�ж϶���Ԫ�ص���������
LinkQueue TypeQueue(LinkQueue Link){
	int type;
	printf("����������Ҫ��ӵ���������:\n");
	printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���\n");
	scanf("%d", &type);
	getchar();
	while (1>type || 4<type){
		system("cls");
		printf("����������ֳ�������������: ");
		scanf("%d", &type);
		getchar();
	}
	switch (type){
		case 1:{//���� 
			int data;
			printf("������������ӵ����ݣ�");
			scanf("%d", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 2:{//�ַ��� 
			char data;
			printf("������������ӵ����ݣ�");
			scanf(" %c", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 3:{//������ 
			float data;
			printf("������������ӵ����ݣ�");
			scanf("%f", &data);
			getchar();
			Link = PushQueue(Link, &data, type);
			break;
		}
			
		case 4:{//�ַ��� 
			char data[21];
			printf("������������ӵ����ݣ�(������20λ)");
			scanf("%20s", data);
			getchar();
			Link = PushQueue(Link, data, type);
			break;
		}
	}
	system("cls");
	printf("��Ϊ��������");
	sleep(2); 
	return Link; 
} 

//����
LinkQueue PopQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("���л�δ��ʼ��\n");
		sleep(2);
		return Link;
	}
	else if (IsEmptyQueue(Link)){
		printf("����Ϊ��\n");
		sleep(2);
		return Link;
	}
	QueuePtr p = Link.head;
	Link.head = Link.head->next;
	Link.Length--;
	free(p->data);
	free(p);
	printf("��Ϊ���������");
	sleep(2);
	return Link;
} 

//���ٶ���
void DestroyQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("���л�δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("����Ϊ��\n");
		sleep(2);
		return;
	}
	QueuePtr p = Link.head, q;
	while (p!=NULL){
		q = p;
		p = p->next;
		free(q->data);
		free(q);
	}
	Link.head = NULL;
	Link.tail = NULL;
	Link.Length = -1;
	printf("�������������");
	sleep(2);
}

//�������� 
void ShowQueue(LinkQueue Link){
	if (IsUndefineQueue(Link)){
		printf("���л�δ��ʼ��\n");
		sleep(2);
		return;
	}
	else if (IsEmptyQueue(Link)){
		printf("����Ϊ��\n");
		sleep(2);
		return;
	}
	printf("������������:\n");
	int i=1;
	QueuePtr p = Link.head;
	while(p!=NULL){
		switch (p->type){
			case 1://���� 
				printf("��%d����%d ", i, *((int*)p->data)); 
				break;
				
			case 2://�ַ��� 
				printf("��%d����%c ", i, *((char*)p->data)); 
				break;
				
			case 3://������ 
				printf("��%d����%f ", i, *((float*)p->data)); 
				break;
				
			case 4://�ַ��� 
				printf("��%d����%s ", i, p->data); 
				break;
		}
		i++;
		p = p->next;
	}
	sleep(2);
}
