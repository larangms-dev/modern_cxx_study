#pragma once
#include <stdint.h>

#include <string>
#include <vector>

class StringConvertor
{
public:
    static std::wstring ConvertToPascalCase(std::wstring_view wstr);

    template<typename... Args>
    static std::wstring ConvertHexNumberToUpper(Args... args);
    template<typename... Args>
    static std::wstring ConvertHexNumberToLower(Args... args);

private:
    static std::wstring ConvertHexNumberToUpper_(uint64_t num);
    static std::wstring ConvertHexNumberToLower_(uint64_t num);

private:
    static std::vector<wchar_t> hex_lower_table;
    static std::vector<wchar_t> hex_upper_table;
};

template<typename ...Args>
inline std::wstring StringConvertor::ConvertHexNumberToUpper(Args ...args)
{
    std::wstring result;

    (result.append(ConvertHexNumberToUpper_(args)), ...);

    return result;
}

template<typename ...Args>
inline std::wstring StringConvertor::ConvertHexNumberToLower(Args ...args)
{
    std::wstring result;

    (result.append(ConvertHexNumberToLower_(args)), ...);

    return result;
}
