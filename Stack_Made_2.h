#pragma once
#define MAX_STACK_SIZE 20
#include <iostream>

// ���� ó�� �Լ�
inline void error(const char* message) { // inline - > �ش��Լ��� �ҽ��ڵ� �ȿ� ���ΰɷ� ġȯ ��Ŵ
	std::cout << message << std::endl;
	exit(1); // �Լ��� ������������ ���� ������ �ǹ���.
}

class ArrayStack {
private:
	int top;
	int data[MAX_STACK_SIZE];
public:
	ArrayStack()
		: top(-1) {}
	~ArrayStack() {}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFuLL() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}
	void push(int n) {
		if (isFuLL()) { error("Error : Stack is FULL!!"); }
		else {
			top += 1;
			data[top] = n;
		}
	}
	char pop() { // ���� ��ȯ �Ҷ� char������ �ٲ۴�.
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			char popdata = data[top];
			top -= 1;
			return popdata;
		}
	}
	int peek() {
		if (isEmpty()) { error("Error :: Stack is Empty !!"); }
		else {
			return data[top];
		}
	}
	void display() {
		std::cout << "���� ������ : " << top + 1 << std::endl;
		std::cout << "---------------Stack---------------" << std::endl;
		for (int i = 0; i <= top; i++) {
			std::cout << data[i] << std::endl;
		}
	}
};
