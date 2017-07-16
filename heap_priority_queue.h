#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue : public AbstractPriorityQueue<T>
{
public:

	// return true if the priority queue is empty
	bool isEmpty();

	// insert item into the queue
	// may throw on allocation failure
	void add(const T& item);

	// remove highest priority item from the queue
	// throws std::logic_error if queue is empty
	void remove();

	// get the item with the highest priority from the queue
	// throws std::logic_error if queue is empty
	T peek();
private:

	DynamicArrayList<T> confused; //creation of a dynamic arraylist


};

#include "heap_priority_queue.txx"

#endif// _HEAP_PRIORITY_QUEUE_H_
