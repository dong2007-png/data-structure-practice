#include<iostream>
using namespace std;
int removement(int arr[],int n,int val)
{
    int slow=0;
    for (int fast=0;fast<n;fast++)
    {
        if (arr[fast]!=val)
        {
            arr[slow]=arr[fast];
            slow++;
        }
    }
    return slow;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int newlength=removement(arr,n,x);
    cout<<newlength<<endl;
    for (int i=0;i<newlength;i++)
    {
        cout<<arr[i]<<" ";
    }


}