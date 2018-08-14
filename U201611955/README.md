# 汪泽旸的demo  
1. 某天是什么日子小程序  
2. 运行文件夹中的程序  
依次输入年份+空格+月份+空格+日期，再敲打回车键后程序开始运行计算  
程序会依次显示**是否为闰年、这天是该年第几天、是什么星座**的信息
3. 运行示例图如下  
![示例图](WangZeyangDemo\1.png "示例图")
---
这是我程序的代码
```c++
#include "stdafx.h"


#include "stdafx.h"

#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
	int flag;

public:
	Date(int a, int b, int c) { year = a; month = b; day = c; }
	void runian() {
		if (year % 4 == 0 && year % 100 != 0)
		{
			cout << "是闰年" << endl;
			flag = 1;
		}
		else if (year % 400 == 0)
		{
			cout << "是闰年" << endl;
			flag = 1;
		}
		else {
			cout << "不是闰年" << endl;
			flag = 0;
		}
	}
	int date() {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int i, x = 0;
		for (i = 0; i<month - 1; i++)
			x += a[i];
		x = x + day;
		if (month>2)
			if (flag)
				x++;
		return x;
	}

};
void main(void)
{
	int q, w, e;
	cout << "输入年月日" << endl;
	cin >> q >> w >> e;
	Date j(q, w, e);
	j.runian();
	cout << "这天是该年第" << j.date() << "天" << endl;
	if (w == 1 && e >= 20)
		cout << "这天是水瓶座" << endl;
	else if (w == 2 && e <= 18)
		cout << "这天是水瓶座" << endl;
	else if (w == 2 && e > 18)
		cout << "这天是双鱼座" << endl;
	else if (w == 3 && e <= 20)
		cout << "这天是双鱼座" << endl;
	else if (w == 3 && e > 20)
		cout << "这天是白羊座" << endl;
	else if (w == 4 && e <= 19)
		cout << "这天是白羊座" << endl;
	else if (w == 4 && e >= 20)
		cout << "这天是金牛座" << endl;
	else if (w == 5 && e <= 20)
		cout << "这天是金牛座" << endl;
	else if (w == 5 && e >= 21)
		cout << "这天是双子座" << endl;
	else if (w == 6 && e <= 21)
		cout << "这天是双子座" << endl;
	else if (w == 6 && e >= 22)
		cout << "这天是巨蟹座" << endl;
	else if (w == 7 && e <= 22)
		cout << "这天是巨蟹座" << endl;
	else if (w == 7 && e >= 23)
		cout << "这天是狮子座" << endl;
	else if (w == 8 && e <= 22)
		cout << "这天是狮子座" << endl;
	else if (w == 8 && e >= 23)
		cout << "这天是处女座" << endl;
	else if (w == 9 && e <= 22)
		cout << "这天是处女座" << endl;
	else if (w == 9 && e >= 23)
		cout << "这天是天秤座" << endl;
	else if (w == 10 && e <= 23)
		cout << "这天是天秤座" << endl;
	else if (w == 10 && e >= 24)
		cout << "这天是天蝎座" << endl;
	else if (w == 11 && e <= 22)
		cout << "这天是天蝎座" << endl;
	else if (w == 11 && e >= 23)
		cout << "这天是射手座" << endl;
	else if (w == 12 && e <= 21)
		cout << "这天是射手座" << endl;
	else if (w == 12 && e >= 22)
		cout << "这天是摩羯座" << endl;
	else if (w == 1 && e <= 19)
		cout << "这天是摩羯座" << endl;
}