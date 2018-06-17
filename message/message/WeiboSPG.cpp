#include "WeiboSPG.h"


void WeiboSPG::AddFriend()
{
	int search_id;
	bool flag = false;
	cout << "请输入要添加的微博ID：" << endl;
	cin >> search_id;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	for (; it != all_friends_list.end(); ++it)
	{
		if ((*it)->friend_weibo_qq_id_ == search_id)
		{
			friends_list_.push_back(*it);
			flag = true;
			(*it)->is_weibo_friend_ = 1;
			cout << "添加成功！" << endl;
		}
	}
	if (flag == false)
		cout << "没有该用户！" << endl;
}

void WeiboSPG::DeleteFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "您有以下好友：" << endl;
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
		cout << "请输入要删除好友的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该好友！" << endl;
		else
		{
			friends_list_.erase(friends_list_.begin() + number);
			(*it)->is_weibo_friend_ = 0;
			cout << "删除成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何好友！" << endl;
	}
}

void WeiboSPG::TellFriendsInf()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	cout << "您有以下好友：" << endl;
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
		cout << "请输入查询信息的好友序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该好友！" << endl;
		else
		{
			cout << "ID：" << friends_list_[number]->friend_weibo_qq_id_ << endl;
			friends_list_[number]->TellMyInf();
		}
	}
	else
	{
		cout << "您没有任何好友！" << endl;
	}
}

void WeiboSPG::RecommendFriend()
{
	int i = 0, number, all = 0;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = all_friends_list.begin();
	cout << "推荐好友：" << endl;
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
		cout << "请输入要添加好友的序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该推荐好友！" << endl;
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
			cout << "添加成功！" << endl;
		}
	}
	else
	{
		cout << "您没有任何推荐好友！" << endl;
	}
}

void WeiboSPG::JoinGroup()
{
	int group_id;
	bool flag = false;
	cout << "请输入要申请加入的群号：" << endl;
	cin >> group_id;
	vector<GroupSPG*>::iterator it = all_groups_list.begin();
	for (; it != all_groups_list.end(); ++it)
	{
		if (group_id == (*it)->group_id_ && (*it)->is_weibo_member_ == 0)
		{
			flag = true;
			group_list_.push_back(*it);
			(*it)->is_weibo_member_ = 1;
			cout << "加群成功" << endl;
		}
	}
	if (flag == false)
	{
		cout << "您已在该群或没有该群！" << endl;
	}
}

void WeiboSPG::CreateGroup()
{
	GroupSPG *p = new GroupSPG;
	GroupMemberSPG *q = new GroupMemberSPG;
	vector<int> friends;
	cout << "请输入群名：" << endl;
	cin >> p->group_name_;
	int i = 0, number, all = 0, judge;
	bool flag = false;
	vector<FriendsSPG*>::iterator it = friends_list_.begin();
	p->is_owner_ = 1;
	srand((unsigned)time(NULL));
	p->group_id_ = random(2000, 9999);
	cout << "您有以下好友：" << endl;
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
		cout << "请输入要邀请的好友序号：" << endl;
		cin >> number;
		if (number > all)
			cout << "不存在该好友！" << endl;
		else
		{
			friends.push_back(number);
			vector<int>::iterator it1 = friends.begin();
			for (; it1 != friends.end(); ++it1)
			{
				if (*it1 == number)
				{
					cout << "您已邀请该好友！请重新输入！" << endl;
					goto goon;
				}
			}
			q->group_member_nickname_ = friends_list_[number]->friend_nickname_;
			p->group_member_list_.push_back(q);
			cout << "邀请该好友成功！是否继续邀请？（1是/0否）" << endl;
			cin >> judge;
			if (judge == 1)
				goto goon;
		}
	}
	else
	{
		cout << "您没有任何好友！" << endl;
	}

}