#include "SingleLinkedList.h"
#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T>
void SingleLinkedList<T>::push_front(T value)
{
	auto newNode = std::make_shared<Node<T>>(value);
	newNode->next = head;
	head = newNode;
	size++;
}

template <typename T>
void SingleLinkedList<T>::push_back(T value)
{
	auto newNode = std::make_shared<Node<T>>(value);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		auto temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	size++;
}

template <typename T>
void SingleLinkedList<T>::pop_front()
{
	if (head == nullptr)
	{
		throw std::out_of_range("List is empty");
	}
	auto temp = head;
	head = head->next;
	temp->next = nullptr;
	size--;
}

template <typename T>
void SingleLinkedList<T>::pop_back()
{
	if (head == nullptr)
	{
		throw std::out_of_range("List is empty");
	}
	if (head->next == nullptr)
	{
		head = nullptr;
	}
	else
	{
		auto temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
	}
	size--;
}

template <typename T>
T SingleLinkedList<T>::get(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of range");
	}
	auto temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
void SingleLinkedList<T>::insert(int index, T value)
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
		auto newNode = std::make_shared<Node<T>>(value);
		auto temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		size++;
	}
}

template <typename T>
void SingleLinkedList<T>::erase(int index) {
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
		nodeToDelete->next = nullptr;
		size--;
	}
}

template <typename T >
int SingleLinkedList<T>::getSize()
{
	return size;
}

template <typename T>
bool SingleLinkedList<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
int SingleLinkedList<T>::find(T value)
{
	auto temp = head;
	int index = 0;
	while (temp)
	{
		if (temp->data == value)
		{
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}