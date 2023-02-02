#include <cmath>

#include "pch.h"
#include "function.h"

vector<UINT64> Function::PrimeFactorization(UINT64 n)
{
	vector<UINT64> answer;

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
	answer |= 1ull << n_exponent;

	for (UINT64 i = 0; i < n_exponent; i++)
	{
		answer |= (Bit(n, i) ^ Bit(n, i + 1)) << i;
	}

	return answer;
}

UINT64 Function::GrayCodeToBinary(UINT64 n)
{
	UINT64 answer = 0, n_exponent = Exponent(n);
	answer |= 1ull << n_exponent;

	for (UINT64 i = n_exponent - 1; i > 0; i--)
	{
		answer |= (Bit(answer, i + 1) ^ Bit(n, i)) << i;
	}

	answer |= (Bit(answer, 1) ^ Bit(n, 0));

	return answer;
}

UINT64 Function::Exponent(UINT64 n)
{
	UINT64 answer = 0;

	while (n = n >> 1)
	{
		++answer;
	}

	return answer;
}

UINT64 Function::Bit(UINT64 base, UINT64 index)
{
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
		{ L"=X=C", 90000000 }, { L"=L", 50000000 }, { L"=X=L", 40000000 }, { L"=X", 10000000 },
		{ L"-M=X", 9000000 },  { L"-F", 5000000 },  { L"-M-F", 4000000 },  { L"-M", 1000000 },
		{ L"-C-M", 900000 },   { L"-D", 500000 },   { L"-C-D", 400000 },   { L"-C", 100000 },
		{ L"-X-C", 90000 },    { L"-L", 50000 },    { L"-X-L", 40000 },    { L"-X", 10000 },
		{ L"M-X",  9000 },     { L"F",  5000 },     { L"MF",   4000 },     { L"M",  1000 },
		{ L"CM",   900 },      { L"D",  500 },      { L"CD",   400 },      { L"C",  100 },
		{ L"XC",   90 },       { L"L",  50 },       { L"XL",   40 },       { L"X",  10 },
		{ L"IX",   9 },        { L"V",  5 },        { L"IV",   4 },        { L"I",  1 },
	};

	double share = 0;
	UINT64 remainder = 0;
	for (auto& iter : romans)
	{
		share = n / iter.value;
		remainder = n % iter.value;
		n = remainder;

		for (UINT64 j = 0; j < share; j++)
		{
			answer += iter.roman;
		}
	}

	return answer;
}
