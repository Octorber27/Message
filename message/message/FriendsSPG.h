#pragma once
#include <string>
#include <iostream>
using namespace std;

class FriendsSPG
{
public:
	void TellMyInf();
	friend class QQSPG;
	friend class WeiboSPG;
	friend class WeChatSPG;
	//protected:
	int friend_weibo_qq_id_;//΢����QQID
	string friend_wechat_id_;//΢��ID
	string friend_nickname_, friend_location_;//�ǳơ����ڵ�
	int friend_birthday_[3];//΢����QQ��΢������
	char friend_age_[64];//���Ѻ�������ʱ��
	bool is_weibo_friend_ = 0, is_qq_friend_ = 0, is_wechat_friend_ = 0;//�Ƿ�Ϊ΢����QQ��΢�ź���
};