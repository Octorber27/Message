#include "BasicInfSPG.h"

void BasicInfSPG::Create()
{
	cout << "请设置昵称：" << endl;
	cin >> nickname_;
	cout << "请设置出生日期：" << endl;
	cin >> birthday_[0] >> birthday_[1] >> birthday_[2];
	cout << "请设置所在地：" << endl;
	cin >> location_;
	struct tm t;//tm结构指针
	time_t nowT;//声明time_t类型变量
	time(&nowT);//获取系统日期和时间
	localtime_s(&t, &nowT);//获取当地日期和时间
	asctime_s(age_, &t);
}

void BasicInfSPG::TellInf()
{
	//外部给出ID
	cout << "昵称：" << nickname_ << endl << "生日：" << birthday_[0] << "年"
		<< birthday_[1] << "月" << birthday_[2] << "日" << endl << "所在地："
		<< location_ << endl << "号码申请时间：" << age_ << endl;
	system("pause");
}

void BasicInfSPG::QuitGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = group_list_.begin();
	cout << "您有以下群：" << endl;
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
		cout << "请输入要退出群的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该群！" << endl;
		else
		{
			group_list_.erase(group_list_.begin() + number);
			(*it)->is_qq_member_ = 0;
			cout << "退群成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何群！" << endl;
	}
}

GroupSPG* BasicInfSPG::ManageGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = group_list_.begin();
	cout << "您有以下群：" << endl;
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
		cout << "请输入要管理的群序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该群！" << endl;
		else
			return *it;
	}
	else
	{
		cout << "您未加入任何群！" << endl;
		return 0;
	}
}