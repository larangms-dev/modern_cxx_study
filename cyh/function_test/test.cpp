#include "pch.h"
#include "function.h"

TEST(function, prime_factorization)
{
	UINT64 n = 432894;
	auto& v = Function::PrimeFactorization(n);

	for (auto& iter : v)
	{
		n /= iter;
	}

	EXPECT_EQ(n, 1);
}

TEST(function, gray_code)
{
	UINT64 n = 0b1001;

	UINT64 n_gray_code = Function::BinaryToGrayCode(n);
	EXPECT_EQ(n_gray_code, 0b1101);

	UINT64 n_binary = Function::GrayCodeToBinary(n_gray_code);
	EXPECT_EQ(n_binary, 0b1001);

	n = 0b111101010101;
	n_gray_code = Function::BinaryToGrayCode(n);
	EXPECT_EQ(n_gray_code, 0b100011111111);

	n_binary = Function::GrayCodeToBinary(n_gray_code);
	EXPECT_EQ(n_binary, 0b111101010101);
}

TEST(function, exponent)
{
	UINT64 n = pow(2, 15);
	EXPECT_EQ(Function::Exponent(n), 15);

	n = 1 << 7;
	EXPECT_EQ(Function::Exponent(n), 7);
}

TEST(function, bit)
{
	EXPECT_EQ(Function::Bit(0b1001, 3), 1);
	EXPECT_EQ(Function::Bit(0b1001, 2), 0);
	EXPECT_EQ(Function::Bit(0b1001, 1), 0);
	EXPECT_EQ(Function::Bit(0b1001, 0), 1);
}

TEST(function, roma_number)
{
	EXPECT_EQ(Function::RomaNumber(666), L"DCLXVI");
	EXPECT_EQ(Function::RomaNumber(777), L"DCCLXXVII");
	EXPECT_EQ(Function::RomaNumber(888), L"DCCCLXXXVIII");
	EXPECT_EQ(Function::RomaNumber(999), L"CMXCIX");
}