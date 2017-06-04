#include <iostream>
#include "cEmailSender.h"
#include <Windows.h>
#include "sStringUtils.h"
using namespace std;
int main(const int p_ciTotalArgs, char** p_ptrptrchArguments)
{

	try
	{
		cEmailSender emailSender("smtp.live.com", 587,
			"<username>@domain.com",
			"<password>",
			"<recipient>@domain.com");

		emailSender.sendMail();

		return 0;
	}
	catch (exception e)
	{
		MessageBox(nullptr, sStringUtils::str2wstr(e.what()).c_str(), L"Error", MB_OK | MB_ICONERROR);
		return -1;
	}
	catch (...)
	{
		MessageBox(nullptr, L"Unknown Error", L"Error", MB_ICONERROR);
		return -1;
	}
}