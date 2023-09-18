#include<iostream>
#include<math.h>
using namespace std;

unsigned solution(int num)
{
    unsigned ans = 0 ;
    for(int i=0;i<32;i++) // assuming that the given number is of 4byte or 32 bit
    {
      if(1<<i & num){
        ans = 1<<((32-i)-1) | ans;
      }
    }
   return ans;
}

unsigned solution2(int num)
{
    unsigned ans = 0;
    while(num > 0)
    {
        ans = ans<<1;
        if(num & 1)
        {
            ans = ans ^ 1;
        }
        num = num>>1;
    }
    return ans;
}

int main(){
    int num;
    cin>>num;
    // cout<<solution(num);
    cout<<solution2(num);
}