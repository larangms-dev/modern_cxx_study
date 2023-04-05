#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "temperature.h"
#include "ipv4.h"
#include "license_plate_verifier.h"
#include "date_formatter.h"

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
	auto DD_MM_YYYY1 = DateFormatter::ChangeDateFormat(L"12.25.2023", DATE_FORMAT::YYYY_MM_DD, L'&');
	auto DD_MM_YYYY2 = DateFormatter::ChangeDateFormat(L"2023.12.25", DATE_FORMAT::DD_MM_YYYY, L'/');

	wcout << DD_MM_YYYY1 << "  " << DD_MM_YYYY2 << "\n";

	return 0;
}