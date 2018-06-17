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
	void Create();//�����˺ź���
	void TellInf();//��ѯ�Լ���Ϣ
	virtual void AddFriend() = 0;//��Ӻ���
	virtual void DeleteFriend() = 0;//ɾ������
	virtual void TellFriendsInf() = 0;//��ѯ������Ϣ
	virtual void RecommendFriend() = 0;//�Ƽ�����
	void QuitGroup();//��Ⱥ
	GroupSPG* ManageGroup();//ѡ�����Ⱥ
	string nickname_;
	friend class WeiboSPG;
	friend class QQSPG;
	friend class WeChatSPG;
	friend class UserSPG;
protected:
	string location_, password_;//���ڵء�����
	int birthday_[3];//����ʱ��
	char age_[64];//��������ʱ��
	vector<FriendsSPG*> friends_list_;//�����б�
	vector<GroupSPG*> group_list_;//Ⱥ�б�
};
