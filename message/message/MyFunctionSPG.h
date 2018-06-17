#pragma once
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "UserSPG.h"

extern vector<UserSPG*> user_list;
extern vector<FriendsSPG*> all_friends_list;
extern vector<GroupSPG*> all_groups_list;
extern int login_method;

void ReadFile();//读取文件信息
void SaveVector();//保存向量信息
UserSPG* Login();//登录函数
void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();
void Action();//开始
int MainSelect();//开始菜单
int QQSelect();//QQ功能菜单
int WeiboSelect();//微博功能菜单
int WeChatSelect();//微信功能菜单
int FriendSelect();//好友菜单
int QQGroupSelect();//QQ群功能菜单
int WeiboGroupSelect();//微博群功能菜单
int WeChatGroupSelect();//微信群功能菜单
int ManageGroupSelect();//管理群功能