// һάdp����ʵ��
#include <iostream>
#include <vector>
using namespace std;


void printVector(const vector<int>vec){
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // ��ȡ M �� N
    int M, N;
    cin >> M >> N;

    vector<int> costs(M);
    vector<int> values(M);




    // for (int i = 0; i < M; i++) {
    //     cin >> costs[i];
    // }
    // for (int j = 0; j < M; j++) {
    //     cin >> values[j];
    // }
    // N �����ռ�
    costs = {2, 2, 3, 1, 5, 2};
    values = {2, 3, 1, 5, 4, 3};
    // ����һ����̬�滮����dp����ʼֵΪ0
    vector<int> dp(N + 1, 0);

    // ���ѭ������ÿ�����͵��о�����

    // dp[j]Ϊ ����Ϊj�ı�������������ֵ��
    for (int i = 0; i < M; ++i)
    {
        // �ڲ�ѭ���� N �ռ��𽥼��ٵ���ǰ�о�������ռ�ռ�
        for (int j = N; j >= costs[i]; --j)
        {
            // ���ǵ�ǰ�о�����ѡ��Ͳ�ѡ��������ѡ�����ֵ
            dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
        }
        printVector(dp);

    }

    // ���dp[N]�����ڸ��� N ����ռ����Я�����о���������ֵ
    cout << dp[N] << endl;
    system("pause");
    return 0;
}
