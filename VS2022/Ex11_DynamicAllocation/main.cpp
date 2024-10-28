/*
    홍정모 연구소 https://honglab.co.kr/
*/

#include <iostream>
#include <cstring>

using namespace std;

const int kMaxStr = 100; // 전역 상수

// size_t는 64비트 부호가 없는 정수
size_t Min(size_t a, size_t b)
{
    return a < b ? a : b; // 삼항연산자
}

int main()
{
    // 문자열 복사
    char str1[] = "Hello, World!";
    char str2[kMaxStr];
    // str1과 str2는 초기화 시 대괄호[]를 사용했기 때문에 컴파일러가 배열로 사용할 것이라는 것을 미리 알 수 있다.
    // 컴파일러가 배열이라는 것을 알면 편리한 점도 있지만 단점도 있는데 크기가 고정되어 바꿀 수 없고
    // 아주 큰 메모리를 사용할 수 없다.
    // 정적 배열(크기가 고정) static


    // str2 = str1; Error
    // str1은 내부적으로 포인터지만 실제 사용할 때는 문자열로 사용하기 때문에 주소를 복사하라는 것인지 내용인 문자열을 복사하라는 것에 대한 것인지가 문제가 됨
    
    // c언어 컴파일러 입장에서 두 개의 size가 달라 복사를 하는 것이 정의가 안 됨
    // c++ 언어 컴파일러 입장에서 개발자의 의도를 명확히 이해할 수 없기 때문에 오류 발생시키고 해주지 않는다.
    // 쉽게 말해 편의성이 부족하다.
    // c++ 언어는 편의 기능 보다는 효율성이 중요하기 때문에 이런 것들을 알아서 구현해주지 않음.

    // for문을 통해 하나씩 복사해도 되지만 우리는 sizeof를 통해 메모리 크기를 구하는 법을 알기 때문에 memory copy를 사용해보자.
    // sizeof(str1)은 배열이 사용하는 메모리 전체 크기

    // dest, src 안내 (복사할 메모리 크기 주의 안내)
    // memcpy에 마우스를 갖다 대면 사용법이 나오는데 destination의 포인터, source의 포인터, 크기
    memcpy(str2, str1, Min(sizeof(str1), sizeof(str2)));
    cout << "str2: " << str2 << endl;

    // 내가 이만큼의 메모리가 필요하다고 OS에게 요구해서 메모리 할당을 받게 되는데 new 키워드를 사용해서 OS에게 내가 할당받고 싶은 메모리를 요구하게 된다.
    // char[kMaxStr]는 얼핏보면 배열같지만 char type의 데이터가 kMaxStr개 만큼 들어갈 수 있는 메모리를 할당해 달라는 말
    // char는 1byte 이므로 1byte * kMaxStr인 100 = 100 bytes를 할당해 달라는 의미.
    // OS는 메모리 공간에서 100 bytes 만큼 할당할 수 있는 곳을 찾는다.
    // OS는 굉장히 많은 프로그램을 관리하고 있다. 그떄그때 상황을 봐서 여기있는 메모리를 쓰라고 하면 되겠구나 하고 결정해서 그 메모리 공간의 첫 번째 주소를 준다.
    // 그러면 우리는 이 포인터를 이용해서 메모리에 접근. 마치 배열처럼 이 메모리 공간을 사용할 수 있다.
    // 아래와 같이 사용할 수도 있고 아니면 pointer 연산자를 사용할 수 있다.
    char *dynamic_array = new char[kMaxStr];

    // 주의: 동적할당 메모리는 변수 사이즈가 포인터 사이즈임 (배열이 아님)
    memcpy(dynamic_array, str1, Min(sizeof(str1), kMaxStr));
    // memcpy(dynamic_array, str2, kMaxStr);
    cout << "dynamic_array: " << dynamic_array << endl;

    // str1, str2, dynamic_array는 포인터(주소 값)이다.
    // 이를 10진수로 변환해서 보면 str1과 str2는 비슷하고 dynamic_array는 다르다. 140737488345218 140737488345232 93842992326336
    // static 배열은 Stack에 잡혀있고 dynamic 배열은 Heap에 잡혀있기 때문이다. 그래서 주소 값 차이가 많이 난다.
    // Stack은 많이 잡으면 stack overflow가 일어나고 Heap은 OS가 많이 잡아놓는다.

    cout << "str1: " << str1 << " " << "str2: " << str2 << " " << dynamic_array << endl;
    cout << "size_t(str1): " << size_t(str1) << " " "size_t(str2): " << size_t(str2) << " " << "size_t(dynamic_array): " << size_t(dynamic_array) << endl;

    // 보통 크기를 별도로 저장함
    // 다 사용한 메모리나 더이상 사용하지 않을 메모리를 OS에게 반납하는 것.
    // 대괄호를 붙이는데 숫자가 안 들어간 이유?????
    // OS가 이미 다 알고있다. 얼마나 메모리를 먹는지. 그래서 delete를 할 때는 굳이 크기를 알려주지 않아도 된다.
    // new로 할당한 메모리는 어딘가에서 delete[]을 해줘야 한다.
    // 경우에 따라 new로 할당한 포인터에 새로운 메모리를 다시 할당하는 경우도 있다. OS 입장에서는 첫 번째로 할당한 메모리도 주고 두 번째로 할당한 메모리도 줬는데
    // 우리 프로그램 입장에서는 기존의 메모리 주소를 알고있는 변수가 사라지기 때문에 첫 번째로 할당한 메모리를 접근할 수 없는 희안한 사태가 발생함.
    // 기초적인 c/c++ 프로그래밍을 할 때는 이런 것들을 주의해야 함.

    // 그래서 같은 포인터 변수에(기존에 동적 할당한) 동적 할당을 새로 받고 싶다면 delete[]로 삭제하고 다시 받아야 함.
    // 그리고 새로 할당한 메모리도 다 쓰고나면 지워야 함.
    // 메모리 관리를 직접 해보는 것이 장기적으로 좋은 프로그래밍 습관을 들이는 데 도움이 많이 된다.

    delete[] dynamic_array; // 배열 삭제시 []

    // 지우지 않고 재할당할 경우 잃어버림
    // dynamic_array = new char[원하는크기];
    // delete[] dynamic_array; 다시 지워줘야 함


    const char *p1 = "Hello, World!";
    const char *p2 = "Hi~~~";
    p1 = p2;
    cout << "p1: " << p1 << endl;

    return 0;
}
