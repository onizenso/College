#pragma once
#include <string>
using namespace std;

template <class T>
class t_stack
{
    private:
	int capacity;
	int top;
	T *stackPtr;

	void resize();//function to resize capacity
    public:
	t_stack(int);
	~t_stack();

	bool push(T input);
	T pop();

	int size();
	bool isEmpty();
	bool isFull();
	T operator[](int index);
	void sort();
};

template <class T>
t_stack<T>::t_stack(int x=10){
    capacity = x;
    top = 0;
    stackPtr = new T [capacity];
}

template <class T>
t_stack<T>::~t_stack(){
    delete [] stackPtr;
}

template <class T>
void t_stack<T>::resize(){
    T * temp = new T [capacity*2];
 
    for(int j=0;j<capacity;j++)
	temp[j] = stackPtr[j];

    delete [] stackPtr;
    stackPtr = temp;
    capacity *= 2;
}

template <class T>
T t_stack<T>::operator [] (int index){
    return stackPtr[index];
}

template <class T>
bool t_stack<T>::isEmpty(){
    if(top == 0)
	return true;
    return false;
}

template <class T>
bool t_stack<T>::isFull(){
    if(top==(capacity-1))
	return true;
    return false;
}

template <class T>
bool t_stack<T>::push(T input){
    while (isFull()){
	resize();
    }
    if (!isFull()){    
	stackPtr[top] = input;
	top++;
	return true;
    }
    else 
	return false;
}

template <class T>
T t_stack<T>::pop() {
    top--;
    if(isEmpty())
	return stackPtr[top];
    return stackPtr[top];
}

template <class T>
int t_stack<T>::size(){
    return top;
}

template <class T>
void t_stack<T>::sort(){
    bool swap;
    T tmp;

    do{
	swap = false;
	for(int i=0; i < (size()-1); i++){
	    if(stackPtr[i]>stackPtr[i+1]){
		tmp = stackPtr[i];
		stackPtr[i] = stackPtr[i+1];
		stackPtr[i+1] = tmp;
		swap=true;
	    }
	}
    }while(swap);
}
