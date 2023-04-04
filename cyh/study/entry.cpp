#include <iostream>
#include <vector>
#include <string>

#include "temperature.h"
#include "ipv4.h"
#include "license_plate_verifier.h"

using namespace std;

int main()
{
	LicensePlate temp;

	wcin >> temp;

	auto verification_result = LicensePlateVerifier::Verification(temp);
	auto license_number = LicensePlateVerifier::GetLicensePlateNumber(temp);

	cout << "verification_result: " << verification_result << " / license_number: " << license_number << "\n";

	return 0;
}