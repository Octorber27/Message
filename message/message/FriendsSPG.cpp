#include "FriendsSPG.h"

void FriendsSPG::TellMyInf()
{
	//外部给出ID
	cout << "昵称：" << friend_nickname_ << endl << "生日：" << friend_birthday_[0] << "年"
		<< friend_birthday_[1] << "月" << friend_birthday_[2] << "日" << endl << "所在地："
		<< friend_location_ << endl << "号码申请时间" << friend_age_[64] << endl;
}