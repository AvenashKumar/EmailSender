#pragma once
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

//Source: https://www.codeproject.com/Articles/98355/SMTP-Client-with-SSL-TLS
class cEmailSender
{
private:
	//SMTP Sever Info
	const string m_cstrSmtpServer;
	const int m_ciSmtpPort;

	//Send/Receive Info
	const string m_cstrSenderEmail;
	const string m_cstrPassword;
	const string m_cstrReceiverEmail;
	string m_strMailBody;
	string m_strMailSubject;

	//Attachment Info
	vector<string> m_vtstrAttachments;


private:
	cEmailSender();

public:
	cEmailSender(const string &p_crefstrSmtpServer,
		const int p_ciSmtpPort,
		const string &p_crefstrSenderEmail,
		const string &p_crefstrPassword,
		const string &p_crefstrReceiverEmail);

	void setAttachmentPath(const vector<string> &p_crefvtstrAttachments);
	void setBody(const string &p_crefstrEmailBody);
	void setSubject(const string &p_crefstrEmailSubject);

	void sendMail();

private:
	string getSenderName()const;

};