//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: 1132
//----------------------------------------------------------
#include <cstdio>
#include <cstdlib>

#include <cmath>
#include <algorithm>
#include <vector>

const int MAX_X = 5 * 100000;

int sep[MAX_X+1];
int res[MAX_X+1];
std::vector <int> primes;

void solve_primes(int v){
    int m = v/2;
    int f = primes[primes.size()-1];
    for (int i = f+1; i < m; ++i)
        {
            bool isprime = true;
            for (int j = 0; j < primes.size(); ++j)
                {
                    if (i % primes[j] == 0) {
                        isprime = false;
                        break;
                    }
                }
            if (isprime) {
                primes.push_back(i);
                // printf("is prime: %d\n", i);
            }
        }
}

void sepp(int v){
    if ( primes[primes.size()-1] < (v / 2)) solve_primes(v);

    int vt = v;

    if (v <= 1) { sep[v] = 0; return; }

    sep[v] = 1;
    int m = std::sqrt(vt);

    int i = 0;
    while(vt > 1){
        int p = primes[i];

        if (vt % p == 0) {
            sep[v] = std::max(sep[v], p);
            vt /= p;

            if ( sep[vt] > 0 ){
                sep[v] = std::max(sep[v], sep[vt]);
                return;
            }

            i = 0;
            continue;
        }

        i++;
        // this number is prime
        if (i >= primes.size()) {
            // printf("is prime: %d\n", vt);
            primes.push_back(vt);
            return;
        }
    }
}

int solve(int v){
    if (res[v] != -1) return res[v];
    if (sep[v] < 0) sepp(v);
    if (sep[v] == 1) {res[v] = 1; return 1; };
    if (v <= 1) return 0;

    int last = sep[v];
    int last_count = 0;

    int pre = v;
    while( true ){
        if (pre % last > 0) break;
        pre /= last;
        last_count ++;
    }
    
    int pre_result = solve(pre);
    int result = 0;

    for (int i = 0; i < last_count+1; ++i)
        {
            // result += last ^ i;
            result += (pre_result + pre) * pow(last, i);
            // printf("result: %d, %e \n", result, pow(last, i));
        }
    result -= v;

    // printf("pre: %d, last: %d, last_count: %d, pre: %d, result: %d\n", pre, last, last_count, pre_result, result);

    res[v] = result;
    return result;
}

int lazy_solve(int v){
    int r = 0;
    if (v <= 1) return 0;
    for (int i = 1; i <= (v/2); ++i)
        {
            if (v % i == 0) r+=i;
        }
    return r;
};

void check_result(){
    for (int i = 10; i < 1000; ++i)
        {
            int result = solve(i);
            printf("sep %d max %d", i, sep[i]);
            printf(", solve: %d\n", result);
        }
}

int main(int argc, char *argv[])
{
    std::fill(res, (res + MAX_X + 1), -1);
    std::fill(sep, (sep + MAX_X + 1), -1);
    // solve_primes();
    primes.push_back(2);
    
    // pre_sep();
    // check_result();
    // return 0;

    int c = 0;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i)
        {
            int v = 0;
            scanf("%d", &v);

            int r = solve(v);
            printf("%d\n", r);
        }
    return 0;
}

