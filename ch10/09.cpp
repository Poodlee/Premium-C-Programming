#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> v;
	double aver;
	int num, size = 0;
	while (1)
	{
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> num;
		if (num == 0)
			break;
		size++;
		v.push_back(num);
		aver = 0.0;
		for (int i = 0; i < size; i++)
		{
			cout << v[i] << ' ';
			aver += v[i];
		}
		cout << "\n평균 = " << (double)aver / size << '\n';
	}
}