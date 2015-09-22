// Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "LinkStackNode.h"
#include "car.h"
#include <string>
#include <stack>//使用stl定义的栈
#include <fstream>//打开文件fstream iifstream ofstream

using namespace std;

//括号匹配函数
void bracket()
{
	cout << "请输入括号序列（以0结束）：";
	LinkStack<char> small;

	char a;
	
	do
	{
		cin >> a;
		switch (a)
		{
		case '(':
			small.Push(a);
			break;
		case ')':
			if (!small.IsEmpty())
			{
				small.Pop();
				break;
			}
			else
			{
				cout << "Wrong!" << endl;
				exit(0);
				break;
			}
		}
	} while (a != '0');
	
	if (small.IsEmpty())
		cout << "OK!" << endl;
	else
		cout << "Wrong!" << endl;
}

//停车场停车函数
void stop()
{
	string in_fileName = "data.txt";
	//ifstream 以读的方式打开文件 oftream以写的方式打开文件
	//c_str()生成一个const char*指针，指向以空字符终止的数组
	ifstream infs(in_fileName.c_str());

	if (!infs)
	{
		cerr << "Can't open the file" << in_fileName << endl;
	}

	stack<car*> parking_lot, tempStack;
	car *p_car;
	string licence_plate, action;

	//按行读取数据文件
	while (!infs.eof())
	{
		infs >> licence_plate >> action;//读取数据，车的代号，车的动作
		if (action == "arrives")
		{
			if (parking_lot.size() < 5)
			{
				p_car = new car(licence_plate, 0);
				parking_lot.push(p_car);
			}
			else
			{
				//当停车场已经停满车，对新来的车提示“车场已满”
				cout << "Sorry" << licence_plate << ",The lot is full" << endl;
			}
		}
		else if (action == "departs")
		{
			//停车场有车，同时要出去的车不是栈顶的那辆车
			while (!parking_lot.empty() && parking_lot.top()->getLicence() != licence_plate)
			{
				tempStack.push(parking_lot.top());
				parking_lot.top()->move();
				parking_lot.pop();
			}

			//输出每辆车的移动情况
			if (parking_lot.top()->getLicence() == licence_plate)
			{
				cout << parking_lot.top()->getLicence() << " was moved *" << parking_lot.top()->getMovedTimes() <<
					"* times while it was here" << endl;

				delete parking_lot.top();
				parking_lot.pop();
			}
			else
				cout << "Exception" << endl;


			while (!tempStack.empty())
			{
				parking_lot.push(tempStack.top());
				tempStack.pop();
			}

		}
	}

	//输出仍然被停在停车场中车辆
	cout << "These cars are still in the lot" << endl;

	while (!parking_lot.empty())
	{
		cout << parking_lot.top()->getLicence() << "was moved &&" << parking_lot.top()->getMovedTimes() <<
			"&& times while it was here" << endl;
		delete parking_lot.top();
		parking_lot.pop();
	}

	infs.close();//关闭文件
}


int _tmain(int argc, _TCHAR* argv[])
{
	//bracket();

	stop();

	return 0;
}

