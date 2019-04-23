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
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void display();
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
int stack::pop()
{
	if (isEmpty())
	{
		cout << "UnderFlow-------Program Terminated";
		exit(EXIT_FAILURE);
	}
	cout << "Removing " << arr[top] << endl;
	return arr[top--];
}
int stack::peek()
{
	if (!isEmpty())
		cout<<arr[top]<<endl;
	else
		exit(EXIT_FAILURE);
}
bool stack::isEmpty()
{
	return top == -1;
}
bool stack::isFull()
{
	return top == capacity - 1;
}
void stack::display()
{
	int i;
	if(top==-1)
	{
	cout<<"Stack is empty!!"<<endl;
	}
	else
	{
	cout<<"Stack is: "<<endl;
		for(i=top;i>=0;--i)
			cout<<arr[i]<<endl;
}
}
class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        void sort();
        circular_llist()
        {
            last = NULL;
        }
};

int main()
{
	stack s1;
	int ch;
	do
	{
		cout<<"Press the Following Accordingly:"<<endl;
			cout<<"1: PUSH"<<endl;
			cout<<"2: POP"<<endl;
			cout<<"3: PEEK"<<endl;

			cin>>ch;
		switch(ch)
		{
			case 1:
				int a;
				cin>>a;
				s1.push(a);
				break;
			case 2:
				s1.pop();
				break;
			case 3:
				s1.peek();
				break;
			case 4:
				s1.display();
				break;
		        default :
				cout<<"Wrong Choice Entered"<<endl;
				break;
		}
    }
    while(ch!=5);
    return 0;
}

