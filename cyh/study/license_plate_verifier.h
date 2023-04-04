#pragma once
#include <iostream>
#include <string>

constexpr int32_t LICENSE_PLATE_MAX_LENGTH = 11;

class LicensePlate
{
	friend class LicensePlateVerifier;
public:
	LicensePlate();
	LicensePlate(std::wstring_view license_str);
public:
	friend std::wostream& operator<< (std::wostream& wos, const LicensePlate& license_plate) noexcept;
	friend std::wistream& operator>> (std::wistream& wis, LicensePlate& license_plate);
public:
	void SetLicensePlate(std::wstring_view license_str);
private:
	wchar_t full_license_plate[LICENSE_PLATE_MAX_LENGTH];
	int32_t license_plate_number;
};

class LicensePlateVerifier
{
public:
	static bool Verification(LicensePlate license_plate);
	static int32_t GetLicensePlateNumber(LicensePlate license_plate);
};

