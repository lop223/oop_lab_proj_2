#ifndef OUTPUTRESRICTEDQUEUE_H
#define OUTPUTRESRICTEDQUEUE_H

#include<iostream>
#include <stdexcept>
#include <memory>
#include "Queue.h"


template <typename T>
class OutputRestrictedQueue : public Queue<int>
{
public:
	OutputRestrictedQueue() : Queue<T>() {}

	~OutputRestrictedQueue() {}

	void enqueue_front(T value)
	{
		auto newNode = std::make_shared<NodeQueue<T>>(value);
		if (this->front == nullptr)
		{
			this->front = newNode;
			this->back = newNode;
		}
		else
		{
			newNode->next = this->front;
			this->front = newNode;
		}
		this->size++;
	}

	void enqueue_back(T value)
	{
		auto newNode = std::make_shared<NodeQueue<T>>(value);
		if (this->back == nullptr)
		{
			this->front = newNode;
			this->back = newNode;
		}
		else
		{
			this->back->next = newNode;
			this->back = newNode;
		}
		this->size++;
	}
};


#endif