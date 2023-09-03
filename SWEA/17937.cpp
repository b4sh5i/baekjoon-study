#include<stdio.h>

long long m_abs(long long n)
{
    if (n > 0)
        return n;
    else
        return n * (-1);
}

long long gcd(long long v1, long long v2){
    while(v2 != 0){
        long long t = v1 % v2;
        v1 = v2;
        v2 = t;
    }
    return m_abs(v1);
}

int main(){
    int c;
    long long max, min;
    scanf("%d", &c);
    for(int i=0; i<c; i++){
        scanf("%lld %lld", &max, &min);
        printf("#%d %lld\n", i+1, gcd(max, min));
    }
}
