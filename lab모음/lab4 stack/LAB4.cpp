#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const int stackSize = 100;
int ST[stackSize]; int top;
int match(char, char);
void create_stack();
void push(char);
int pop();
int isEmpty();
int main() {
	
	int temp, i, result;
	char buffer[80];

	while (infile.getline(buffer, 80)) {
		create_stack();
		result = 0;
		for (i = 3; i < strlen(buffer); i++) {
			if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[') {
				push(buffer[i]);
			}
			else if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') {
				if (isEmpty())
				{
					result = 1;
					
					break;
				}
				temp = pop();
				if (!match(temp, buffer[i]))
				{
					result = 1;
                    break;
					
				}
			}
		}
		if (result == 0)
		{
			if (isEmpty())
			{
				cout << buffer << endl << "The Expression is Valid" << endl;
            }
			else
			{
				result = 1;
			}
		}
	}
}
void create_stack() { 
    top = -1; 
}
int isEmpty() {
	if (top == -1) 
        return 1;
	else 
        return 0;
}
void push(char num) {
	++top;
	ST[top] = num;
}
int pop() {
	return (ST[top--]);
}
int match(char x, char y)
{
	if (x == '(' && y == ')')
	{
		return 1;
	}
	else if (x == '[' && y == ']')
	{
		return 1;
	}
	else if (x == '{' && y == '}')
	{
		return 1;
	}
	return 0;
}