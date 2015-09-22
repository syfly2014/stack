#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class car
{
private:
	string licence;
	int movedTimes;
public:
	car(string, int);
	virtual ~car();

	string getLicence() const;
	int getMovedTimes() const;

	void move();
};

#endif