#include <cmath>

#include "pch.h"
#include "function.h"

vector<UINT64> Function::PrimeFactorization(UINT64 n)
{
	vector<UINT64> answer;

	// n의 제곱근을 구하는 이유는
	// 10을 예로들면 10의 제곱근은 대략 3이다 (9의 제곱근이 3이며 16의 제곱근이 4)
	// 따라서 3보다 작은 수의 배수를 거르면
	//		2, 4, 6, 8, 10
	//		3, 6, 9
	//		1(무시), 5, 7이되고
	// 10에서 작은 값 부터 나눌 경우 (10 / 5 = 2)가 되며
	// 몫인 2로 다시 반복을 수행할 경우 2의 제곱근은 1보다 작기에 for문을 수행하지 않고 바로 나누어 버린다.
	//																				   (n /= n_mpn)
	// 2 / 2 = 1이 되기에 while문이 종료된다.
	// answer(5, 2)

	UINT64 n_sqrt = floor(sqrt(n)), n_mpn = 0;

	while (n > 1)
	{
		n_mpn = n;

		for (size_t i = 2; i <= n_sqrt; i++)
		{
			if (n % i == 0)
			{
				n_mpn = i;
				break;
			}
		}

		answer.emplace_back(n_mpn);
		n /= n_mpn;
	}

	return answer;
}

UINT64 Function::BinaryToGrayCode(UINT64 n)
{
	UINT64 answer = 0, n_exponent = Exponent(n);
	// 최상위 비트는 그대로 적용
	answer |= 1ull << n_exponent;

	// n의 i 번째 비트와 n의 i + 1 번째 비트(i 번째 비트보다 한칸 왼쪽에 있는)와 XOR 연산
	for (UINT64 i = 0; i < n_exponent; i++)
	{
		// XOR 연산 결과가 i 번째 비트에 반영되어야 하므로 i만큼 왼쪽 쉬프트 연산 수행
		answer |= (Bit(n, i) ^ Bit(n, i + 1)) << i;
	}

	return answer;
}

UINT64 Function::GrayCodeToBinary(UINT64 n)
{
	UINT64 answer = 0, n_exponent = Exponent(n);
	// 최상위 비트는 그대로 적용
	answer |= 1ull << n_exponent;

	// answer의 i + 1 번째 비트(i 번째 비트보다 한칸 왼쪽에 있는)와 n의 i 번째 비트와 XOR 연산
	for (UINT64 i = n_exponent - 1; i > 0; i--)
	{
		// XOR 연산 결과가 i 번째 비트에 반영되어야 하므로 i만큼 왼쪽 쉬프트 연산 수행
		answer |= (Bit(answer, i + 1) ^ Bit(n, i)) << i;
	}

	// for문의 조건식을 i >= 0으로 할 경우 무한 반복이 됨
	answer |= (Bit(answer, 1) ^ Bit(n, 0));

	return answer;
}

UINT64 Function::Exponent(UINT64 n)
{
	UINT64 answer = 0;

	// 최상위 비트가 몇 번째 비트인지 확인
	// n을 오른쪽으로 1칸씩 밀면서 1이상이면 반복
	while (n = n >> 1)
	{
		++answer;
	}

	return answer;
}

UINT64 Function::Bit(UINT64 base, UINT64 index)
{
	// base에 대해서 1을 index만큼 왼쪽으로 밀었을 때 그 비트가 1인지 0인지 확인
	return (base & (1ull << index) ? 1 : 0);
}

struct RomanPair
{
	wstring roman;
	UINT64 value;
};
wstring Function::RomaNumber(UINT64 n)
{
	wstring answer;
	vector<RomanPair> romans
	{
		{ L"=X=C",   90000000 }, { L"=L", 50000000 }, { L"=X=L", 40000000 }, { L"=X", 10000000 },
		{ L"-F-M-F", 9000000 },  { L"-F", 5000000 },  { L"-M-F", 4000000 },  { L"-M", 1000000 },
		{ L"-C-M",   900000 },   { L"-D", 500000 },   { L"-C-D", 400000 },   { L"-C", 100000 },
		{ L"-X-C",   90000 },    { L"-L", 50000 },    { L"-X-L", 40000 },    { L"-X", 10000 },
		{ L"FMF",    9000 },     { L"F",  5000 },     { L"MF",   4000 },     { L"M",  1000 },
		{ L"CM",     900 },      { L"D",  500 },      { L"CD",   400 },      { L"C",  100 },
		{ L"XC",     90 },       { L"L",  50 },       { L"XL",   40 },       { L"X",  10 },
		{ L"IX",     9 },        { L"V",  5 },        { L"IV",   4 },        { L"I",  1 },
	};

	// 몫
	double share = 0;
	// 나머지
	UINT64 remainder = 0;
	// 제일 큰 수 부터 연산을 수행
	for (auto& iter : romans)
	{
		// 몫 구하기
		share = n / iter.value;
		// 나머지 구하기
		remainder = n % iter.value;
		// 나머지 대입
		// 12 % 90000000 = 12
		// 12 % 10 = 2
		n = remainder;

		// 몫이 1보다 크다면 몫 만큼 반복하면서 나누었던 수의 로마자를 추가한다.
		// 12(XII) / 10(X) = 1.2
		// answer(X)
		for (UINT64 j = 0; j < share; j++)
		{
			answer += iter.roman;
		}

		// 나머지가 0이면 종료
		if (n == 0)
		{
			break;
		}
	}

	return answer;
}
