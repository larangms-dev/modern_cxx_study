/* problem_04.cpp
    주어진 수보다 작은 가장 큰 소수를 계산하는 프로그램 구현하기
    사용자에 의해 주어진 수보다 작은 가장 큰 소수를 계산하고 출력하라
    결과는 반드시 양의 정수여야 한다.

    소수 : 1과 자신, 두 개의 수로만 나누어 떨어지는 수

    https://www.youtube.com/watch?v=7190bHPx-Ro

    정수론
    n != 1 인 자연수라면

    - 소수
    - 합성수 : 약수가 3개 이상인 수, 제곱했을때 n보다 크지 않은 소수를 약수로 가진다.

    => 합성수의 정의를 이용하여 증명 : 합성수가 아니면 소수다    
    

    n 이 합성수라면
    1, a ... n (1 < a < n)
        1) a^2 <= n
                a는 n의 약수이기 때문에 
                n = a * b   (b != n, b != 1)
                a <= b      (a가 가장 작은 약수로 가정)
                a^2 <= a * b = n

            
        2) a가 소수 
                a가 합성수라면 a = c * d               (1 < c, d < a)
                n = a * b = cd * b = c * (db)
                -> c는 a 보다 작은 n의 약수가 되어 모순


    결론: n 이 합성수라면 반드시 제곱해서 n 보다 크지 않은 소수를 약수로 갖는다
*/

#include <iostream>

bool is_prime(int const num)
{
    if (num <= 3)
    {
        return num > 1;
    }
    else if (num % 2 == 0 || num % 3 == 0)
    {
        return false;
    }
    else
    {
        for (int i = 5; i * i <= num; i += 6)
        {
            if (num % i == 0 || num % (i + 2) == 0)
            {
                return false;
            }
        }

        return true;
    }
}

int main()
{
    int limit = 0;
    std::cout << "Upper limit:";
    std::cin >> limit;

    for (int i = limit; i > 1; i--)
    {
        if (is_prime(i))
        {
            std::cout << "Largest prime:" << i << std::endl;
            return 0;
        }
    }
}
