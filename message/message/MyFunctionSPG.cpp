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
	cout << "��ѡ���¼��ʽ" << endl;
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "΢��";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "Q Q";
	SetCursorPosition(17, 20);
	cout << "΢��";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "΢��";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
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
					cout << "΢��";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
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
					cout << "΢��";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "΢��";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "Q Q";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	system("cls");
	SetCursorPosition(0, 0);
	if (key == 1 || key == 2)
	{
		cout << "������";
		if (key == 1)
			cout << "΢���˺ţ�" << endl;
		else
			cout << "QQ�˺ţ�" << endl;
		cin >> weibo_qq_id;
		cout << "���������룺" << endl;
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
			cout << "�˺Ż�������������ԣ�" << endl;
			cout << "��������ȷ���˺ţ�" << endl;
			cin >> weibo_qq_id;
			cout << "��������ȷ�����룺" << endl;
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
		cout << "������΢���˺ţ�";
		cin >> wechat_id;
		while (1)
		{
			for (it = user_list.begin(); it != user_list.end(); ++it)
			{
				if (wechat_id == (*it)->ReturnWeChatId() && password == (*it)->ReturnPassword())
					return *it;
			}
			system("cls");
			cout << "�˺Ż�������������ԣ�" << endl;
			cout << "��������ȷ���˺ţ�" << endl;
			cin >> weibo_qq_id;
			cout << "��������ȷ�����룺" << endl;
			cin >> password;
		}
	}
	login_method = key;
}

void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
	system("title ̰����");//���ô��ڱ���
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(const int x, const int y)//���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//�����ı���ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

void Action()
{
	ReadFile();//��ȡ�ļ���Ϣ
	SetWindowSize(41, 31);//���ô��ڴ�С
	SetColor(3);
	SetCursorPosition(16, 10);
	cout << "��ӭʹ��΢X����";
	SetCursorPosition(16, 26);
	system("pause");
}

int MainSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "ע��";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "��¼";
	SetCursorPosition(17, 20);
	cout << "�˳�";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "ע��";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "��¼";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "��¼";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "�˳�";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "��¼";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "ע��";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "�˳�";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "��¼";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int QQSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "�鿴����";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "���ѹ���";
	SetCursorPosition(17, 20);
	cout << "Ⱥ�����";
	SetCursorPosition(17, 22);
	cout << "����΢��";
	SetCursorPosition(17, 24);
	cout << "����΢��";
	SetCursorPosition(18, 26);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "�鿴����";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "���ѹ���";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "Ⱥ�����";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "����΢��";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "����΢��";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "�鿴����";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "���ѹ���";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "Ⱥ�����";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����΢��";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����΢��";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int WeiboSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "�鿴����";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "���ѹ���";
	SetCursorPosition(17, 20);
	cout << "Ⱥ�����";
	SetCursorPosition(17, 22);
	cout << "����Q Q";
	SetCursorPosition(17, 24);
	cout << "����΢��";
	SetCursorPosition(18, 26);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "�鿴����";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "���ѹ���";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "Ⱥ�����";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "����Q Q";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "����Q Q";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "����΢��";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "�鿴����";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "���ѹ���";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����Q Q";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "Ⱥ�����";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Q Q";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����΢��";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int WeChatSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "�鿴����";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "���ѹ���";
	SetCursorPosition(17, 20);
	cout << "Ⱥ�����";
	SetCursorPosition(17, 22);
	cout << "����Q Q";
	SetCursorPosition(17, 24);
	cout << "����΢��";
	SetCursorPosition(18, 26);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "�鿴����";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "���ѹ���";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "Ⱥ�����";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "����Q Q";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "����Q Q";
					SetCursorPosition(17, 24);
					SetColor(3);
					cout << "����΢��";
					--key;
					break;
				case 6:
					SetCursorPosition(17, 24);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(18, 26);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "���ѹ���";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "�鿴����";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "Ⱥ�����";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "���ѹ���";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����Q Q";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "Ⱥ�����";
					++key;
					break;
				case 4:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����΢��";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Q Q";
					++key;
					break;
				case 5:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����΢��";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int FriendSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "��Ӻ���";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "ɾ������";
	SetCursorPosition(17, 20);
	cout << "��������";
	SetCursorPosition(17, 22);
	cout << "�Ƽ�����";
	SetCursorPosition(18, 24);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "��Ӻ���";
					SetCursorPosition(17, 18);//����ѡ����ȡ������ɫ
					SetColor(3);
					cout << "ɾ������";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "ɾ������";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "��������";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "��������";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "�Ƽ�����";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "�Ƽ�����";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "ɾ������";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "��Ӻ���";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "��������";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "ɾ������";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�Ƽ�����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "��������";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "�Ƽ�����";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int QQGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "����Ⱥ";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "�˳�Ⱥ";
	SetCursorPosition(17, 20);
	cout << "����Ⱥ";
	SetCursorPosition(17, 22);
	cout << "����Ⱥ";
	SetCursorPosition(18, 24);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "�˳�Ⱥ";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "����Ⱥ";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "����Ⱥ";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "�˳�Ⱥ";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int WeiboGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "����Ⱥ";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "�˳�Ⱥ";
	SetCursorPosition(17, 20);
	cout << "����Ⱥ";
	SetCursorPosition(17, 22);
	cout << "����Ⱥ";
	SetCursorPosition(18, 24);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "�˳�Ⱥ";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(17, 20);
					SetColor(3);
					cout << "����Ⱥ";
					--key;
					break;
				case 4:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 22);
					SetColor(3);
					cout << "����Ⱥ";
					--key;
					break;
				case 5:
					SetCursorPosition(17, 22);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(18, 24);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				case 2:
					SetCursorPosition(17, 20);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "�˳�Ⱥ";
					++key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				case 4:
					SetCursorPosition(18, 18);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int WeChatGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "����Ⱥ";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "�˳�Ⱥ";
	SetCursorPosition(18, 20);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "����Ⱥ";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "�˳�Ⱥ";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(18, 20);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "�˳�Ⱥ";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ";
					++key;
					break;
				case 2:
					SetCursorPosition(18, 20);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "�˳�Ⱥ";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}

int ManageGroupSelect()
{
	system("cls");
	SetCursorPosition(16, 8);
	cout << "��ѡ�����!";
	SetCursorPosition(13, 10);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	SetCursorPosition(17, 16);
	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "����Ⱥ�ڳ�Ա";
	SetCursorPosition(17, 18);
	SetColor(3);
	cout << "��ѯ��Ա����";
	SetCursorPosition(18, 20);
	cout << "����";
	SetCursorPosition(0, 30);
	int ch;//��¼����ֵ
	int key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 16);//����ѡ�������ñ���ɫ
					SetBackColor();
					cout << "����Ⱥ�ڳ�Ա";
					SetCursorPosition(17, 18);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					cout << "��ѯ��Ա����";
					--key;
					break;
				case 3:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "��ѯ��Ա����";
					SetCursorPosition(18, 20);
					SetColor(3);
					cout << "����";
					--key;
					break;
				}
			}
			break;
		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 18);
					SetBackColor();
					cout << "��ѯ��Ա����";
					SetCursorPosition(17, 16);
					SetColor(3);
					cout << "����Ⱥ�ڳ�Ա";
					++key;
					break;
				case 2:
					SetCursorPosition(18, 20);
					SetBackColor();
					cout << "����";
					SetCursorPosition(17, 18);
					SetColor(3);
					cout << "��ѯ��Ա����";
					++key;
					break;
				}
			}
			break;
		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��
		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}
	return key;
}