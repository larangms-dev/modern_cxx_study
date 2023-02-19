#include <iostream>
#include <functional>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <list>
#include <array>
#include <assert.h>

// 가변 인자 함수 템플릿
// 참고(https://modoocode.com/290)
template <typename T>
T minimum(T const a, T const b) { return a < b ? a : b; }

template <typename T1, typename... T>
T1 minimum(T1 a, T... args)
{
	return minimum(a, minimum(args...));
}

// 사용자 정의 자료형을 사용하기 위한 템플릿
template <class Compare, typename T>
T minimumc(Compare comp, T const a, T const b) { return comp(a, b) ? a : b; }

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args)
{
	return minimumc(comp, a, minimumc(comp, args...));
}

// problem 19
template<typename C, typename... Args>
void push_back(C& c, Args&&... args)
{
	// Fold 식을 쓸 때 꼭 () 로 감싸줘야 한다
	(c.push_back(args), ...); // fold expressions(단항 우측 Fold) C++17
}

// problem 20
template<class C, class T>
bool contains(const C& c, const T& value)
{
	return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class... T>
bool contains_any(const C& c, T&&... value)
{
	return (... || contains(c, value));
}

template<class C, class... T>
bool contains_all(const C& c, T&&... value)
{
	return (... && contains(c, value));
}

template<class C, class... T>
bool contains_none(const C& c, T&&... value)
{
	return !contains_any(c, std::forward<T>(value)...);
}