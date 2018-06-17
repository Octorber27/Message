#pragma once
#include "BasicInfSPG.h"

extern vector<FriendsSPG*> all_friends_list;
extern vector<GroupSPG*> all_groups_list;
class QQSPG : public BasicInfSPG
{
public:
	void AddFriend();
	void DeleteFriend();
	void TellFriendsInf();
	void RecommendFriend();
	void JoinGroup();
	void CreateGroup();
};