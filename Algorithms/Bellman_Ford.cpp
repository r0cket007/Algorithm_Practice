/*
	Bellman Ford Algorithm
	Time Complexity -> O( V * E )
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

void BellmanFord( int graph[ ][ 3 ] , int V , int E , int src )
{
	int distance[ V ] ;
	for( auto &i : distance )
	{
		i = INT_MAX ;
	}
	distance[ src ] = 0 ; 
	for( int i = 0 ; i < V - 1 ; i ++ )
	{
		for( int j = 0 ; j < E ; j ++ )
		{
			if( distance[ graph[ j ][ 0 ] ] != INT_MAX && distance[ graph[ j ][ 0 ] ] + graph[ j ][ 2 ] < distance[ graph[ j ][ 1 ] ] )
			{
				distance[ graph[ j ][ 1 ] ] = distance[ graph[ j ][ 0 ] ] + graph[ j ][ 2 ] ;
			}
		}
	}

	//to check negative cycle
	for( int i = 0 ; i < E ; i ++ )
	{
		if( distance[ graph[ i ][ 0 ] ] != INT_MAX && distance[ graph[ i ][ 0 ] ] + graph[ i ][ 2 ] < distance[ graph[ i ][ 1 ] ] )
		{
			cout << "Negative cycle Present" ;
			return ;
		}
	}
	for( int i = 0 ; i < V ; i ++ )
	{
		cout << i << " " << distance[ i ] << endl;
	}

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
		int V = 5; 
	    int E = 8; 
	    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
		                       { 1, 2, 3 }, { 1, 3, 2 },
		                       { 1, 4, 2 }, { 3, 2, 5 },
		                       { 3, 1, 1 }, { 4, 3, -3 } };
		BellmanFord( graph , 5 , 8 , 0 );
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}
/*
0 0
1 -1
2 2
3 -2
4 1
*/