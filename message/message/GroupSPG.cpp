#include "GroupSPG.h"

void GroupSPG::KickOut()
{
	if (is_owner_ == 1)
	{
		int number, i = 0;
		vector<GroupMemberSPG*>::iterator it = group_member_list_.begin();
		cout << "Ⱥ��Ա���£�" << endl;
		for (; it != group_member_list_.end(); ++it, ++i)
		{
			cout << i << '.' << (*it)->group_member_nickname_ << endl;
		}
		cout << "������Ҫɾ��Ⱥ��Ա����ţ�" << endl;
		cin >> number;
		if (number > i)
			cout << "�����ڸó�Ա��" << endl;
		else
		{
			group_member_list_.erase(group_member_list_.begin() + number);
			cout << "ɾ��Ⱥ��Ա�ɹ���" << endl;
		}
	}
	else
		cout << "������Ⱥ����û��Ȩ�ޣ�" << endl;
}

void GroupSPG::TellMember()
{
	vector<GroupMemberSPG*>::iterator it = group_member_list_.begin();
	cout << "Ⱥ��Ա���£�" << endl;
	for (int i = 0; it != group_member_list_.end(); ++it, ++i)
		cout << i << '.' << (*it)->group_member_nickname_ << endl;
}