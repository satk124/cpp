#include <iostream>
#include <string>
#include <climits>
#include <cstring>

using namespace std;
bool dp[50][10];

bool isPar(int *arr, int sum, int n){
	if(sum==0) return true;
	if(n<0) return false;
	else if(dp[sum][n]!=0) return dp[sum][n];
	else if(arr[n]>sum) return dp[sum][n]=isPar(arr, sum, n-1);
	else {
		bool t1=isPar(arr, sum, n-1);
		bool t2=isPar(arr, sum-arr[n], n-1);
		dp[sum][n]= t1||t2;
		return dp[sum][n];
	}
}

int main(){
	int arr[] = {3, 1, 1, 2, 2, 1};
	int n=sizeof(arr)/sizeof(arr[0]);
		
	memset(dp, 0, sizeof(dp));
	int sum=0;
	for(int i=0; i<n ; i++)  sum+=arr[i];
	
	if(sum%2==1) {
		cout<<"No  partition"<<endl;
	return 0;
}
	
	if(isPar(arr, sum/2, n-1)) cout<<"TRUE"<<endl;
	else cout<<"FALSE"<<endl;

	return 0;
}
