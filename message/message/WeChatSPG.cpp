#include "WeChatSPG.h"



void WeChatSPG::AddFriend()
{
	string search_id;
	bool flag = false;
	cout << "请输入要添加的微博ID：" << endl;
	cin >> search_id;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->friend_wechat_id_ == search_id)
		{
			friends_list_.push_back(*it);
			flag = true;
			(*it)->is_wechat_friend_ = 1;
			cout << "添加成功！" << endl;
		}
	}
	if (flag == false)
		cout << "没有该用户！" << endl;
}

void WeChatSPG::DeleteFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "您有以下好友：" << endl;
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
		cout << "请输入要删除好友的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该好友！" << endl;
		else
		{
			friends_list_.erase(friends_list_.begin() + number);
			(*it)->is_wechat_friend_ = 0;
			cout << "删除成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何好友！" << endl;
	}
}

void WeChatSPG::TellFriendsInf()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "您有以下好友：" << endl;
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
		cout << "请输入查询信息的好友序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该好友！" << endl;
		else
		{
			cout << "ID：" << friends_list_[number]->friend_wechat_id_ << endl;
			friends_list_[number]->TellMyInf();
		}
	}
	else
	{
		cout << "您没有任何好友！" << endl;
	}
}

void WeChatSPG::RecommendFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	cout << "推荐好友：" << endl;
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
		cout << "请输入要添加好友的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该推荐好友！" << endl;
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
			cout << "添加成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何推荐好友！" << endl;
	}
}

void WeChatSPG::RecommendGroup()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<GroupSPG*>::iterator it = all_groups_list.begin();
	cout << "您的好友推荐您加入以下群：" << endl;
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
		cout << "请输入要添加群的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该推荐群！" << endl;
		else
		{
			for (it = all_groups_list.begin(), i = 0; it != all_groups_list.end() && i <= number; ++it)
			{
				if ((*it)->is_wechat_member_ == 0)
					++i;
			}
			group_list_.push_back(*it - 1);
			(*it - 1)->is_wechat_member_ = 1;
			cout << "加群成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何推荐群！" << endl;
	}

}