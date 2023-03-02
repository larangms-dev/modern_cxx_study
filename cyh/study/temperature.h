#pragma once

class Temperature
{
public:
	explicit Temperature(long double val)
		: kelvin{ val }
	{
	}
public:
	Temperature& operator=(const Temperature& other) noexcept;
	Temperature operator-() noexcept;
	Temperature operator+(const Temperature& other) noexcept;
	Temperature operator-(const Temperature& other) noexcept;
	Temperature operator*(const Temperature& other) noexcept;
	Temperature operator/(const Temperature& other) noexcept;
	Temperature& operator+=(const Temperature& other) noexcept;
	Temperature& operator-=(const Temperature& other) noexcept;
	Temperature& operator*=(const Temperature& other) noexcept;
	Temperature& operator/=(const Temperature& other) noexcept;
public:
	bool operator==(const Temperature& other) const noexcept;
	bool operator!=(const Temperature& other) const noexcept;
	bool operator<(const Temperature& other) const noexcept;
	bool operator>(const Temperature& other) const noexcept;
	bool operator<=(const Temperature& other) const noexcept;
	bool operator>=(const Temperature& other) const noexcept;
public:
	long double C();
	long double F();
	long double K();
private:
	long double kelvin;
};

Temperature operator"" _C(long double c) noexcept;
Temperature operator"" _F(long double f) noexcept;
Temperature operator"" _K(long double k) noexcept;