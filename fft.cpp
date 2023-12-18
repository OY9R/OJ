#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

using namespace std;

const double PI = acos(-1.0);

// 递归实现FFT
void fft(vector<complex<double>>& a, bool inv) {
    int n = a.size();
    if (n == 1) {
        return;
    }
    
    //分治
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, j++) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    fft(a0, inv);
    fft(a1, inv);
    
    //FFT
    double angle = 2 * PI / n * (inv ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        w *= wn;
    }
}

// FFT乘法
vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    // 将多项式的项数变为2的整数次幂
    while (n < a.size() + b.size()) {
        n *= 2;
    }
    a.resize(n), b.resize(n);
    
    vector<complex<double>> c(n), d(n);
    for (int i = 0; i < n; i++) {
        c[i] = complex<double>(a[i], 0);
        d[i] = complex<double>(b[i], 0);
    }
    
    // 求原多项式的FFT
    fft(c, false), fft(d, false);
    for (int i = 0; i < n; i++) {
        c[i] *= d[i];
    }
    
    // 求乘法结果的IFFT
    fft(c, true);
    
    // 将IFFT中与逆矩阵相差的1/n乘进去
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = (int)(c[i].real() / n + 0.5);
    }
    
    // 处理进位
    int carry = 0;
    for (int i = 0; i< n; i++) {
    	res[i] += carry;
    	carry = res[i] / 10;
    	res[i] %= 10;
	}
    
    // 去高位的0
	while (res.size() > 1 && res.back() == 0) {
    	res.pop_back();
	}
	return res;
}

// 将大整数字符串转换为vector<int>
vector<int> to_vector(string s) {
	vector<int> res;
	for (int i = s.size() - 1; i >= 0; i--) {
		res.push_back(s[i] - '0');
	}
	return res;
}

// 将vector<int>转换为大整数字符串
string to_string(vector<int> a) {
	string res;
	for (int i = a.size() - 1; i >= 0; i--) {
		res += to_string(a[i]);
	}
	return res;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> a = to_vector(s1), b = to_vector(s2);
	vector<int> c = multiply(a, b);
	cout << to_string(c) << endl;
	return 0;
}