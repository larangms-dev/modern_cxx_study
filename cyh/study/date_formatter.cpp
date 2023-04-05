#include "date_formatter.h"

std::wstring DateFormatter::ChangeDateFormat(std::wstring_view date_text, DATE_FORMAT change_to_format, wchar_t delimiter)
{
	_ASSERT(date_text.size() == DATE_TEXT_MAX_LENGTH);

	auto equal_date_format_result = IsEqualDateFormat(date_text, change_to_format, delimiter);
	if (equal_date_format_result)
	{
		return equal_date_format_result.value();
	}

	wchar_t date_data[DATE_TEXT_MAX_LENGTH + 1] = { 0, };

	bool is_dd_mm_yyyy = date_text[2] < L'0' || L'9' < date_text[2];

	uint64_t start_copy_index = 5Ui64 + is_dd_mm_yyyy;
	uint64_t copy_length = 5Ui64 - is_dd_mm_yyyy;

	memcpy(date_data, date_text.data() + start_copy_index, copy_length * sizeof(wchar_t));
	date_data[copy_length] = L'.';

	uint64_t start_paste_index = 6Ui64 - is_dd_mm_yyyy;
	copy_length = 4Ui64 + is_dd_mm_yyyy;
	memcpy(date_data + start_paste_index, date_text.data(), copy_length * sizeof(wchar_t));

	equal_date_format_result = IsEqualDateFormat(date_data, change_to_format, delimiter);
	if (equal_date_format_result)
	{
		return equal_date_format_result.value();
	}

	_ASSERT(false);

	return L"";
}

std::optional<std::wstring> DateFormatter::IsEqualDateFormat(std::wstring_view date_text, DATE_FORMAT change_to_format, wchar_t delimiter)
{
	std::wstring str{ date_text };
	const int32_t bit_flag = static_cast<int32_t>(change_to_format);
	wchar_t temp;

	for (uint64_t i = 0; i < DATE_TEXT_MAX_LENGTH; i++)
	{
		temp = date_text[DATE_TEXT_MAX_LENGTH - 1 - i];
		str[DATE_TEXT_MAX_LENGTH - 1 - i] = temp;

		if (!(bit_flag & (1 << i)))
		{
			continue;
		}

		if (L'0' <= temp && temp <= L'9')
		{
			return std::nullopt;
		}

		str[DATE_TEXT_MAX_LENGTH - 1 - i] = delimiter;
	}

	return str;
}
