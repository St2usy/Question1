#include "Stack_Made_2.h"
#include <iostream>
#pragma warning (disable:4996)

#include "OperandStack.h"
// �Է����κ��� ���� ǥ�� ������ �о� ����ϴ� �Լ�
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

// ��ü�� �켱���� ���
inline int precedence(char op) {
	switch (op) {
	case '(': case')': return 0;
	case '+': case'-': return 1; // �켱���� �߰�
	case '*': case'/': return 2; // �켱���� ����
	}
	return -1;
}

// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� �Լ�
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
		else if (c == '(') stack.push(c); // '( �̸� ���ÿ� ����

		else if (c == ')') { // ') �̸� '( �� ���ö����� ������ ���
			while (!stack.isEmpty()) {
				op = stack.pop();
				if (op == '(') break;
				else std::cout << op << " ";
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') { // ������( + - * / )�� --> �켱���� �� ó�� < ������� �ٽ� ���� >
			while (!stack.isEmpty()) {
				op = stack.peek();
				if (precedence(c) <= precedence(op)) { // ������ �����ڿ� ���ؼ� ���� �������� �켱������ �� ������
					std::cout << op << " "; // ������ �����ڸ� �������
					stack.pop(); // pop�� �����Ѵ�.
				}
				else break;
			}
			stack.push(c);
		}
	}
	while (!stack.isEmpty())  // ��ȸ�� ������ �����ִ� �����ڵ��� ����Ѵ�.
		std::cout << stack.pop() << " ";
	std::cout << std::endl;
}

void main() {
	std::cout << "�����Է� (Infix) = ";
	innfix2Postfix();
	double res = calcPostfixExpr();
	std::cout << res;
}
