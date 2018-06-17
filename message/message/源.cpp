#include "UserSPG.h"
#include "MyFunctionSPG.h"

vector<UserSPG*> user_list;
vector<FriendsSPG*> all_friends_list;
vector<GroupSPG*> all_groups_list;
int login_method;

int main()
{
	/*	FriendsSPG *p = new FriendsSPG;
	for (int i = 0; i < 1; ++i)
	{
	cout << "qqid" << endl;
	cin >> p->friend_weibo_qq_id_;
	cout << "weiixnid" << endl;
	cin >> p->friend_wechat_id_;
	cout << "昵称" << endl;
	cin >> p->friend_nickname_;
	cout << "所在地" << endl;
	cin >> p->friend_location_;
	cout << "shengti" << endl;
	cin >> p->friend_birthday_[0] >> p->friend_birthday_[1] >> p->friend_birthday_[2];
	struct tm t;//tm结构指针
	time_t nowT;//声明time_t类型变量
	time(&nowT);//获取系统日期和时间
	localtime_s(&t, &nowT);//获取当地日期和时间
	asctime_s(p->friend_age_, &t);
	all_friends_list.push_back(p);
	}
	fstream fp1("friends.txt", ios::in | ios::out);
	vector<FriendsSPG*>::iterator it1 = all_friends_list.begin();
	for (; it1 != all_friends_list.end(); ++it1)
	fp1.write((char*)*it1, sizeof(*it1));
	fp1.close();*/

	/*	GroupSPG *p = new GroupSPG;
	GroupMemberSPG *q = new GroupMemberSPG;
	for (int i = 0; i < 1; ++i)
	{
	cout << "id" << endl;
	cin >> p->group_id_;
	cout << "群名" << endl;
	cin >> p->group_name_;
	for (int j = 0; j < 2; j++)
	{
	cin >> q->group_member_nickname_;
	p->group_member_list_.push_back(q);
	}
	all_groups_list.push_back(p);
	}
	fstream fp1("groups.txt", ios::in | ios::out);
	vector<GroupSPG*>::iterator it1 = all_groups_list.begin();
	for (; it1 != all_groups_list.end(); ++it1)
	fp1.write((char*)*it1, sizeof(*it1));
	fp1.close();*/

	int select;
	UserSPG *p_now_user = new UserSPG;
	GroupSPG *p_now_group = new GroupSPG;
	Action();
menu1:
	select = MainSelect();
	if (select == 1)
	{
		system("cls");
		SetCursorPosition(0, 0);
		UserSPG *p_new_user = new UserSPG;
		p_new_user->Create();
		user_list.push_back(p_new_user);
		goto menu1;
	}
	else if (select == 2)
	{
		p_now_user = Login();
		if (login_method == 2)
			goto menu6;
		if (login_method == 3)
			goto menu5;
	menu4:
		if (p_now_user->qq->nickname_ == "")
			p_now_user->qq->Create();
		select = QQSelect();
		switch (select)
		{
		case 1:
			system("cls");
			cout << "QQ账号：" << p_now_user->ReturnWeiboQqId() << endl;
			p_now_user->qq->TellInf();
			goto menu4;
		case 2:
			select = FriendSelect();
			switch (select)
			{
			case 1:
				p_now_user->qq->AddFriend();
				break;
			case 2:
				p_now_user->qq->DeleteFriend();
				break;
			case 3:
				p_now_user->qq->TellFriendsInf();
				break;
			case 4:
				p_now_user->qq->RecommendFriend();
				break;
			case 5:
				goto menu4;
			}
			break;
		case 3:
		menu5:
			select = QQGroupSelect();
			switch (select)
			{
			case 1:
				p_now_user->qq->JoinGroup();
				break;
			case 2:
				p_now_user->qq->QuitGroup();
				break;
			case 3:
				p_now_user->qq->CreateGroup();
				break;
			case 4:
				p_now_group = p_now_user->qq->ManageGroup();
				if (p_now_group != 0)
				{
					select = ManageGroupSelect();
					switch (select)
					{
					case 1:
						p_now_group->KickOut();
						break;
					case 2:
						p_now_group->TellMember();
						break;
					case 3:
						goto menu5;
					}
				}
				break;
			case 5:
				goto menu4;
			}
			break;
		case 4:
		menu2:
			select = WeiboSelect();
			switch (select)
			{
			case 1:
				system("cls");
				cout << "微博账号：" << p_now_user->ReturnWeiboQqId() << endl;
				p_now_user->weibo->TellInf();
				goto menu2;
			case 2:
				select = FriendSelect();
				switch (select)
				{
				case 1:
					p_now_user->weibo->AddFriend();
					break;
				case 2:
					p_now_user->weibo->DeleteFriend();
					break;
				case 3:
					p_now_user->weibo->TellFriendsInf();
					break;
				case 4:
					p_now_user->weibo->RecommendFriend();
				case 5:
					goto menu2;
				}
				break;
			case 3:
			menu6:
				if (p_now_user->weibo->nickname_ == "")
					p_now_user->weibo->Create();
				select = WeiboGroupSelect();
				switch (select)
				{
				case 1:
					p_now_user->weibo->JoinGroup();
					break;
				case 2:
					p_now_user->weibo->QuitGroup();
					break;
				case 3:
					p_now_user->weibo->CreateGroup();
					break;
				case 4:
					p_now_group = p_now_user->weibo->ManageGroup();
					if (p_now_group != 0)
					{
						select = ManageGroupSelect();
						switch (select)
						{
						case 1:
							p_now_group->KickOut();
							break;
						case 2:
							p_now_group->TellMember();
							break;
						case 3:
							goto menu6;
						}
					}
				case 5:
					goto menu2;
				}
				break;
			case 4:
				goto menu4;
			case 5:
				goto menu3;
			case 6:
				goto menu1;
			}
		case 5:
		menu3:
			if (p_now_user->wechat->nickname_ == "")
			{
				p_now_user->wechat->Create();
				p_now_user->SetWeChatId();
			}
			select = WeChatSelect();
			switch (select)
			{
			case 1:
				system("cls");
				cout << "微信账号：" << p_now_user->ReturnWeChatId() << endl;
				p_now_user->wechat->TellInf();
				goto menu3;
			case 2:
				select = FriendSelect();
				switch (select)
				{
				case 1:
					p_now_user->wechat->AddFriend();
					break;
				case 2:
					p_now_user->wechat->DeleteFriend();
					break;
				case 3:
					p_now_user->wechat->TellFriendsInf();
					break;
				case 4:
					p_now_user->wechat->RecommendFriend();
					break;
				case 5:
					goto menu3;
				}
				break;
			case 3:
				select = WeChatGroupSelect();
				switch (select)
				{
				case 1:
					p_now_user->wechat->RecommendGroup();
					break;
				case 2:
					p_now_user->wechat->QuitGroup();
				case 3:
					goto menu3;
				}
				break;
			case 4:
				goto menu4;
			case 5:
				goto menu2;
			case 6:
				goto menu1;
			}
		case 6:
			goto menu1;
		}
	}
	SaveVector();
	return 0;
}