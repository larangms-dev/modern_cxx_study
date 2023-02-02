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
};

