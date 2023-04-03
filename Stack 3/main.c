#include <stdio.h>
#include <time.h>
#define MAX_STACK_SIZE 10

// ���� �迭 ���
typedef int element;
typedef struct {
	element* data;
	int top;
	int capacity;
}StackType;

// ���� �ʱ�ȭ
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� �˻�
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// ��ȭ ���� �˻�
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->data = realloc(s->data, s->capacity*2);
		return;
	}
	else {
		s->top++;
		*(s->data + s->top) = item;
		return;
	}
}
/*
void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}
*/

//�����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else s->data[(s->top--)];
}

int main()
{
	srand(time(NULL));

	StackType *s;
	
	s = (StackType*)malloc(sizeof(StackType));
	init_stack(&s);

	printf("�����迭\n");

	for (int i = 1; i <= 30; i++)
	{
		int rand_num = rand() % 100 + 1;

		if (rand_num % 2 == 0) {
			push(&s, rand_num);
			printf("[%d] Push %d\n", i, rand_num);
		}

		else if (rand_num % 2 == 1)
		{
			pop(&s);
			printf("[%d] Pop %d\n", i, rand_num);
		}
	}

	free(s);
	return 0;
}