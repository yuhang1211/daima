//��������2
//��� 2016/3/11

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
     cout<<"*************��������2*************"<<endl;
	 cout<<endl;
	 cout<<endl;
     
      cout<<"��������ʽ������ÿ����ʾ����(��ӡ��ʽ����"<<endl;
      cin>>num>>line;
     
     cout<<"�Ƿ�Ҫ�г˳�������1/0��"<<endl;
     cin>>CC;
      while(1)                             //�ж������Ƿ�Ϸ�
     {
        if(CC != 1&&CC != 0)
        {
            cout<<"�����������������룺";
            cin>>CC;
        }
         else
             break;
     }
     
     cout<<"�Ӽ����޸�������1/0��"<<endl;
      cin>>FS;
     while(1)                             //�ж������Ƿ�Ϸ�
     {
        if(FS != 1&&FS != 0)
         {
            cout<<"�����������������룺";
            cin>>FS;
          }
         else
              break;
      }
      
      cout<<"����������������1/0��"<<endl;
      cin>>YS;
      while(1)                             //�ж������Ƿ�Ϸ�
      {
         if(YS != 1&&YS != 0)
          {
             cout<<"�����������������룺";
             cin>>YS;
         }
          else
              break;
      }
     
	   cout<<"�Ƿ������ţ���1/0��"<<endl;
      cin>>KH;
     while(1)                             //�ж������Ƿ�Ϸ�
     {
        if(KH!= 1&&KH != 0)
         {
            cout<<"�����������������룺";
            cin>>KH;
          }
         else
              break;
      }


      cout<<"��������������ֵ��Χmin,max��min<max��"<<endl;
	  cin>>min>>max;
	 cout<<endl;
     while(1)                            //�ж������Ƿ�Ϸ�
     {
         if(min>=max)
          {
             cout<<"�����������������룺";
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
	  srand( (unsigned)time( NULL ) );//srand()��������һ���Ե�ǰʱ�俪ʼ���������
      for(i=0;;i++)
      {
          a=min+rand()%m;
          b=min+rand()%m;
		  d=min+rand()%m;
          c=rand()%4;

         if(CC==0)              //���CC=0��ȥ��c=2,3�����
         {
              if(c==2||c==3)
                 continue;
			  

          }
          if(FS==0)              //���FS=0��ȥ��c=0,1�½��С��0�����
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
        if(YS==0)             //���YS=0�����ǳ�����ȥ��a��b��������������
         {
            if(c==3)
                 if(0 != a%b)
                    continue;
        }
    
        
		
		//����ʽ��Ϊ�ӡ������ˡ�������
         if(c==0)                       //�ӷ�
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
         else if(c==1)                   //����
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
         else if(c==2)                     //�˷�
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
         else                               //����
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
         if(num==A0+A1+A2+A3)                //������ʽ����
             break;
     }
    
	
	 
	 //���
	  for(i=0;i<A0;i++)                        //  �ӷ�
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
      for(i=0;i<A1;i++)                         // ����
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
     for(i=0;i<A2;i++)                         // �˷�
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
     for(i=0;i<A3;i++)                          // ����
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
    