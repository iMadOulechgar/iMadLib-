#pragma once

#include <iostream>
#include <string>
#include "clsdate.h"

using namespace std;

class clsPeriod
{
public:

	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;

	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{

		if (
			clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
			)
			return false;
		else
			return true;

	}


	bool IsOverLapWith(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();


	}
};

