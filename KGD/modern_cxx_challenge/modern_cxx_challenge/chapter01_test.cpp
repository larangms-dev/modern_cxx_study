#include "chapter01_12.h"
#include "chapter01_13.h"
#include "chapter01_14.h"

int main()
{
    /* problem 12
    {
        struct test_data
        {
            unsigned long long limit;
            unsigned long long start;
            long steps;
        };

        std::vector<test_data> data
        {
           { 10ULL, 9ULL, 19 },
           { 100ULL, 97ULL, 118 },
           { 1000ULL, 871ULL, 178 },
           { 10000ULL, 6171ULL, 263 },
           { 100000ULL, 77031ULL, 350 },
           { 1000000ULL, 837799ULL, 524 },
           { 10000000ULL, 8400511ULL, 685 },
           { 100000000ULL, 63728127ULL, 949 }
        };

        for (auto const& d : data)
        {
            auto result = longest_collatz(d.limit);

            if (result.first != d.start || result.second != d.steps)
                std::cout << "error on limit " << d.limit << std::endl;
            else
                std::cout
                << "less than      : " << d.limit << std::endl
                << "starting number: " << result.first << std::endl
                << "sequence length: " << result.second << std::endl;
        }
    }//*/

    /* problem 13
    {
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        auto eng = std::mt19937{ seq };
        auto dist = std::uniform_real_distribution<>{ 0, 1 };

        for (auto j = 0; j < 9; j++)
        {
            std::cout << compute_pi(eng, dist, std::pow(10,j)) << std::endl;
        }
    }//*/

    //* problem 14
    {
        assert(validate_isbn_10("0306406152"));
        assert(!validate_isbn_10("0306406151"));

        std::string isbn;
        std::cout << "isbn:";
        std::cin >> isbn;

        std::cout << "valid: " << validate_isbn_10(isbn) << std::endl;
        std::cout << "valid: " << validate_isbn_10_limit(isbn) << std::endl;
    }//*/
}