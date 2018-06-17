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
	cout << "请设置微信ID：" << endl;
	cin >> wechat_id_;
}

void UserSPG::Create()
{
	int judge;
	char ch;
	srand((unsigned)time(NULL));
	weibo_qq_id_ = random(225756789, 987654321);
	cout << "是否开通QQ服务？（1是/0否）" << endl;
	cin >> judge;
	if (judge == 1)
	{
		qq->Create();
		cout << "恭喜您获得QQ账号：" << weibo_qq_id_ << endl;
	}
	cout << "是否开通微博服务？（1是/0否）" << endl;
	cin >> judge;
	if (judge == 1)
	{
		weibo->Create();
		cout << "恭喜您获得微博账号：" << weibo_qq_id_ << endl;
	}
	cout << "是否开通微信服务？（1是/0否）" << endl;
	cin >> judge;
	if (judge == 1)
	{
		wechat->Create();
		SetWeChatId();
	}
	cout << "请设置密码：" << endl;
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
	cout << endl << "创建成功！" << endl;
	system("pause");
}