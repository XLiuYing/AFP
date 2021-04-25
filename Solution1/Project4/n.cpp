#include <iostream>
using namespace std;

#define max 50
int x[max + 1];//第i行的皇后放在第x[i]列上

int n;//棋盘宽度以及皇后数量
int sum = 0;//计算解的数量


			//即将放入的皇后坐标为（row,col）,判断是否能够放置
bool Place(int row, int col) {
	for (int i = 1; i < row; i++)  //比较之前row -1行已经放置的皇后
	{
		if (col == x[i] || abs(row - i) == abs(col - x[i]))  //判断即将放的皇后与已经存在的皇后们是否处于同一列或同一斜线
			return false;
	}
	return true;
}

//递归的回溯函数，若满足条件则往下递归，若不满足条件，则往前回溯
void Backtrack(int t, int n) {
	if (t == n + 1)  //成功将全部棋盘遍历了一次，形成了一个解
		sum++;
	else {
		//若这一行遍历到n仍不能放置皇后，则向前回溯
		for (int i = 1; i <= n; i++) {
			x[t] = i;
			if (Place(t, x[t]))//判断是否能放置皇后
				Backtrack(t + 1, n);//若这一行能放置皇后，则向下一行进行递归
		}
	}
}

int main()
{
	cout << "请输入皇后的数量: ";
	cin >> n;
	Backtrack(1, n);
	cout << "解的个数为: " << sum << endl;

	return 0;
}

