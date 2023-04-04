#include <iostream>
#include <vector>
#include <string>

#include "temperature.h"
#include "ipv4.h"
#include "license_plate_verifier.h"
#include "date_formatter.h"

using namespace std;

int main()
{
	auto DD_MM_YYYY1 = DateFormatter::ChangeDateFormat(L"12.25.2023", DATE_FORMAT::YYYY_MM_DD, L'&');
	auto DD_MM_YYYY2 = DateFormatter::ChangeDateFormat(L"2023.12.25", DATE_FORMAT::DD_MM_YYYY, L'/');

	wcout << DD_MM_YYYY1 << "  " << DD_MM_YYYY2 << "\n";

	return 0;
}