#include "stdafx.h"
#include "car.h"
using namespace std;

car::car(string licenceString, int) :licence(licenceString), movedTimes(0){}

car::~car() {}

//返回车辆被移动的次数,常成员函数，可以使用常对象调用该函数
int car::getMovedTimes() const
{
	return movedTimes;
}

//返回车辆代号
string car::getLicence() const
{
	return licence;
}

//当车辆移动时，属性movedTimes会增加1
void car::move()
{
	movedTimes++;
}

