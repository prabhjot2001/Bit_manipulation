#include <iostream>
#include <utility>
using namespace std;

/* <----   Problem statement   ----->
The problem is that, you are given with an array of n elements and
   every element occurs two times in an array expect two elements which are different.
   Your task is to return those two elements
*/

pair<int, int> solution(int arr[], int n)
{
    pair<int, int> ans;
    int xorValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        xorValue ^= arr[i];
    }
    xorValue = xorValue & ~(xorValue - 1); // find the right most bit "(x & ~(x-1))"
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (xorValue & arr[i])
            num1 ^= arr[i]; /* this line here means that, for eg:- num1 has 9 stored in it and if
           again 9 appears in the array then it will be cancelled out and num1 become 0. But if
           num1 contain an element which doesn't appear more than once then num1 contain that
           value only.
           */
        else
            num2 ^= arr[i];
    }
    ans = {num1, num2};
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int, int> ans = solution(arr, n);
    cout << ans.first << "," << ans.second << endl;
}