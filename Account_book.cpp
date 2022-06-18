#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <string>
using namespace std;

#define VERSION 20220618


struct account
{
    string name;
    double money;
    struct account* next;
};

struct account* login_account(struct account* account)
{
    struct account* account_ori = account;
    string cmd;
    string name;

    while(1)
    {
        cout<<"請輸入登入名稱"<<endl;
        cin>>name;
        while(account!=NULL)
        {
            if(account->name==name)
            {
                return account;
            }
            else
            {
                account=account->next;
            }
        }
        cout<<"帳號不存在，請選擇指令:"<<endl;
        cout<<"y:重新輸入名稱"<<endl;
        cout<<"q:回到主畫面"<<endl;
        cin>>cmd;
        if(cmd=="y")
        {
            continue;
        }
        else if(cmd=="q")
        {
            break;
        }
        else
        {
            cout<<"未知的指令"<<endl;
        }
        account=account_ori;
    }
    return account_ori;
}


struct account* add_account(struct account* account,string name)
{
    struct account* account_ori = account;
    struct account* account_past;
    int side = 0;

    while(account!=NULL)
    {
        account_past=account;
        account=account->next;
        side=1;

    }
    if(side==0) //新增的第一組帳號
    {
        account=(struct account*)malloc(sizeof(struct account));
        account->name=name;
        account->money=0;
        return account;
    }
    else
    {
        account=(struct account*)malloc(sizeof(struct account));
        account_past->next=account;
        account->name=name;
        account->money=0;
        return account_ori;
    }
    return account_ori;
}

int main()
{
    string cmd;
    double temp;
    struct account* account=NULL;
    while(1)
    {
        cout<<"===歡迎使用eCash"<<VERSION<<"版"<<endl;
        cout<<"請輸入指令:"<<endl;
        cout<<"a:新增帳號"<<endl;
        cout<<"l:登入帳號"<<endl;
        cin>>cmd;
        if(cmd=="a")
        {
            string name;
            cout<<"請輸入名稱"<<endl;
            cin>>name;
            account=add_account(account,name);
        }
        else if(cmd=="l")
        {
            account=login_account(account);
            if(account==NULL)
            {
                continue;
            }
            cout<<account->name<<"您好，請選擇項目，請輸入指令"<<endl;
            cout<<"s:儲值"<<endl;
            cout<<"p:消費"<<endl;
            cout<<"d:查詢餘額"<<endl;
            cout<<"q:離開"<<endl;
            cin>>cmd;
            while(cmd!="s" && cmd!="p" && cmd!="d" && cmd!="q")
            {
                cout<<"未知的指令，請重新輸入指令"<<endl;
                cin>>cmd;
            }
            if(cmd=="s")
            {
                cout<<"請輸入儲值金額"<<endl;
                cin>>temp;
                account->money+=temp;
                cout<<"eCash您存了"<<temp<<"元"<<endl;
            }
            else if(cmd=="p")
            {
                cout<<"請輸入消費金額"<<endl;
                cin>>temp;
                account->money-=temp;
                cout<<"eCash您消費了"<<temp<<"元"<<endl;
            }
            else if(cmd=="d")
            {
                cout<<"目前有"<<account->money<<"元"<<endl;
            }
            else
            {
                continue;
            }
        }
        else
        {
            cout<<"未知的指令"<<endl;
        }
    }
    return 0;
}

 