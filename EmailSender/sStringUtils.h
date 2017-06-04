#pragma once
#include <string>
using namespace std;
class sStringUtils
{
public:
	static string wstr2str(const wstring &p_crefwstrInput);
	static wstring str2wstr(const std::string& s);
};

