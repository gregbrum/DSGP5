#pragma once
#include <string>
using namespace std;
class Flight
{
private:
	string start;
	string end;
	int mileage;
	int cost;
public:
	Flight(string s, string e,int distance, int price)
	{
		mileage = distance;
		cost = price;
		start = s;
		end = e;
	}
	~Flight()
	{

	}
	void setStart(string s)
	{
		start = s;
	}
	void setEnd(string s)
	{
		end = s;
	}
	void setMileage(int s)
	{
		mileage = s;
	}
	void setCost(int s)
	{
		cost = s;
	}
	int getCost()
	{
		return cost;
	}
	int getMileage()
	{
		return mileage;
	}
	string getStart()
	{
		return start;
	}
	string getEnd()
	{
		return end;
	}
};
