#include "ProcessingQueue.h"
#include <stdexcept>
#include <string>

#pragma region Methods
int ProcessingQueue::enqueue(int data) {
	int result = 0;
	if (isFull() || data == 0) return result;
	if (body[rearIndex] == 0 || body[rearIndex] == data){
		bool flag = false;
		if (body[rearIndex] == 0)
			size += 1;
		else
			flag = true;
		result = body[rearIndex] * 2;
		body[rearIndex] += data;
		if(flag){
			rearIndex = (rearIndex + 1) % maxSize;
			body[rearIndex] = 0;
		}
	} else {
		rearIndex = (rearIndex + 1) % maxSize;
		body[rearIndex] = data;
		size += 1;
	}
	return result;
}

int ProcessingQueue::dequeue() {
	using namespace std;
	int result = 0;
	if (isEmpty()) return result;
	result = body[frontIndex];
	frontIndex = (frontIndex + 1) % maxSize;
	size -= 1;
	return result;
}

int ProcessingQueue::getSize() const {
	return maxSize;
}

bool ProcessingQueue::isFull() const {
	return size == maxSize;
}

bool ProcessingQueue::isEmpty() const {
	return size == 0;
}

void ProcessingQueue::clear(){
    size = 0;
    frontIndex = rearIndex = 0;
    body[0] = 0;
}
#pragma endregion

#pragma region Operators
int ProcessingQueue::operator[](int index) {
	using namespace std;
	if (index >= maxSize || index < 0) 
		throw new std::out_of_range(NULL);
	return body[(frontIndex + index) % maxSize];
}
#pragma endregion

#pragma region Constructor & Destructor
ProcessingQueue::ProcessingQueue(int size) : maxSize(size)
{
	body = new int[size];
    clear();
}


ProcessingQueue::~ProcessingQueue()
{
	delete[] body;
}
#pragma endregion
