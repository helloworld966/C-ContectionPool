#pragma once
#include<string>
#include<queue>
using namespace std;
#include"Connection.h"
#include<memory>
#include<mutex>
#include<thread>
#include<functional>
#include<atomic>
#include<iostream>
#include<condition_variable>
/*
ʵ�����ӳع���ģ��
*/
class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	//���ⲿ�ṩ�ӿڣ������ӳ��л�ȡһ�����õĿ�������
	shared_ptr<Connection> getConnection();
private:
	ConnectionPool();

	bool loadConfigFile();
	//�����ڶ������߳��У�ר�Ÿ�������������
	void produceConnectionTask();
	//ɨ�賬��_maxIdleTimeʱ��Ŀ������ӣ����ж��ڵ����ӻ���
	void scannerConnectionTask();


	string _ip;//ip��ַ
	unsigned short _port;//�˿ں�
	string _username;//�û���
	string _password;//����
	string _dbname;
	int _initSize;//��ʼ������
	int _maxSize;//���������
	int _maxIdleTime;//������ʱ��
	int _connectionTimeout;//��ȡ���ӵĳ�ʱʱ��


	queue<Connection*> _connectionQue;//�洢����
	mutex _queueMutex;//ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt;//��¼���ӵ�������
	condition_variable cv;
};