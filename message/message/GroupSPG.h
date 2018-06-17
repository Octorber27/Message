#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "GroupMemberSPG.h"
using namespace std;

class GroupSPG
{
public:
	void KickOut();
	void TellMember();
	friend class BasicInfSPG;
	friend class QQSPG;
	friend class WeiboSPG;
	friend class WeChatSPG;
	protected:
	string group_name_;
	int group_id_;
	vector<GroupMemberSPG*> group_member_list_;
	bool is_qq_member_ = 0, is_weibo_member_ = 0, is_wechat_member_ = 0, is_owner_ = 0;
};