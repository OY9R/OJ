#include <iostream>
#include <algorithm>
using namespace std;
bool isInsertionSort(int n, int a[], int b[]);
bool isMergeSort(int n, int a[], int b[]);
bool isEqual(int n, int a[], int b[]);

int main(){
    int n; cin >> n;
    int a[n], b[n], c[n];
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if(isInsertionSort(n, a, b)) {
        cout << "Insertion Sort" << endl;
        for(int i = 0; i < n; i++){
            cout << a[i];
            if(i != n - 1) cout << ' ';
        }
    } else if(isMergeSort(n, c, b)){
        cout << "Merge Sort" << endl;
        for(int i = 0; i < n; i++){
            cout << c[i];
            if(i != n - 1) cout << ' ';
        }
    }
    return 0;
}

bool isInsertionSort(int n, int a[], int b[]){
    for(int i = 1; i < n; i++){
        sort(a,a + i + 1);
        if(isEqual(n, a, b)) {
            i++; sort(a,a + i + 1);
            return 1;
        }
    }
    return 0;
}

bool isMergeSort(int n, int a[], int b[]){
    for(int i = 2; i / 2 <= n; i *= 2) {
        for(int j = 0; j < n; j += i)
            sort(a + j,a + min(j + i, n));
        if(isEqual(n, a, b)) {
            i *= 2;
            for(int j = 0; j < n; j += i)
                sort(a + j,a + min(j + i, n));
            return 1;
        }
    }
    return 0;
}

bool isEqual(int n, int a[], int b[]){
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) return 0;
    return 1;
}