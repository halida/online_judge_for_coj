//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: 1132
//----------------------------------------------------------
#include <cstdio>

#include <cmath>
#include <algorithm>
#include <vector>

const int MAX_X = 5 * 100000;

std::vector <int> sep[MAX_X+1];

int res[MAX_X+1];

void sepp(int v){
    int vt = v;
    int i = 1;

    if (v > 1) sep[v].push_back(1);

    while (vt > 1){
        i++;
        if (i > vt/2) break;

        if (vt % i == 0) {
            sep[v].push_back(i);
            vt /= i;
            i = 1;

            if ( ! sep[vt].empty() ){
                // std::vector<int> a=sep[v], b=sep[vt];
                // a.insert(a.end(), b.begin(), b.end());
                // sep[v] = a;
                sep[v].insert(sep[v].end(), sep[vt].begin(), sep[vt].end());
                sort(sep[v].begin(), sep[v].end());
                return;
            }
        }
    }
    if (vt != v) sep[v].push_back(vt);
        
    sort(sep[v].begin(), sep[v].end());
}

int solve(int v){
    if (v <= 1) return 0;
    if (res[v] != -1) return res[v];
    if (sep[v].empty()) sepp(v);

    if (sep[v].size() <= 1) {
        res[v] = 1;
        return 1;
    }

    // printf("sep.size = %d\n", sep[v].size());

    int last = sep[v][ sep[v].size()-1 ];
    int last_count = 0;

    int pre = v;
    while( true ){
        if (pre % last > 0) break;
        pre /= last;
        last_count ++;
    }
    
    // for (int i = 0; i < sep[v].size()-1; ++i)
    //     {
    //         int c = sep[v][i];
    //         if (c != last) {
    //             pre *= c;
    //         } else {
    //             last_count ++;
    //         }
    //     }

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
    for (int i = 0; i < MAX_X/10; ++i)
        {
            int result = solve(i);
            // printf("sep %d size %d = ", i, static_cast<int>(sep[i].size()));
            // for (int j = 0; j < sep[i].size(); ++j)
            //     {
            //         printf("%d ", sep[i][j]);
            //     }
            // printf(", solve: %d\n", result);
        }
}

void pre_sep(){
    // find parameters
    int i = 2;
    int m = std::sqrt(MAX_X);
    for (int i = 1; i <= m; ++i)
        {
            if (sep[i].size() > 1) continue;
            for (int j = 1; j <= MAX_X/i; ++j)
                {
                    if (i == 1 && j == 1) continue;
                    sep[i*j].push_back(i);
                }
        }
    // find parameter count
}

int main(int argc, char *argv[])
{
    std::fill(res, (res + MAX_X + 1), -1);

    // pre_sep();
    check_result();
    return 0;

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

