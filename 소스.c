
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100


struct Stack {
	int top;
	char items[MAX_LENGTH];
};


struct Stack* createStack() {
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1;
	return stack;
}

int isFull(struct Stack* stack) {
	return stack->top == MAX_LENGTH - 1;
}


int isEmpty(struct Stack* stack) {
	return stack->top == -1;
}


void push(struct Stack* stack, char item) {
	if (isFull(stack)) {
		printf("Stack Overflow\n");
		return;
	}
	stack->items[++stack->top] = item;
}

char pop(struct Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack->items[stack->top--];
}


int isPalindrome(char* str) {
	int n = strlen(str);
	struct Stack* stack = createStack();
	for (int i = 0; i < n; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			// �빮��
			str[i] += 32;
			push(stack, str[i]);
		}
		else if (str[i] >=97 && str[i]<=122) {
			push(stack, str[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			if (str[i] != pop(stack)) {
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	char str[MAX_LENGTH];
	for (int i = 0; i <= 10; i++) {
		printf("���ڿ��� �Է��Ͻÿ�: ");
		fgets(str, MAX_LENGTH, stdin);
		str[strcspn(str, "\n")] = 0; // �ٹٲٱ� ���� ����
		if (isPalindrome(str)) {
			printf("ȸ���Դϴ�.\n", str);
		}
		else {
			printf("ȸ���� �ƴմϴ�.\n", str);
		}
	}
	return 0;
}

