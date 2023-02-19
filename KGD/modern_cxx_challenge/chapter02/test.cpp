#include "problem15_16.h"
#include "problem17.h"
#include "problem18_20.h"

int main()
{
    /* problem 15
    {
        ipv4 a(168, 192, 0, 1);
        std::cout << a << std::endl;
        std::cout << a.to_string() << std::endl;

        ipv4 b = a;
        ipv4 c;
        c = b;

        ipv4 ip;
        std::cout << ip << std::endl;
        std::cin >> ip;
        if (!std::cin.fail())
            std::cout << ip << std::endl;
    }//*/

    /* problem 16
    {
        std::cout << "input range: ";
        ipv4 a1, a2;
        std::cin >> a1 >> a2;
        if (a2 > a1)
        {
            for (ipv4 a = a1; a <= a2; a++)
            {
                std::cout << a << std::endl;
            }
        }
        else
        {
            std::cerr << "invalid range!" << std::endl;
        }
    }//*/

    /* problem 17
    {
        {
            std::cout << "test fill" << std::endl;

            array2d<int, 2, 3> a;
            a.fill(1);

            print_array2d(a);
        }

        {
            std::cout << "test operator()" << std::endl;
            array2d<int, 2, 3> a;

            for (size_t i = 0; i < a.size(1); ++i)
            {
                for (size_t j = 0; j < a.size(2); ++j)
                {
                    a(i, j) = 1 + i * 3 + j;
                }
            }

            print_array2d(a);
        }

        {
            std::cout << "test move semantics" << std::endl;

            array2d<int, 2, 3> a{ 10,20,30,40,50,60 }; // initializer_list
            print_array2d(a);

            array2d<int, 2, 3> b(std::move(a));
            print_array2d(b);
        }

        {
            std::cout << "test swap" << std::endl;

            array2d<int, 2, 3> a{ 1,2,3,4,5,6 };
            array2d<int, 2, 3> b{ 10,20,30,40,50,60 };

            print_array2d(a);
            print_array2d(b);

            a.swap(b);

            print_array2d(a);
            print_array2d(b);
        }

        {
            std::cout << "test capacity" << std::endl;

            array2d<int, 2, 3> const a{ 1,2,3,4,5,6 };

            for (size_t i = 0; i < a.size(1); ++i)
            {
                for (size_t j = 0; j < a.size(2); ++j)
                {
                    std::cout << a(i, j) << ' ';
                }

                std::cout << std::endl;
            }
        }

        {
            std::cout << "test iterators" << std::endl;

            array2d<int, 2, 3> const a{ 1,2,3,4,5,6 };
            for (const auto e : a)
            {
                std::cout << e << ' ';
            }
            std::cout << std::endl;

            std::copy(
                std::begin(a), std::end(a),
                std::ostream_iterator<int>(std::cout, " "));

            std::cout << std::endl;
        }
    }//*/

    /* problem 18
    {
        auto x = minimum(5, 4, 2, 3);
        std::cout << x << std::endl;

        auto y = minimumc(std::less<>(), 3, 2, 1, 0);
        std::cout << y << std::endl;
    }//*/

    /* problem 19
    {
        std::vector<int> v;
        push_back(v, 1, 2, 3, 4);
        std::copy(std::begin(v), std::end(v),
            std::ostream_iterator<int>(std::cout, " "));

        std::list<int> l;
        push_back(l, 1, 2, 3, 4);
        std::copy(std::begin(l), std::end(l),
            std::ostream_iterator<int>(std::cout, " "));
    }//*/

    //* problem 20
    {
        std::vector<int> v{ 1,2,3,4,5,6 };
        std::array<int, 6> a{ { 1,2,3,4,5,6 } };
        std::list<int> l{ 1,2,3,4,5,6 };
        
        assert(contains(v, 3));
        assert(contains(a, 3));
        assert(contains(l, 3));

        assert(!contains(v, 30));
        assert(!contains(v, 30));
        assert(!contains(v, 30));

        assert(contains_any(v, 0, 3, 30));
        assert(contains_any(a, 0, 3, 30));
        assert(contains_any(l, 0, 3, 30));

        assert(!contains_any(v, 0, 30));
        assert(!contains_any(a, 0, 30));
        assert(!contains_any(l, 0, 30));

        assert(contains_all(v, 1, 3, 6));
        assert(contains_all(a, 1, 3, 6));
        assert(contains_all(l, 1, 3, 6));

        assert(!contains_all(v, 0, 1));
        assert(!contains_all(a, 0, 1));
        assert(!contains_all(l, 0, 1));

        assert(contains_none(v, 0, 7));
        assert(contains_none(a, 0, 7));
        assert(contains_none(l, 0, 7));

        assert(!contains_none(v, 0, 6, 7));
        assert(!contains_none(a, 0, 6, 7));
        assert(!contains_none(l, 0, 6, 7));
    }//*/
}