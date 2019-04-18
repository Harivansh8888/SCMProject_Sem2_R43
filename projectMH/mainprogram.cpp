#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10
class stack
{
	int *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);
	void push(int);
	bool isEmpty();
	bool isFull();
};
stack::stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}
void stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow-------Program Terminated";
		exit(EXIT_FAILURE);
	}
	cout << "Inserting " << x << endl;
	arr[++top] = x;
}
bool stack::isEmpty()
{
	return top == -1;
}
bool stack::isFull()
{
	return top == capacity - 1;
}
int main()
{
	stack s1;
	int ch;
	do
	{
		cout<<"Press the Following Accordingly:"<<endl;
			cout<<"1: PUSH"<<endl;
			cin>>ch;
		switch(ch)
		{
			case 1:
				int a;
				cin>>a;
				s1.push(a);
				break;
		default :
				cout<<"Wrong Choice Entered"<<endl;
				break;
		}
    }
    while(ch!=5);
    return 0;
}

