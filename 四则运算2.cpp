//四则运算2
//孔宇航 2016/3/11

#include <iostream>
#include<stdlib.h>  
#include <time.h>  
using namespace std;
  
  void main()
  {
      int a0[1000],b0[1000],c0[1000],a1[1000],b1[1000],c1[1000],a2[1000],b2[1000],c2[1000],a3[1000],b3[1000],c3[1000],C[1000];
	  int a,b,c,d;
      int i,j,A0,A1,A2,A3,B0,B1,B2,B3;
      int num,line,k;
      int min,max,m;
      int CC,FS,YS,KH;

  
      k=0;
      A0=0;A1=0;A2=0;A3=0;
      B0=0;B1=0;B2=0;B3=0;
     cout<<"*************四则运算2*************"<<endl;
	 cout<<endl;
	 cout<<endl;
     
      cout<<"请输入算式数量和每行显示数量(打印方式）："<<endl;
      cin>>num>>line;
     
     cout<<"是否要有乘除法？（1/0）"<<endl;
     cin>>CC;
      while(1)                             //判断输入是否合法
     {
        if(CC != 1&&CC != 0)
        {
            cout<<"输入有误，请重新输入：";
            cin>>CC;
        }
         else
             break;
     }
     
     cout<<"加减有无负数？（1/0）"<<endl;
      cin>>FS;
     while(1)                             //判断输入是否合法
     {
        if(FS != 1&&FS != 0)
         {
            cout<<"输入有误，请重新输入：";
            cin>>FS;
          }
         else
              break;
      }
      
      cout<<"除法有无余数？（1/0）"<<endl;
      cin>>YS;
      while(1)                             //判断输入是否合法
      {
         if(YS != 1&&YS != 0)
          {
             cout<<"输入有误，请重新输入：";
             cin>>YS;
         }
          else
              break;
      }
     
	   cout<<"是否有括号？（1/0）"<<endl;
      cin>>KH;
     while(1)                             //判断输入是否合法
     {
        if(KH!= 1&&KH != 0)
         {
            cout<<"输入有误，请重新输入：";
            cin>>KH;
          }
         else
              break;
      }


      cout<<"请输入两个数数值范围min,max（min<max）"<<endl;
	  cin>>min>>max;
	 cout<<endl;
     while(1)                            //判断输入是否合法
     {
         if(min>=max)
          {
             cout<<"输入有误，请重新输入：";
              cin>>min>>max;
          }
          else
              break;
      }
  
      m=max-min+1;
      for(i=0;i<1000;i++)
      {
          a0[i]=0;b0[i]=0;
          a1[i]=0;b1[i]=0;
          a2[i]=0;b2[i]=0;
          a3[i]=0;b3[i]=0;
     }
	  srand( (unsigned)time( NULL ) );//srand()函数产生一个以当前时间开始的随机种子
      for(i=0;;i++)
      {
          a=min+rand()%m;
          b=min+rand()%m;
		  d=min+rand()%m;
          c=rand()%4;

         if(CC==0)              //如果CC=0，去除c=2,3的情况
         {
              if(c==2||c==3)
                 continue;
			  

          }
          if(FS==0)              //如果FS=0，去除c=0,1下结果小于0的情况
         {
              if(c==0)
              {
                  if(a+b<0)
                      continue;
              }
              else if(c==1)
              {
                 if(a-b<0)
                     continue;
             }
       }
        if(YS==0)             //如果YS=0，且是除法，去除a，b相除有余数的情况
         {
            if(c==3)
                 if(0 != a%b)
                    continue;
        }
    
        
		
		//将算式分为加、减、乘、除四组
         if(c==0)                       //加法
         {
             for(j=0;j<=A0;j++)
             {
                 if(a==a0[j]&&b==b0[j])
                 {
                     B0++;break;
                 }
             }
             if(B0>0)
             {
                 B0=0;continue;
             }
             else
             {
                 a0[A0]=a;
                 b0[A0]=b;
                 c0[A0]=a+b;
                 A0++;
             }
         }
         else if(c==1)                   //减法
         {
             for(j=0;j<=A1;j++)
            {
                 if(a==a1[j]&&b==b1[j])
                {
                     B1++;break;
                 }
             }
             if(B1>0)
             {
                 B1=0;continue;
             }
             else
             {
                 a1[A1]=a;
                 b1[A1]=b;
                 c1[A1]=a+b;
                 A1++;
             }
         }
         else if(c==2)                     //乘法
         {
            for(j=0;j<=A2;j++)
             {
                 if(a==a2[j]&&b==b2[j])
                 {
                    B2++;break;
                 }
             }
             if(B2>0)
             {
                 B2=0;continue;
             }
             else
             {
                 a2[A2]=a;
                b2[A2]=b;
                 c2[A2]=a+b;
                 A2++;
             }
         }
         else                               //除法
         {
             if(b==0)
                 continue;
             for(j=0;j<=A3;j++)
             {
                 if(a==a3[j]&&b==b3[j])
                 {
                     B3++;break;
                 }
             }
             if(B3>0)
             {
                 B3=0;continue;
             }
             else
             {
                 a3[A3]=a;
                 b3[A3]=b;
                 c3[A3]=a+b;
                 A3++;
             }
         }
         if(num==A0+A1+A2+A3)                //限制算式数量
             break;
     }
    
	
	 
	 //输出
	  for(i=0;i<A0;i++)                        //  加法
	 {
         k++;
         if(a0[i]<0)
             cout<<"("<<a0[i]<<")";
         else
             cout<<a0[i]<<" ";
             cout<<"+";
         if(b0[i]<0)
             cout<<"("<<b0[i]<<")";
         else
             cout<<" "<<b0[i]<<" ";
         cout<<"=";
         if(k%line==0)
             cout<<endl;
         else
             cout<<"\t";
     }
      for(i=0;i<A1;i++)                         // 减法
     {
         k++;
         if(a1[i]<0)
             cout<<"("<<a1[i]<<")";
        else
             cout<<a1[i]<<" ";
         cout<<"-";
         if(b1[i]<0)
             cout<<"("<<b1[i]<<")";
         else
             cout<<" "<<b1[i]<<" ";
         cout<<"=";
         if(k%line==0)
             cout<<endl;
         else
             cout<<"\t";
     }
     for(i=0;i<A2;i++)                         // 乘法
     {
        k++;
         if(a2[i]<0)
             cout<<"("<<a2[i]<<")";
        else
             cout<<a2[i]<<" ";
         cout<<"*";
         if(b2[i]<0)
             cout<<"("<<b2[i]<<")";
         else
             cout<<" "<<b2[i]<<" ";
         cout<<"=";
        if(k%line==0)
             cout<<endl;
         else
             cout<<"\t";
     }
     for(i=0;i<A3;i++)                          // 除法
     {
         k++;
         if(a3[i]<0)
             cout<<"("<<a3[i]<<")";
        else
             cout<<a3[i]<<" ";
        cout<<"/";
        if(b3[i]<0)
             cout<<"("<<b3[i]<<")";
         else
            cout<<" "<<b3[i]<<" ";
        cout<<"=";
         if(k%line==0)
             cout<<endl;
         else
            cout<<"\t";
     }
	 }
    