#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "temperature.h"
#include "ipv4.h"
#include "string_convertor.h"

using namespace std;

class MyClass
{
public:
	MyClass(uint32_t val)
		:val_{ val }
	{
	}

	MyClass(std::string val)
		:val_{ 0 }
	{
	}
private:

	uint32_t val_;
};

void F1(MyClass sp)
{

}

template<typename Func, typename Val>
void CallFunc(Func f, Val v)
{
	f(v);
}

//template<typename Func>
//void CallFunc(Func f, int v)
//{
//	f(v);
//}

//using TempFunc = void (*)(std::shared_ptr<MyStruct>);
//
//template<>
//void CallFunc(TempFunc f, int v)
//{
//	f(v);
//}

int main()
{
	F1(0);

	char* p;

	CallFunc(F1, p);

	std::shared_ptr<MyClass> a{ 0 };

	wcout << StringConvertor::ConvertToPascalCase(L"wellcome to nice c++ world! nice to meet you!") << L"\n";

	return 0;
}