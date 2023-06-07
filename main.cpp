#include"pch.h"
#include<iostream>
#include"Connection.h"
#include"ConnectionPool.h"
using namespace std;

int main()
{
	Connection conn;
	conn.connect("127.0.0.1", 3306, "root", "123123", "chat");

	clock_t begin = clock();
	thread t1([]() {
		for (int i = 0; i < 2500; i++)
		{
			Connection conn;
			char sql[1024] = { 0 };
			printf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123123", "chat");
			conn.update(sql);
		}
	});
	thread t2([]() {
		for (int i = 0; i < 2500; i++)
		{
			Connection conn;
			char sql[1024] = { 0 };
			printf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123123", "chat");
			conn.update(sql);
		}
		});
	thread t3([]() {
		for (int i = 0; i < 2500; i++)
		{
			Connection conn;
			char sql[1024] = { 0 };
			printf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123123", "chat");
			conn.update(sql);
		}
		});
	thread t4([]() {
		for (int i = 0; i < 2500; i++)
		{
			Connection conn;
			char sql[1024] = { 0 };
			printf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhang san", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123123", "chat");
			conn.update(sql);
		}
		});


	t1.join();
	t2.join();
	t3.join();
	t4.join();

	clock_t end = clock();
	cout << (end - begin) << "ms" << endl;


#if 0
	for (int i = 0; i < 10000; i++)
	{
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')", "zhang san", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123123", "chat");
		conn.update(sql);
	}
#endif
	return 0;
}