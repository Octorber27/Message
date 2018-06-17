#include "WeChatSPG.h"



void WeChatSPG::AddFriend()
{
	string search_id;
	bool flag = false;
	cout << "������Ҫ��ӵ�΢��ID��" << endl;
	cin >> search_id;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->friend_wechat_id_ == search_id)
		{
			friends_list_.push_back(*it);
			flag = true;
			(*it)->is_wechat_friend_ = 1;
			cout << "��ӳɹ���" << endl;
		}
	}
	if (flag == false)
		cout << "û�и��û���" << endl;
}

void WeChatSPG::DeleteFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "�������º��ѣ�" << endl;
	for (; it != friends_list_.end(); ++it)
	{
		if ((*it)->friend_wechat_id_ != "0")
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
			(*it)->is_wechat_friend_ = 0;
			cout << "ɾ���ɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κκ��ѣ�" << endl;
	}
}

void WeChatSPG::TellFriendsInf()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "�������º��ѣ�" << endl;
	for (; it != friends_list_.end(); ++it)
	{
		if ((*it)->friend_wechat_id_ != "0")
		{
			cout << i << '.' << (*it)->friend_nickname_ << endl
				<< '(' << (*it)->friend_wechat_id_ << ')' << endl;
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
			cout << "ID��" << friends_list_[number]->friend_wechat_id_ << endl;
			friends_list_[number]->TellMyInf();
		}
	}
	else
	{
		cout << "��û���κκ��ѣ�" << endl;
	}
}

void WeChatSPG::RecommendFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	cout << "�Ƽ����ѣ�" << endl;
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->is_wechat_friend_ == 0 && ((*it)->is_qq_friend_ == 1
			|| (*it)->is_weibo_friend_ == 1))
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
				if ((*it)->is_wechat_friend_ == 0 && ((*it)->is_qq_friend_ == 1
					|| (*it)->is_weibo_friend_ == 1))
					++i;
			}
			friends_list_.push_back(*it - 1);
			(*it - 1)->is_wechat_friend_ = 1;
			cout << "��ӳɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κ��Ƽ����ѣ�" << endl;
	}
}

void WeChatSPG::RecommendGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = all_groups_list.begin();
	cout << "���ĺ����Ƽ�����������Ⱥ��" << endl;
	for (; it != all_groups_list.end(); ++it)
	{
		if ((*it)->is_wechat_member_ == 0)
		{
			cout << i << '.' << (*it)->group_name_ << endl;
			++i;
			flag = true;
		}
		++all;
	}
	if (flag = true)
	{
		cout << "������Ҫ���Ⱥ����ţ�" << endl;
		cin >> number;
		if (number > all)
			cout << "�����ڸ��Ƽ�Ⱥ��" << endl;
		else
		{
			for (it = all_groups_list.begin(), i = 0; it != all_groups_list.end() && i <= number; ++it)
			{
				if ((*it)->is_wechat_member_ == 0)
					++i;
			}
			group_list_.push_back(*it - 1);
			(*it - 1)->is_wechat_member_ = 1;
			cout << "��Ⱥ�ɹ���" << endl;
		}
	}
	else
	{
		cout << "��û���κ��Ƽ�Ⱥ��" << endl;
	}

}