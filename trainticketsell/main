#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"train.h"
using namespace std;
void xianshi(struct Train);
void xianshilist(List);
int caidan();
void cin1(char[]);
int dingpiao(List&);
int ding1(List&,char[],int);
int find4(List);
int find1(List,char[]);
int find2(List,char[]);
int find3(List,char[]);
int shuru(struct Train&,List&);
int tuipiao(struct Train&);
int tuipiao1(List&);
int main()
{
    caidan();
    return 0;
}
int caidan(){
    List huoche;
    huoche.size=0;
    int i=1;
    while (i=1){
    int a;//控制跳出端
    cout<<"请选择你需要的功能"<<endl;
    cout<<"1.输入列车的班次信息"<<endl;
    cout<<"2.查询列车的基本信息"<<endl;
    cout<<"3.订票"<<endl;
    cout<<"4.退票"<<endl;
    cout<<"5.显示所有火车信息"<<endl;
    cout<<"6.退出系统"<<endl;
    cin>>a;
    fflush(stdin);
    switch(a){
    case 1:
        struct Train Train1;
        shuru(Train1,huoche);
        break;
    case 2:
        find4(huoche);
        break;
    case 3:
        dingpiao(huoche);
        break;
    case 4:
        tuipiao1(huoche);
        break;
    case 5:
        xianshilist(huoche);
        break;
    case 6:
        i=0;
        return 0;
        break;
    default:
        cout<<"输入错误，请重新输入："<<endl;
        i=caidan();
        break;
    }
    if (i==0) return i;
    }
}
int shuru(struct Train &t1,List &q){
    cout<<"请输入列车的班次信息:班次号，起点，终点，开车时间,余票量，用回车分割"<<endl;
    int e;
    cin1(t1.number);
    fflush(stdin);
    cin1(t1.starting);
    fflush(stdin);
    cin1(t1.terminal);
    fflush(stdin);
    cin1(t1.departure_time);
    fflush(stdin);
    cin>>e;
    fflush(stdin);
    cout<<endl;
    t1.rest=e;
    LNode *start=t1.tickets=new LNode;
    t1.kaishi=start;
    start->data=1;
    for(int i=1;i<e;i++){
        LNode *current=new LNode;
        current->data=i+1;
        start->next=current;
        start=start->next;
    }
    start->next=NULL;
    cout<<"输入成功"<<endl;
    q.list[q.size]=t1;
    q.size++;
    return 1;
}
void cin1(char a[]){
    char b;
    int size=0;
    b=cin.get();
    while(b!='\n'){
            a[size]=b;
            size++;
            b=cin.get();
            cin.clear();
    }
    cout<<endl;
}
void xianshi(struct Train c){
	cout<<"班次号：  "<<c.number<<"起点站：  "<<c.starting<<"终点站:  "<<c.terminal<<"开车时间：  "<<c.departure_time<<"余票量：  "<<c.rest<<endl;
	cout<<"已售车票号："<<"  ";
	while(c.kaishi!=c.tickets){
        cout<<"  "<<c.kaishi->data<<"   ";
        c.kaishi=c.kaishi->next;
	}
	cout<<endl;
	cout<<"可售车票号:"<<"  ";
	while(c.tickets!= NULL){
        cout<<"  "<<c.tickets->data<<"   ";
        c.tickets=c.tickets->next;
	}
	cout<<endl;
}
void xianshilist(List q){
    cout<<"目前所有火车如下："<<endl;
    for(int i=0;i<q.size;i++){
        xianshi(q.list[i]);
        cout<<endl;
    }
}
int dingpiao(List &q){
    int i=1;//控制端
    char a[20];
    int e;
    do{
       cout<<"请输入你需要定的班次号"<<endl;
       cout<<"输入000返回上一级"<<endl;
       cin>>a;
       cout<<endl;
       if (!strcmp(a,"000")) return 1;//如果输入退出就退出上一级
       cout<<"请输入你定的票数"<<endl;
       cin>>e;
       i=ding1(q,a,e);
    if (i==0)
    cout<<"订票完毕！"<<endl;
    else
    	cout<<"重新输入订票"<<endl;
    }while(i!=0);
    return 1;
}
int ding1(List &q,char number[],int e){   //根据车次号查询
     for(int i=0;i<q.size;i++){
		if  (!strcmp(number,q.list[i].number))
        {
            if(e>q.list[i].rest) {
               cout<<"余票不足"<<endl;
               return 1;
            }
            q.list[i].rest-=e;
            LNode* current=q.list[i].tickets;
            for (int i=0;i<e;i++){
                current=current->next;
            }
            q.list[i].tickets=current;
            cout<<"订票成功"<<endl;
            xianshi(q.list[i]);
			return 0;
		}
    }
	cout<<"找不到对应的列车"<<endl;
    return 1;
}
int find4(List q){
    int i=1;
	int a;
	char number[50];
	do{
	cout<<"------请输入你要查询的方式------"<<endl;
	cout<<"1.车次号"<<endl;
	cout<<"2.起始站"<<endl;
	cout<<"3.终点站"<<endl;
	cout<<"4.退出"<<endl;
    cin>>a;
    if (a==4) return 999;//如果输入退出就退出上一级
    cout<<"请输入你查询的资料"<<endl;
    cin>>number;
    switch (a){
    	case 1:
    	i=find1(q,number);
    	break;
    	case 2:
    	i=find2(q,number);
    	break;
    	case 3:
    	i=find3(q,number);
    	break;
    	default:
    	   cout<<"查询方式有误"<<endl;
           i=1;
    }
    if (i==0)
    cout<<"查询完毕！"<<endl;
    else
    	cout<<"重新输入查询"<<endl;
    }while(i!=0);
    return 1;
}
int find1(List q,char number[]){   //根据车次号查询
    for(int i=0;i<q.size;i++){
		if  (!strcmp(number,q.list[i].number))
        {
			xianshi(q.list[i]);
			return 0;
		}
    }
	cout<<"找不到对应的列车"<<endl;
    return 1;
}
int find2(List q,char number[]){    //根据起始站查询
    for(int i=0;i<q.size;i++){
		if  (!strcmp(number,q.list[i].starting))
        {
			xianshi(q.list[i]);
			return 0;
		}
    }
	cout<<"找不到对应的列车"<<endl;
	return 1;
}
int find3(List q,char number[]){ //根据终点站查询
    for(int i=0;i<q.size;i++){
		if  (!strcmp(number,q.list[i].terminal))
        {
			xianshi(q.list[i]);
			return 0;
		}
    }
    cout<<"找不到对应的列车"<<endl;
    return 1;
}
int tuipiao1(List &q){
    int i=1;//控制端
    char a[20];
    int e;
    do{
       cout<<"请输入你需要退的班次号"<<endl;
       cout<<"输入000返回上一级"<<endl;
       cin>>a;
       cout<<endl;
       if (!strcmp(a,"000")) return 1;//如果输入退出就退出上一级
       for (int b=0;b<q.size;b++){
            if (!strcmp(a,q.list[b].number))
                i=tuipiao(q.list[b]);
       }
       if (i==0)
          cout<<"退票完毕！"<<endl;
       else
         cout<<"重新输入退票"<<endl;
    }while(i!=0);
    return 1;
}
int tuipiao(struct Train &c){
    cout<<"请输入你退票的票号"<<endl;
    int e;
    cin>>e;
    LNode* current=c.kaishi;
    LNode* newptr=new LNode;
    while(current!=c.tickets){
        if (e==current->next->data)
        {
            newptr->data=e;
            newptr->next=c.tickets;
            if(current->next->next==c.tickets){
            c.tickets=newptr;
            current->next=c.tickets;
            }
            else{
                current->next=current->next->next;
                while(current->next!=c.tickets){
                    current=current->next;
                }
                current->next=newptr;
                c.tickets=newptr;
            }
            break;
        }
        current=current->next;
    }
    if (current==c.tickets){
        cout<<"找不到已售的车票号"<<endl;
        return 1;
    }
    else {
         cout<<"退票成功"<<endl;
         c.rest++;
         return 0;
    }
}
