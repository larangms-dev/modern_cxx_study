#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// adapter pattern
// 어댑터 패턴이란 클래스의 인터페이스를 사용자가 기대하는 다른 인터페이스로 변환하는 패턴이다.
// 여기서는 array를 2차원 array로 변환하였다.

template <class T, size_t R, size_t C>
class array2d
{
    typedef T                   value_type;
    typedef value_type*         iterator;
    typedef value_type const*   const_iterator;

    std::vector<T> arr;

public:
    array2d() 
        : arr(R * C) {}

    explicit array2d(std::initializer_list<T> l) 
        : arr(l) {}

    // 요구 사항 : data
    constexpr T* data() noexcept 
    { 
        return arr.data();
    }

    constexpr const T* data() const noexcept 
    { 
        return arr.data();
    }

    // 요구 사항 : at
    constexpr T& at(const size_t r, const size_t c)
    {
        return arr.at(r * C + c);
    }

    constexpr const T& at(const size_t r, const size_t c) const
    {
        return arr.at(r * C + c);
    }

    // ()를 통해 dimension index를 받음
    // 사용한 container는 메모리 낭비를 줄이기 위해 하나의 연속된 메모리에 저장함
    constexpr T& operator() (const size_t r, const size_t c)
    {
        return arr[r * C + c];
    }

    constexpr const T& operator() (const size_t r, const size_t c) const
    {
        return arr[r * C + c];
    }

    constexpr bool empty() const noexcept
    {
        return R == 0 || C == 0;
    }

    // 요구 사항 : 각 차원의 크기를 반환하는 메소드
    constexpr size_t size(const int rank) const
    {
        if (rank == 1)
        {
            return R;
        }
        else if (rank == 2)
        {
            return C;
        }

        throw std::out_of_range("Rank is out of range!");
    }

    // 요구 사항 : 배열을 한 가지 값으로 채우는 메소드
    void fill(const T& value)
    {
        std::fill(std::begin(arr), std::end(arr), value);
    }

    // 요구 사항 : 동일한 차원의 다른 객체와 교환하는 메소드
    void swap(array2d& other) noexcept
    {
        arr.swap(other.arr);
    }

    const_iterator begin() const
    {
        return arr.data();
    }

    const_iterator end() const
    {
        return arr.data() + arr.size();
    }

    iterator begin()
    {
        return arr.data();
    }

    iterator end()
    {
        return arr.data() + arr.size();
    }
};

template <class T, size_t R, size_t C>
void print_array2d(const array2d<T, R, C>& arr)
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            std::cout << arr.at(i, j) << ' ';
        }

        std::cout << std::endl;
    }
}