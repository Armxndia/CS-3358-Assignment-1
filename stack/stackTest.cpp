#include <iostream>
#include "myStack.h"

using namespace std;

void postfixTest() {
	myStack operandStack(100);
	cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
	cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;
	
	while(1){
		char inputHolder;
		cin >> inputHolder;
		
		// End Case
		if (inputHolder == '=') {
            if (!operandStack.isEmpty()) {
				//Pop will print char instead of ASCII
                cout << "Result: " << operandStack.pop() << endl;
            } else {
                cerr << "Error: No result to display." << endl;
            }
            break;
        }
		//Since char data type is stored as ASCII in memory we will convert by removing the ASCII offset before pushing
		if (inputHolder >= '0' && inputHolder <= '9') {
			//0 in ASCII is 48 which is the same as the offset of each number 1=49, 2=50, ...
            operandStack.push(inputHolder - '0');
			//Inside stack the element is now an integer for future operations like multiplication to work correctly
        }

		else if (inputHolder == '+' || inputHolder == '-' || inputHolder == '*' || inputHolder == '/') {
            if (operandStack.isEmpty()) {
                cerr << "Error: Not enough operands (stack is empty)." << endl; //If empty before popping once stack is empty
                break;
            }
            int operand2 = operandStack.pop(); // Top element is right operand [4 5 +] = 4 + 5 (im assuming this is what is intended from the example in pdf)
            
            if (operandStack.isEmpty()) {
                cerr << "Error: Not enough operands (stack only has 1 element)." << endl; //If empty after popping once stack had 1 element (duh)
                break;
            }
            int operand1 = operandStack.pop(); // Next element is left operand
            
			//Same as nested if statements
            switch (inputHolder) {
                case '+': 
                    operandStack.push(operand1 + operand2); 
                    break;
                case '-': 
                    operandStack.push(operand1 - operand2); 
                    break;
                case '*': 
                    operandStack.push(operand1 * operand2); 
                    break;
                case '/': 
                    if (operand2 == 0) {
                        cerr << "Error: Division by zero." << endl;
                        return;
                    }
                    operandStack.push(operand1 / operand2); 
                    break;
            }
        }
		else{
			cout << "Invalid input: " << inputHolder << endl;
		}
	}
}

int main()
{
    cout << "Testing the basic functions of the stack..." << endl;
	cout << "Please enter the max capacity of the testStack: ";
	int testSize;
	cin >> testSize;
	myStack testStack(testSize);
	
	cout << "Testing..." << endl;
	while(1) {
		cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		cin >> userChoice;
		
		if(userChoice == 'e')
			break;
		
		switch (userChoice) {
			case 'p':			
				if(!testStack.isFull()) {
					cout << "Please enter the integer you would like to push: ";
					int userInt;
					cin >> userInt;
					testStack.push(userInt);
				}
				else
					cout << "Nothing has been pushed in. The stack is full!" << endl;
				break;
			case 'o':
				if(!testStack.isEmpty())
					cout << testStack.pop() << " has been popped out" << endl;
				else
					cout << "Nothing has been popped out. The stack is empty!" << endl;
				break;
			default:
				cout << "Illegal user-input character. Please try again." << endl;
		}
	}

	cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
	postfixTest();	
	
	return 0;
}

