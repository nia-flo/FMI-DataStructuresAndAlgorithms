#include "Dequeue.h"

#include <iostream>

using namespace std;

int main()
{
	Dequeue<char> d;

	d.push_back('c');
	d.push_back('d');
	d.push_back('e');

	d.push_front('b');
	d.push_front('a');

	cout << d.front() << ' ' << d.back() << '\n';

	d.pop_front();
	d.pop_back();

	cout << d.front() << ' ' << d.back() << '\n';

	d.pop_front();
	d.pop_back();

	cout << d.front() << ' ' << d.back() << '\n';

	cout << d.isEmpty() << '\n';

	d.pop_back();

	cout << d.isEmpty() << '\n';

	return 0;
}