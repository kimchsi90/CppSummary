//#include <iostream>
//
//using namespace std;
//
//
//class MyClass
//{
//public:
//	MyClass() // 생성자
//	{
//		cout << "MyClass" << endl;
//		cout << this << endl;
//	}
//
//	MyClass(int a) // 생성자
//	{
//		cout << "MyClass(int a)" << endl;
//		this->my_number_ = a;
//		cout << this << endl;
//
//	}
//
//	~MyClass() // 소멸자
//	{
//		cout << "~MyClass()" << endl;
//
//	}
//
//	void Increment(int a)
//	{
//		my_number_ += a;
//
//	}
//
//	void Print()
//	{
//		cout << "my_number: " << this->my_number_ << endl;
//	}
//
//
//private:
//	int my_number_ = 0;
//
//};
//
//
//
//int main()
//{
//	MyClass my_class1;
//	MyClass my_class2(123);
//
//	my_class1.Print();
//	my_class1.Increment(5);
//	my_class1.Print();
//
//	my_class2.Print();
//
//
//	return 0;
//}



/*
    홍정모 연구소 https://honglab.co.kr/
*/

#include <iostream>
#include <cstring>

using namespace std;

// public, private 접근 권한 확인

class MyClass
{
public:
    MyClass()
    {
        // 호출 시점 확인
        cout << "MyClass()" << endl;
    }

    MyClass(int number)
    {
        cout << "MyClass(int number)" << endl;

        // this pointer 소개
        this->number_ = number;
    }

    ~MyClass()
    {
        // 호출 시점 확인
        cout << "~MyClass()" << endl;
    }

    void Increment(int a)
    {
        number_ += a;
    }

    void Print()
    {
        cout << number_ << endl;
    }

private:
    int number_ = 0; // 초기값
};

int main()
{
    MyClass my_class1;
    MyClass my_class2(123);

    my_class1.Print();
    my_class2.Print();

    my_class1.Increment(1);
    my_class1.Print();

    // 배열 사용 가능
    // 포인터 사용 가능 등 안내
    // 기본 자료형과 비교

    return 0;
}
