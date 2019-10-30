#include<bits/stdc++.h>
#define ll long long
#define lld long long double
#define pb push_back
#define mp make_pair
using namespace std;
int solve(int a[],int n){
	if(n<=2) return n;
	int dp[n][n];
	int llap=2;
	for(int i=0;i<n;i++) dp[i][n-1]=2;
	for(int j=n-2;j>=1;j--){
		int i=j-1,k=j+1;
		while(i>=0 && k<=n-1){
			if(a[i]+a[k]<2*a[j]) k++;
			else if(a[i]+a[k]>2*a[j]){
				dp[i][j]=2; i--;
			}
			else{
				dp[i][j]=dp[j][k]+1;
				llap=max(llap,dp[i][j]);
				i--; k++;
			}
		}
		while(i>=0){
			dp[i][j]=2;
			i--;
		}
	}
   return llap;
}
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++) cin>>a[i];
      cout<<solve(a,n)<<endl;
    }
	return 0;
}