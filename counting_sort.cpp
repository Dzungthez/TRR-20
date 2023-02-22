#include<iostream>
using namespace std;
void cs(int a[], int n)
{
    int max = a[1];
    for(int i = 2; i <= n; i++) 
    {
        if(max < a[i]) max = a[i];
    }
    int b[n];
    int c[max];
    for(int i = 0; i <= max; i++) c[i] = 0;
    for(int i = 1; i <= n; i++) c[a[i]]++;
    for(int i = 1; i <= max; i++) c[i] += c[i - 1];
    for(int i = 1; i <= n; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for(int i = 1; i <= n; i++) a[i] = b[i];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 1; i <= n; i++) cin >> a[i];
    cs(a, n);
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}