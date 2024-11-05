/*Program for Expression Evaluation (Postfix Input)*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stck[10], tos = -1;

void push(int);
int pop();

int main() {

	char expression[50];
	int val1, val2, ans, i = 0;

	printf("\nEnter a Postfix Expression: \n");
	fgets(expression, sizeof(expression), stdin);
	
	while (expression[i] != '\0' && expression[i] != '\n') {
		if (isdigit(expression[i])) {
			push(expression[i] - '0'); 
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			val1 = pop();
			val2 = pop();
			
			switch(expression[i]) {
				case '+' : ans = val2 + val1;
					   break;
				
				case '-' : ans = val2 - val1;
					   break;
				
				case '*' : ans = val2 * val1;
					   break;
				
				case '/' : 
					if (val1 == 0) {
						printf("\nError: Division by zero!\n");
						exit(1);
					}
					ans = val2 / val1;
					   break;
				
				default : printf("\nInvalid Expression!");
					   exit(1);
			}
			push(ans);
		}
		else if(expression[i] != ' ') { 
			printf("\nInvalid Character in Expression!");
			exit(1);
		}
		i++;
	}
	
	printf("\nAnswer is %d\n", stck[tos]);
	return 0;
}

void push(int x) {
	if (tos == 9) {
		printf("\nStack is Full!\n");
		exit(1);
	}
	else {
		tos++;
		stck[tos] = x;
	}
}

int pop() {
	if (tos == -1) {
		printf("\nStack is Empty!\n");
		exit(1);
	}
	else {
		int y = stck[tos];
		tos--;
		return y;
	}
}

