#include <cmath>
#include <assert.h>

// epsilon : 허용 오차 한계
bool are_equal(const double d1, const double d2, const double epsilon = 0.001)
{
    return std::fabs(d1 - d2) < epsilon;
}

namespace temperature
{
    enum class scale
    {
        celsius,
        fahrenheit,
        kelvin
    };

    template <scale S>
    class quantity
    {
        const double amount;
    public:
        constexpr explicit quantity(double const a)
            : amount(a) {}

        explicit operator double() const 
        { 
            return amount;
        }
    };

    template <scale S>
    inline bool operator==(const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return are_equal(static_cast<double>(lhs), static_cast<double>(rhs));
    }

    template <scale S>
    inline bool operator!=(const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return !(lhs == rhs);
    }

    template <scale S>
    inline bool operator< (const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return static_cast<double>(lhs) < static_cast<double>(rhs);
    }

    template <scale S>
    inline bool operator> (const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return rhs < lhs;
    }

    template <scale S>
    inline bool operator<=(const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return !(lhs > rhs);
    }

    template <scale S>
    inline bool operator>=(const quantity<S>& lhs, const quantity<S>& rhs)
    {
        return !(lhs < rhs);
    }

    template <scale S>
    constexpr quantity<S> operator+(const quantity<S>& q1, const quantity<S>& q2)
    {
        return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
    }

    template <scale S>
    constexpr quantity<S> operator-(const quantity<S>& q1, const quantity<S>& q2)
    {
        return quantity<S>(static_cast<double>(q1) - static_cast<double>(q2));
    }

    template <scale S, scale R>
    struct conversion_traits
    {
        static double convert(double const value) = delete;
    };

    template <>
    struct conversion_traits<scale::celsius, scale::kelvin>
    {
        static double convert(const double value)
        {
            return value + 273.15;
        }
    };

    template <>
    struct conversion_traits<scale::kelvin, scale::celsius>
    {
        static double convert(const double value)
        {
            return value - 273.15;
        }
    };

    template <>
    struct conversion_traits<scale::celsius, scale::fahrenheit>
    {
        static double convert(const double value)
        {
            return (value * 9) / 5 + 32;;
        }
    };

    template <>
    struct conversion_traits<scale::fahrenheit, scale::celsius>
    {
        static double convert(const double value)
        {
            return (value - 32) * 5 / 9;
        }
    };

    template <>
    struct conversion_traits<scale::fahrenheit, scale::kelvin>
    {
        static double convert(const double value)
        {
            return (value + 459.67) * 5 / 9;
        }
    };

    template <>
    struct conversion_traits<scale::kelvin, scale::fahrenheit>
    {
        static double convert(const double value)
        {
            return (value * 9) / 5 - 459.67;
        }
    };

    template <scale R, scale S>
    constexpr quantity<R> temperature_cast(const quantity<S> q)
    {
        return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
    }

    namespace temperature_scale_literals
    {
        constexpr quantity<scale::celsius> operator"" _deg(const long double amount)
        {
            return quantity<scale::celsius> {static_cast<double>(amount)};
        }

        constexpr quantity<scale::fahrenheit> operator"" _f(const long double amount)
        {
            return quantity<scale::fahrenheit> {static_cast<double>(amount)};
        }

        constexpr quantity<scale::kelvin> operator"" _k(const long double amount)
        {
            return quantity<scale::kelvin> {static_cast<double>(amount)};
        }
    }
}

int main()
{
    using namespace temperature;
    using namespace temperature_scale_literals;

    auto t1{ 36.5_deg };
    auto t2{ 79.0_f };
    auto t3{ 100.0_k };

    {
        auto tf = temperature_cast<scale::fahrenheit>(t1);
        auto tc = temperature_cast<scale::celsius>(tf);
        assert(t1 == tc);
    }

    {
        auto tk = temperature_cast<scale::kelvin>(t1);
        auto tc = temperature_cast<scale::celsius>(tk);
        assert(t1 == tc);
    }

    {
        auto tc = temperature_cast<scale::celsius>(t2);
        auto tf = temperature_cast<scale::fahrenheit>(tc);
        assert(t2 == tf);
    }

    {
        auto tk = temperature_cast<scale::kelvin>(t2);
        auto tf = temperature_cast<scale::fahrenheit>(tk);
        assert(t2 == tf);
    }

    {
        auto tc = temperature_cast<scale::celsius>(t3);
        auto tk = temperature_cast<scale::kelvin>(tc);
        assert(t3 == tk);
    }

    {
        auto tf = temperature_cast<scale::fahrenheit>(t3);
        auto tk = temperature_cast<scale::kelvin>(tf);
        assert(t3 == tk);
    }
}