#include <bits/stdc++.h>  // 使用万能头文件stdc++.h，注意，有的IDE可能不支持
#include "random.h"  // 使用自制的随机库

using namespace std;

// 普通高斯消去，LU分解
void LU(float** A, int N) {
    // cout << "start LU" << endl;
    for (int k=0; k<N; k++) {
        for (int j=k+1; j<N; j++) {
            A[k][j] = A[k][j] / A[k][k];
        }
        A[k][k] = 1.0;
        for (int i=k+1; i<N; i++) {
            for (int j=k+1; j<N; j++) {
                A[i][j] = A[i][j] - A[k][j]*A[i][k];
            }
            A[i][k] = 0;
        }
        // print(A, N);
        // cout << endl;
    }
}

int main() {
    int N;
    vector<int> size = {200, 500, 1000, 2000, 3000};
    for (int i=0; i<5; i++) {
        // 设置问题规模
        N = size[i];

        // 初始化二维数组
        float** A = new float*[N];
        for (int i=0; i<N; i++) {
            A[i] = new float[N];
        }
        reset(A, N);
        // print(A, N);

        // 使用C++11的chrono库来计时
        auto start = chrono::high_resolution_clock::now();
        LU(A, N);
        auto end = chrono::high_resolution_clock::now();
        auto diff = chrono::duration_cast<chrono::duration<double, milli>>(end - start);
        cout << "Size = " << N << ": " << diff.count() << "ms" << endl;
        // print(A, N);
        // break;
    }
    return 0;
}