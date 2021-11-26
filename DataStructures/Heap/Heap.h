#pragma once

#define INITIAL_CAPACITY 10

// Heap implements max heap
template <typename T>
class Heap
{
public:
	Heap(int capacity = INITIAL_CAPACITY);

	~Heap();

	void insert(const T& element);
	T top() const;
	void pop();

private:
	int* elements;
	int capacity;
	int elementCount;

	void expandElementsArray();
	int parentIndex(int index);
	int leftChildIndex(int index);
	int rightChildIndex(int index);
	void heapify(int rootIndex);
};

template<typename T>
inline Heap<T>::Heap(int capacity)
{
	this->capacity = capacity;
	this->elements = new int[this->capacity];
	this->elementCount = 0;
}

template<typename T>
inline Heap<T>::~Heap()
{
	delete[] this->elements;
}

template<typename T>
inline void Heap<T>::insert(const T& element)
{
	if (this->elementCount == this->capacity)
	{
		this->expandElementsArray();
	}

	this->elements[this->elementCount] = element;
	this->elementCount++;

	for (int index = this->elementCount - 1, parent = this->parentIndex(index); parent >= 0 && this->elements[parent] < this->elements[index]; index = parent, parent = this->parentIndex(parent))
	{
		T buffer = this->elements[parent];
		this->elements[parent] = this->elements[index]; 
		this->elements[index] = buffer;
	}
}

template<typename T>
inline T Heap<T>::top() const
{
	if (this->elementCount == 0)
	{
		return T();
	}

	return this->elements[0];
}

template<typename T>
inline void Heap<T>::pop()
{
	this->elementCount--;

	if (this->elementCount == 0)
	{
		return;
	}

	this->elements[0] = this->elements[this->elementCount];
	this->heapify(0);
}

template<typename T>
inline void Heap<T>::expandElementsArray()
{
	int* newElements = new int[this->capacity * 2];
	for (int i = 0; i < this->capacity; i++)
	{
		newElements[i] = this->elements[i];
	}

	delete[] this->elements;
	this->elements = newElements;
}

template<typename T>
inline int Heap<T>::parentIndex(int index)
{
	return (index - 1) / 2;
}

template<typename T>
inline int Heap<T>::leftChildIndex(int index)
{
	return 2 * index + 1;
}

template<typename T>
inline int Heap<T>::rightChildIndex(int index)
{
	return 2 * index + 2;
}

template<typename T>
inline void Heap<T>::heapify(int rootIndex)
{
	if (rootIndex < 0 || rootIndex >= this->elementCount)
	{
		return;
	}

	int leftChild = this->leftChildIndex(rootIndex);
	int rightChild = this->rightChildIndex(rootIndex);

	int maxElementIndex = rootIndex;
	if (leftChild < this->elementCount && this->elements[leftChild] > this->elements[maxElementIndex])
	{
		maxElementIndex = leftChild;
	}
	if (rightChild < this->elementCount && this->elements[rightChild] > this->elements[maxElementIndex])
	{
		maxElementIndex = rightChild;
	}

	if (maxElementIndex == rootIndex)
	{
		return;
	}

	T buffer = this->elements[rootIndex];
	this->elements[rootIndex] = this->elements[maxElementIndex];
	this->elements[maxElementIndex] = buffer;

	this->heapify(maxElementIndex);
}
