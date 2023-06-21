#include "pch.h"
#include "IpcClient.h"


CIpcClient* CIpcClient::m_pInstance = nullptr;

CIpcClient::CIpcClient()
{

}

CIpcClient::~CIpcClient()
{

}

CIpcClient* CIpcClient::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CIpcClient();
	}
	return m_pInstance;
}

//添加观察者
void CIpcClient::AddObserver(IDataCallback* pCallback)
{
	//m_pObservers = pCallback;
	m_vecObservers.push_back(pCallback);
}

void CIpcClient::SendPackage()
{

}

//通知观察者
void CIpcClient::ReveivePackage()
{
	std::string strData = "helllo";
// 	if (m_pObservers)
// 	{
// 		m_pObservers->OnDataCallback(strData);
// 	}

	if (!m_vecObservers.size())
	{
		return;
	}

	for (auto it = m_vecObservers.begin(); it != m_vecObservers.end(); ++it)
	{
		IDataCallback* pCallback = *it;
		pCallback->OnDataCallback(strData);

		//(*it)->OnDataCallback(strData);
	}
}

void CIpcClient::Start()
{

}

void CIpcClient::Stop()
{

}
