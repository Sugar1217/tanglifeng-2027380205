#pragma once
#include "IDataCallback.h"
#include <vector>
class CIpcClient
{
public:
	CIpcClient();
	~CIpcClient();
	static CIpcClient* GetInstance();
	void AddObserver(IDataCallback* pCallback);

	void SendPackage();
	void ReveivePackage();
	void Start();
	void Stop();

private:
	IDataCallback* m_pObservers;
	std::vector<IDataCallback* > m_vecObservers;
	static CIpcClient* m_pInstance;

};

