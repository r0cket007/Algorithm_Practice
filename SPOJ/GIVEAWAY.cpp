
// Link : https://www.spoj.com/problems/GIVEAWAY/
/*

INPUT 
5
1 2 3 4 5
3
0 1 5 10
1 2 20
0 1 3 10


OUTPUT 
0
1

CONCEPT: BINARY SEARCH , SQRT DECOMPOSITION 
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen( "input.txt","r",stdin ) ;
#define out freopen( "output.txt","w",stdout ) ;
#define r0cket007 in out 
using namespace std ;
int n , blk_idx , blk_sz ;
std::vector<int> v ;
std::vector< std::vector<int> > block( 1000 ) ;

void preprocess( )
{
	blk_idx = -1 ;
	blk_sz = sqrt( n ) ;
	for (int i = 0; i < n; ++i)
	{
		if( i % blk_sz == 0 )
		{
			if( blk_idx != -1 ) 
				sort( block[ blk_idx ].begin(), block[ blk_idx ].end() ) ;
			blk_idx ++ ;
		}
		block[ blk_idx ].push_back( v[ i ] ) ;
	}
}


void update( int a , int b )
{
	int block_no = a / blk_sz ;
	int temp = v[ a ] ;
	int pos = lower_bound( block[ block_no ].begin(), block[ block_no ].end(), temp ) - block[ block_no ].begin( ) ;
	block[ block_no ][ pos ] = b ;
	v[ a ] = b ;
	sort( block[ block_no ].begin(), block[ block_no ].end() ) ;
}


int Query( int l , int r , int c )
{

	int ans = 0 ;
	while( l < r && l % blk_sz != 0 && l != 0 )
	{
		if( v[ l ] >= c )
		{
			ans ++ ;
		}
		l ++ ;
	}
	while( l + blk_sz <= r )
	{
		int pos = lower_bound( block[ l / blk_sz ].begin( ) , block[ l / blk_sz ].end( ) , c ) - block[ l / blk_sz ].begin( );
		ans += block[ l / blk_sz ].size( ) - pos ;
		l += blk_sz ;
	}
	while( l <=r )
	{
		if( v[ l ] >= c )
		{
			ans ++ ;
		}
		l ++ ;
	}
	return ans ;
}


signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		cin >> n ;
		for( int i = 0 ; i < n ; i ++ )
		{
			int a ;
			cin >> a ;
			v.push_back( a ) ;
		}
		preprocess();
		int q ;
		cin >> q ;
		while( q -- )
		{
			int query , a , b , c ;
			cin >> query ;
			if( !query )
			{	
				cin >> a >> b >> c ;
				a -- , b-- ;
				cout << Query( a , b , c ) << endl ;
			}
			else
			{
				cin >> a >> b ;
				a -- ;
				update( a , b ) ;
			}
		}
		// cout << endl ;
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}
