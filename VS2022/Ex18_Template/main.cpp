#include <iostream>
#include <cstring>

using namespace std;


class MyInt
{
public:
	int data;
};

class MyChar
{
public:
	char data;
};

class MyDouble
{
public:
	double data;
};

template <typename T>
class MyType
{
public:
	T data;
};



int main()
{
	MyInt my_int;
	MyChar my_char;
	MyDouble my_double;

	my_int.data;
	my_char.data;
	my_double.data;

	MyType<char> my_type;
	my_type.data;

	return 0;
}



//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class MyInt
//{
//public:
//    int data_;
//};
//
//class MyDouble
//{
//public:
//    double data_;
//};
//
//template <typename T>
//class MyClass
//{
//public:
//    T data_;
//};
//
//
//int main()
//{
//    MyClass<int> my_int;
//    MyClass<double> my_double;
//
//    my_int.data_;
//    my_double.data_;
//
//    cout << sizeof(my_int) << " " << sizeof(my_double) << endl;
//
//    return 0;
//}
