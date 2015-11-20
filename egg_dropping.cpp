// Egg Droping problem

#include <iostream>
#include <climits>
#include <cstring>

using namespace std;
int dp[3][38];
int w(int e, int f){
	if(e==1) return f;
	else if(f==0 || f==1) return f;
	if(dp[e][f]!=0) return dp[e][f];
	else {
		int min=INT_MAX, temp, temp2, max;
		for(int i=1; i<=f; i++){
			max=INT_MIN;
			temp=w(e-1, i-1);
			temp2=w(e, f-i);
			if(temp>temp2) max=temp;
			else max=temp2;
			if(max<min) min=max;
		}
		return dp[e][f]=1+min;		
	}
}
int main(){
	int e, f;
	memset(dp, 0, sizeof(dp));
	cin>>e>>f;	
	cout<<w(e,f)<<endl;
	for(int i=1; i<=e; i++){
		for(int j=1; j<=f; j++){
			cout<<dp[i][j]<<"| ";
		}
		cout<<"\n";
	}
	return 0;
}
