#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include <stdexcept>
#include <memory>

template <typename T>
struct NodeQueue
{
	T data;
	std::shared_ptr<NodeQueue<T>> next;
	NodeQueue(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue
{
protected:
	std::shared_ptr<NodeQueue<T>> front, back;
	int size;
public:
	Queue() : front(nullptr), back(nullptr), size(0) {}

	~Queue() {}

	void  enqueue(T value) final
	{
		auto newNode = std::make_shared<NodeQueue<T>>(value);
		if (back == nullptr)
		{
			front = newNode;
			back = newNode;
		}
		else
		{
			back->next = newNode;
			back = newNode;
		}
		size++;
	}

	T dequeue() final 
	{
		if (front == nullptr)
		{
			throw std::out_of_range("Queue is empty");
		}
		auto temp = front;
		front = front->next;
		if (front == nullptr)
		{
			back = nullptr;
		}
		temp->next = nullptr;
		size--;
		return temp->data;
	}

	T peek()
	{
		if (front == nullptr)
		{
			throw std::out_of_range("Queue is empty");
		}
		return front->data;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}
};

#endif