#pragma once
#include <string>
#include <map>
#include <vector>
#include "IDataCallback.h"

enum IMAGE_TYPE
{
	NORMAL_IMAGE = 6,
	FG_IMAGE =10,
	NG_IMAGE ,
	AG_IMAGE 
};

class CTaskManager : public IDataCallback
{
public:
	CTaskManager();
	~CTaskManager();
	static CTaskManager* GetInstance();

	void Init();
	IMAGE_TYPE AddTask(std::wstring strFilePath);
	void AddDirTask(std::wstring strDirPath);

	void ProcessTask();

	virtual void OnDataCallback(std::string strData) override;
private:
	int m_nNums = 0;

	static CTaskManager* m_pInstance;

	std::map<std::wstring, int>  m_mapResult;
	std::vector<std::wstring>  m_vecTasks;
};

