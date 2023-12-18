#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int a_sum, n;
void tmax(int& a, int b) { if (a < b)a = b; }
// O(*max_element(ws) * ws.size())
int maximum_subset_sum(std::vector<int> ws, const int& w_limit)
{
	sort(ws.begin(), ws.end(), greater<int>());
	if (ws[0] > w_limit)return a_sum - ws[0]; if (!ws.back())return 0;
	int B = 2000,n = int(ws.size()), w_break = 0, lb = 0;	
	while(w_break + ws[lb] <= w_limit) w_break += ws[lb++];
	std::vector<int> ss(B*2+1, -1);ss[B- w_limit + w_break] = lb;
	std::vector<int> new_ss = ss;
	// ss/new_ss[i]=j:j�ĺ���
	// A:j==lb:ʹ��ws[0,lb),��������,sum�ɴ�w_limit+i-B
	//B:j<lb:ʹ��ws[0,j)����ʹ��ws[j],��������,sum�ɴ�w_limit+i-B;��ʹ��ws[0,j]�����಻һ��
	//�������󿿽�ss[B]
	for (int t = lb; t < n; t++) 
	{		
		for (int w = 0; w < B; w++) tmax(new_ss[w + ws[t]], ss[w]);//���Ƿ����µ���ws[t]
		for (int w = B << 1; w > B; w--)//����س���ws[0,j],���������п��� ͬʱsum<=B�󲻱�Ҫ��������,��(�����µ���ws[t])sum>B���ٳ���,����ʧ��Ϣ
			for (int j = new_ss[w] - 1; j >= std::max(ss[w], 0); j--) //j<ss[w]&&ss[w]>0:֮ǰ�� ss[w]�����󴫵ݹ�,�����ظ�
				tmax(new_ss[w - ws[j]], j);
		ss = new_ss; if (ss[B] != -1) return w_limit;
	}
	for (int w = B; w; w--)if (ss[w] != -1) return w_limit + w-B;
}

int main() 
{
	cin >> n;vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i],a_sum+=a[i];
	std::cout << a_sum - maximum_subset_sum(a, a_sum / 2) << '\n';
}
