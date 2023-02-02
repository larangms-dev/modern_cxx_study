#pragma once
#include <iostream>
#include <random>
#include <algorithm>
#include <array>

template <
    typename E = std::mt19937,
    typename D = std::uniform_real_distribution<>>
    double compute_pi(E& engine, D& dist,
        int const samples = 1000000)
{
    auto hit = 0;

    for (auto i = 0; i < samples; i++)
    {
        auto x = dist(engine);
        auto y = dist(engine);

        if (y <= std::sqrt(1 - std::pow(x, 2))) hit += 1;
    }

    return 4.0 * hit / samples;
}