// by http://www.douban.com/people/huoxiaochai/
#include<iostream> 

using namespace std; 


int main() 
{ 
int _cases; 
int _index; 

int ans[500001] = { 0} ; 
for(int i = 1 ; i <= 250000 ; i++ ) 
for (int j = 2 ; i*j <= 500000 ; j++ ) 
ans[i*j] += i ; 

cin>>_cases; 

for(int i=1; i<=_cases; i++ ) 
{ 
cin>>_index; 
cout<<ans[_index]<<endl; 
} 
}
