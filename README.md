# OHW组总结md  
## 汪泽旸的demo   
1. 某天是什么日子小程序  
2. 运行文件夹中的程序  
依次输入年份+空格+月份+空格+日期，再敲打回车键后程序开始运行计算  
程序会依次显示**是否为闰年、这天是该年第几天、是什么星座**的信息
3. 运行示例图如下  
![示例图](U201611955\WangZeyangDemo\1.png "示例图")
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
  
  
## U201612041 李瑶璐的demo
## 该demo实现的功能
这个python小程序可以导入.xlsx文件中的数据，再由用户在控制台输入图的横坐标及纵坐标、图表标题、图表类型，从而输出用户想要的表格。
## 该demo使用的库文件
**matplotlib**这一模块可以实现简单的统计向画图功能，而导入并提取excel表格文件中的数据需要用到**xlrd**模块。
## 代码的具体实现
### 1. 定义图表函数
虽然matplotlib提供了现成的画图表函数，但是为了方便后面进行类型选择的代码编写，打算使用`def`来进行每种图画图过程的封装。
### 2. 提取表格文档数据
首先打开所需的工作簿，然后对工作表进行遍历并提取具体数据。

值得一提的是，xlrd模块中的append函数在工作表中直接提取出来的数据是一个二维数组，即使你提取的仅有一行数据。而matplotlib的画图功能仅能输入一维数组，因此对提出来的数组还要用for循环再append一次，才能得到想要的结果。
### 3. 输入图表坐标说明文字
由于仅仅是在控制台输入，该功能用最简单的`print`即可实现。不过python一般情况下不支持中文，所以要成功输入中文就要在前面加一行`#-*-coding:utf-8-*-`。
### 4. 进行图表类型选择
python没有switch函数，但可以通过编写一个字典，然后通过`choice`函数来实现选择的功能。
### **该demo的具体代码如下：**
```python
#-*-coding:utf-8-*-
import xlrd
import matplotlib.pyplot as plt
def tiaoxingtu():
    plt.bar(num_1,num_2,color='y')
    plt.legend()
    plt.xlabel(tex_x)
    plt.ylabel(tex_y)
    plt.title(tex_tit)
    plt.show()
def sandiantu():
    plt.scatter(num_1,num_2, color='r', s=25)
    plt.xlabel(tex_x)
    plt.ylabel(tex_y)
    plt.title(tex_tit)
    plt.legend()
    plt.show()
def duidietu():
    plt.stackplot(num_1, num_2, colors='m')
    plt.xlabel(tex_x)
    plt.ylabel(tex_y)
    plt.title(tex_tit)
    plt.show()
file=input('请输入表格位置:')
sheet_index=0
workbook = xlrd.open_workbook(file)
sheet = workbook.sheet_by_index(sheet_index)
print("工作表名称:", sheet.name)
print("行数:", sheet.nrows)
print("列数:", sheet.ncols)
num_11= []
num_22= []
num_1=[]
num_2=[]
num_11.append(sheet.col_values(0))
num_22.append(sheet.col_values(1))

for m in range(0,1):

    for i in num_11[m]:

        num_1.append(i)

for m in range(0,1):

    for i in num_22[m]:

        num_2.append(i)

print(num_1)
print(num_2)
tex_x = input("输入横坐标: ")
print("横坐标为:",tex_x)
tex_y= input("输入纵坐标: ")
print("纵坐标为:",tex_y)
tex_tit=input("输入图表标题：")
print("标题为:",tex_tit)
tex_tp=input("输入类型 :1 条形图 2 散点图 3 堆叠图")
choice = { '1' : tiaoxingtu, '2' : sandiantu, '3': duidietu }
if tex_tp in choice:
    choice[tex_tp]()
else: print("没有适合的类型")
```
## 代码具体输出示例

![图表测试代码1](image/图表测试1.png "图表标签输入英文时")

![图表输出1](image/图表测试2.png "标签正常输出")

然而matplotlib也不支持默认中文输入，即使编码最开头做了设置。要想解决这一问题，需要启用字体管理器，这个问题会在后面的版本做出修改。


![图表测试代码2](image/图表测试3.png "图表标签输入中文时")

![图表输出2](image/图表测试4.png "标签输出有问题")

## 不足与改进
这个demo虽然能解决这个图表打印的简单层面问题，但是还有不少深入的部分需要解决，比如图表其他元素的设置（颜色等）；而且它只能打印表格的前两列数据，如何根据用户需求打印其他列的数据也是一个要解决的问题。代码简洁性亦需要加强。后面将会在新的版本中解决这些问题。
## *谢谢大家的阅读*
  
    

## 于启辰的demo
## 作用
此程序主要作用是对学生信息进行输入，查询和修改。先将学生信息诸如学号，姓名，住址，寝室进行依次输入，再通过以姓名，学号等关键词进行查询，进而进行修改。  
## 如何运行
----
1. 调试运行程序
2. 进行选择  
    1. 输入学生信息  
    2. 显示学生信息  
    4. 查询学生信息  
    2. 统计学生信息
    6. 删除学生信息
    3. 修改学生信息
    7. 清理屏幕
    6. 退出系统  
4. 根据指示进行下一步动作
----
```c++
void Student::StuShow()
{
	fstream fin("d:\\userInfo.txt", ios::in);
	if (fin.fail())
	{
		cout << "d:\\userInfo.txt" << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		fin >> number >> name >> sex >> age >> address >> chamber;
		if (fin.fail())
		{
			break;
		}
		cout << "学号为：" << number << "\t姓名为：" << name << "\t年龄为：" << age << "\t住址为：" << address << "\t寝室号为：" << chamber << endl;
		if (sex == 'm')
		{
			cout << "该名学生的性别为：男" << endl;
		}
		else
			cout << "该名学生的性别为：女" << endl;

	}
	fin.close();
}
//删除、修改，操作提示界面
void chosemenu()
{
	cout << "--------------------------------" << endl;
	cout << "1、删除该学生" << endl;
	cout << "2、修改该学生的信息" << endl;
	cout << "请选择你需要进行的操作,输入0退出" << endl;
}
//删改学生信息
void Student::chose()
{
	while (true)
	{
		int n;
		chosemenu();
		cin >> n;
		if (n == 0)
			break;
		switch (n)
		{
		case 1:; break;
		case 2:; break;
		default:cout << "输入有误请重新输入" << endl;
		}
	}
}
//删除学生信息
void Student::deldata()
{
	string id;
	cin >> id;
	cout << "请输入要删除的学生的学号：" << endl;
	vector <Student> name;//vector 是个容器
	fstream fin("userInfo.txt", ios::in);
Student stu;
	int n = 0;
	if (fin.fail())
	{
		cout << "Cannot open fail.";
		exit(1);
	}
    while (!fin.eof())
	{
		fin >> stu.number >> stu.name >> stu.sex >> stu.age >> stu.address
			>> stu.chamber;
		if (stu.number.length() == 0)
			break;
		if (stu.number == id)
		{
			n = 1;
			continue;//break是跳出循环而continue是再次继续运行循环
		}
		name.push_back(stu);
	}
	fin.close();
	if (n == 0)
	{
		cout << "没有该用户" << endl;
	}
	fstream fout("userInfo.txt", ios::out);
	if (!fout)
	{
		cout << "Cannot open file." << endl;
		exit(1);
	}
	for (int i = 0; i<name.size(); i++)
	{
		fout << " " << name[i].number << " " << name[i].name << " " << name[i].sex << " " << name[i].age << " " << name[i].address << " "
			<< name[i].chamber << endl;
	}
	fout.close();
}  
```
## ![恭喜完成](学生管理/finish.png "Rock'n Roll")


