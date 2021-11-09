#pragma once

#define INITIAL_DATA_SIZE 4

template<typename T>
class Dequeue
{
public:
	Dequeue();

	~Dequeue();

	void push_front(const T& element);
	void push_back(const T& element);
	void pop_front();
	void pop_back();
	T front() const;
	T back() const;
	bool isEmpty() const;

private:
	T* data;
	int capacity;
	int elementsCount;
};

template<typename T>
inline Dequeue<T>::Dequeue()
{
	this->data = new T[INITIAL_DATA_SIZE];
	this->elementsCount = 0;
	this->capacity = INITIAL_DATA_SIZE;
}

template<typename T>
inline Dequeue<T>::~Dequeue()
{
	delete[] this->data;
}

template<typename T>
inline void Dequeue<T>::push_back(const T& element)
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
inline void Dequeue<T>::push_front(const T& element)
{
	if (this->elementsCount == this->capacity)
	{
		this->capacity *= 2;
	}

	T* oldData = this->data;
	this->data = new T[this->capacity];

	this->data[0] = element;
	for (int i = 0; i < this->elementsCount; i++)
	{
		this->data[i + 1] = oldData[i];
	}

	delete oldData;

	this->elementsCount++;
}

template<typename T>
inline void Dequeue<T>::pop_front()
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
inline void Dequeue<T>::pop_back()
{
	if (this->elementsCount == 0)
	{
		return;
	}

	this->elementsCount--;

	if (this->elementsCount < this->capacity / 4)
	{
		this->capacity /= 2;
		T* oldData = this->data;
		this->data = new T[this->capacity];

		for (int i = 0; i < this->elementsCount; i++)
		{
			this->data[i] = oldData[i];
		}

		delete oldData;
	}
}

template<typename T>
inline T Dequeue<T>::front() const
{
	return this->data[0];
}

template<typename T>
inline T Dequeue<T>::back() const
{
	return this->data[this->elementsCount - 1];
}

template<typename T>
inline bool Dequeue<T>::isEmpty() const
{
	return this->elementsCount == 0;
}
