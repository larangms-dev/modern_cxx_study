#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <string_view>
#include <assert.h>

bool validate_isbn_10(std::string_view isbn)
{
    auto valid = false;

    if (isbn.size() == 10 &&
        std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
    {
        auto w = 10;
        auto sum = std::accumulate(
            std::begin(isbn), std::end(isbn), 0,
            [&w](const int total, const char c) {
                return total + w-- * (c - '0'); });

        valid = !(sum % 11);
    }

    return valid;
}

bool validate_isbn_10_limit(std::string_view isbn)
{
    auto valid = false;

    if (isbn.size() == 10 &&
        std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
    {
        auto w = 10;
        char sum = 0;
        for (auto it = std::begin(isbn); it != std::end(isbn); ++it) 
        {
            char c = *it;
            sum += w-- * (c - '0') % 11;
        }

        valid = !(sum % 11);
    }

    return valid;
}