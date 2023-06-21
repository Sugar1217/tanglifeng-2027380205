#include "pch.h"
#include "TaskManager.h"
#include "IpcClient.h"

CTaskManager* CTaskManager::m_pInstance = nullptr;

CTaskManager::CTaskManager()
{

}

CTaskManager::~CTaskManager()
{

}

CTaskManager* CTaskManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CTaskManager;
	}

	return m_pInstance;
}

void CTaskManager::Init()
{
	CIpcClient::GetInstance()->AddObserver(this);
}

//生产者
IMAGE_TYPE CTaskManager::AddTask(std::wstring strFilePath)
{
	m_vecTasks.push_back(strFilePath);
	return IMAGE_TYPE::AG_IMAGE;
}

void CTaskManager::AddDirTask(std::wstring strDirPath)
{
	//1.for循环来枚举目录下的所有文件


	//2.每个文件都调用AddTask
}

//消费者
void CTaskManager::ProcessTask()
{
	for (auto it = m_vecTasks.begin(); it != m_vecTasks.end(); ++it)
	{
		//处理任务

		//删除任务
		m_vecTasks.erase(it);
	}
}

void CTaskManager::OnDataCallback(std::string strData)
{
	//处理数据

}
