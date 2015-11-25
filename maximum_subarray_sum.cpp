#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int cSum(int * arr, int l, int h, int m){
	int l_sum=INT_MIN;
	int sum=0;
	for(int i=m; i>=l;i--){
		sum+=arr[i];
		if(sum>l_sum) l_sum=sum;
	} 
	sum=0;
	int r_sum=INT_MIN;
	for( int i=m+1; i<=h; i++){
		sum+=arr[i];
		if(sum>r_sum) r_sum=sum;		
	}
	return l_sum+r_sum;
}

int subArraySum(int * arr, int l, int h){
	if(l==h) return arr[l];
	else{
		int m=(l+h)/2;
		int lsum=subArraySum(arr, l, m);
		int rsum=subArraySum(arr, m+1, h);
		int csum=cSum(arr, l, h, m);
		int max;
		if(lsum>rsum) max=lsum;
		else max=rsum;
		if(max>csum) return max;
		else return csum;		
	}
}

int main(){
	int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<subArraySum(arr,0 , n-1)<<endl;	
	return 0;
}

