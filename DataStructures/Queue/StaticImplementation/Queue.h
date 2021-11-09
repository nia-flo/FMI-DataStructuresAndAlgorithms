#pragma once

#define INITIAL_DATA_SIZE 4

template<typename T>
class Queue
{
public:
	Queue();

	~Queue();

	void push_back(const T& element);
	void pop_front();
	T front() const;
	bool isEmpty() const;

private:
	T* data;
	int capacity;
	int elementsCount;
};

template<typename T>
inline Queue<T>::Queue()
{
	this->data = new T[INITIAL_DATA_SIZE];
	this->elementsCount = 0;
	this->capacity = INITIAL_DATA_SIZE;
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] this->data;
}

template<typename T>
inline void Queue<T>::push_back(const T& element)
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
inline void Queue<T>::pop_front()
{
	if (this->elementsCount == 0)
	{
		return;
	}

	this->elementsCount--;

	if (this->elementsCount < this->capacity / 4)
	{
		this->capacity /= 2;
	}

	T* oldData = this->data;
	this->data = new T[this->capacity];

	for (int i = 0; i < this->elementsCount; i++)
	{
		this->data[i] = oldData[i + 1];
	}

	delete oldData;
}

template<typename T>
inline T Queue<T>::front() const
{
	return this->data[0];
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return this->elementsCount == 0;
}
