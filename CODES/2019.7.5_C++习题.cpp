#include <iostream>

typedef struct List {
	char node;
	struct List* next;
}List;

int main(){
	using namespace std;
	int num=0;//�ܽڵ���
	char ListArray[100];
	cin.getline(ListArray, 100);//��������
	while (ListArray [num]!= '\0') {
		num++;
	}//��ȡ�ڵ���Ŀ
	List* p;
	p = (List*)malloc(num*sizeof(List));//������ͷָ��
	if (p == NULL) return 0;
	p->next = NULL;
	List* q=p;//�������ͷָ��
	List* cir_p=p;//����ѭ��ָ��
	int k;
	cin >> k;//�����û������Ŀ
	int i = num - 1;
	while (i != -1) {
		List *temp;
		temp = (List*)malloc(sizeof(List));
		if (temp == NULL) return 0;
		temp->node = ListArray[i]-'0';
		temp->next = p->next;
		p->next = temp;
		--i;
	}
	int num2 = num;
	int k2 = k;
	while (num2 >= k) 
	{
		while (k2>1) 
			{				
			int k3 = k2;
			while (k3 > 1)
				{
					cir_p = cir_p->next;
					--k3;
				}
			List* cir_t = cir_p->next;//����β���ָ��
			cir_p -> next = cir_t -> next;
			cir_t->next = q->next;
			q->next = cir_t;
			q = q->next;
			cir_p = q;
			k2=k2-1;
			}
		if (q == NULL) return 0;
		q = q->next;
		cir_p = q;
		num2 = num2 - k;
		k2 = k;
	}
	while (p->next != NULL) 
	{
		printf("%d", p->next->node);
		p = p->next;
	}
	return 0;
}
