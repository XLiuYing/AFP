#include <iostream>
using namespace std;

#define max 50
int x[max + 1];//��i�еĻʺ���ڵ�x[i]����

int n;//���̿���Լ��ʺ�����
int sum = 0;//����������


			//��������Ļʺ�����Ϊ��row,col��,�ж��Ƿ��ܹ�����
bool Place(int row, int col) {
	for (int i = 1; i < row; i++)  //�Ƚ�֮ǰrow -1���Ѿ����õĻʺ�
	{
		if (col == x[i] || abs(row - i) == abs(col - x[i]))  //�жϼ����ŵĻʺ����Ѿ����ڵĻʺ����Ƿ���ͬһ�л�ͬһб��
			return false;
	}
	return true;
}

//�ݹ�Ļ��ݺ��������������������µݹ飬������������������ǰ����
void Backtrack(int t, int n) {
	if (t == n + 1)  //�ɹ���ȫ�����̱�����һ�Σ��γ���һ����
		sum++;
	else {
		//����һ�б�����n�Բ��ܷ��ûʺ�����ǰ����
		for (int i = 1; i <= n; i++) {
			x[t] = i;
			if (Place(t, x[t]))//�ж��Ƿ��ܷ��ûʺ�
				Backtrack(t + 1, n);//����һ���ܷ��ûʺ�������һ�н��еݹ�
		}
	}
}

int main()
{
	cout << "������ʺ������: ";
	cin >> n;
	Backtrack(1, n);
	cout << "��ĸ���Ϊ: " << sum << endl;

	return 0;
}

