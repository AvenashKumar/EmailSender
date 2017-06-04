#include "cEmailSender.h"
#include "sSysInfo.h"
#include "cSmtp.h"
cEmailSender::cEmailSender(const string &p_crefstrSmtpServer,
	const int p_ciSmtpPort,
	const string &p_crefstrSenderEmail,
	const string &p_crefstrPassword,
	const string &p_crefstrReceiverEmail) :
	m_cstrSmtpServer(p_crefstrSmtpServer),
	m_ciSmtpPort(p_ciSmtpPort),
	m_cstrSenderEmail(p_crefstrSenderEmail),
	m_cstrPassword(p_crefstrPassword),
	m_cstrReceiverEmail(p_crefstrReceiverEmail),
	m_strMailSubject(sSysInfo::getSystemUserName()),
	m_strMailBody("")
{

}

void cEmailSender::setAttachmentPath(const vector<string> &p_crefvtstrAttachments)
{
	m_vtstrAttachments = p_crefvtstrAttachments;
}
void cEmailSender::setBody(const string &p_crefstrEmailBody)
{
	m_strMailBody = p_crefstrEmailBody;
}
void cEmailSender::setSubject(const string &p_crefstrEmailSubject)
{
	m_strMailSubject = p_crefstrEmailSubject;
}

void cEmailSender::sendMail()
{
	CSmtp m_SmtpMailSender;

	//Set smtp port server
	m_SmtpMailSender.SetSMTPServer(m_cstrSmtpServer.c_str(), m_ciSmtpPort);

	//Set security type
	m_SmtpMailSender.SetSecurityType(USE_TLS);

	//Set login credentials
	m_SmtpMailSender.SetLogin(m_cstrSenderEmail.c_str());
	m_SmtpMailSender.SetPassword(m_cstrPassword.c_str());

	//Set sender name email
	m_SmtpMailSender.SetSenderName(getSenderName().c_str());
	m_SmtpMailSender.SetSenderMail(m_cstrSenderEmail.c_str());

	//Set receiver email
	m_SmtpMailSender.AddRecipient(m_cstrReceiverEmail.c_str(), sSysInfo::getSystemUserName().c_str());

	//Set email subject and body
	m_SmtpMailSender.SetSubject(m_strMailSubject.c_str());
	m_SmtpMailSender.AddMsgLine(m_strMailBody.c_str());

	//Set priority
	m_SmtpMailSender.SetXPriority(XPRIORITY_NORMAL);

	//Set attachment
	for (const auto &itrAttachment : m_vtstrAttachments)
	{
		m_SmtpMailSender.AddAttachment(itrAttachment.c_str());
	}

	//Send email
	m_SmtpMailSender.Send();
}

string cEmailSender::getSenderName()const
{
	size_t uiAtPos = m_cstrSenderEmail.rfind("@");
	if (uiAtPos == string::npos)
		return m_cstrSenderEmail;

	return m_cstrSenderEmail.substr(0, uiAtPos);
}