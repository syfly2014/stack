// Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "LinkStackNode.h"
#include "car.h"
#include <string>
#include <stack>//ʹ��stl�����ջ
#include <fstream>//���ļ�fstream iifstream ofstream

using namespace std;

//����ƥ�亯��
void bracket()
{
	cout << "�������������У���0��������";
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

//ͣ����ͣ������
void stop()
{
	string in_fileName = "data.txt";
	//ifstream �Զ��ķ�ʽ���ļ� oftream��д�ķ�ʽ���ļ�
	//c_str()����һ��const char*ָ�룬ָ���Կ��ַ���ֹ������
	ifstream infs(in_fileName.c_str());

	if (!infs)
	{
		cerr << "Can't open the file" << in_fileName << endl;
	}

	stack<car*> parking_lot, tempStack;
	car *p_car;
	string licence_plate, action;

	//���ж�ȡ�����ļ�
	while (!infs.eof())
	{
		infs >> licence_plate >> action;//��ȡ���ݣ����Ĵ��ţ����Ķ���
		if (action == "arrives")
		{
			if (parking_lot.size() < 5)
			{
				p_car = new car(licence_plate, 0);
				parking_lot.push(p_car);
			}
			else
			{
				//��ͣ�����Ѿ�ͣ�������������ĳ���ʾ������������
				cout << "Sorry" << licence_plate << ",The lot is full" << endl;
			}
		}
		else if (action == "departs")
		{
			//ͣ�����г���ͬʱҪ��ȥ�ĳ�����ջ����������
			while (!parking_lot.empty() && parking_lot.top()->getLicence() != licence_plate)
			{
				tempStack.push(parking_lot.top());
				parking_lot.top()->move();
				parking_lot.pop();
			}

			//���ÿ�������ƶ����
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

	//�����Ȼ��ͣ��ͣ�����г���
	cout << "These cars are still in the lot" << endl;

	while (!parking_lot.empty())
	{
		cout << parking_lot.top()->getLicence() << "was moved &&" << parking_lot.top()->getMovedTimes() <<
			"&& times while it was here" << endl;
		delete parking_lot.top();
		parking_lot.pop();
	}

	infs.close();//�ر��ļ�
}


int _tmain(int argc, _TCHAR* argv[])
{
	//bracket();

	stop();

	return 0;
}

