#pragma once
#define MAX_STACK_SIZE 20
#include <iostream>

// 오류 처리 함수
inline void error(const char* message) { // inline - > 해당함수를 소스코드 안에 쓰인걸로 치환 시킴
	std::cout << message << std::endl;
	exit(1); // 함수가 비정상적으로 종료 됐음을 의미함.
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
	char pop() { // 수식 변환 할때 char형으로 바꾼다.
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
		std::cout << "스택 갯수는 : " << top + 1 << std::endl;
		std::cout << "---------------Stack---------------" << std::endl;
		for (int i = 0; i <= top; i++) {
			std::cout << data[i] << std::endl;
		}
	}
};
