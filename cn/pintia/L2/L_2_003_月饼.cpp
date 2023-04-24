#include <algorithm>
#include <iostream>
using namespace std;
struct mooncake {
    double store;
    double sell;
    double price;
};
int main() {
    int n;
    double d;
    double sum= 0;
    mooncake cake[1000];
    bool cmp(mooncake, mooncake);
    cin >> n >> d;
    for(int i= 0; i < n; i++)
        cin >> cake[i].store; // 输入数量
    for(int i= 0; i < n; i++) {
        cin >> cake[i].sell;                         // 输入总价
        cake[i].price= cake[i].sell / cake[i].store; // 计算单价
    }
    sort(cake, cake + n, cmp);
    for(int i= 0; i < n; i++) {
        if(cake[i].store <= d) // 如果需求大于数量，全部卖出
        {
            d= d - cake[i].store;
            sum= sum + cake[i].sell;
        } else {
            sum= sum + cake[i].price * d; // 如果需求小于数量，单价
            break;                        //*剩下的数量
        }
    }
    printf("%.2f\n", sum);
    return 0;
}
bool cmp(mooncake a, mooncake b) {
    return a.price > b.price; // 以单价为标准进行从大到小排序
}
