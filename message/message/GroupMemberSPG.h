#pragma once
#include <string>
using namespace std;

class GroupMemberSPG
{
public:
	friend class GroupSPG;
	friend class QQSPG;
	friend class WeiboSPG;
	//protected:
	string group_member_nickname_;
};