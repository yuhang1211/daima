//随机生成30道四则运算（包括真分数）
//孔宇航 2016/3/4

#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
using namespace std;
#define random() (rand()%100)
void main()
{
	   int num1,num2,num3,num4;
	   srand((int)time(NULL));
       for(int i=0;i<30;i++)
	  {
		 num1=random();
		 num2=random();
		int k=(int)rand()%5;
		switch(k)
		{
		case 0:{cout<<num1<<"+"<<num2<<"="; 
		break;}                                 //进行整数加法运算
		case 1:{cout<<num1<<"-"<<num2<<"=";
		break;}                                //进行整数减法运算
		case 2:{cout<<num1<<"*"<<num2<<"=";
		break;}                                //进行整数乘法运算
		case 3:{
		while(num2==0)
		num2=random();
		cout<<num1<<"/"<<num2<<"=";
		break;}                                //进行整数除法运算
		case 4:                                //真分数运算部分
	    {
          while(num2==0||num1>=num2)
         {
            num1=random();
		    num2=random();
         }
            num3=random();
		    num4=random();
        while(num4==0||num3>=num4)
        {
            num3=random();
		    num4=random();
        }
	   int q=(int)rand()%4;
        switch(q)
        {
            case 0:
                cout<<"("<<num1<<"/"<<num2<<")"<<"+"<<"("<<num3<<"/"<<num4<<")"<<"=";
               
                break;
            case 1: 
				cout<<"("<<num1<<"/"<<num2<<")"<<"-"<<"("<<num3<<"/"<<num4<<")"<<"=";
              
                break;
            case 2:
                 cout<<"("<<num1<<"/"<<num2<<")"<<"*"<<"("<<num3<<"/"<<num4<<")"<<"=";
               
                break;
            case 3:
                cout<<"("<<num1<<"/"<<num2<<")"<<"/"<<"("<<num3<<"/"<<num4<<")"<<"=";
                break;
		   } 
		  }
        }
		cout<<endl;
	  }
}