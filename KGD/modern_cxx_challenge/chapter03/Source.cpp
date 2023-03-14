#include <iostream>
#include "chapter03.h"

int main()
{
	// problem 27
	std::cout << "Problem 27\n";
	std::string inputString;
	std::string inputDelimiters;

	std::cout << "Input string : ";
	std::getline(std::cin, inputString);
	std::cout << "Input delimiters : ";
	std::getline(std::cin, inputDelimiters);

	if (inputString.empty())
	{
		inputString = "Hello, world! This is a test.";
		inputDelimiters = ", ";
	}

	auto tokens = splitString(inputString, inputDelimiters);

	for (const auto& token : tokens)
	{
		std::cout << token << std::endl;
	}

	// probelm 26
	std::cout << "Problem 26\n";
	std::string input;
	std::string inputDelimiter;

	std::cout << "Input string : ";
	std::getline(std::cin, input);
	std::cout << "Input delimiters : ";
	std::getline(std::cin, inputDelimiter);

	auto inputStrings = splitString(input, " ");

	auto sentence = joinStrings(inputStrings, inputDelimiter);

	std::cout << sentence << std::endl;

	return 0;
}