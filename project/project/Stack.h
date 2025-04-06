#ifndef STACK_H
#define STACK_H

template <typename T>
struct NodeStack
{
	T data;
	std::shared_ptr<NodeStack<T>> next;
	NodeStack(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack
{
private:
	std::shared_ptr<NodeStack<T>> top;
	int size;
public:
	Stack() : top(nullptr), size(0) {}

	~Stack() {}

	void push(T value)
	{
		auto newNode = std::make_shared<NodeStack<T>>(value);
		newNode->next = top;
		top = newNode;
		size++;
	}

	T pop()
	{
		if (top == nullptr)
		{
			throw std::out_of_range("Stack is empty");
		}
		auto temp = top;
		top = top->next;
		temp->next = nullptr;
		size--;
		return temp->data;
	}

	T peek()
	{
		if (top == nullptr)
		{
			throw std::out_of_range("Stack is empty");
		}
		return top->data;
	}

	int getSize() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	void printInfo() {
		std::cout << "Stack size: " << size << std::endl;
		std::cout << "Stack elements: ";
		auto current = top;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};

#endif

