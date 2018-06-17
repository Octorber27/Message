#pragma once
#include "QQSPG.h"
#include "WeiboSPG.h"
#include "WeChatSPG.h"

class UserSPG
{
public:
	void Create();
	int ReturnWeiboQqId();
	string ReturnWeChatId();
	string ReturnPassword();
	void SetWeChatId();
	QQSPG *qq = new QQSPG;
	WeiboSPG *weibo = new WeiboSPG;
	WeChatSPG *wechat = new WeChatSPG;
protected:
	int weibo_qq_id_;//Œ¢≤©∫ÕQQ’À∫≈
	string wechat_id_;//Œ¢–≈’À∫≈
	string password_;//√‹¬Î
};