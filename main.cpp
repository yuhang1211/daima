//����һ���������������������ĺ�
//����������� 2016/3/21

#include<iostream>
using namespace std;

int main()
{
    int arr[1000];
    int i, MaxSum = 0, max, sum = 0, num = 1, count = 0;
    /*MaxSum������������
      max������������ֵ
      sum��������ĺ�
      num��Ԫ�ظ���
      count��Ԫ���и����ĸ���*/
    cout << "������һ���������飨������1000������" << endl;
    cin >> arr[0];
    while (getchar() != '\n')
    {
        cin >> arr[num];
        num++;
    }

    for (i = 0; i < num; i++)
    {
        if (sum < 0)
            sum = arr[i];//���������С��0ʱ����������������������ӣ��Ϳ϶�С�ں�һ������֮�ͣ���ʱ����b���¸�ֵ����Ϊ��һ��Ԫ��
        else
            sum += arr[i];
        if (MaxSum < sum)
            MaxSum = sum;
    }

    max = arr[0];//d��¼�����е����Ԫ��ֵ
    for (i = 0; i<num; i++)  //�������ȫΪ���������������;������������ֵ
    {
        if (arr[i]<0)
            count++;
        if (arr[i]>max)
            max = arr[i];
        if (count == num)
            MaxSum = max;

    }
    cout << "�����������Ϊ��" << MaxSum << endl;
    return 0;

}