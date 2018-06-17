#include "WeiboSPG.h"


void WeiboSPG::AddFriend()
{
	int search_id;
	bool flag = false;
	cout << "������Ҫ��ӵ�΢��ID��" << endl;
	cin >> search_id;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->friend_weibo_qq_id_ == search_id)
		{
			friends_list_.push_back(*it);
			flag = true;
			(*it)->is_weibo_friend_ = 1;
			cout << "��ӳɹ���" << endl;
		}
	}
	if (flag == false)
		cout << "û�и��û���" << endl;
}

void WeiboSPG::DeleteFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "�������º��ѣ�" << endl;
	for (; it != friends_list_.end(); ++it)
	{
		if ((*it)->friend_weibo_qq_id_ != 0)
		{
			cout << i << '.' << (*it)->friend_nickname_ << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag == true)
	{
		cout << "������Ҫɾ�����ѵ���ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸú��ѣ�" << endl;
		else
		{
			friends_list_.erase(friends_list_.begin() + number);
			(*it)->is_weibo_friend_ = 0;
			cout << "ɾ���ɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κκ��ѣ�" << endl;
	}
}

void WeiboSPG::TellFriendsInf()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "�������º��ѣ�" << endl;
	for (; it != friends_list_.end(); ++it)
	{
		if ((*it)->friend_weibo_qq_id_ != 0)
		{
			cout << i << '.' << (*it)->friend_nickname_ << endl << '('
				<< (*it)->friend_weibo_qq_id_ << ')' << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag == true)
	{
		cout << "�������ѯ��Ϣ�ĺ�����ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸú��ѣ�" << endl;
		else
		{
			cout << "ID��" << friends_list_[number]->friend_weibo_qq_id_ << endl;
			friends_list_[number]->TellMyInf();
		}
	}
	else
	{
		cout << "��û���κκ��ѣ�" << endl;
	}
}

void WeiboSPG::RecommendFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	cout << "�Ƽ����ѣ�" << endl;
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->is_weibo_friend_ == 0 && ((*it)->is_qq_friend_ == 1
			|| (*it)->is_wechat_friend_ == 1))
		{
			cout << i << '.' << (*it)->friend_nickname_ << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag = true)
	{
		cout << "������Ҫ��Ӻ��ѵ���ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸ��Ƽ����ѣ�" << endl;
		else
		{
			for (it = all_friends_list.begin(), i = 0; it != all_friends_list.end() && i <= number; ++it)
			{
				if ((*it)->is_weibo_friend_ == 0 && ((*it)->is_qq_friend_ == 1
					|| (*it)->is_wechat_friend_ == 1))
					++i;
			}
			friends_list_.push_back(*it - 1);
			(*it - 1)->is_weibo_friend_ = 1;
			cout << "��ӳɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κ��Ƽ����ѣ�" << endl;
	}
}

void WeiboSPG::JoinGroup()
{
	int group_id;
	bool flag = false;
	cout << "������Ҫ��������Ⱥ�ţ�" << endl;
	cin >> group_id;
	vector<GroupSPG*>::iterator it = all_groups_list.begin();
	for (; it != all_groups_list.end(); ++it)
	{
		if (group_id == (*it)->group_id_ && (*it)->is_weibo_member_ == 0)
		{
			flag = true;
			group_list_.push_back(*it);
			(*it)->is_weibo_member_ = 1;
			cout << "��Ⱥ�ɹ�" << endl;
		}
	}
	if (flag == false)
	{
		cout << "�����ڸ�Ⱥ��û�и�Ⱥ��" << endl;
	}
}

void WeiboSPG::CreateGroup()
{
	GroupSPG *p = new GroupSPG;
	GroupMemberSPG *q = new GroupMemberSPG;
	vector<int> friends;
	cout << "������Ⱥ����" << endl;
	cin >> p->group_name_;
	int i = 0, number, all = 0, judge;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	p->is_owner_ = 1;
	srand((unsigned)time(NULL));
	p->group_id_ = random(2000, 9999);
	cout << "�������º��ѣ�" << endl;
	for (; it != friends_list_.end(); ++it)
	{
		if ((*it)->friend_weibo_qq_id_ != 0)
		{
			cout << i << '.' << (*it)->friend_nickname_ << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag == true)
	{
	goon:
		cout << "������Ҫ����ĺ�����ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸú��ѣ�" << endl;
		else
		{
			friends.push_back(number);
			vector<int>::iterator it1 = friends.begin();
			for (; it1 != friends.end(); ++it1)
			{
				if (*it1 == number)
				{
					cout << "��������ú��ѣ����������룡" << endl;
					goto goon;
				}
			}
			q->group_member_nickname_ = friends_list_[number]->friend_nickname_;
			p->group_member_list_.push_back(q);
			cout << "����ú��ѳɹ����Ƿ�������룿��1��/0��" << endl;
			cin >> judge;
			if (judge == 1)
				goto goon;
		}
	}
	else
	{
		cout << "��û���κκ��ѣ�" << endl;
	}

}