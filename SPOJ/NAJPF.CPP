/*
LINK : https://www.spoj.com/problems/NAJPF/

INPUT :
3
ababab ab
aaaaa bbb
aafafaasf aaf

OUTPUT:
3
1 3 5 

Not Found


1
1 

*/

// RABIN KARP SEARCHING ALGO 
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

void solve( string &s , string &t )
{
	vector< int > ans ;
	int p = 31 ;
	int m = 1e9 + 7 ;
	int S = s.length( ) , T = t.length( ) ;
	std::vector<int> pow_p( max( S , T ) ) ;
	pow_p[ 0 ] = 1 ;
	
	// polynomial rolling function 
	for (int i = 1; i < pow_p.size( ) ; ++i)
	{
		pow_p[ i ] = ( pow_p[ i - 1 ] * p ) % m ;
	}
	std::vector<int> ht( T + 1 , 0 ) ;

	// hash for all prefix of text ( t ) 
	for (int i = 0; i < T ; ++i)
	{
		ht[ i + 1 ] = ( ht[ i ] + ( t[ i ] - 'a' + 1 ) * pow_p[ i ] ) % m ; 
	}

	// hash for s
	int hs = 0 ;
	for (int i = 0; i < S; ++i)
	{
		hs = ( hs + ( s[ i ] - 'a' + 1 ) * pow_p[ i ] ) % m ;
	}

	// get hash of hash( i , j ) by ( hash[ 0 , j ] - hash[ 0 , i - 1 ] ) % m 
	for( int i = 0 ; i + S - 1 < T ; i ++ )
	{
		int curr = ( ht[ i + S ] + m - ht[ i ] ) % m ;
		if( curr == ( hs * pow_p[ i ] ) % m  )
		{
			ans.push_back( i ) ;
		}
	}


	if( ans.size( ) == 0 )
	{
		cout << "Not Found\n" ;
	}
	else 
	{
		cout << ans.size( ) << endl ;
		for( auto i : ans )
		{
			cout << i + 1 << " " ;
		}
	}
	cout << endl ;

}


signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	cin >> testcases ;
	while( testcases -- )
	{
		int n ;
		// cin >> n ;
		string s , t ;
		cin >> t >> s ;
		solve( s , t ) ;
		cout << endl ;


	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}
