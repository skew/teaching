#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Elem{
  public:
		int data;
		Elem *pointer;
};

class Stack{
	Elem *head;
	int length;
	public:
		Stack();
		void push(int push_me);
		int pop();
		int top();
		int size();
		bool isEmpty();
};

struct StackException
{
    string msg;
    StackException(const string& msg) :
        msg(msg)
    {}
};

int main(){
	int a;
	Stack st;
	st.push(0);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<"Top of the stack - "<<st.top()<<"."<<endl;
	cout<<"Size of the stack - "<<st.size()<<"."<<endl;
	cout<<"Make pop. Extracted - "<<st.pop()<<"."<<endl;
	cout<<"New top of the stack - "<<st.top()<<"."<<endl;
	cout<<"Make pop. Extracted - "<<st.pop()<<"."<<endl;
	cout<<"New top of the stack - "<<st.top()<<"."<<endl;
	cin>>a;
}

Stack::Stack(){
	length = 0;
	head = NULL;
	cout<<"New stack was created."<<endl;
}

int Stack::size(){
	return length;
}

void Stack::push(int _new){
	Elem *tmp = new Elem;
	tmp->data = _new;
	tmp->pointer = head;
	head = tmp;
	length++;
}

int Stack::pop(){
	try{
		if(length == 0){
			throw StackException("Stack is empty. Fill it fisrtly!");
		}
		else if(length > 0){
			int res = head->data;
			head->data = (head->pointer)->data;
			head->pointer = (head->pointer)->pointer;
			length--;
			return res;
		}
	}
	catch (StackException& e){
	    cout<<e.msg << '\n';
		return 0;
	}	
}

int Stack::top(){
	return head->data;    
}
