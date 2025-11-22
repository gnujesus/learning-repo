#include <iostream>
#include "vector.h"

int main()
{
	Vector<int> v;

	std::cout << '\n'
						<< "Before" << '\n';

	v.PushFront(3);
	v.PushFront(5);
	v.PushFront(5);

	for (int i = 0; i < v.Size(); i++)
	{
		std::cout << v[i] << '\n';
	}

	std::cout << '\n'
						<< "After" << '\n';

	v.Pop(0);

	for (int i = 0; i < v.Size(); i++)
	{
		std::cout << v[i] << '\n';

	}

std::cout << '\n'
						<< "After" << '\n';


	v.Clear();

	for (int i = 0; i < v.Size(); i++)
	{
		std::cout << v[i] << '\n';

	}


	return 0;
}
