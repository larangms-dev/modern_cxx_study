/* problem_03.cpp 
    최소공배수 프로그램 구현하기
    
    양의 정수가 두 개 또는 그 이상 주어졌을 때 최소공배수를 찾는 프로그램을 작성

    최소공배수(Lowest Common Multiple, LCM)
        공배수(common multiple)란 두 수 이상의 여러 수의 공통된 배수를 의미합니다.
        최소공배수(LCM)란 두 수 이상의 여러 수의 공배수 중 최소인 수를 가리킵니다.

        A * B = GCD * LCM
        LCM = (A * B) / GCD
*/

#include <iostream>
#include <numeric>
#include <vector>

int gcd(int const a, int const b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm1(int const a, int const b)
{
    int h = gcd(a, b);
    return h ? (a * (b / h)) : 0;
}

template<class InputIt>
int lcmr(InputIt first, InputIt last)
{
    return std::accumulate(first, last, 1, lcm1);
}

template<class InputIt>
int std_lcmr(InputIt first, InputIt last)
{
    return std::accumulate(first, last, 1, std::lcm<int, int>);
}

int main()
{
    int n = 0;
    std::cout << "Input Count:";
    std::cin >> n;

    std::vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int v{ 0 };
        std::cin >> v;
        numbers.push_back(v);
    }

    std::cout << "lcm = " << lcmr(std::begin(numbers), std::end(numbers)) << std::endl;
    std::cout << "lcm = " << std_lcmr(std::begin(numbers), std::end(numbers)) << std::endl;
}
