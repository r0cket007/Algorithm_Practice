/*
	Prim's Minimum Spanning Tree Problem
	Time Complexity -> O( V^2 )
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
#define inf INT_MAX
#define V 5

int find_min( bool visited[ ] , int distance[ ] )
{
	int mx = inf ;
	int min_idx = -1 ;
	for (int i = 0; i < V; ++i)
	{
		if( !visited[ i ] && mx > distance[ i ] )
		{
			mx = distance[ i ] ;
			min_idx = i ;
		}
	}
	visited[ min_idx ] = true ;
	return min_idx ; 
}

bool prims_algo( int graph[ ][ V ] )
{
	int parent[ V ] = { -1 } ;
	bool visited[ V ] = { false } ;
	int distance[ V ] = { 0 } ;
	for( int i = 1 ; i < V ; i ++ )
	{
		distance[ i ] = inf ;
	}

	for( int count = 0 ; count < V - 1 ; count ++ )
	{
		int u = find_min( visited , distance ) ;
		for (int v = 0; v < V; ++v )
		{
			if( graph[ u ][ v ] && !visited[ v ] && graph[ u ][ v ] < distance[ v ] )
			{
				parent[ v ] = u ;
				distance[ v ] = graph[ u ][ v ] ; 
			} 
		}
	}

	for( int i = 1 ; i < V ; i ++ )
	{
		cout << parent[ i ] << " " << i << "-" << graph[ parent[ i ] ][ i ] << endl ; 
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
	    /* Let us create the following graph 
	        2 3 
	    (0)--(1)--(2) 
	    | / \ | 
	    6| 8/ \5 |7 
	    | / \ | 
	    (3)-------(4) 
	            9     
	    */
	    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                            { 2, 0, 3, 8, 5 }, 
                            { 0, 3, 0, 0, 7 }, 
                            { 6, 8, 0, 0, 9 }, 
                            { 0, 5, 7, 9, 0 } 
                          }; 
        prims_algo( graph ) ;
		cout << endl ;
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}