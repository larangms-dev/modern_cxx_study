#pragma once
#include <vector>
#include <string>

#include "using_types.h"

using namespace std;

class Function
{
public:
	// 소인수분해
	static vector<UINT64> PrimeFactorization(UINT64 n);
	static UINT64 BinaryToGrayCode(UINT64 n);
	static UINT64 GrayCodeToBinary(UINT64 n);
	// 2^x + (0 or 1)에서 x의 값을 반환
	static UINT64 Exponent(UINT64 n);
	// base값의 index 번째 비트를 반환
	static UINT64 Bit(UINT64 base, UINT64 index);
	// n을 로마숫자로 변환하여 반환
	static wstring RomaNumber(UINT64 n);
	// 템플릿 가변 인자를 사용하여 < 연산자를 사용해 가장 작은 값을 반환하는 함수
	template<typename T>
	static T Min(const T op1, const T op2);
	template<typename T, typename... Arg>
	static T Min(T op1, Arg... args);
	// 컨테이너에 여러 값을 추가하는 함수 push_back 함수가 구현되어 있어야 함
	template<typename Container, typename... Arg>
	static void PushBacks(Container& container, Arg&&... args);
	// 컨테이너 안의 원소를 조건별로 확인하는 함수 작성
	template<typename Container, typename T>
	static bool Contains(const Container& container, const T& value);
	template<typename Container, typename... Arg>
	static bool Any(const Container& container, Arg&&... args);
	template<typename Container, typename... Arg>
	static bool All(const Container& container, Arg&&... args);
	template<typename Container, typename... Arg>
	static bool None(const Container& container, Arg&&... args);
};

template<typename T>
inline T Function::Min(const T op1, const T op2)
{
	return op1 < op2 ? op1 : op2;
}

template<typename T, typename ...Arg>
inline T Function::Min(T op1, Arg ...args)
{
	return Min(op1, Min(args...));
}

template<typename Container, typename ...Arg>
inline void Function::PushBacks(Container& container, Arg&&... args)
{
	// c++17 fold experssion
	(container.push_back(args), ...);
}

template<typename Container, typename T>
inline bool Function::Contains(const Container& container, const T& value)
{
	return std::end(container) != std::find(std::begin(container), std::end(container), value);
}

template<typename Container, typename ...Arg>
inline bool Function::Any(const Container& container, Arg && ...args)
{
	return (Contains(container, args) || ...);
}

template<typename Container, typename ...Arg>
inline bool Function::All(const Container& container, Arg && ...args)
{
	return (Contains(container, args) && ...);
}

template<typename Container, typename ...Arg>
inline bool Function::None(const Container& container, Arg && ...args)
{
	return !Any(container, args...);
}
