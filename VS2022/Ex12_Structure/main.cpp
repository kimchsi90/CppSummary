#include <iostream>

using namespace std;

struct Mystruct
{
	int first = 0;
	int second = 0;


	int Sum()
	{
		return first + second;
	}
};

int main()
{
	Mystruct a;
	cout << a.first << endl;


	return 0;
}
