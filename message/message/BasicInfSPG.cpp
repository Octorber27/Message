#include "BasicInfSPG.h"

void BasicInfSPG::Create()
{
	cout << "�������ǳƣ�" << endl;
	cin >> nickname_;
	cout << "�����ó������ڣ�" << endl;
	cin >> birthday_[0] >> birthday_[1] >> birthday_[2];
	cout << "���������ڵأ�" << endl;
	cin >> location_;
	struct tm t;//tm�ṹָ��
	time_t nowT;//����time_t���ͱ���
	time(&nowT);//��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &nowT);//��ȡ�������ں�ʱ��
	asctime_s(age_, &t);
}

void BasicInfSPG::TellInf()
{
	//�ⲿ����ID
	cout << "�ǳƣ�" << nickname_ << endl << "���գ�" << birthday_[0] << "��"
		<< birthday_[1] << "��" << birthday_[2] << "��" << endl << "���ڵأ�"
		<< location_ << endl << "��������ʱ�䣺" << age_ << endl;
	system("pause");
}

void BasicInfSPG::QuitGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = group_list_.begin();
	cout << "��������Ⱥ��" << endl;
	for (; it != group_list_.end(); ++it)
	{
		if ((*it)->group_id_ != 0)
		{
			cout << i << '.' << (*it)->group_name_ << endl << '(' << (*it)->group_id_ << ')' << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag == true)
	{
		cout << "������Ҫ�˳�Ⱥ����ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸ�Ⱥ��" << endl;
		else
		{
			group_list_.erase(group_list_.begin() + number);
			(*it)->is_qq_member_ = 0;
			cout << "��Ⱥ�ɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κ�Ⱥ��" << endl;
	}
}

GroupSPG* BasicInfSPG::ManageGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = group_list_.begin();
	cout << "��������Ⱥ��" << endl;
	for (; it != group_list_.end(); ++it)
	{
		if ((*it)->group_id_ != 0)
		{
			cout << i << '.' << (*it)->group_name_ << '('
				<< (*it)->group_id_ << ')' << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag == true)
	{
		cout << "������Ҫ�����Ⱥ��ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸ�Ⱥ��" << endl;
		else
			return *it;
	}
	else
	{
		cout << "��δ�����κ�Ⱥ��" << endl;
		return 0;
	}
}