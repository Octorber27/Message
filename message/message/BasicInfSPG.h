#pragma once
#include <conio.h>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "FriendsSPG.h"
#include "GroupSPG.h"
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;


class BasicInfSPG
{
public:
	void Create();//创建账号函数
	void TellInf();//查询自己信息
	virtual void AddFriend() = 0;//添加好友
	virtual void DeleteFriend() = 0;//删除好友
	virtual void TellFriendsInf() = 0;//查询好友信息
	virtual void RecommendFriend() = 0;//推荐好友
	void QuitGroup();//退群
	GroupSPG* ManageGroup();//选择管理群
	string nickname_;
	friend class WeiboSPG;
	friend class QQSPG;
	friend class WeChatSPG;
	friend class UserSPG;
protected:
	string location_, password_;//所在地、密码
	int birthday_[3];//出生时间
	char age_[64];//号码申请时间
	vector<FriendsSPG*> friends_list_;//好友列表
	vector<GroupSPG*> group_list_;//群列表
};
