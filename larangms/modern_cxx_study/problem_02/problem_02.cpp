/*problem_02.cpp

    최대공약수 프로그램 구현하기

    양의 정수 두개가 주어졌을 때, 두 수의 최대공약수를 계산하고 출력
    
    최대공약수(Greatest Common Divisor, GCD)
    : 주어진 수 모두를 나누어 떨어지게 만드는 가장 큰 양의 정수 

    만약 gcd(a, b) = 1이면, 두 수 a, b는 서로소(coprime) 관계에 있다고 한다.
    유클리드 알고리즘이 가장 효율적이다.
*/

#include <iostream>
#include <numeric>

// 재귀를 통한 구현
uint32_t gcd1(uint32_t const a, uint32_t const b)
{
    return b == 0 ? a : gcd1(b, a % b);
}

// 비재귀 구현
uint32_t gcd2(uint32_t a, uint32_t b)
{
    while (b != 0)
    {
        uint32_t r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    std::cout << "Input numbers:";

    uint32_t a, b;
    std::cin >> a >> b;

    std::cout << "rec gcd(" << a << ", " << b << ") = " << gcd1(a, b) << std::endl;
    std::cout << "gcd(" << a << ", " << b << ") = " << gcd2(a, b) << std::endl;
    std::cout << "std::gcd(" << a << ", " << b << ") = " << std::gcd(a, b) << std::endl;
}
