//��������������3��2016/3/14��������&���

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<cmath> 
#define random(x) (rand()%x)
using namespace std;

/*ѡ���ӡ��ʽ*/
void Output(int sf)
{
    if (sf == 1)//�����ĵ�
    {
        ofstream outfile("formula.txt", ios::out);
        if (!outfile)
        {
            cout << "Open error!!" << endl;
            exit(1);
        }
        outfile << "----------------��ӭ��Сѧ�������������ϵͳ:-D----------------" << endl;
        outfile.close();
    }
}

/*�ж�����0.1���Ƿ�������ȷ*/
int Istrue_input(int mnu01)
{
    while (1)
    {
        if (mnu01 != 0 && mnu01 != 1)
        {
            cout << "�����������������루������0��1��:" << endl;
            cin >> mnu01;
        }
        else
            break;
    }
    return mnu01;
}

/*����һ��ĳ��Χ�ڵ���������������У�*/
int Creat_random(int r1, int r2)
{
    int r, shu;
    /*srand((int)time(0));*/
    r = r2 - r1;
    shu = r1 + rand() % r;
    return shu;
}

/*����һ����������*/
string Create_oper(int lai)
{
    srand((int)time(0));
    string sign;
    int Num_sym, Sign_num;
    if (lai == 0)//�Ӽ�
        Num_sym = 2;
    else if (lai == 1)//�Ӽ��˳�
        Num_sym = 4;
    Sign_num = rand() % Num_sym;//������������ִ��������
    switch (Sign_num)
    {
    case(0) : sign = '+'; break;
    case(1) : sign = '-'; break;
    case(2) : sign = '*'; break;
    case(3) : sign = '/'; break;
    }
    return sign;
}

/*�ж�����������ȡ�෴��*/
int Opp_zf(int a)
{
    if (a < 0)
        a = -a;
    return a;
}

/*��int����ת��Ϊstring����*/
string Int_str(int shu)
{
    char zhuan[100];
    string str,zuo="(",you=")";
    str=itoa(shu, zhuan, 10);
    if (shu < 0)
        str = zuo + str + you;
    return str;
}

/*����һ��(ĳ��Χ)�����*/
void Creat_fen(int r1, int r2, string &fenshu, double &zhi)
{
    /*srand((int)time(0));*/
    int i, r = r2 - r1, up, down, s;
    bool flag;
    string xian = "/", fu = "-", zuo = "(", you = ")";
    /*char zhuan1[10], zhuan2[10];*/
    string zhuan1, zhuan2;
loop:do
    {
         flag = false;//���ܶ���ȫ�ֱ�������
         up = r1 + rand() % r;
         up = Opp_zf(up);
         down = r1 + rand() % r;
         down = Opp_zf(down);
    } while ((up >= down) || (down == 0) || (up == 0));//���ӡݷ�ĸ or ��ĸ=0 or ����=0 ��������
    
    for (i = 2; i <= up; i++)
    {
        /*if ((i == -1)|| (i == 0))
        continue;*/
        if (up%i == 0 && down%i == 0)
        {
            flag = true;//�й�Լ��    
            break;
        }
    }
    if (flag == true)
    {
        goto loop;
    }
    else
    {
        zhi = (double)up / (double)down;
        //itoa(up, zhuan1, 10);//����ת����string����
        //itoa(down, zhuan2, 10);//��ĸת����string����
        zhuan1 = Int_str(up);//up/down�������������ټ�һ������
        zhuan2 = Int_str(down);
        s = rand() % 2;
        switch (s)
        {
            //������
            case(0) : 
                fenshu = zuo + zhuan1 + xian + zhuan2 + you; 
                break;
            //������
            case(1) : 
                fenshu = zuo + fu + zhuan1 + xian + zhuan2 + you;
                zhi = -zhi;
                break;
        }
    }
    //return fenshu;
}

///*����*/
//bool Is_rept(string str1, string str2)
//{
//    if (str1 == str2)
//        return true;//�ظ�
//    return false;//���ظ�
//}

/*��������*/
void Have_kuohao(int r1, int r2, string &formula,double &zhi)
{
    srand((int)time(0));
    int op,op1, op2;
    int yn, qh;//�����Ƿ�����š��͡��������ǰ�󡱵�����
    string symbol1,symbol2;
    string zhuan,zhuan1, zhuan2;
    string jia = "+", jian = "-", cheng = "*", chu = "/",zuo="(",you=")";

    zhi = (double)Creat_random(r1, r2);
    op1 = Creat_random(r1, r2);
    op2 = Creat_random(r1, r2);
    op = Creat_random(r1, r2);//����op2����ĸ����Ϊ0
    while (1)
    {
        if (op == 0)
            op = Creat_random(r1, r2);
        else
            break;
    }
    zhuan1 = Int_str(zhi);
    zhuan2 = Int_str(op);
    symbol1 = Create_oper(1);

    if (symbol1 == "+")
    {
        zhi = (double)op1 + (double)op2;
        formula = zhuan1 + jia + zhuan2;
        yn = rand() % 2;
        switch (yn)
        {
            //���治������
            case(0) : break;
            //���������
            case(1) :
            {
                        formula = zuo + formula + you;
                        qh = rand() % 2;
                        symbol2 = Create_oper(1);
                        switch (qh)
                        {
                            //�ӵ�ǰ��
                            case(0) :
                           {
                                    formula = symbol2 + formula;
                                    op = Creat_random(r1, r2);
                                    zhuan = Int_str(op);
                                    if (symbol2 == "+")
                                    {
                                        zhi = (double)op + zhi;
                                        formula = zhuan + jia + formula;
                                    }
                                    else if (symbol2 == "-")
                                    {
                                        zhi = (double)op - zhi;
                                        formula = zhuan + jian + formula;
                                    }
                                    else if (symbol2 == "*")
                                    {
                                        zhi = (double)op * zhi;
                                        formula = zhuan + cheng + formula;
                                    }
                                    else if (symbol2 == "/")
                                    {
                                        if (zhi == 0)//��ֹ����������ɵĳ��ź����ֵΪ0��
                                            break;
                                        else
                                        {
                                            zhi = (double)op / zhi;
                                            formula = zhuan + chu + formula;
                                        }    
                                    }
                                    break;

                             }
                             //�ӵ�����
                            case(1) :
                            {
                                    formula = formula + symbol2;
                                    op = Creat_random(r1, r2);//��ֹ��������������ţ���ĸΪ0
                                    while (1)
                                    {
                                        if (op == 0)
                                            op = Creat_random(r1, r2);
                                        else
                                            break;
                                    }
                                    zhuan = Int_str(op);
                                    if (symbol2 == "+")
                                    {
                                        zhi = zhi + (double)op;
                                        formula = formula + jia + zhuan;
                                    }
                                    else if (symbol2 == "-")
                                    {
                                        zhi = zhi - (double)op;
                                        formula = formula + jian + zhuan;
                                    }
                                    else if (symbol2 == "*")
                                    {
                                        zhi = zhi * (double)op;
                                        formula = formula + cheng + zhuan;
                                    }
                                    else if (symbol2 == "/")
                                    {
                                        zhi = zhi / (double)op;
                                        formula = formula + chu + zhuan;
                                    }
                                    break;
                              }

                        }
                        break;
            }
                
                
        }
        
        
    }
    else if (symbol1 == "-")
    {
        zhi = (double)op1 - (double)op2;
        formula = zhuan1 + jian + zhuan2;
    }
    else if (symbol1 == "*")
    {
        zhi = (double)op1 * (double)op2;
        formula = zhuan1 + cheng + zhuan2;
    }
    else if (symbol1 == "/")
    {
        zhi = (double)op1 / (double)op2;
        formula = zhuan1 + chu + zhuan2;
    }

        
    
    

}

/*���������*/
void Have_fenshu(int LL, int r1, int r2, string &formula, double &zhi, int jj)
{
    srand((int)time(0));
    string F1, F2, symbol, zhuan;
    double Z1, Z2;//ֵ
    int inter, type;
    inter = Creat_random(r1, r2);//����
    zhuan = Int_str(inter);
    Creat_fen(r1, r2, F1, Z1);//����1
    Creat_fen(r1, r2, F2, Z2);//����2
    symbol = Create_oper(LL);//����
    type = rand() % 3;//����

    if (jj == 0)//�Ӽ�û�и���
    {
        inter = Opp_zf(inter);
        zhuan = Int_str(inter);
        while (1)
        {
            if (Z1 <0)
                Creat_fen(r1, r2, F1, Z1);
            else
                break;
        }
        while (1)
        {
            if (Z2 <0)
                Creat_fen(r1, r2, F2, Z2);
            else
                break;
        }
    }

    switch (type)
    {
        //op1����
    case(0) :
        formula = F1 + symbol + zhuan;
        if (symbol == "+")
            zhi = Z1 + (double)inter;
        else if (symbol == "-")
        {
            if (jj == 0)
                break;
            else
                zhi = Z1 - (double)inter;
        }
        else if (symbol == "*")
            zhi = Z1 * (double)inter;
        else if (symbol == "/")
        {
            if (inter != 0)
                break;
            else
                zhi = Z1 / (double)inter;
        }
        break;
        //op2����
    case(1) :
        formula = zhuan + symbol + F1;
        if (symbol == "+")
            zhi = (double)inter + Z1;
        else if (symbol == "-")
            zhi = (double)inter - Z1;
        else if (symbol == "*")
            zhi = (double)inter * Z1;
        else if (symbol == "/")
        {
            if (Z1 != 0)
                zhi = (double)inter / Z1;
            else
                break;
        }
        break;
        //ȫ����  
    case(2) :
        formula = F1 + symbol + F2;
        if (symbol == "+")
            zhi = Z1 + Z2;
        else if (symbol == "-")
        {
            if ((jj == 0) && (Z1 < Z2))
                break;
            else
                zhi = Z1 - Z2;
        }
        else if (symbol == "*")
            zhi = Z1 * Z2;
        else if (symbol == "/")
        {
            if (Z1 != 0)
                zhi = Z1 / Z2;
            else
                break;
        }
        break;
    }

}

/*�����������*/
void Only_integer(int LL, int r1, int r2, string &formula, double &zhi,int jj,int cc)
{
    srand((int)time(0));
    int op1, op2;
    string symbol,zhuan1,zhuan2;
    op1 = Creat_random(r1, r2);//����1
    op2 = Creat_random(r1, r2);//����2
    symbol = Create_oper(LL);//����

    if (jj == 0)//�Ӽ���������
    {
        op1 = Opp_zf(op1);
        op2 = Opp_zf(op2);
        if ((symbol == "-") && (op1 < op2))
        {
            int temp;
            temp = op1;
            op1 = op2;
            op2 = temp;
        }
    }

    if ((cc == 0) && (symbol == "/"))//��������������ȥ�����ż���������
    {
        while (1)
        {
            op1 = Opp_zf(op1);
            op2 = Opp_zf(op2);
            if (op1 % op2 != 0)//����������������
            {
                op1 = Creat_random(r1, r2);
                op2 = Creat_random(r1, r2);
            }
            else
                break;
        }
    }

    zhuan1 = Int_str(op1);
    zhuan2 = Int_str(op2);
    formula = zhuan1 + symbol + zhuan2;
    if (symbol == "+")
        zhi = op1 + op2;
    else if (symbol == "-")
        zhi = op1 - op2;
    else if (symbol == "*")
        zhi = op1*op2;
    else if (symbol == "/")
        zhi = op1 / op2;
}

void main()
{
    ofstream outfile("formula.txt", ios::out);
    if (!outfile)
    {
        cout << "open error!" << endl;
        exit(1);
    }
    outfile << "----------------��ӭ��Сѧ�������������ϵͳ:-D----------------" << endl;

    int i,j,N, R1, R2;
    int SF, KH, FS, Lei,JJ,CC,count=0;
    string question="";//���ɵ�����
    double Zhi, answer;
    int fenzi, fenmu;
    bool repeat = false;
    
    cout << "----------------��ӭ��Сѧ�������������ϵͳ:-D----------------"<<endl;
    /*ѡ����Ŀ��Χ������*/
    cout << "����Ϊ���Ӷ���ʲô��Χ����Ŀ�أ����ɺ��и��� && ���ޡ����ޣ���" << endl;
    cout << "���ޣ�";
    cin >> R1;
    cout << "���ޣ�";
    cin >> R2;
    while (1)//�Ƿ�����Ϸ�
    {
        if (R2 < R1)
        {
            cout << "����ķ�Χ����������������(���ޡ�����):" << endl;
            cout << "���ޣ�";
            cin >> R1;
            cout << "���ޣ�";
            cin >> R2;
        }
        else
            break;
    }

    cout << "���ƶ��ٵ����أ������������" << endl;
    cout << "(������ʾ������ҪΪ���ӳ�̫�����Ŀ(���1000��)��лл������)" << endl;
    cin >> N;
    while (1)//�Ƿ�����Ϸ�
    {
        if (N<=0||N>1000)
        {
            cout << "�������Ŀ��������������������:" << endl;
            cin >> N;
        }
        else
            break;
    }

    /*ѡ���ӡ��ʽ*/
    cout << "���Ƿ���Ҫ�����ĵ�����0������Ҫ 1����Ҫ��" << endl;
    cin >> SF;
    SF=Istrue_input(SF);//�Ƿ�����Ϸ�
    Output(SF);

    cout << "*********�����밴�պ��ӵ�ѧϰ�̶�ѡ����Ŀ���Ѷȣ���*********"<<endl;
    /*�Ƿ�������*/
    cout << "�Ƿ���ϰ�������ŵ��Ѷ����㣿��0������Ҫ 1����Ҫ��";
    cin >> KH;
    KH=Istrue_input(KH);//�Ƿ�����Ϸ�
    if (KH == 1)//������
    {
        for (i = 1; i <= N; i++)
        {
            string Formula = "";
            double Zhi;
            Have_kuohao(R1, R2,Formula,Zhi);  
        }
        

    }

    //��������
    else if (KH == 0)
    {
        /*�Ӽ����������������*/
        cout << "��ѡ��0��ֻ���мӼ����㣿 1�������������㣿";
        cin >> Lei;
        Lei=Istrue_input(Lei);//�Ƿ�����Ϸ�

        cout << "�Ӽ��������Ƿ��и�������0��û�� 1���У�";
        cin >> JJ;
        JJ = Istrue_input(JJ);
    
        if (Lei == 1)//�˳�
        {
            cout << "�������Ƿ������������0��û�� 1���У�";
            cin >> CC;
            CC = Istrue_input(CC);
        }

        /*�Ƿ��������*/
        cout << "��Ŀ���Ƿ������������0������Ҫ 1����Ҫ��";
        cin >> FS;
        Istrue_input(FS);//�Ƿ�����Ϸ�

        cout << N << "����Ŀ���£�" << endl;
        if (SF == 1)//�ļ����
        {
            outfile << N << "����Ŀ���£�" << endl;
        }
        string ku[10000] = {};
        
        for (i = 1; i <= N; i++)
        {
            if (FS == 0)//ȫ����
                Only_integer(Lei, R1, R2, question, Zhi, JJ, CC);
            else if (FS == 1)//�������
                Have_fenshu(Lei, R1, R2, question, Zhi, JJ);

            ku[i] = question;
            /*repeat = false;*/
            for (j = 0; j <i; j++)
            {
                if (ku[j] == ku[i])
                {
                    i = i - 1;
                    repeat = true;//�ظ�
                    break;
                }
            }
            /*if (repeat) ku[i+1] = "";*/
            if (!repeat)//���ظ�
            {
                /*Is_rept(i,str);*/
                cout << i << "�� " << question << " = " << endl;
                if (SF == 1)//�ļ����
                {
                    outfile << i << "�� " << question << " = " << Zhi << endl;
                }

                if ((Zhi - (int)Zhi)< 1E-7 && (Zhi - (int)Zhi)> -(1E-7))//����Ϊ��������
                {
                    cin >> answer;
                }
                else
                {
                    cout << "    ���ӣ�";
                    cin >> fenzi;
                    cout << "    ��ĸ��";
                    cin >> fenmu;
                    answer = (double)fenzi / (double)fenmu;
                }
                
                if ((answer - Zhi) < 1E-7 && (answer - Zhi) > -(1E-7))
                {
                    cout << "                        ��" << endl;
                    count++;
                }
                else
                {
                    cout << "                        ��" << endl;
                    cout << "���ǣ�" << Zhi << endl;
                }
            }
        }
        
        cout << "���ĺ���һ�������" << count << "����Ŀ���� ��ϲ����" << endl;
        if (SF == 1)//�ļ����
        {
            outfile << "���ĺ���һ�������" << count << "����Ŀ���� ��ϲ����" << endl;
        }
        cout << "����" << N - count << "����Ŀ�����ԭ�򲢸���~~  ���ͣ���" << endl;
        if (SF == 1)//�ļ����
        {
            outfile << "����" << N - count << "����Ŀ�����ԭ�򲢸���~~  ���ͣ���" << endl;
        }
    }
    outfile.close();

}