#include <iostream>
using namespace std;

/*     <-------Problem statement----------->
    you are given an array of n elements, where each element occurs three times except one
    element that appears only once. you need to find that element and return it.
    Try to not use extra space and be within O(n) time.

*/

int solution(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < 32; i++) // 4byte integer = 32bit
    {
        int count_zero = 0, count_one = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1<<i))
            {
                count_one++;
            }
            else
            {
                count_zero++;
            }
        }
        if(count_one%3 !=0)
        {
            ans = ans | (1<<i); // since the 1 will be set on the ith shift and other are
                           // remains 0 that's why there is no need of else part
        }
    }
  return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 1, 4, 4, 5, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solution(arr, n);
}