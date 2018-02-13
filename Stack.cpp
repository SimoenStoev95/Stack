#include<iostream>
using namespace std;

template<typename T = int>
class Stack {
public:
	// The big four
	Stack();
	Stack(const Stack<T>&);
	~Stack();
	Stack<T>& operator=(const Stack<T>&);
	// Push and Pop
	void pop(T&);
	void push(T);
	// Full and Empty
	bool full() const;
	bool empty() const;
	// Get Peak
	void getPeak(T&) const;
	// Print
	void print();
	// Resize
	void resize();
private:
	void copy(const Stack<T>&);
	void deletee();
	T* elem;
	int size;
	int curSize;
};

template<typename T>
Stack<T>::Stack()
{
	size = 10;
	curSize = -1;
	elem = new T[size];
}

template<typename T>
Stack<T>::~Stack()
{
	deletee();
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		deletee();
		copy(other);
	}
	return *this;
}

template<typename T>
void Stack<T>::deletee()
{
	delete[] elem;
}

template<typename T>
void Stack<T>::copy(const Stack<T>& other)
{
	size = other.size;
	curSize = other.curSize;
	elem = new T[size];
	for (int i = 0; i <= curSize; i++)
		elem[i] = other.elem[i];
}

template<typename T>
void Stack<T>::resize()
{
	T* temp = new T[curSize+1];
	for (int i = 0; i <= curSize; i++)
		temp[i] = elem[i];
	delete[] elem;
	size *= 2;
	elem = new T[size];
	for (int i = 0; i <= curSize; i++)
		elem[i] = temp[i];
	delete[] temp;
}

template<typename T>
bool Stack<T>::full() const
{
	return curSize - 1 == size;
}

template<typename T>
bool Stack<T>::empty() const
{
	return curSize == -1;
}

template<typename T>
void Stack<T>::pop(T& temp)
{
	if (empty())
	{
		cout << "The stack is empty, you can't remove an element." << endl;
	}
	else
	{
		temp = elem[curSize];
		curSize--;
	}
}

template<typename T>
void Stack<T>::push(T temp)
{
	if (full())
		resize();
	curSize++;
	elem[curSize] = temp;
}

template<typename T>
void Stack<T>::getPeak(T& temp) const
{
	if (empty())
	{
		cout << "The stack is empty, you cannot get the last element." << endl;
	}
	else
		temp = elem[curSize];
}

template<typename T>
void Stack<T>::print()
{
	T help;
	while (!empty())
	{
		pop(help);
		cout << help << endl;
	}
}