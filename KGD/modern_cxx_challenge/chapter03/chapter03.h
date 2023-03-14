#pragma once
#include <string>
#include <vector>
#include <regex>

auto splitString(const std::string& string, const std::string& delimiters)
{
	std::regex regex("[^" + delimiters + "]+");
	auto iterator = std::sregex_iterator(string.begin(), string.end(), regex);
	auto end = std::sregex_iterator();
	std::vector<std::string> tokens;

	while (iterator != end)
	{
		tokens.push_back(iterator->str());
		++iterator;
	}

	return tokens;
}

auto joinStrings(const std::vector<std::string>& strings, const std::string& delimiter)
{
	std::string result;
	for (const auto& string : strings)
	{
		result += string + delimiter;
	}

	if (!result.empty())
	{
		result.resize(result.size() - 1);
	}

	return result;
}