#include "temperature.h"

Temperature& Temperature::operator=(const Temperature& other) noexcept
{
	kelvin = other.kelvin;
	return *this;
}

Temperature Temperature::operator-() noexcept
{
	return Temperature(-kelvin);
}

Temperature Temperature::operator+(const Temperature& other) noexcept
{
	long double temp = kelvin + other.kelvin;

	if (temp < 0)
	{
		temp = 0;
	}

	return Temperature(temp);
}

Temperature Temperature::operator-(const Temperature& other) noexcept
{
	long double temp = kelvin - other.kelvin;

	if (temp < 0)
	{
		temp = 0;
	}

	return Temperature(temp);
}

Temperature Temperature::operator*(const Temperature& other) noexcept
{
	long double temp = kelvin * other.kelvin;

	if (temp < 0)
	{
		temp = 0;
	}

	return Temperature(temp);
}

Temperature Temperature::operator/(const Temperature& other) noexcept
{
	long double temp = kelvin / other.kelvin;

	if (temp < 0)
	{
		temp = 0;
	}

	return Temperature(temp);
}

Temperature& Temperature::operator+=(const Temperature& other) noexcept
{
	kelvin = this->operator+(other).kelvin;
	return *this;
}

Temperature& Temperature::operator-=(const Temperature& other) noexcept
{
	kelvin = this->operator-(other).kelvin;
	return *this;
}

Temperature& Temperature::operator*=(const Temperature& other) noexcept
{
	kelvin = this->operator*(other).kelvin;
	return *this;
}

Temperature& Temperature::operator/=(const Temperature& other) noexcept
{
	kelvin = this->operator/(other).kelvin;
	return *this;
}

bool Temperature::operator==(const Temperature& other) const noexcept
{
	return kelvin == other.kelvin;
}

bool Temperature::operator!=(const Temperature& other) const noexcept
{
	return kelvin != other.kelvin;
}

bool Temperature::operator<(const Temperature& other) const noexcept
{
	return kelvin < other.kelvin;
}

bool Temperature::operator>(const Temperature& other) const noexcept
{
	return kelvin > other.kelvin;
}

bool Temperature::operator<=(const Temperature& other) const noexcept
{
	return kelvin <= other.kelvin;
}

bool Temperature::operator>=(const Temperature& other) const noexcept
{
	return kelvin >= other.kelvin;
}

long double Temperature::C()
{
	if (kelvin < 0)
	{
		kelvin = 0;
	}
	return kelvin - 273.15;
}

long double Temperature::F()
{
	if (kelvin < 0)
	{
		kelvin = 0;
	}
	return (kelvin - 273.15) * (9.0 / 5.0) + 32;
}

long double Temperature::K()
{
	if (kelvin < 0)
	{
		kelvin = 0;
	}
	return kelvin;
}

Temperature operator"" _C(long double c) noexcept
{
	return Temperature(c + 273.15);
}
Temperature operator"" _F(long double f) noexcept
{
	return Temperature((f - 32.0) * (5.0 / 9.0) + 273.15);
}
Temperature operator"" _K(long double k) noexcept
{
	return Temperature(k);
}