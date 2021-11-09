#pragma once

#define INITIAL_DATA_SIZE 4

template<typename T>
class Stack
{
public:
	Stack();

	~Stack();

	void push(const T& element);
	void pop();
	T top() const;
	bool isEmpty() const;

private:
	T* data;
	int capacity;
	int elementsCount;
};

template<typename T>
inline Stack<T>::Stack()
{
	this->data = new T[INITIAL_DATA_SIZE];
	this->elementsCount = 0;
	this->capacity = INITIAL_DATA_SIZE;
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] this->data;
}

template<typename T>
inline void Stack<T>::push(const T& element)
{
	if (this->elementsCount == this->capacity)
	{
		T* oldData = this->data;
		this->capacity *= 2;
		this->data = new T[this->capacity];

		for (int i = 0; i < this->elementsCount; i++)
		{
			this->data[i] = oldData[i];
		}

		delete oldData;
	}
	
	this->data[this->elementsCount] = element;
	this->elementsCount++;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (this->elementsCount == 0)
	{
		return;
	}

	this->elementsCount--;

	if (this->elementsCount < this->capacity / 4)
	{
		T* oldData = this->data;
		this->capacity /= 2;
		this->data = new T[this->capacity];

		for (int i = 0; i < this->elementsCount; i++)
		{
			this->data[i] = oldData[i];
		}

		delete oldData;
	}
}

template<typename T>
inline T Stack<T>::top() const
{
	return this->data[this->elementsCount - 1];
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return this->elementsCount == 0;
}
