#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include<iostream>
#include <stdexcept>
#include <memory>

template <typename T>
struct DoubleNode
{
	T data;
	std::shared_ptr<DoubleNode<T>> next;
	std::shared_ptr<DoubleNode<T>> prev;
	DoubleNode(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoubleLinkedList
{
private:
	std::shared_ptr<DoubleNode<T>> head, tail;
	int size;
public:
	DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~DoubleLinkedList() {}
	void push_front(T value) {
		auto newNode = std::make_shared<DoubleNode<T>>(value);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		size++;
	}

	void push_back(T value)
	{
		auto newNode = std::make_shared<DoubleNode<T>>(value);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			throw std::out_of_range("List is empty");
		}
		auto temp = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		temp->next = nullptr;
		size--;
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			throw std::out_of_range("List is empty");
		}
		if (head->next == nullptr)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			auto temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			temp->prev = nullptr;
		}
		size--;
	}

	T get(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index out of range");
		};
		auto temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->data;
	}

	void insert(int index, T value)
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Index out of range");
		}
		if (index == 0)
		{
			push_front(value);
		}
		else if (index == size)
		{
			push_back(value);
		}
		else
		{
			auto newNode = std::make_shared<DoubleNode<T>>(value);
			auto temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
			size++;
		}
	}

	void erase(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		if (index == 0)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			auto temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			auto nodeToDelete = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			nodeToDelete->next = nullptr;
			nodeToDelete->prev = nullptr;
			size--;
		}
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int find(T value)
	{
		auto temp = head;
		for (int i = 0; i < size; i++)
		{
			if (temp->data == value)
			{
				return i;
			}
			temp = temp->next;
		}
		return -1;
	}

	friend std::ostream& operator<<(std::ostream& out, const DoubleLinkedList<T>& list)
	{
		auto temp = list.head;
		while (temp != nullptr)
		{
			out << temp->data << " ";
			temp = temp->next;
		}
		return out;
	}
};

#endif 

