#include<iostream>
using namespace std;

int solution(int ip) //my approach
{
    int count = 0;
    for(int i=0 ;i<32;i++)
    {
       if(ip & (1<<i))
       {
        count++;
       }
    }
    return count;
}

int solution2(int ip){
    int count = 0;
      while(ip != 0)
      {
        ip = ip & (ip -1);
        count++;
      }
      return count;
}

int main()
{
    int input;
    cin>>input;

    cout<<solution2(input);
}
