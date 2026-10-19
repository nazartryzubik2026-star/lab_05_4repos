#include <iostream>
#include <cmath>

using namespace std;

// Helper function: single term of the sum
double term(const int j, const int N)
{
    return 1. * j * (N - j) / (1. * j * j + 1. * (N - j) * (N - j));
}

// 5) Iterative method (control)
double S0(const int K, const int N)
{
    double s = 0;
    for (int j = K; j <= N; j++)
        s += term(j, N);
    return s;
}

// 1) Recursion down, parameter decreases
double S1(const int K, const int N, const int j, double t)
{
    t = t + term(j, N);
    if (j <= K)
        return t;
    else
        return S1(K, N, j - 1, t);
}

// 2) Recursion down, parameter increases
double S2(const int K, const int N, const int j, double t)
{
    t = t + term(j, N);
    if (j >= N)
        return t;
    else
        return S2(K, N, j + 1, t);
}

// 3) Recursion up, parameter decreases
double S3(const int K, const int N, const int j)
{
    if (j < K)
        return 0;
    else
        return term(j, N) + S3(K, N, j - 1);
}

// 4) Recursion up, parameter increases
double S4(const int K, const int N, const int j)
{
    if (j > N)
        return 0;
    else
        return term(j, N) + S4(K, N, j + 1);
}

int main()
{
    const int K = 2; // Lower bound
    int N;

    cout << "N = ";
    cin >> N;

    if (N < K)
    {
        cout << "N must be >= " << K << endl;
        return 1;
    }

    cout << "(iter)       S0 = " << S0(K, N) << endl;
    cout << "(down, j--)  S1 = " << S1(K, N, N, 0) << endl;
    cout << "(down, j++)  S2 = " << S2(K, N, K, 0) << endl;
    cout << "(up, j--)    S3 = " << S3(K, N, N) << endl;
    cout << "(up, j++)    S4 = " << S4(K, N, K) << endl;

    return 0;
}