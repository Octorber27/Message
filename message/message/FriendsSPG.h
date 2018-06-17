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
	int friend_weibo_qq_id_;//微博和QQID
	string friend_wechat_id_;//微信ID
	string friend_nickname_, friend_location_;//昵称、所在地
	int friend_birthday_[3];//微博、QQ和微信生日
	char friend_age_[64];//好友号码申请时间
	bool is_weibo_friend_ = 0, is_qq_friend_ = 0, is_wechat_friend_ = 0;//是否为微博、QQ、微信好友
};