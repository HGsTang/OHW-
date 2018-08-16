// 日期查询程序.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include<assert.h>
#include <fstream>
using namespace std;
class Date
{

public:

	Date(int year = 1997, int month = 1, int day = 1)
		:years(year)
		, months(month)
		, days(day)
	{
		assert(IScorrect());
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			years = d.years;
			months = d.months;
			days = d.days;
		}
		return *this;
	}

	Date& operator + (int day)
	{
		while (day > 365)
		{
			if (ISleapyear() && day > 366)
			{
				years++;
				day = day - 366;
			}
			else
			{
				years++;
				day = day - 365;
			}
		}
		while (day >= Getmonthsday())
		{
			//注意这里的次序问题,一定先减 再加 最后再判断. 如果顺序错了会出BUG的. 
			day = day - Getmonthsday();
			months++;
			if (months > 12)
			{
				years++;
				months = 1;
			}
		}

		while (day >0)
		{
			DateAdvance();
			day = day - 1;
			days++;
		}
		return *this;
	}

	Date& operator - (int day) //先减去一年，然后在使用加的重载,所以你只需要写一个无懈可击的加算法就够了. 
	{
		while (day > 365)
		{
			if (ISleapyear() && day > 366)
			{
				day = day - 366;
				years--;
			}
			else
			{
				day = day - 365;
				years--;
			}
		}
		if (ISleapyear())
		{
			day = 366 - day;
			years--;
		}
		else
		{
			day = 365 - day;
			years--;
		}
		operator+(day);
		return *this;
	}

	void DateAdvance() //用于出现可以进化的情况 
	{
		if (days > Getmonthsday())
		{
			months++;
			days = 1;
		}
			if (months > 12)
			{
				years++;
				months = 1;
			}
		
	}

	int operator - (Date D)
	{
		int count = 0;
		if (*this > D)
		{
			while (*this != D)
			{
				D.operator+(1);
				count++;
			}
		}
		else
		{
			while (*this != D)
			{
				operator+(1);
				count++;
			}
		}
		return count;
	}

	bool ISleapyear()
	{
		if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0))
		{
			return true;
		}
		return false;
	}
int Getmonthsday()
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (ISleapyear() && months == 2)
		{
			return 29;
		}
		return monthDays[months];
	}

	void print()
	{
		cout << years << "." << months << "." << days << endl;
	}

	bool IScorrect()
	{
		if (years > 0 && ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0)) && days < 367)//闰年 
		{
			if (months >0 && months < 13)
			{
				if (days > 0 && days <= Getmonthsday())
				{
					return true;
				}
			}
		}
		else if (years >0 && days < 366) //非闰年 
		{
			if (months >0 && months < 13)
			{
				if (days > 0 && days <= Getmonthsday())
				{
					return true;
				}
			}
		}
		return false;
	}

Date operator += (int day)
	{
		*this = *this + 100;
		return *this;
	}
	Date operator -= (int day)
	{
		return *this = *this - day;
	}
	inline Date& operator++()
	{
		*this += 1;
		return *this;
	}
	inline Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}

	bool operator == (const Date& d)
	{
		return (years == d.years&& months == d.months&&days == d.days);
	}

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	bool operator >(const Date& d)
	{
		if (years > d.years ||
			(years == d.years&&months > d.months)
			|| (years == d.years&&months == d.months && days > d.days))
		{
			return true;
		}
		return false;
	}

	bool operator < (const Date& d)
	{
		return !(*this > d);
	}

	bool operator >= (const Date& d)
	{
		return (*this == d) && (*this > d);
	}

	bool operator <= (const Date& d)
	{
		return (*this == d) && (*this < d);
	}
	int date() {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int i, x = 0;
		for (i = 0; i<months - 1; i++)
			x += a[i];
		x = x + days;
		if (months>2)
			if (ISleapyear())
				x++;
		return x;
	}

private:
	int years;
	int months;
	int days;
};

int main()
{
	int birth_year, birth_month, birth_day;
	cout << "请输入你的生日：" << endl;
	cin >> birth_year >> birth_month >> birth_day;
	Date birthday(birth_year, birth_month, birth_day);
	struct tm t;   //tm结构指针

	time_t now;  //声明time_t类型变量

	time(&now);      //获取系统日期和时间

	localtime_s(&t, &now);   //获取当地日期和时间
	int now_year = t.tm_year + 1900;
	int now_month = t.tm_mon + 1;
	int now_day = t.tm_mday;
	Date now_date(now_year, now_month, now_day);
	cout << "你的生日为：";
	birthday.print();
	/*d1 = d1 - 400;*/
	cout << "今天的日期为：";
	now_date.print();
	cout <<"你已经出生了"<<  now_date- birthday << "天"<<endl;//不包括出生当天
	int next_birthday;
	int next_year = now_year + 1;
	if (birthday.date()>now_date.date() || now_date.date() == birthday.date())
	{
		next_birthday =  birthday.date()- now_date.date();
	}
	else
	{
		if (now_date.ISleapyear())
			next_birthday = 366 + birthday.date() - now_date.date();
		else next_birthday = 365 + birthday.date() - now_date.date();
	}
	cout << "距离下一个生日还有" << next_birthday << "天" << endl;
	int constellation_num;
	if ((birth_month == 1 && birth_day >= 20) || (birth_month == 2 && birth_day <= 18))
	{
		cout << "这天是水瓶座" << endl;
		constellation_num = 1;
	}
	else if ((birth_month == 2 && birth_day > 18) || (birth_month == 3 && birth_day <= 20))
	{
		cout << "这天是双鱼座" << endl;
		constellation_num = 2;
	}
	else if ((birth_month == 3 && birth_day > 20) || (birth_month == 4 && birth_day <= 19))
	{
		cout << "这天是白羊座" << endl;
		constellation_num = 3;
	}
	else if ((birth_month == 4 && birth_day >= 20) || (birth_month == 5 && birth_day <= 20))
	{
		cout << "这天是金牛座" << endl;
		constellation_num = 4;
	}
	else if ((birth_month == 5 && birth_day >= 21) || (birth_month == 6 && birth_day <= 21))
	{
		cout << "这天是双子座" << endl;
		constellation_num = 5;
	}
	else if ((birth_month == 6 && birth_day >= 22) || (birth_month == 7 && birth_day <= 22))
	{
		cout << "这天是巨蟹座" << endl;
		constellation_num = 6;
	}
	else if ((birth_month == 7 && birth_day >= 23) || (birth_month == 8 && birth_day <= 22))
	{
		cout << "这天是狮子座" << endl;
		constellation_num = 7;
	}
	else if ((birth_month == 8 && birth_day >= 23) || (birth_month == 9 && birth_day <= 22))
	{
		cout << "这天是处女座" << endl;
		constellation_num = 8;
	}
	else if ((birth_month == 9 && birth_day >= 23) || (birth_month == 10 && birth_day <= 23))
	{
		cout << "这天是天秤座" << endl;
		constellation_num = 9;
	}
	else if ((birth_month == 10 && birth_day >= 24) || (birth_month == 11 && birth_day <= 22))
	{
		cout << "这天是天蝎座" << endl;
		constellation_num = 10;
	}
	else if ((birth_month == 11 && birth_day >= 23) || (birth_month == 12 && birth_day <= 21))
	{
		cout << "这天是射手座" << endl;
		constellation_num = 11;
	}
	else if ((birth_month == 12 && birth_day >= 22) || (birth_month == 1 && birth_day <= 19))
	{
		cout << "这天是摩羯座" << endl;
		constellation_num = 12;
	}
	
	ofstream mycout;
	mycout.open ("运势记录.txt");
	mycout << "你今天的运势是：" << endl;
	cout << "你今天的运势是：" << endl;
	switch (constellation_num)
	{
	case 1:
	{
		mycout << "01" << endl;
		cout << "01" << endl;
		break;
	}
	case 2:
	{
		mycout << "02" << endl;
		cout << "02" << endl;
		break;
	}
	case 3:
	{
		mycout << "03" << endl;
		cout << "03" << endl;
		break;
	}
	case 4:
	{
		mycout << "04" << endl;
		cout << "04" << endl;
		break;
	}
	case 5:
	{
		mycout << "05" << endl;
		cout << "05" << endl;
		break;
	}
	case 6:
	{
		mycout << "06" << endl;
		cout << "06" << endl;
		break;
	}
	case 7:
	{
		mycout << "07" << endl;
		cout << "07" << endl;
		break;
	}
	case 8:
	{
		mycout << "08" << endl;
		cout << "08" << endl;
		break;
	}
	case 9:
	{
		mycout << "09" << endl;
		cout << "09" << endl;
		break;
	}
	case 10:
	{
		mycout << "010" << endl;
		cout << "010" << endl;
		break;
	}
	case 11:
	{
		mycout << "011" << endl;
		cout << "011" << endl;
		break;
	}
	case 12:
	{
		mycout << "012" << endl;
		cout << "012" << endl;
		break;
	}
	}
	mycout.close();
	system("pause");
	return 0;
}
