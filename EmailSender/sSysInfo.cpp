#include "sSysInfo.h"
#include <Windows.h>
#include "sStringUtils.h"
const string sSysInfo::getSystemUserName()
{
	wchar_t  chstrUsername[233];
	DWORD dwordLength = 1024;
	if (!GetUserName(chstrUsername, &dwordLength))
	{
		string strError = "Fail to find system user name, Error Code:=" + std::to_string(GetLastError());
		throw exception(strError.c_str());
	}
	return sStringUtils::wstr2str(wstring(chstrUsername));
}