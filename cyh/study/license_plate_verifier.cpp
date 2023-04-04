#include "license_plate_verifier.h"

LicensePlate::LicensePlate()
	: full_license_plate{ 0, }, license_plate_number{ 0 }
{
}

LicensePlate::LicensePlate(std::wstring_view license_str)
	: license_plate_number{ 0 }
{
	SetLicensePlate(license_str);
}

void LicensePlate::SetLicensePlate(std::wstring_view license_str)
{
	const auto license_str_size = license_str.size();

	if (license_str_size != LICENSE_PLATE_MAX_LENGTH &&
		license_str_size != (LICENSE_PLATE_MAX_LENGTH - 1))
	{
		return;
	}

	memset(full_license_plate, 0, LICENSE_PLATE_MAX_LENGTH);
	memcpy(full_license_plate, license_str.data(), license_str_size * sizeof(wchar_t));
	license_plate_number = 0;

	constexpr int32_t start_index = 7;
	int32_t temp{ 0 };

	for (int32_t i = license_str_size - 1; i >= start_index; i--)
	{
		temp = full_license_plate[i] - L'0';
		license_plate_number += pow(10, license_str_size - i - 1) * temp;
	}
}

bool LicensePlateVerifier::Verification(LicensePlate license_plate)
{
	const bool valid_license_plate =
		license_plate.full_license_plate[0] != L'\0' &&
		license_plate.full_license_plate[3] == L'-' &&
		license_plate.full_license_plate[6] == L' ';

	if (!valid_license_plate)
	{
		return false;
	}

	for (size_t i = 0; i < 6; i++)
	{
		if (i == 3 && license_plate.full_license_plate[i] == L'-')
		{
			continue;
		}

		if (license_plate.full_license_plate[i] < L'A' || L'Z' < license_plate.full_license_plate[i])
		{
			return false;
		}
	}

	for (size_t i = 7; i < LICENSE_PLATE_MAX_LENGTH; i++)
	{
		if (license_plate.full_license_plate[i] < L'0' || L'9' < license_plate.full_license_plate[i])
		{
			return false;
		}
	}

	return true;
}

int32_t LicensePlateVerifier::GetLicensePlateNumber(LicensePlate license_plate)
{
	return license_plate.license_plate_number;
}

std::wostream& operator<<(std::wostream& wos, const LicensePlate& license_plate) noexcept
{
	wos << license_plate.full_license_plate;
	return wos;
}

std::wistream& operator>>(std::wistream& wis, LicensePlate& license_plate)
{
	std::wstring wstr;
	std::getline(wis, wstr);
	license_plate.SetLicensePlate(wstr);
	return wis;
}
