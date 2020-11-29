//Longest Palindrome SubString
#include<iostream>
#include<stdio.h>
using std::cout;
using std::endl;
using std::cin;
class LSP
{
		char* str;
		int len;
	public:
		LSP()
		{
			str=new char[10];
		}
		void getInput()
		{
			cout<<"\nEnter a String --> ";
			cin>>str;
			int i=0;
			while(str[i++]);
			len=i-1;
		}
		void solve()
		{
			int** table=new int*[len];
			for(int i=0;i<len;i++)
				table[i]=new int[len];
			for(int i=0;i<len;i++)
				table[i][i]=1;
			int min1=0,max1=0;
			for(int i=0;i<len-1;i++)
				if(str[i]==str[i+1])
				{
					table[i][i+1]=1;
					min1=i;
					max1=i+1;
				}
			int start=0, end=2;
			int prevEnd=end-1;
			int c=0;
			while(c!=len-2)
			{
				end=prevEnd+1;
				for(;end<len;end++,start++)
				{
					if(str[start]==str[end] && table[start+1][end-1]==1)
					{
						table[start][end]=1;
						min1=start;
						max1=end;
					}
				}
				c++;
				start=0;
				prevEnd++;
			}
			cout<<"Longest Palindrome SubString is :: ";
			for(;min1<=max1;min1++)
				cout<<str[min1];
			cout<<endl<<endl;
		}
};
main()
{
	LSP lsp;
	lsp.getInput();
	lsp.solve();
}
