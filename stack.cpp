#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

namespace stack{
	class Stack{
		class Elem{
			public:
				int data;
				Elem *pointer;
		};
		Elem *head;
		int length;
		public:
			Stack();
			void push(int);
			int pop();
			int top();
			int size();
			bool find(int);
	};
}
//исключения при работе со стеком
struct StackException
{
    string msg;
    StackException(const string& msg) :
        msg(msg)
    {}
};

int main(){
	int a;
	stack::Stack st;
	if(st.find(5)) cout<<"5 is found in the stack"<<"."<<endl;
	else cout<<"No 5 in the stack"<<"."<<endl;
	if(st.find(4)) cout<<"4 is found in the stack"<<"."<<endl;
	else cout<<"No 4 in the stack"<<"."<<endl;
	cout<<"Top of the stack - "<<st.top()<<"."<<endl;
	st.push(0);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	if(st.find(5)) cout<<"5 is found in the stack"<<"."<<endl;
	else cout<<"No 5 in the stack"<<"."<<endl;
	if(st.find(4)) cout<<"4 is found in the stack"<<"."<<endl;
	else cout<<"No 4 in the stack"<<"."<<endl;
	st.push(5);
	if(st.find(5)) cout<<"5 is found in the stack"<<"."<<endl;
	else cout<<"No 5 in the stack"<<"."<<endl;
	cout<<"Top of the stack - "<<st.top()<<"."<<endl;
	cout<<"Size of the stack - "<<st.size()<<"."<<endl;
	cout<<"Make pop. Extracted - "<<st.pop()<<"."<<endl;
	cout<<"New top of the stack - "<<st.top()<<"."<<endl;
	cout<<"Make pop. Extracted - "<<st.pop()<<"."<<endl;
	cout<<"New top of the stack - "<<st.top()<<"."<<endl;
	cin>>a;
	return 0;
}

//конструктор
stack::Stack::Stack(){
	length = 0;
	head = NULL;
	cout<<"New stack was created."<<endl;
}

//метод возвращает размер
int stack::Stack::size(){
	return length;
}

//метод кладет новый элемент
void stack::Stack::push(int _new){
	Elem *tmp = new Elem;
	tmp->data = _new;
	tmp->pointer = head;
	head = tmp;
	length++;
}

//метод извлекает элемент, если стек не пуст. Иначе исключение
int stack::Stack::pop(){
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

//метод возвращает то, что в вершине, если стек не пуст. Иначе исключение
int stack::Stack::top(){
	try{
		if(length == 0){
			throw StackException("Stack is empty. Fill it fisrtly!");
		}
		else if(length > 0){
			int res = head->data;
			return res;
		}
	}
	catch (StackException& e){
	    cout<<e.msg << '\n';
		return 0;
	}
}

//поиск элемента
bool stack::Stack::find(int find_me){
	if(length == 0) return false;
	Elem *finder = new Elem;
	finder = head;
	while(finder->pointer){
		if(finder->data == find_me)
			return true;
		else
			finder = finder->pointer;
	}
	return false;
}
