#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define MAX 1000 //通讯录容纳量


//封装函数显示菜单
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  7、历史联系人  *****" << endl;
	cout << "*****  8、保存联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
	cout << "this addressbook 1.7 made by \"temporary empty light \" in 2023.8.26 " << endl;
	cout << "1.0 -> 1.5		add 2 new features : read and write!" << endl;
	cout << "1.5 -> 1.6		encrypt the save method!" << endl;
	cout << "1.6 -> 1.7		has repaired a bug in Person_Age by Coldoak!" << endl;
	cout << "\n" << "请输入你想要进行的命令：" << endl;
}




//联系人类
class Person
{
public:
	//姓名
	string Person_Name;
	//性别 1 = 男  2 = 女
	int Person_Sex;
	//年龄
	int Person_Age;
	//联系电话
	string Person_PhoneNumber;
	//住址
	string Person_Address;
};





//通讯录类
class Addressbooks
{
public:
	Person personArray[MAX];//通讯录中保留的联系人数组
	int Person_Size;//通讯录中的联系人个数
};





//添加联系人
void addPerson(Addressbooks* abs)//此处abs可换成其他字母，并非主函数中的abs
{
	//判断通讯录是否已满
	if (abs->Person_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->Person_Size].Person_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 ---男" << endl;
		cout << "2 ---女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->Person_Size].Person_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入!" << endl;
			}
			
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (cin.good() == 1) 
			{
				abs->personArray[abs->Person_Size].Person_Age = age;
				break;
			}
			else
			{
				cout << "输入错误！请重新输入！" << endl;
				cin.clear();
				cin.ignore();

				//cout << "程序即将报错，建议直接关闭" << endl;
				//system("pause");
				//system("cls");
			}
		}

		//联系电话
		cout << "请输入电话：" << endl;
		string PhoneNumber;
		cin >> PhoneNumber;
		abs->personArray[abs->Person_Size].Person_PhoneNumber = PhoneNumber;

		//住址
		cout << "请输入住址： " << endl;
		string Address;
		cin >> Address;
		abs->personArray[abs->Person_Size].Person_Address = Address;

		//更新通讯录中的人数
		abs->Person_Size++;

		cout << "添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏 clean screen
	}
}





//显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录人数是否为0
	if (abs->Person_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Person_Size; i++)
		{
			cout << "姓名：  " << abs->personArray[i].Person_Name << "\t";
			cout << "性别：  " << (abs->personArray[i].Person_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：  " << abs->personArray[i].Person_Age << "\t";
			cout << "联系电话：  " << abs->personArray[i].Person_PhoneNumber << "\t";
			cout << "住址：  " << abs->personArray[i].Person_Address << endl;
		}
	}
	system("pause");
	system("cls");
}




//检测联系人，若存在，返还通讯录中的位置
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->Person_Size; i++)
	{
		if (abs->personArray[i].Person_Name == name)
		{
			return i;//找到了就返回下标
		}
	}
	return -1;  //没找到返回-1
}





//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人姓名： " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i < abs->Person_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->Person_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}




//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人的姓名： " << endl;
	string name;
	cin >> name;

	int  ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名：  " << abs->personArray[ret].Person_Name << "\t";
		cout << "性别：  " << (abs->personArray[ret].Person_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：  " << abs->personArray[ret].Person_Age << "\t";
		cout << "联系电话：  " << abs->personArray[ret].Person_PhoneNumber << "\t";
		cout << "住址：  " << abs->personArray[ret].Person_Address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}




//修改联系人
void motifyPerson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人的姓名：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].Person_Name = name;
		//性别
		int sex;
		cout << "请输入性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		cin >> sex;
		abs->personArray[ret].Person_Sex = sex;
		//年龄
		int age;
		cout << "请输入年龄: " << endl;
		cin >> age;
		abs->personArray[ret].Person_Age = age;
		//联系电话
		string phonenumber;
		cout << "请输入联系电话: " << endl;
		cin >> phonenumber;
		abs->personArray[ret].Person_PhoneNumber = phonenumber;
		//住址
		string address;
		cout << "请输入住址： " << endl;
		cin >> address;
		abs->personArray[ret].Person_Address = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}




//清空通讯录
void cleanPerson(Addressbooks* abs)
{
	abs->Person_Size = 0;
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");
}




//历史联系人
void ReadFile(Addressbooks* abs)
{
	//创建流对象
	fstream diary;
	fstream diary_size;

	//读取通讯录长度
	diary_size.open("diary_size1.6.txt", ios::in | ios::binary);

	if (!diary_size.is_open())
	{
		cout << "通讯录长度读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	diary_size.read((char*)&abs->Person_Size, sizeof(int));

	diary_size.close();

	//打开文件，并判断是否打开成功
	diary.open("diary1.6.txt", ios::in | ios::binary);
	if (!diary.is_open())
	{
		cout << "文件打开失败" << endl;
		system("pause");
		system("cls");
		return;
	}

	//读取文件
	for (int i = 0; i < abs->Person_Size; i++)
	{
		diary.read((char*)&abs->personArray[i], sizeof(Person));
	}
	
	cout << "读取成功！" << endl;

	for (int i = 0; i < abs->Person_Size; i++)
	{
		cout << "姓名：  " << abs->personArray[i].Person_Name << "\t";
		cout << "性别：  " << (abs->personArray[i].Person_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：  " << abs->personArray[i].Person_Age << "\t";
		cout << "联系电话：  " << abs->personArray[i].Person_PhoneNumber << "\t";
		cout << "住址：  " << abs->personArray[i].Person_Address << endl;
		
	}

	//关闭文件
	diary.close();
	
	//输入任意键以清屏
	system("pause");
	system("cls");
	
}


//将已保存的联系人信息写入文件
void SaveFile(Addressbooks* abs)
{
	
	//创建信息流
	fstream diary;
	fstream diary_size;

	//以写入模式打开
	diary.open("diary1.6.txt", ios::out | ios::binary);

	//判断通讯录是否为空，空则不执行写入操作
	if (abs->Person_Size == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Person_Size; i++)
		{
			diary.write((char*)&abs->personArray[i], sizeof(Person));
		}
	}
	//关闭文件
	diary.close();

	//保存通讯录长度
	diary_size.open("diary_size1.6.txt", ios::out | ios::binary);

	diary_size.write((char*)&abs->Person_Size, sizeof(int));

	diary_size.close();
	cout << "保存成功！" << endl;

	//输入任意键清屏
	system("pause");
	system("cls");
}




int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.Person_Size = 0;

	int decision = 0;
	

	while (true)
	{
		//菜单
		showMenu();

		cin >> decision;

		switch (decision)
		{
		case 1:						//1、添加联系人
			addPerson(&abs);		//注意是地址传递，不是值传递
			break;
		case 2:						//2、显示联系人
			showPerson(&abs);
			break;
		case 3:						//3、删除联系人
			deletePerson(&abs);
			break;
		case 4:						//4、查找联系人
			findPerson(&abs);
			break;
		case 5:						//5、修改联系人
			motifyPerson(&abs);
			break;
		case 6:						//6、清空联系人
			cleanPerson(&abs);
			break;
		case 7:                    //7、历史联系人
			ReadFile(&abs);
			break;
		case 8:						//8、保存联系人
			SaveFile(&abs);
			break;
		case 0:						//0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	cout << "你没有按照规则来进行" << endl;
	system("pause");
	system("cls");
	return 0;
}