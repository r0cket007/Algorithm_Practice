#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

void KMP( const string& txt , const string &pat )			
{
	int t = txt.length( ) ;
	int S = pat.length( ) ;
	int n = S + t + 1 ;
	string s = pat + "#" + txt ;
	std::vector<int> LPS( n , 0 ) ;
	int j = 0 ;
	for( int i = 1 ; i < n ; i ++ )
	{
		while( j != 0 && s[ i ] != s[ j ] )
		{
			j = LPS[ j - 1 ] ;
		}
		if( s[ i ] == s[ j ] )
		{
			j ++ ;
		}
		LPS[ i ] = j ;
	}
	for( int i = 0 ; i < n ; i ++ )
	{
		if( LPS[ i ] == S )
		{
			cout << i - ( 2*S ) << " " ;
		}
	}
}

signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	while( testcases -- )
	{
		string txt , pat ;
		cin >> txt ;
		cin >> pat ;
		KMP( txt , pat ) ;
		cout << endl ;
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}