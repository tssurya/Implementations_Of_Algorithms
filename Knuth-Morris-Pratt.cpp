//Knuth Morris Pratt string matching algorithm
//complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

int F[100000];

void Compute_Prefix_Function(string pattern)
{
	F[0]=0;
	F[1]=0;
	int m=pattern.size()-1;
	int k=0;

	for(int q=2;q<=m;q++)
	{
		while(k>0 and pattern[q]!=pattern[k+1])
		{
			k=F[k];
		}
		if(pattern[q]==pattern[k+1])
		{
			k=k+1;
		}
		F[q]=k;
	}
	cout<<"The computed prefix function is\n";
	for(int i=1;i<=m;i++)
	{
		cout<<F[i]<<" ";
	}
	cout<<"\n";
}

void KMP_Matcher(string text, string pattern)
{
	int n= text.size()-1;
	int m= pattern.size()-1;
	int q=0;

	for(int i=1; i<=n; i++)
	{
		while(q>0 and pattern[q+1]!=text[i])
		{
			q=F[q];
		}
		if(pattern[q+1]==text[i])
		{
			q=q+1;
		}
		//cout<<q ;
		if(q==m)
		{
			cout<<"pattern found!\n";
			q=F[q];
		//	break;
		}
		
	}
}

int main()
{
	string pattern=" ",text=" ";
	string p,t;
	cin>>p;
	cin>>t;

	pattern+=p;
	text+=t;
	Compute_Prefix_Function(pattern);
	KMP_Matcher(text, pattern);
	return 0;
}
