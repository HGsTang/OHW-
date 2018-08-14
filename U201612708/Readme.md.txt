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


