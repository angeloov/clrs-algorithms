#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> v) {
    for (int el : v) cout << el << " ";
    cout << endl;
}

void sum_binary(vector<int> a, vector<int> b, int N) {
    vector<int> c(N+1);
    int carry = 0;
    
    int i;
    
    for ( i = N-1; i >= 0; i--) {
        c[i+1] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }
    
    c[0] = carry;
    
    printvec(c);
}

int main() {
    vector<int> a = {0,1,0,1};
    vector<int> b = {1,1,1,1};
    int N = 4;
    sum_binary(a, b, N);

    return 0;
}