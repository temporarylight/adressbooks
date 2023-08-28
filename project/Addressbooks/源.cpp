#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#define MAX 1000 //ͨѶ¼������


//��װ������ʾ�˵�
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  7����ʷ��ϵ��  *****" << endl;
	cout << "*****  8��������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
	cout << "this addressbook 1.7 made by \"temporary empty light \" in 2023.8.26 " << endl;
	cout << "1.0 -> 1.5		add 2 new features : read and write!" << endl;
	cout << "1.5 -> 1.6		encrypt the save method!" << endl;
	cout << "1.6 -> 1.7		has repaired a bug in Person_Age by Coldoak!" << endl;
	cout << "\n" << "����������Ҫ���е����" << endl;
}




//��ϵ����
class Person
{
public:
	//����
	string Person_Name;
	//�Ա� 1 = ��  2 = Ů
	int Person_Sex;
	//����
	int Person_Age;
	//��ϵ�绰
	string Person_PhoneNumber;
	//סַ
	string Person_Address;
};





//ͨѶ¼��
class Addressbooks
{
public:
	Person personArray[MAX];//ͨѶ¼�б�������ϵ������
	int Person_Size;//ͨѶ¼�е���ϵ�˸���
};





//�����ϵ��
void addPerson(Addressbooks* abs)//�˴�abs�ɻ���������ĸ�������������е�abs
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->Person_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->Person_Size].Person_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 ---��" << endl;
		cout << "2 ---Ů" << endl;
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
				cout << "������������������!" << endl;
			}
			
		}

		//����
		cout << "���������䣺 " << endl;
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
				cout << "����������������룡" << endl;
				cin.clear();
				cin.ignore();

				//cout << "���򼴽���������ֱ�ӹر�" << endl;
				//system("pause");
				//system("cls");
			}
		}

		//��ϵ�绰
		cout << "������绰��" << endl;
		string PhoneNumber;
		cin >> PhoneNumber;
		abs->personArray[abs->Person_Size].Person_PhoneNumber = PhoneNumber;

		//סַ
		cout << "������סַ�� " << endl;
		string Address;
		cin >> Address;
		abs->personArray[abs->Person_Size].Person_Address = Address;

		//����ͨѶ¼�е�����
		abs->Person_Size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�����������
		system("cls");//���� clean screen
	}
}





//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ0
	if (abs->Person_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Person_Size; i++)
		{
			cout << "������  " << abs->personArray[i].Person_Name << "\t";
			cout << "�Ա�  " << (abs->personArray[i].Person_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺  " << abs->personArray[i].Person_Age << "\t";
			cout << "��ϵ�绰��  " << abs->personArray[i].Person_PhoneNumber << "\t";
			cout << "סַ��  " << abs->personArray[i].Person_Address << endl;
		}
	}
	system("pause");
	system("cls");
}




//�����ϵ�ˣ������ڣ�����ͨѶ¼�е�λ��
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->Person_Size; i++)
	{
		if (abs->personArray[i].Person_Name == name)
		{
			return i;//�ҵ��˾ͷ����±�
		}
	}
	return -1;  //û�ҵ�����-1
}





//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�������� " << endl;

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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}




//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�˵������� " << endl;
	string name;
	cin >> name;

	int  ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������  " << abs->personArray[ret].Person_Name << "\t";
		cout << "�Ա�  " << (abs->personArray[ret].Person_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺  " << abs->personArray[ret].Person_Age << "\t";
		cout << "��ϵ�绰��  " << abs->personArray[ret].Person_PhoneNumber << "\t";
		cout << "סַ��  " << abs->personArray[ret].Person_Address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}




//�޸���ϵ��
void motifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[ret].Person_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա� " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cin >> sex;
		abs->personArray[ret].Person_Sex = sex;
		//����
		int age;
		cout << "����������: " << endl;
		cin >> age;
		abs->personArray[ret].Person_Age = age;
		//��ϵ�绰
		string phonenumber;
		cout << "��������ϵ�绰: " << endl;
		cin >> phonenumber;
		abs->personArray[ret].Person_PhoneNumber = phonenumber;
		//סַ
		string address;
		cout << "������סַ�� " << endl;
		cin >> address;
		abs->personArray[ret].Person_Address = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}




//���ͨѶ¼
void cleanPerson(Addressbooks* abs)
{
	abs->Person_Size = 0;
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");
}




//��ʷ��ϵ��
void ReadFile(Addressbooks* abs)
{
	//����������
	fstream diary;
	fstream diary_size;

	//��ȡͨѶ¼����
	diary_size.open("diary_size1.6.txt", ios::in | ios::binary);

	if (!diary_size.is_open())
	{
		cout << "ͨѶ¼���ȶ�ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	diary_size.read((char*)&abs->Person_Size, sizeof(int));

	diary_size.close();

	//���ļ������ж��Ƿ�򿪳ɹ�
	diary.open("diary1.6.txt", ios::in | ios::binary);
	if (!diary.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	//��ȡ�ļ�
	for (int i = 0; i < abs->Person_Size; i++)
	{
		diary.read((char*)&abs->personArray[i], sizeof(Person));
	}
	
	cout << "��ȡ�ɹ���" << endl;

	for (int i = 0; i < abs->Person_Size; i++)
	{
		cout << "������  " << abs->personArray[i].Person_Name << "\t";
		cout << "�Ա�  " << (abs->personArray[i].Person_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺  " << abs->personArray[i].Person_Age << "\t";
		cout << "��ϵ�绰��  " << abs->personArray[i].Person_PhoneNumber << "\t";
		cout << "סַ��  " << abs->personArray[i].Person_Address << endl;
		
	}

	//�ر��ļ�
	diary.close();
	
	//���������������
	system("pause");
	system("cls");
	
}


//���ѱ������ϵ����Ϣд���ļ�
void SaveFile(Addressbooks* abs)
{
	
	//������Ϣ��
	fstream diary;
	fstream diary_size;

	//��д��ģʽ��
	diary.open("diary1.6.txt", ios::out | ios::binary);

	//�ж�ͨѶ¼�Ƿ�Ϊ�գ�����ִ��д�����
	if (abs->Person_Size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Person_Size; i++)
		{
			diary.write((char*)&abs->personArray[i], sizeof(Person));
		}
	}
	//�ر��ļ�
	diary.close();

	//����ͨѶ¼����
	diary_size.open("diary_size1.6.txt", ios::out | ios::binary);

	diary_size.write((char*)&abs->Person_Size, sizeof(int));

	diary_size.close();
	cout << "����ɹ���" << endl;

	//�������������
	system("pause");
	system("cls");
}




int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.Person_Size = 0;

	int decision = 0;
	

	while (true)
	{
		//�˵�
		showMenu();

		cin >> decision;

		switch (decision)
		{
		case 1:						//1�������ϵ��
			addPerson(&abs);		//ע���ǵ�ַ���ݣ�����ֵ����
			break;
		case 2:						//2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:						//3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:						//4��������ϵ��
			findPerson(&abs);
			break;
		case 5:						//5���޸���ϵ��
			motifyPerson(&abs);
			break;
		case 6:						//6�������ϵ��
			cleanPerson(&abs);
			break;
		case 7:                    //7����ʷ��ϵ��
			ReadFile(&abs);
			break;
		case 8:						//8��������ϵ��
			SaveFile(&abs);
			break;
		case 0:						//0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	cout << "��û�а��չ���������" << endl;
	system("pause");
	system("cls");
	return 0;
}