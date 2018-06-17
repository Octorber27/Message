#pragma once
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "UserSPG.h"

extern vector<UserSPG*> user_list;
extern vector<FriendsSPG*> all_friends_list;
extern vector<GroupSPG*> all_groups_list;
extern int login_method;

void ReadFile();//��ȡ�ļ���Ϣ
void SaveVector();//����������Ϣ
UserSPG* Login();//��¼����
void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();
void Action();//��ʼ
int MainSelect();//��ʼ�˵�
int QQSelect();//QQ���ܲ˵�
int WeiboSelect();//΢�����ܲ˵�
int WeChatSelect();//΢�Ź��ܲ˵�
int FriendSelect();//���Ѳ˵�
int QQGroupSelect();//QQȺ���ܲ˵�
int WeiboGroupSelect();//΢��Ⱥ���ܲ˵�
int WeChatGroupSelect();//΢��Ⱥ���ܲ˵�
int ManageGroupSelect();//����Ⱥ����