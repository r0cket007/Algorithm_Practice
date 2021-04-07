#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

class Graph
{
	int v ;
	std::vector<int> *adj;
	bool *visited ;
	bool *stack ; 
public:
	Graph( int v )
	{
		this->v = v ;
		adj = new std::vector<int>[ this->v ];
		visited = new bool[ this->v ] ;
		stack = new bool[ this->v ] ;
	}
	bool addEdge( int s , int d )
	{
		adj[ s ].push_back( d ) ;
		adj[ d ].push_back( s ) ;
	}
	bool isCyclic( int x )
	{
		if( !visited[ x ] )
		{
			visited[ x ] = true ;
			stack[ x ] = true ;
			for( auto i : adj[ x ] )
			{
				if( !visited[ i ] && isCyclic( i ) )
				{
					return true ;
				}
				else if( stack[ i ] == true)
				{
					return true ;
				}

			}

		}
		stack[ v ] = false ;
		return false ;
	}
};

signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
	    Graph g(4);
	    g.addEdge(0, 1);
	    g.addEdge(0, 2);
	    g.addEdge(1, 2);
	    g.addEdge(2, 0);
	    g.addEdge(2, 3);
	    g.addEdge(3, 3);
	    cout << ( g.isCyclic( 0 ) ? "YES" : "NO" );
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}