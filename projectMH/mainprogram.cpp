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

//Doubly linked list

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
 
/*
 Class Declaration 
 */
class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        {
            start = NULL;  
        }
};

/*
 * Create Double Link List
 */
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 

 
/*
 * Insertion at the beginning
 */
void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Insertion of element at a particular position
 */
void double_llist::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}
 


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

