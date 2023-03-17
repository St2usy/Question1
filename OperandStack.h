#pragma once
#define MAX_STACK_SIZE 20
#include <iostream>

// 오류 처리 함수
inline void error3(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class OperandStack {
private:
	int top;
	double data[MAX_STACK_SIZE];
public:
	OperandStack()
		: top(-1) {}
	~OperandStack() {}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFuLL() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}
	void push(double n) {
		if (isFuLL()) { error3("Error : Stack is FULL!!"); }
		else {
			top += 1;
			data[top] = n;
		}
	}
	double pop() {
		if (isEmpty()) { error3("Error :: Stack is Empty !!"); }
		else {
			double popdata = data[top];
			top -= 1;
			return popdata;
		}
	}
	double peek() {
		if (isEmpty()) { error3("Error :: Stack is Empty !!"); }
		else {
			return data[top];
		}
	}
	void display() {
		std::cout << "스택 갯수는 : " << top + 1 << std::endl;
		std::cout << "---------------Stack---------------" << std::endl;
		for (int i = 0; i <= top; i++) {
			std::cout << data[i] << std::endl;
		}
	}
};
