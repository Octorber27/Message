#include "MyFunctionSPG.h"

void ReadFile()
{
	fstream fp1("information.txt", ios::in | ios::out);
	UserSPG *q1 = new UserSPG;
	while (!fp1.eof())
	{
		fp1.read((char*)q1, sizeof(*q1));
		user_list.push_back(q1);
	}
	user_list.pop_back();
	fp1.close();
	fstream fp2("friends.txt", ios::in | ios::out);
	FriendsSPG *q2 = new FriendsSPG;
	while (!fp2.eof())
	{
		fp2.read((char*)q2, sizeof(*q2));
		all_friends_list.push_back(q2);
	}
	all_friends_list.pop_back();
	fp2.close();
	fstream fp3("groups.txt", ios::in | ios::out);
	GroupSPG *q3 = new GroupSPG;
	while (!fp3.eof())
	{
		fp3.read((char*)q3, sizeof(*q3));
		all_groups_list.push_back(q3);
	}
	all_groups_list.pop_back();
	fp3.close();
}

void SaveVector()
{
	fstream fp4("information.txt", ios::in | ios::out | ios::trunc);
	vector<UserSPG*>::iterator it1 = user_list.begin();
	for (; it1 != user_list.end(); ++it1)
		fp4.write((char*)*it1, sizeof(*it1));
	fp4.close();
	fstream fp5("friends.txt", ios::in | ios::out | ios::trunc);
	vector<FriendsSPG*>::iterator it2 = all_friends_list.begin();
	for (; it2 != all_friends_list.end(); ++it2)
		fp5.write((char*)*it2, sizeof(*it2));
	fp5.close();
	fstream fp6("groups.txt", ios::in | ios::out | ios::trunc);
	vector<GroupSPG*>::iterator it3 = all_groups_list.begin();
	for (; it3 != all_groups_list.end(); ++it3)
		fp6.write((char*)*it3, sizeof(*it3));
	fp6.close();
}

UserSPG* Login()
{
	system("cls");
	int weibo_qq_id;
	string wechat_id, password;
	vector<UserSPG*>::iterator it;
	SetCursorPosition(15, 8);
	cout << "请选择登录方式" << endl;
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "微博";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "Q Q";
	SetCursorPosition(17, 20);
	cout << "微信";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "微博";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "Q Q";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "Q Q";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "微信";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "Q Q";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "微博";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "微信";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "Q Q";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	system("cls");
	SetCursorPosition(0, 0);
	if (key == 1 || key == 2)
	{
		cout << "请输入";
		if (key == 1)
			cout << "微博账号：" << endl;
		else
			cout << "QQ账号：" << endl;
		cin >> weibo_qq_id;
		cout << "请输入密码：" << endl;
		while ((ch = _getch()) != 13)
		{
			if (ch != 8)
			{
				password += ch;
				cout << '*';
			}
			else
			{
				password = password.substr(0, password.size() - 1);
				cout << "\b \b";
			}
		}
		while (1)
		{
			for (it = user_list.begin(); it != user_list.end(); ++it)
			{
				if (weibo_qq_id == (*it)->ReturnWeiboQqId() && password == (*it)->ReturnPassword())
					return *it;
			}
			system("cls");
			cout << "账号或密码错误，请重试！" << endl;
			cout << "请输入正确的账号：" << endl;
			cin >> weibo_qq_id;
			cout << "请输入正确的密码：" << endl;
			password = "";
			while ((ch = _getch()) != 13)
			{
				if (ch != 8)
				{
					password += ch;
					cout << '*';
				}
				else
				{
					password = password.substr(0, password.size() - 1);
					cout << "\b \b";
				}
			}
		}
	}
	else
	{
		cout << "请输入微信账号：";
		cin >> wechat_id;
		while (1)
		{
			for (it = user_list.begin(); it != user_list.end(); ++it)
			{
				if (wechat_id == (*it)->ReturnWeChatId() && password == (*it)->ReturnPassword())
					return *it;
			}
			system("cls");
			cout << "账号或密码错误，请重试！" << endl;
			cout << "请输入正确的账号：" << endl;
			cin >> weibo_qq_id;
			cout << "请输入正确的密码：" << endl;
			cin >> password;
		}
	}
	login_method = key;
}

void SetWindowSize(int cols, int lines)//设置窗口大小
{
	system("title 贪吃蛇");//设置窗口标题
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void Action()
{
	ReadFile();//读取文件信息
	SetWindowSize(41, 31);//设置窗口大小
	SetColor(3);
	SetCursorPosition(16, 10);
	cout << "欢迎使用微X服务！";
	SetCursorPosition(16, 26);
	system("pause");
}

int MainSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "注册";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "登录";
	SetCursorPosition(17, 20);
	cout << "退出";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "注册";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "登录";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "登录";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "退出";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "登录";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "注册";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "退出";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "登录";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int QQSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "查看资料";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "好友管理";
	SetCursorPosition(17, 20);
	cout << "群组管理";
	SetCursorPosition(17, 22);
	cout << "切至微博";
	SetCursorPosition(17, 24);
	cout << "切至微信";
	SetCursorPosition(18, 26);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "查看资料";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "好友管理";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "群组管理";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "切至微博";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "切至微博";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "切至微信";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "切至微信";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "查看资料";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "好友管理";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至微博";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "群组管理";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至微信";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至微博";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至微信";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int WeiboSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "查看资料";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "好友管理";
	SetCursorPosition(17, 20);
	cout << "群组管理";
	SetCursorPosition(17, 22);
	cout << "切至Q Q";
	SetCursorPosition(17, 24);
	cout << "切至微信";
	SetCursorPosition(18, 26);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "查看资料";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "好友管理";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "群组管理";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "切至Q Q";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "切至Q Q";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "切至微信";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "切至微信";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "查看资料";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "好友管理";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至Q Q";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "群组管理";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至微信";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至Q Q";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至微信";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int WeChatSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "查看资料";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "好友管理";
	SetCursorPosition(17, 20);
	cout << "群组管理";
	SetCursorPosition(17, 22);
	cout << "切至Q Q";
	SetCursorPosition(17, 24);
	cout << "切至微博";
	SetCursorPosition(18, 26);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "查看资料";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "好友管理";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "群组管理";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "切至Q Q";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "切至Q Q";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "切至微博";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "切至微博";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "好友管理";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "查看资料";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "群组管理";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "好友管理";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至Q Q";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "群组管理";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "切至微博";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至Q Q";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "切至微博";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int FriendSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "添加好友";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "删除好友";
	SetCursorPosition(17, 20);
	cout << "好友资料";
	SetCursorPosition(17, 22);
	cout << "推荐好友";
	SetCursorPosition(18, 24);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "添加好友";
					SetCursorPosition(17, 18);//将已选中项取消背景色
					SetColor(3);
					cout << "删除好友";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "删除好友";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "好友资料";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "好友资料";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "推荐好友";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "推荐好友";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "删除好友";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "添加好友";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "好友资料";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "删除好友";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "推荐好友";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "好友资料";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "推荐好友";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int QQGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "加入群";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "退出群";
	SetCursorPosition(17, 20);
	cout << "创建群";
	SetCursorPosition(17, 22);
	cout << "管理群";
	SetCursorPosition(18, 24);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "加入群";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "退出群";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "创建群";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "创建群";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "管理群";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "管理群";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "加入群";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "创建群";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "退出群";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "管理群";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "创建群";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "创建群";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int WeiboGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "加入群";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "退出群";
	SetCursorPosition(17, 20);
	cout << "创建群";
	SetCursorPosition(17, 22);
	cout << "管理群";
	SetCursorPosition(18, 24);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "加入群";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "退出群";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "创建群";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "创建群";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "管理群";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "管理群";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "加入群";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "创建群";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "退出群";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "管理群";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "创建群";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "创建群";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int WeChatGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "加入群";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "退出群";
	SetCursorPosition(18, 20);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "加入群";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "退出群";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(18, 20);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "退出群";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "加入群";
					++key;
					break;
				case 2:
					SetCursorPosition(18, 20);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "退出群";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}

int ManageGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "请选择服务!";
	SetCursorPosition(13, 10);
	cout << "(上下键选择,回车确认)";
	SetCursorPosition(17, 16);
	SetBackColor();//第一个选项设置背景色以表示当前选中
	cout << "管理群内成员";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "查询成员资料";
	SetCursorPosition(18, 20);
	cout << "返回";
	SetCursorPosition(0, 30);
	int ch;//记录键入值
	int key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//给待选中项设置背景色
					SetBackColor();
					cout << "管理群内成员";
					SetCursorPosition(17, 18);//将已选中项取消我背景色
					SetColor(3);
					cout << "查询成员资料";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "查询成员资料";
					SetCursorPosition(18, 20);
					SetColor(3);
					cout << "返回";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "查询成员资料";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "管理群内成员";
					++key;
					break;
				case 2:
					SetCursorPosition(18, 20);
					SetBackColor();
					cout << "返回";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "查询成员资料";
					++key;
					break;
				}
			}
			break;
		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag) break;//输入Enter回车键确认，退出检查输入循环
		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}
	return key;
}