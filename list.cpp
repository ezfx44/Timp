#include <iostream>
template <typename T> class List
{
private:
	
	T* list;
	int size;

public:
	List();
	List(const T& value);
	~List();
	void add(int num,  T value);
	void print()const;
	void del(int num);
	T get(int num);
};

template <typename T> List<T>::List()
{
	list = new T[5]();
	size = 5;
}
template<typename T> List<T>::List(const T& value)
{
	list = new T[value]();
	size = value;
}
template <typename T> List<T>::~List()
{
	delete[] list;
}
template<typename T> void List<T>::add(int num,  T value)
{
	if (num >= size)
	{
		T* ptr = new T [num+1]();
		for (int i = 0; i < size; i++)
			ptr[i] = list[i];
		delete[] list;
		list = ptr;
		size = num+1;
		list[num] = value;
	}
	else
	{
		list[num] = value;
	}
}

template<typename T> void List<T>::print()const
{
	if (size)
	{

		for (int i = 0; i < size; i++)
			std::cout << list[i] << "\t";
		std::cout << "\nSIZE *" << size << "*" << "\n\n";
	}
	else
	{
		std::cout << "List is empty!";
	}
}

template<typename T> void List<T>::del(int num)
{
	if (num < size)
	{
		int j = 0;
		T* ptr = new T[size - 1]();
		for (int i = 0; i < size; i++)
		{
			if (num == i)
				continue;
			ptr[j] = list[i];
			++j;
		}
		delete[] list;
		list = ptr;
		size--;
	}
	else {
		std::cout << "List is empty!";
	}
}

template<typename T> T List<T>::get(int num)
{
	if (num < size)
		return list[num];
	else
	{
		std::cout << "Error";
		exit(1);
	}
}
int main()
{
	int _size, value, key;
	char ch = '9';
	std::cout << "Enter the size: ";
	std::cin >> _size;
	List<int> test(_size);
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
					std::cout << "Enter the key: ";
					std::cin >> key;
					std::cout << "Enter the value: ";
					std::cin >> value;
					test.add(key, value);
					break;
		}
		case '2':
		{
					std::cout << "Enter the key: ";
					std::cin >> key;
					test.del(key);
					break;
		}
		case '3':
		{
					std::cout << "Enter the key: ";
					std::cin >> key;
					std::cout << "Last element: " << test.get(key) << "\n";
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
