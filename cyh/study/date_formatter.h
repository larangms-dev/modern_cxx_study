#pragma once
#include <string>
#include <optional>

constexpr int32_t DATE_TEXT_MAX_LENGTH = 10;

enum class DATE_FORMAT : int32_t
{
	YYYY_MM_DD = 0b0000100100,
	DD_MM_YYYY = 0b0010010000,
};

class DateFormatter
{
public:
	static std::wstring ChangeDateFormat(std::wstring_view date_text, DATE_FORMAT change_to_format, wchar_t delimiter = L'-');
private:
	static std::optional<std::wstring> IsEqualDateFormat(std::wstring_view date_text, DATE_FORMAT change_to_format, wchar_t delimiter);
};