#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int dp[100];
int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

int val(int l){
	if(l<=0) return 0;
	else if(dp[l]!=0) return dp[l];
	else {
		int max=INT_MIN;
		for(int i=0; i<l; i++){
			int temp=price[i]+val(l-i-1);
			if(temp>max) max=temp;
		}
		return dp[l]=max;
	}
}

int main(){	 
	 int sz= sizeof(price)/sizeof(price[0]);
	 memset(dp, 0, sizeof(dp));
	 cout<<val(sz);	 
}
