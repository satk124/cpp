#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int arr[] = {1, 101, 2, 3, 100, 4, 5};
int dp[100];
int ldp[100];

int main(){
	int sz=sizeof(arr)/sizeof(arr[0]);	
	int max=arr[0];
	for(int i=0; i<sz; i++){
		ldp[i]=1;
		dp[i]=arr[i];
		if(i==0) continue;
		
		for(int j=0; j<i; j++){			
			if(ldp[j]+1>ldp[i] && arr[i]>arr[j]){
				ldp[i]=ldp[j]+1;		
				dp[i]=dp[i]+arr[j];							
			}
		}		
		//cout<<dp[i]<<"|"<<ldp[i]<<"::";
		if(max<dp[i]) max=dp[i];
	}
	cout<<max<<endl;
	return 0;	
} 
