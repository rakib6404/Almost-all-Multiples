#include <bits/stdc++.h>
using namespace std;
using 11 = long long;
using vi = vector<int>;
using v1 = vector<11>;
using vv1 = vector<v1>;
using vb = vector<bool>;
#define fast ios_base ::sync_with_stdio(0);cout.tie(0);
int main()
{
	fast;
	int t;
	cin>>t;
	while (t--){
		int n,x;
		cin>>n>>x;
		if (n%x !=0){
			cout<<-1<<"\n";
			continue;
		}
		int v =n/x;
		v1 pf;
		while (v>1){
			for (int i = 2;i<=v;i++){
				while (v%i == 0){
					pf.push_back(i);
					v/=i;
				}
			}
		}

		vb is(n+1,false);
		vi nextVal(n+1);
		vi vals;
		int cur = x;
		for (auto it:pf){
			is[cur] = true;
			nextVal[cur] =cur*it;
			cur *=it;
		}

		assert(cur== n);

		for (int i = 1;i<=n;i++){
			if(i == 1)
				cout<<x<<" ";
			else if (i== n)
				cout<<1<<" ";
			else if (is[i]){
				cout<<nextVal[i]<<" ";

			}
			else 
				cout<<i<<" ";
		}
		cout<<"\n";
	}

	return 0;
}