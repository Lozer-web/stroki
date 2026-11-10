#include <iostream>
#include <string>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

wchar_t toupper(wchar_t c)
{
	if (c >= L'a' && c <= L'z')
	{
		return c - (L'a' - L'A');
	}
	
	return c;
}
wchar_t tolower(wchar_t c)
{
	if (c >= L'A' && c <= L'Z')
	{
		return c + (L'a' - L'A');
	}
	return c;
}
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	std::wstring text;
	std::wcout << L"Введите текст: ";
	std::getline(std::wcin, text);

	if (text.empty())
	{
		std::wcout << L"ваш текст пустой!!!!!" << std::endl;
		return 0;
	}

	bool newword = true;

	for (size_t i = 0; i < text.length(); i++)
	{
		if (text[i] == L' ' || text[i] == L'\t')
		{
			newword = true;
		}
		else
		{
			if (newword)
			{
				text[i] = toupper(text[i]);
				newword = false;
			}
			else
			{
				text[i] = tolower(text[i]);
			}
		}
	}

	if (text.back() != L'.')
	{
		text += L'.';

	}
	std::wcout << L"Результат: " << text << std::endl;



	return 0;
}