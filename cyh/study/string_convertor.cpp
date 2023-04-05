#include "string_convertor.h"

std::vector<wchar_t> StringConvertor::hex_lower_table =
{
    L' ', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f'
};

std::vector<wchar_t> StringConvertor::hex_upper_table =
{
    L' ', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F'
};

std::wstring StringConvertor::ConvertToPascalCase(std::wstring_view wstr)
{
    std::wstring result{ wstr };

    bool firstLetter = true;
    char isLargeLetter = 0;

    constexpr char largeSmallLetterGap = 32;

    for (auto& wchar : result)
    {
        if ((wchar < L'A' || L'Z' < wchar) && (wchar < L'a' || L'z' < wchar))
        {
            continue;
        }

        isLargeLetter = wchar - L'a';

        if (firstLetter)
        {
            // 소문자인 경우
            if (isLargeLetter >= 0)
            {
                // 대문자로 만들기
                wchar -= largeSmallLetterGap;
                firstLetter = false;
            }
        }
        else
        {
            // 대문자인 경우
            if (isLargeLetter < 0)
            {
                // 소문자로 만들기
                wchar += largeSmallLetterGap;
            }
        }
    }

    return result;
}

std::wstring StringConvertor::ConvertHexNumberToUpper_(uint64_t num)
{
    std::wstring result;
    uint64_t remainder = 0;
    do
    {
        remainder = num % 16;
        result.insert(result.begin(), hex_upper_table[remainder]);
        num /= 16;
    } while (num != 0);

    return result;
}

std::wstring StringConvertor::ConvertHexNumberToLower_(uint64_t num)
{
    std::wstring result;
    uint64_t remainder = 0;
    do
    {
        remainder = num % 16;
        result.insert(result.begin(), hex_lower_table[remainder]);
        num /= 16;
    } while (num != 0);

    return result;
}
