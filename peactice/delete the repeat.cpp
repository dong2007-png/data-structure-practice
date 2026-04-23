#include <iostream>
#include <algorithm>
using namespace std;
int remove(int arr[],int n)
{
    if (n==0) return 0;
    int slow=1;
    for (int fast=1;fast<n;fast++)
    {
        if (arr[fast]!=arr[slow-1])
        {
            arr[slow]=arr[fast];
            slow++;

        }
    }
    return slow;
}
int main()
{
    int arr[]={1,2,3,1,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int newlength=remove(arr,n);
    cout<<newlength<<endl;
    for (int i=0;i<newlength;i++)
    {
        cout<<arr[i]<<" ";
    }
}