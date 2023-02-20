#include <sstream>

#include "ipv4.h"

IPv4::IPv4() noexcept
	: ip{ 0 }
{
}

IPv4::IPv4(UINT32 ip) noexcept
{
	Set(ip);
}

IPv4::IPv4(UINT8 part1, UINT8 part2, UINT8 part3, UINT8 part4) noexcept
{
	Set(part1, part2, part3, part4);
}

IPv4::IPv4(std::string_view ip_str)
	: ip{ 0 }
{
	Set(ip_str);
}

IPv4::IPv4(std::wstring_view ip_wstr)
	: ip{ 0 }
{
	Set(ip_wstr);
}

IPv4& IPv4::operator=(const IPv4& other) noexcept
{
	ip = other.ip;
	return *this;
}

IPv4& IPv4::operator++() noexcept
{
	++ip;
	return *this;
}

IPv4& IPv4::operator--() noexcept
{
	--ip;
	return *this;
}

IPv4& IPv4::operator++(int) noexcept
{
	ip++;
	return *this;
}

IPv4& IPv4::operator--(int) noexcept
{
	ip--;
	return *this;
}

IPv4 IPv4::operator+(UINT32 value) noexcept
{
	return IPv4(ip + value);
}

IPv4 IPv4::operator-(UINT32 value) noexcept
{
	return IPv4(ip - value);
}

IPv4& IPv4::operator+=(UINT32 value) noexcept
{
	ip += value;
	return *this;
}

IPv4& IPv4::operator-=(UINT32 value) noexcept
{
	ip -= value;
	return *this;
}

bool IPv4::operator==(const IPv4& other) const noexcept
{
	return ip == other.ip;
}

bool IPv4::operator!=(const IPv4& other) const noexcept
{
	return ip != other.ip;
}

bool IPv4::operator<(const IPv4& other) const noexcept
{
	return ip < other.ip;
}

bool IPv4::operator>(const IPv4& other) const noexcept
{
	return ip > other.ip;
}

bool IPv4::operator<=(const IPv4& other) const noexcept
{
	return ip <= other.ip;
}

bool IPv4::operator>=(const IPv4& other) const noexcept
{
	return ip >= other.ip;
}

UINT32 IPv4::Get() const noexcept
{
	return ip;
}

std::string IPv4::ToString() const noexcept
{
	std::wstring wstr = ToWString();
	return std::string(wstr.begin(), wstr.end());
}

std::wstring IPv4::ToWString() const noexcept
{
	UINT8 part1 = (UINT8)(ip >> 24);
	UINT8 part2 = (UINT8)(ip >> 16);
	UINT8 part3 = (UINT8)(ip >> 8);
	UINT8 part4 = (UINT8)ip;

	std::wstringstream wss;

	wss << part1 << L"." << part2 << L"." << part3 << L"." << part4;

	return wss.str();
}

void IPv4::Set(UINT32 ip) noexcept
{
	this->ip = ip;
}

void IPv4::Set(UINT8 part1, UINT8 part2, UINT8 part3, UINT8 part4) noexcept
{
	ip = part4;
	ip |= part3 << 8;
	ip |= part2 << 16;
	ip |= part1 << 24;
}

void IPv4::Set(std::string_view str)
{
	std::wstring wstr;
	wstr.assign(str.begin(), str.end());
	Set(wstr);
}

void IPv4::Set(std::wstring_view wstr)
{
	ip = 0;

	std::wstringstream wss(wstr.data());
	std::wstring part;
	UINT16 count = 3;

	try
	{
		while (count >= 0 && std::getline(wss, part, L'.'))
		{
			ip |= std::stoi(part) << (8 * count);
			count--;
		}
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "(w)string ip address was incorrectly" << '\n';
	}
}

std::ostream& operator<<(std::ostream& os, const IPv4& ip) noexcept
{
	os << ip.ToString();
	return os;
}

std::wostream& operator<<(std::wostream& wos, const IPv4& ip) noexcept
{
	wos << ip.ToWString();
	return wos;
}

std::istream& operator>>(std::istream& is, IPv4& ip)
{
	std::string str;
	is >> str;
	ip.Set(str);

	return is;
}

std::wistream& operator>>(std::wistream& wis, IPv4& ip)
{
	std::wstring wstr;
	wis >> wstr;
	ip.Set(wstr);

	return wis;
}