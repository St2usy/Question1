#include "Stack_Made_2.h"
#include <iostream>
#pragma warning (disable:4996)

#include "OperandStack.h"
// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calcPostfixExpr(FILE* fp = stdin) {
	OperandStack stack;
	char c;
	{while ((c = getc(fp)) != '\n')
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			double val2 = stack.pop();
			double val1 = stack.pop();
			switch (c) {
			case '+': stack.push(val1 + val2); break;
			case '-': stack.push(val1 - val2); break;
			case '*': stack.push(val1 * val2); break;
			case '/': stack.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9') {
			ungetc(c, fp);
			double val;
			fscanf(fp, "%lf", &val);
			stack.push(val);
		}
	}
	return stack.pop();
}

// 객체의 우선순위 계산
inline int precedence(char op) {
	switch (op) {
	case '(': case')': return 0;
	case '+': case'-': return 1; // 우선순위 중간
	case '*': case'/': return 2; // 우선순위 높음
	}
	return -1;
}

// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
void innfix2Postfix(FILE* fp = stdin) {
	ArrayStack stack;
	char c, op;
	double val;

	while ((c = getc(fp)) != '\n') {
		if ((c >= '0' && c <= '9')) {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			printf("%.2lf ", val);
		}
		else if (c == '(') stack.push(c); // '( 이면 스택에 삽입

		else if (c == ')') { // ') 이면 '( 가 나올때까지 연산자 출력
			while (!stack.isEmpty()) {
				op = stack.pop();
				if (op == '(') break;
				else std::cout << op << " ";
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') { // 연산자( + - * / )면 --> 우선순위 비교 처리 < 여기부터 다시 공부 >
			while (!stack.isEmpty()) {
				op = stack.peek();
				if (precedence(c) <= precedence(op)) { // 이전의 연산자와 비교해서 이전 연산자의 우선순위가 더 높으면
					std::cout << op << " "; // 이전의 연산자를 출력한후
					stack.pop(); // pop을 수행한다.
				}
				else break;
			}
			stack.push(c);
		}
	}
	while (!stack.isEmpty())  // 순회가 끝나면 남아있는 연산자들을 출력한다.
		std::cout << stack.pop() << " ";
	std::cout << std::endl;
}

void main() {
	std::cout << "수식입력 (Infix) = ";
	innfix2Postfix();
	double res = calcPostfixExpr();
	std::cout << res;
}
