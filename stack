#include <iostream>

template <typename T> class Stack
{
private: 
	T* stackptr;
	int size;
	T top;
public:
	Stack();
	Stack(const T& size);
	~Stack();
	
	void print()const;
	T operator[] (const T& num)const;
	void add(const T& value);
	bool isFull()const;
	void pop();
	T get()const;

};

template <typename T> Stack<T>::Stack()
{
	stackptr = new T [5]();
	top = 0;
	size = 5;
}

template<typename T> Stack<T>::Stack(const T& _size)
{
	stackptr = new T[_size]();
	top = 0;
	size = _size;
}

template <typename T> Stack<T>::~Stack()
{
	delete[] stackptr;
}

template<typename T> T Stack<T>::operator[](const T& num)const
{
	return stackptr[num];
}

template<typename T> bool Stack<T>::isFull()const
{
	return (top >= size);
}

template<typename T> void Stack<T>::add(const T& value)
{	
	if (size == 0)
	{
		delete[] stackptr;
		stackptr = new T[1]();
		stackptr[0] = value;
		++size;
		return;
	}
	
	if (!top && !stackptr[0])
	{
		stackptr[0] = value;
		return;
	}

	++top;
	
	if (isFull())
	{
		T* ptr = new T[size + 1]();
		for (int i = 0; i < size; i++)
			ptr[i] = stackptr[i];
		delete[] stackptr;
		stackptr = ptr;
		++size;
		stackptr[top] = value;
	}
	else
	{	
		stackptr[top] = value;
	}
}

template<typename T> void Stack<T>::print()const
{
	if (size)
	{

		for (int i = 0; i < size; i++)
			std::cout << stackptr[i] << "\t";
		std::cout << "\n";
	}
	else std::cout << "Stack is empty!";
}

template<typename T> void Stack<T>::pop()
{
	if (top)
	{
		T* ptr = new T[size - 1];
		for (int i = 0; i < size - 1; i++)
			ptr[i] = stackptr[i];
		delete[] stackptr;
		stackptr = ptr;
		--size;
		--top;
	}
	else
	{
		std::cout << "Now stack is empty!\n";
		if (top == 0)
		{
			delete[] stackptr;
			stackptr = nullptr;
			size = 0;
		}
	}
}

template<typename T> T Stack<T>::get()const
{
	return stackptr[top];
}

int main()
{
	int _size, value;
	char ch = '9';
	std::cout << "Enter the size: ";
	std::cin >> _size;
	Stack<int> test(_size);
	while (ch != '0')
	{	
		std::cout << "\n\n--------------------------------------------------------------\n" <<
			"What do u want to do?\nPress:\n\"1\" to add data\n\"2\" to delete data\n\"3\" to show last element\n\"4\" to show the stack\n\"0\" to exit\n"
			<< "--------------------------------------------------------------" << "\n\n";

		std::cin >> ch;
		std::cout << "\n";
		switch (ch)
		{
		case '1':
		{
					std::cout << "Enter the value: ";
					std::cin >> value;
					test.add(value);
					break;
		}
		case '2':
		{
					test.pop();
					break;
		}
		case '3':
		{
					std::cout << "Last element: " << test.get() << "\n";
					break;
		}

		case '4':
		{
					test.print();
					break;
		}
		}
	}

	system("pause");
	return 0;
}
