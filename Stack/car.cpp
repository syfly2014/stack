#include "stdafx.h"
#include "car.h"
using namespace std;

car::car(string licenceString, int) :licence(licenceString), movedTimes(0){}

car::~car() {}

//���س������ƶ��Ĵ���,����Ա����������ʹ�ó�������øú���
int car::getMovedTimes() const
{
	return movedTimes;
}

//���س�������
string car::getLicence() const
{
	return licence;
}

//�������ƶ�ʱ������movedTimes������1
void car::move()
{
	movedTimes++;
}

