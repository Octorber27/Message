#include "UserSPG.h"


int UserSPG::ReturnWeiboQqId()
{
	return weibo_qq_id_;
}

string UserSPG::ReturnWeChatId()
{
	return wechat_id_;
}

string UserSPG::ReturnPassword()
{
	return password_;
}

void UserSPG::SetWeChatId()
{
	cout << "������΢��ID��" << endl;
	cin >> wechat_id_;
}

void UserSPG::Create()
{
	int judge;
	char ch;
	srand((unsigned)time(NULL));
	weibo_qq_id_ = random(225756789, 987654321);
	cout << "�Ƿ�ͨQQ���񣿣�1��/0��" << endl;
	cin >> judge;
	if (judge == 1)
	{
		qq->Create();
		cout << "��ϲ�����QQ�˺ţ�" << weibo_qq_id_ << endl;
	}
	cout << "�Ƿ�ͨ΢�����񣿣�1��/0��" << endl;
	cin >> judge;
	if (judge == 1)
	{
		weibo->Create();
		cout << "��ϲ�����΢���˺ţ�" << weibo_qq_id_ << endl;
	}
	cout << "�Ƿ�ͨ΢�ŷ��񣿣�1��/0��" << endl;
	cin >> judge;
	if (judge == 1)
	{
		wechat->Create();
		SetWeChatId();
	}
	cout << "���������룺" << endl;
	while ((ch = _getch()) != 13)
	{
		if (ch != 8)
		{
			password_ += ch;
			cout << '*';
		}
		else
		{
			password_ = password_.substr(0, password_.size() - 1);
			cout << "\b \b";
		}
	}
	cout << endl << "�����ɹ���" << endl;
	system("pause");
}