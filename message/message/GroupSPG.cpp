#include "GroupSPG.h"

void GroupSPG::KickOut()
{
	if (is_owner_ == 1)
	{
		int number, i = 0;
		vector<GroupMemberSPG*>::iterator it = group_member_list_.begin();
		cout << "群成员如下：" << endl;
		for (; it != group_member_list_.end(); ++it, ++i)
		{
			cout << i << '.' << (*it)->group_member_nickname_ << endl;
		}
		cout << "请输入要删除群成员的序号：" << endl;
		cin >> number;
		if (number > i)
			cout << "不存在该成员！" << endl;
		else
		{
			group_member_list_.erase(group_member_list_.begin() + number);
			cout << "删除群成员成功！" << endl;
		}
	}
	else
		cout << "您不是群主，没有权限！" << endl;
}

void GroupSPG::TellMember()
{
	vector<GroupMemberSPG*>::iterator it = group_member_list_.begin();
	cout << "群成员如下：" << endl;
	for (int i = 0; it != group_member_list_.end(); ++it, ++i)
		cout << i << '.' << (*it)->group_member_nickname_ << endl;
}