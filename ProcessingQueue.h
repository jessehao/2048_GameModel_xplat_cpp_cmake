#pragma once
class ProcessingQueue
{
	int* body;
	int size;
	int maxSize;
	unsigned int frontIndex;
	unsigned int rearIndex;
public:
#pragma region Methods
	int enqueue(int data);
	int dequeue();
	int getSize() const;
	bool isFull() const;
	bool isEmpty() const;
    void clear();
#pragma endregion

#pragma region Operators
	int operator[](int index);
#pragma endregion

#pragma region Constructor & Destructor
	ProcessingQueue(int size);
	~ProcessingQueue();
#pragma endregion
};

