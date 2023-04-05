#pragma once
#include <stdint.h>

#include <string>
#include <iostream>

class IPv4
{
public:
	IPv4() noexcept;
	IPv4(uint32_t ip) noexcept;
	IPv4(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4) noexcept;
	IPv4(std::string_view ip_str);
	IPv4(std::wstring_view ip_wstr);
public:
	IPv4& operator=(const IPv4& other) noexcept;
	IPv4& operator++() noexcept;
	IPv4& operator--() noexcept;
	IPv4& operator++(int) noexcept;
	IPv4& operator--(int) noexcept;
	IPv4 operator+(uint32_t value) noexcept;
	IPv4 operator-(uint32_t value) noexcept;
	IPv4& operator+=(uint32_t value) noexcept;
	IPv4& operator-=(uint32_t value) noexcept;
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
	uint32_t Get() const noexcept;
	std::string ToString() const noexcept;
	std::wstring ToWString() const noexcept;
public:
	void Set(uint32_t ip) noexcept;
	void Set(uint8_t part1, uint8_t part2, uint8_t part3, uint8_t part4) noexcept;
	void Set(std::string_view str);
	void Set(std::wstring_view wstr);
private:
	uint32_t ip;
};