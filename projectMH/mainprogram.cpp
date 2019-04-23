#include <iostream>
#include <cstdlib>
#include <conio.h>
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

class Node
{
public:
    int info;
    Node* next;
};
class List:public Node
{

    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();
    void insert();
    void delet();
    void display();
    void search();
};
void List::create()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
 
    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nNot Able to Insert";
        break;
 
    }
}
void List::delet()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nDeleted Element is "<<first->info;
            first=first->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nDeleted Element is: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->info;
            prev->next=cur->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}
void List::display()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void List::search()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"Element"<<value<<"is Found at "<<pos<<" Position";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List";
    }
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
	List l;
 while(1)
    {
        cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE\n2:INSERT\n3:DELETE\n4:SEARCH\n5:DISPLAY\n6:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.delet();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        case 6:
            return 0;
        }
    return 0;
}

