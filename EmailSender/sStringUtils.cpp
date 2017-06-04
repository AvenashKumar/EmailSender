#include "sStringUtils.h"


string sStringUtils::wstr2str(const wstring &p_crefwstrInput)
{
	string strOut(p_crefwstrInput.begin(), p_crefwstrInput.end());
	return strOut;
}

wstring sStringUtils::str2wstr(const std::string& s)
{
	std::wstring temp(s.length(), L' ');
	std::copy(s.begin(), s.end(), temp.begin());
	return temp;
}