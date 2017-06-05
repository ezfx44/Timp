#include <iostream>

template <typename T> class Queue
{
private:
	T* queueptr;
	int size;
	T top;
public:
	Queue();
	Queue(const T& size);
	~Queue();

	void print()const;
	T operator[] (const T& num)const;
	void add(const T& value);
	bool isFull()const;
	void pop();
	T get()const;

};

template <typename T> Queue<T>::Queue()
{
	queueptr = new T[5]();
	top = 0;
	size = 5;
}

template<typename T> Queue<T>::Queue(const T& _size)
{
	queueptr = new T[_size]();
	top = 0;
	size = _size;
}

template <typename T> Queue<T>::~Queue()
{
	delete[] queueptr;
}

template<typename T> T Queue<T>::operator[](const T& num)const
{
	return queueptr[num];
}

template<typename T> bool Queue<T>::isFull()const
{
	return (top >= size);
}

template<typename T> void Queue<T>::add(const T& value)
{
	if (size == 0)
	{
		delete[] queueptr;
		queueptr = new T[1]();
		queueptr[0] = value;
		++size;
		return;
	}
	
	
	if (!top && !queueptr[0])
	{
		queueptr[0] = value;
		return;
	}
	++top;
	if (isFull())
	{
		T* ptr = new T[size + 1]();
		for (int i = 0; i < size; i++)
			ptr[i] = queueptr[i];
		delete[] queueptr;
		queueptr = ptr;
		++size;
		queueptr[top] = value;
	}
	else
	{
		queueptr[top] = value;
	}
}

template<typename T> void Queue<T>::print()const
{
	if (size)
	{
		for (int i = 0; i < size; i++)
			std::cout << queueptr[i] << "\t";
		std::cout << "\n";
	}
	else std::cout << "Queue is empty!";
}

template<typename T> void Queue<T>::pop()
{
	if (top)
	{
		T* ptr = new T[size - 1];
		for (int i = 0; i < size - 1; i++)
			ptr[i] = queueptr[i + 1];
		delete[] queueptr;
		queueptr = ptr;
		--size;
		--top;
	}
	else
	{
		std::cout << "Now queue is empty!\n";
		if (top == 0)
		{
			delete[] queueptr;
			queueptr = nullptr;
			size = 0;
		}
	}
}

template<typename T> T Queue<T>::get()const
{
	return queueptr[top];
}

int main()
{
	int _size, value;
	char ch = '9';
	std::cout << "Enter the size: ";
	std::cin >> _size;
	Queue<int> test(_size);
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
