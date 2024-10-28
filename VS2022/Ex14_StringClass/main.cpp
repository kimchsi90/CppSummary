#include <iostream>
#include <cstring>

using namespace std;


class MyString
{
public:
	MyString(const char *init_str)
	{
		cout << "MyString(const char *init_str)" << endl;
		cout << this << endl;

		// 1. 글자 수 먼저 확인
		size_ = 0;

		// null char를 포함하지 않는 글자 수를 세기
		// *init_str이 포인터라 직접 세보지 않으면 글자 수를 알 수 없음.
		while (init_str[size_] != '\0')
		{
			size_++;
		}

		// 2. 글자 수가 0이 아니면 동적 할당으로 필요한 만큼만 메모리 할당
		if (size_ > 0)
		{
			// 생성자 new가 있으면 나중에 꼭 소멸자 delete로 메모리를 반환해야 함
			str_ = new char[size_];
		}

		// 3. 복사
		// size_만큼만 복사한다는 것은 null char '\0'를 복사하지 않는 다는 것임
		// 이유: size를 알고 있기 때문에

		// 직접 복사
		/*for (int i = 0; i < size_; i++)
		{
			str_[i] = init_str[i];
		}*/

		// memcpy 이용
		memcpy(str_, init_str, size_);
	}

	~MyString()
	{
		cout << "Destructor" << endl;
		// 소멸자는 사용한 메모리를 반납하는 것이 중요한 비중을 차지함!

		size_ = 0;
		if (str_) // 동적 할당 받은 메모리가 있다면(주소가 0이 아니라면)
			delete[] str_;
	}

	void Resize(int new_size)
	{
		char* new_str = new char[new_size];
		
		
		// 방법 1. 직접 복사
		/*for (int i = 0; i < (new_size < size_ ? new_size : size_); i++)
		{
			new_str[i] = str_[i];
		}*/

		// 방법2. memcpy 이용
		memcpy(new_str, str_, size_);
		
		delete[] str_;
		str_ = new_str;
		size_ = new_size;

		// new_str 지우면 안 됨! 
	}

	void Print()
	{
		// 여기서 cout << str_을 사용할 수 없음. 한 글자 한 글자 출력해야 함.
		// 이유: 마지막에 null char '\0'이 있다는 보장이 없기 때문에
		// 위에서 null char는 복사하지 않았음
		for (int i = 0; i < size_; i++)
		{
			cout << str_[i];
		}
		cout << endl;
	}

	void Append(MyString *app_str)
	{
		int old_size = size_;

		Resize(size_ + app_str->size_);

		for (int i = old_size; i < size_; i++)
		{
			str_[i] = app_str->str_[i - old_size];
		}
	}


private:
	int size_ = 0;
	char *str_ = nullptr;
};


int main()
{
	MyString str1("abc"); // 생성자 이용
	MyString str2("123");

	str1.Append(&str2);

	str1.Print();

	//소멸자는 str1 변수가 사라질 때(더이상 메모리의 공간을 차지하지 못할 때) 알아서 호출됨

	exit(-1); // 여기까지만 실행하고 멈추라는 의미


	return 0;
}




/*
코딩 테스트 실전에서 매번 문자열 클래스, 동적 배열 클래스 등을 만들면서 문제를 풀 수는 없겠죠.그때는 std::string, std::vector 등을 가져다가 편하게 사용하게 됩니다.이러한 표준 컨테이너들의 사용법 위주로 공부하는 것이 공부 속도가 빠르다고 착각하는 경우가 많은데요, 역설적으로 코테 문제들의 대부분이 그것들이 어떻게 만들어져있는지 원리를 이해하고 있어야 풀 수 있는 것들입니다.

크고 좋은 회사일 수록 스스로 머리속에 그림을 그릴 수 있는 사람을 원합니다.코테의 1차 목표는 그런 능력이 없는 사람을 걸러내는 것입니다.
*/











///*
//    홍정모 연구소 https://honglab.co.kr/
//*/
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//// public, private 접근 권한 안내
//
//class MyString
//{
//public:
//    MyString()
//    {
//        // 호출 시점 확인
//        cout << "MyString()" << endl;
//
//        size_ = 1;
//        str_ = new char[size_];
//    }
//
//    MyString(const char *init_str) // init_str이 유효한 메모리라고 가정
//    {
//        cout << "MyString(const char *init_str)" << endl;
//
//        // 1. 글자 수 먼저 확인
//        size_ = 0;
//        while (init_str[size_] != '\0')
//        {
//            size_++; // ++ 연산자 안내
//        }
//
//        // 2. 글자 수가 0이 아니면 메모리 할당
//        if (size_ > 0)
//        {
//            str_ = new char[size_];
//        }
//
//        // 3. 복사
//        for (int i = 0; i < size_; i++)
//        {
//            str_[i] = init_str[i];
//        }
//        // memcpy() 사용 가능
//    }
//
//    ~MyString()
//    {
//        // 호출 시점 확인
//        cout << "Destructor" << endl;
//
//        size_ = 0;
//        if (str_)
//            delete[] str_;
//    }
//
//    void Resize(int new_size)
//    {
//        char *new_str = new char[new_size];
//
//        // memcpy() 사용 가능
//        for (int i = 0; i < (new_size < size_ ? new_size : size_); i++)
//        {
//            new_str[i] = str_[i];
//        }
//
//        delete[] str_;
//        str_ = new_str;
//        size_ = new_size;
//
//        // new_str 지우면 안되요!
//    }
//
//    void Print()
//    {
//        for (int i = 0; i < size_; i++)
//        {
//            cout << str_[i];
//        }
//        cout << endl;
//    }
//
//    void Append(MyString *app_str) // 같은 타입을 매개변수로 사용 가능
//    {
//        int old_size = size_;
//
//        // 다른 멤버 함수 호출 가능 안내
//        Resize(size_ + app_str->size_);
//
//        // 그림을 스스로 그려내서 이해할 수 있도록 도와줘야 함
//        for (int i = old_size; i < size_; i++)
//        {
//            str_[i] = app_str->str_[i - old_size];
//        }
//    }
//
//private:
//    int size_ = 0;        // m_size
//    char *str_ = nullptr; // m_str (여기서는 구글 스타일)
//};
//
//int main()
//{
//    // 클래스 기본 문법 안내
//
//    MyString str1("ABCDE"); // 생성자 이용
//    MyString str2("123");
//
//    str1.Append(&str2); // 주소 넣어줌
//
//    str1.Print();
//
//    return 0;
//}
