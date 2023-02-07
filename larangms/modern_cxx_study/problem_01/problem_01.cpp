/*problem_01.cpp

    3이나 5로 나누어 떨어지는 자연수의 합을 계산하는 프로그램 구현하기

    : 사용자가 입력한 상한까지의 자연수 중 3이나 5로 나누어 떨어지는 수의 합을 계산

    (자연수는 1 이상의 모든 정수 이며, 음수는 0 미만의 수 입니다. 0은 자연수도 음수도 아닌 유일한 수 입니다.)

*/

#include <iostream>

int main()
{
    unsigned int limit = 0;
    std::cout << "Upper limit:";
    std::cin >> limit;

    unsigned long long sum = 0;

    for (unsigned int i = 3; i < limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    std::cout << "sum=" << sum << std::endl;
}
