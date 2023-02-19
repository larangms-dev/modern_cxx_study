#pragma once
#include <string>
#include <iostream>

#include "using_types.h"

class IPv4
{
public:
	IPv4();
	IPv4(UINT32 ip);
	IPv4(UINT8 part1, UINT8 part2, UINT8 part3, UINT8 part4);
	IPv4(std::string_view ip_str);
	IPv4(std::wstring_view ip_wstr);
public:
	IPv4& operator=(const IPv4& other) noexcept;
	IPv4& operator++() noexcept;
	IPv4& operator--() noexcept;
	IPv4& operator++(int) noexcept;
	IPv4& operator--(int) noexcept;
	IPv4 operator+(UINT32 value) noexcept;
	IPv4 operator-(UINT32 value) noexcept;
	IPv4& operator+=(UINT32 value) noexcept;
	IPv4& operator-=(UINT32 value) noexcept;
public:
	bool operator==(const IPv4& other) const noexcept;
	bool operator!=(const IPv4& other) const noexcept;
	bool operator<(const IPv4& other) const noexcept;
	bool operator>(const IPv4& other) const noexcept;
	bool operator<=(const IPv4& other) const noexcept;
	bool operator>=(const IPv4& other) const noexcept;
public:
	friend std::ostream& operator<< (std::ostream& os, const IPv4& ip) noexcept;
	friend std::wostream& operator<< (std::wostream& wos, const IPv4& ip) noexcept;
	friend std::istream& operator>> (std::istream& is, IPv4& ip);
	friend std::wistream& operator>> (std::wistream& wis, IPv4& ip);
public:
	UINT32 Get() const noexcept;
	std::string ToString() const noexcept;
	std::wstring ToWString() const noexcept;
public:
	void Set(UINT32 ip) noexcept;
	void Set(UINT8 part1, UINT8 part2, UINT8 part3, UINT8 part4) noexcept;
	void Set(std::string_view str);
	void Set(std::wstring_view wstr);
private:
	UINT32 ip;
};