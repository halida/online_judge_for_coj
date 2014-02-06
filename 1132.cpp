//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: 1132
//----------------------------------------------------------
#include <cstdio>

#include <cmath>
#include <algorithm>

const int MAX_X = 5 * 100000;

int sep[MAX_X+1];
int res[MAX_X+1];

void sepp(int v){
    int vt = v;
    int i = 1;

    if (v <= 1) { sep[v] = 0; return; }

    sep[v] = 1;
    int m = std::sqrt(vt);

    while (vt > 1){
        i++;
        if (i > m) break;

        if (vt % i == 0) {
            sep[v] = std::max(sep[v], i);
            vt /= i;
            i = 1;

            if ( sep[vt] >= 0 ){
                sep[v] = std::max(sep[v], sep[vt]);
                return;
            }
        }
    }

    if (vt != v) sep[v] = std::max(sep[v], vt);
}

int solve(int v){
    if (res[v] != -1) return res[v];
    if (sep[v] < 0) sepp(v);
    if (sep[v] == 1) {res[v] = 1; return 1; };
    if (v <= 1) return 0;

    // printf("sep.size = %d\n", sep[v].size());

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
    for (int i = 0; i < MAX_X+1; ++i)
        {
            int result = solve(i);
            // printf("sep %d max %d", i, sep[i]);
            // printf(", solve: %d\n", result);
        }
}

void pre_sep(){
    // find parameters
    int i = 2;
    int m = std::sqrt(MAX_X);
    for (int i = 1; i <= m; ++i)
        {
            if (sep[i] > 1) continue;
            for (int j = 1; j <= MAX_X/i; ++j)
                {
                    if (i == 1 && j == 1) continue;
                    int t = i*j;
                    sep[t] = std::max(sep[t], i);
                }
        }
    // find parameter count
}

int main(int argc, char *argv[])
{
    std::fill(res, (res + MAX_X + 1), -1);
    std::fill(sep, (sep + MAX_X + 1), -1);

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

