# 于启辰的demo
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
// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#pragma warning (disable: 4786)
#include <vector>
#include <algorithm>
#include <conio.h> 
#include<windows.h>
using namespace std;

class Student
{
public:
	void StuShow();
	void Studenttxt();
	bool duplicated(string);
	void surface();
	int submenu();
	void chose();
	void entrydata();
	bool duplicated();
	void searchname();
	int searchID(string);
	void searchsex();
	void searchcha();
	void updata(string);
	//void deldata();
	void count();
	void countsex(char);
	void countall();
	void deldata();
	void modify();
	Student alterUser(Student);

private:
	string name;
	string number;
	char sex;
	int age;
	string address;
	string chamber;
};


//菜单
void menu()
{
	cout << "-------------------" << endl;
	cout << "1、输入学生信息" << endl;
	cout << "2、显示学生信息" << endl;
	cout << "3、查询学生信息" << endl;
	cout << "4、统计学生信息" << endl;
	cout << "5、删除学生信息" << endl;
	cout << "6、修改学生信息" << endl;
	cout << "7、清理屏幕" << endl;
	cout << "0、退出系统" << endl;
	cout << "-------------------" << endl;
}

//查询学生信息
void searchmenu()
{
	cout << "-------------------------" << endl;
	cout << "1、按学号查找" << endl;
	cout << "2、按姓名查找" << endl;
	cout << "3、按寝室号查找" << endl;
	cout << "4、按性别查找" << endl;
	cout << "-------------------------" << endl;
}
//统计的菜单
void countmenu()
{
	cout << "----------------------------" << endl;
	cout << "请选择你要统计的内容或操作：" << endl;
	cout << "1、统计男生数" << endl;
	cout << "2、统计女生数" << endl;
	cout << "3、统计总人数" << endl;
	cout << "4、按0退出" << endl;
	cout << "----------------------------" << endl;
}
//数据录入
void Student::entrydata()
{
	Student Stu;
	cout << "您正在添加学生信息" << endl;
	cout << "------------------" << endl;
	cout << "请输入学号：" << endl;
	cin >> number;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入性别，m表示男，w表示女：" << endl;
	cin >> sex;
	cout << "请输入年龄：" << endl;
	cin >> age;
	cout << "请输入住址：" << endl;
	cin >> address;
	cout << "请输入寝室号：" << endl;
	cin >> chamber;
	//menu();
	Studenttxt();
}

//数据保存，文本格式
void Student::Studenttxt()
{
	fstream fout1("d:\\userInfo.txt", ios::out | ios::app);
	fout1 << number << " " << name << " " << sex << " " << age << " " << address << " " << chamber << endl;
	fout1.close();
}

//按照学号查询
int Student::searchID(string id)
{
	fstream fin("d:\\userInfo.txt", ios::in);
	if (fin.fail())
	{
		cout << "Cannot open file." << endl;
		exit(1);
	}
	Student Stu;
	int n = 0;
	while (!fin.eof())
	{
		fin >> Stu.number >> Stu.name >> Stu.sex >> Stu.age >> Stu.address >> Stu.chamber;
		if (Stu.number == "")
			break;
		if (Stu.number == id)
		{
			cout << Stu.number << " " << Stu.name << " " << Stu.sex;
			if (Stu.sex == 'm')
			{
				cout << "男";
			}
			else
				cout << "女";
			cout << " " << Stu.age << " " << Stu.address << " " << Stu.chamber << endl;
			n = 1;
		}
		Stu.number = "";
	}
	if (n == 0)
		cout << "没有你要找的学生!!!" << endl;
	fin.close();
	return 0;
}
//数据读取
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
//修改学生信息
void Student::modify()
{
	string id;
	cout << "请输入你要修改的学生号：" << endl;
	cin >> id;
	vector <Student> name;
	fstream fin("d:\\userInfo.txt", ios::in);
	Student Stu;
	int n = 0;
	if (fin.fail())
	{
		cout << "Cannot open fail.";
		exit(1);
	}
	while (!fin.eof())
	{
		fin >> Stu.number >> Stu.name >> Stu.sex >> Stu.sex >> Stu.age >> Stu.address >> Stu.chamber;
		if (Stu.number.length() == 0)
			break;
		if (Stu.number == id)
		{
			Stu = alterUser(Stu);
			n = 1;
		}
		name.push_back(Stu);
	}
	fin.close();
	if (n == 0)
	{
		cout << "没有该用户" << endl;
		return;
	}

	fstream fout("d:\\userInfo.txt", ios::out);
	if (!fout)
	{
		cout << "Cannot open file." << endl;
		exit(1);
	}
	for (int i = 0; i<name.size(); i++)
	{
		fout << name[i].number << " " << name[i].name << " " << name[i].sex << " "
			<< name[i].age << " " << name[i].address << " " << name[i].chamber << endl;
	}
	fout.close();
}
//获取修改后的学生信息
Student Student::alterUser(Student S)
{
	Student Stu;
	Stu.name = S.name;
	cout << "请输入你要修改的姓名：" << S.name << endl;
	cin >> Stu.name;
	cout << "请输入你要修改的性别：" << S.sex << endl;
	cin >> Stu.sex;
	cout << "请输入你要修改的地址：" << S.address << endl;
	cin >> Stu.address;
	cout << "请输入你要修改的寝室号：" << S.chamber << endl;
	cin >> Stu.chamber;
	cout << "你确认要修改么？Yes(1)/No(0)" << endl;
	int n;
	cin >> n;
	if (n == 1)
		return Stu;
	else
		return S;
}
//统计
void Student::count()
{

	while (true)
	{
		int w;
		char Se;
		countmenu();
		cin >> w;
		if (w == 0)
			break;
		switch (w)
		{
		case 1: Se = 'm'; countsex(Se); break;
		case 2: Se = 'n'; countsex(Se); break;
		case 3:; break;
		default:cout << "输入有误请重新输入" << endl;
		}
	}
}
//按照性别统计
void Student::countsex(char Se)
{
	fstream fin("d:\\userInfo.txt", ios::in);
	Student stu;
	int n = 0;
	if (fin.fail())
	{
		cout << "Cannot open fail.";
		exit(1);
	}
	while (!fin.eof())
	{
		fin >> stu.number >> stu.name >> stu.sex
			>> stu.age >> stu.address >> stu.chamber;
		if (stu.name.length() == 0)
			break;
		if (stu.sex == Se)
		{
			n++;
		}
	}
	fin.close();
	cout << (Se == 'm' ? "男" : "女") << "生共有" << n << "人" << endl;
	cout << endl;
}
//统计总人数
void Student::countall()
{
	fstream fin("d:\\userInfo.txt", ios::in);
	Student Stu;
	int n = 0;
	if (fin.fail())
	{
		cout << "Cannot open fail.";
		exit(1);
	}
	while (!fin.eof())
	{
		fin >> Stu.number >> Stu.name >> Stu.age >> Stu.sex >> Stu.address >> Stu.chamber;
		if (Stu.number.length() == 0)
			break;
		n++;
	}
	fin.close();
	cout << "共有" << n << "个人" << endl;
}
//学号重复判断
bool Student::duplicated(string number)
{
	Student Stu;
	bool exist = false;
	fstream fin("d:\\user.txt", ios::in);
	if (fin.fail())
	{
		return exist;
	}
	while (!fin.eof()) //eof判断是否到文件末尾
	{
		fin >> Stu.number >> Stu.name >> Stu.sex >> Stu.age >> Stu.address >> Stu.chamber;
		if (number == Stu.number)
		{
			exist = true; //表示有重名的
			break;
		}
	}
	fin.close();
	return exist;
}
//界面函数
void Student::surface()
{
	menu();
	while (true)
	{
		int n;
		cout << "请输入相应的数字选择操作" << endl;
		cin >> n;
		if (n == 0)
			break;
		switch (n)
		{
		case 1: entrydata(); menu(); break;
		case 2: StuShow(); menu(); break;
		case 3: submenu(); menu(); break;
		case 4: count(); menu(); break;
		case 5: deldata(); break;
		case 6: modify();; break;
		case 7: system("cls"); break;
		default:cout << "输入有误请重新输入" << endl;
		}
	}
}

//学生信息查询
int Student::submenu()
{
	while (true)
	{
		int n;
		searchmenu();
		cout << "请输入你想查找的方式，按0返回上一层" << endl;
		cin >> n;
		if (n == 0)
			break;
		switch (n)
		{
		case 1:
		{
			string id;
			cout << "请输入你要查询的学生号：" << endl;
			cin >> id;
			searchID(id);
			chose();
		}break;
		case 2:; break;
		case 3:; break;
		case 4:; break;
		default:cout << "输入有误请重新输入" << endl;
		}
	}
	return 0;
}
int main()
{
	Student Stu;
	Stu.surface();
	return 0;
}


```
## ![恭喜完成](学生管理/finish.png "Rock'n Roll")


