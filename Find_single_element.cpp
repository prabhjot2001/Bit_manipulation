#include <iostream>
#include <map>
using namespace std;

int solution1(int arr[], int n)
{
   map<int, int> mp;
   for (int i = 0; i < n; i++)
   {
      mp[arr[i]]++;
   }

   //    if(mp.find(1) != mp.end())
   //    {
   //     cout<<"found"<<endl;
   //    }else{
   //     cout<<"not found"<<endl;
   //    }

   for (auto pr : mp)
   {
      if (pr.second == 1)
      {
         return pr.first;
      }
   }
   return -1;
}

int solution2(int arr[], int n)
{
   int result = arr[0];
   for (int i = 1; i < n; i++)
   {
      result = result ^ arr[i];
   }
   return result;
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

   cout << "ans: " << solution1(arr, n);
   cout << "ans: " << solution2(arr, n);
}