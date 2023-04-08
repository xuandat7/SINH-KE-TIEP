#include<bits/stdc++.h>
using namespace std;
int a[20], vs[20], n, minn = INT_MAX;
string ans[15];
vector<string> hv;
int count(string a, string b)
{
	int dd[26]={0};
	int dem=0;
	for(char ch : a)
	   dd[ch - 'A']++;
	for(char ch : b)
	   dd[ch - 'A']++;
	for(int x : dd)
	   if(x == 2)
	     dem++;
	return dem;
}
void dq(int i, int cut)
{
	if(i > n)
	{
		if(cut < minn)
		  minn = cut;
		return;
	}
	for(int j=1; j<=n; j++)
	{
		if(!vs[j])
		{
			int dem;
			if(hv.size() == 0)
			   dem = 0;
			else
			    dem = cut + count(hv.back(), ans[j]);
//			for(string x : hv)
//			cout<<x<<" ";
//			cout<<endl;
//			cout<<dem<<endl;
			if( dem  < minn)
			{
				vs[j] = 1;
				hv.push_back(ans[j]);
				dq(i+1,dem );	
				hv.pop_back();
				vs[j] = 0;
			}
		}
	}
}
int main ()
{
	
	cin>>n;
	for(int i=1; i<=n; i++)
	  cin>>ans[i];
	memset(vs, sizeof(vs), 0);
	dq(1, 0);
	cout<<minn;
	//cout<<count("ABCDEF", "ABCHTIK");
}
