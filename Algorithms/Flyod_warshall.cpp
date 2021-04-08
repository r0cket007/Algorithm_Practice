/*
	Flyod Warshall Negative Cycle Detection
	Time Complexity -> O( V^3 )
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
#define INF INT_MAX
#define V 4

bool floyd_warshall( int graph[ ][ V ] )
{
	int dist[ V ][ V ] ;
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			dist[ i ][ j ] = graph[ i ][ j ] ;
		}
	}

	for( int k = 0 ; k < V ; k ++ )
	{
		for( int i = 0 ; i < V ; i ++ )
		{
			for( int j = 0 ; j < V ; j ++ )
			{
				if( dist[ i ][ k ] + dist[ k ][ j ] < dist[ i ][ j ] )
				{
					dist[ i ][ j ] = dist[ i ][ k ] + dist[ k ][ j ] ;
				}
			}
		}
	}


	for (int i = 0; i < V; ++i)
	{
		if( dist[ i ][ i ] < 0 )
		{
			return true ;
		}
	}
	return false ;

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
	    int graph[V][V] = { {0   , 1   , INF , INF},
                    {INF , 0   , -1  , INF},
                    {INF , INF , 0   ,  -1},
                    {-1  , INF , INF ,   0}};

        cout << ( floyd_warshall( graph ) ? "YES" : "NO" ) ;

		cout << endl ;
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}