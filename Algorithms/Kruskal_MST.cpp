/*
	Kruskal's Minimum Spanning Tree Problem
	Time Complexity -> O( VlogE )
*/

#include<bits/stdc++.h>
#define int long long
using namespace std ;

class Graph
{
	int V ;
	std::set< pair< int , pair<int,int> > > adj;
	int *parent ;
	bool *visited ;
	int *rank ;
public:
	Graph( int V )
	{
		this->V = V ;
		parent = new int[ this->V ] ;
		visited = new bool[ this->V ] ;
		rank = new int[ this->V ] ;
		for( int i = 0 ; i < this->V ; i ++ )
		{
			parent[ i ] = i ;
			visited[ i ] = false ;
			rank[ i ] = 0 ;
		}
	}
	void add_edge( int u , int v , int w )
	{
		if( v < u )
			swap( u , v ) ;
		adj.insert( { w , { u , v } } );
	}
	pair< int , pair< int , int > > get_edge( )
	{
		auto i = *adj.begin( ) ;
		adj.erase( adj.begin( ) ); 
		return i ;
	}
	int find( int x )
	{
		if( parent[ x ] == x )
			return x ;
		parent[ x ] = find( parent[ x ] );
		return parent[ x ] ;
	}
	void Union( int x , int y )
	{
		int xp = find( x ) ;
		int yp = find( y ) ;
		if( xp == yp )
			return ;
		if( rank[ xp ] != rank [ yp ] )
		{
			if( rank[ xp ] > rank[ yp ] )
				swap( xp , yp ) ;
			parent[ xp ] = yp;
		}
		else
		{
			rank[ xp ] ++ ;
			parent[ xp ] = yp ;
		}
	}
};
void Kruskal( int V , Graph &g )
{
	int e = 0 ;
	std::vector< pair<pair<int,int>,int> > ans;
	while( e != V - 1 )
	{
		auto val = g.get_edge( ) ;
		int w = val.first ;
		int u = val.second.first ;
		int v = val.second.second ; 
		int parent_x = g.find( u ) ;
		int parent_y = g.find( v ) ;
		if( parent_x != parent_y )
		{
			g.Union( parent_y , parent_x ) ;
			ans.push_back( { { u , v } , w } );
			e ++ ;
		}
	}
	sort( ans.begin(), ans.end() );
	for( auto i : ans )
	{
		cout << i.first.first << " " << i.first.second << " == " << i.second << endl ;
	}
}
signed main( )
{

	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		int n ;
		int V = 9 ;
		Graph g( V ) ;
		g.add_edge( 0 , 1 , 4 ) ;
		g.add_edge( 0 , 7 , 8 ) ;
		g.add_edge( 1 , 7 , 11 ) ;
		g.add_edge( 2 , 1 , 8 ) ;
		g.add_edge( 2 , 3 , 7 ) ;
		g.add_edge( 7 , 8 , 7 ) ;
		g.add_edge( 7 , 6 , 1 ) ;
		g.add_edge( 6 , 8 , 6 ) ;
		g.add_edge( 2 , 8 , 2 ) ;
		g.add_edge( 6 , 5 , 2 ) ;
		g.add_edge( 4 , 5 , 10 ) ;
		g.add_edge( 3 , 4 , 9 ) ;
		g.add_edge( 5 , 3 , 15 ) ;
		g.add_edge( 2 , 5 , 4 ) ;
		Kruskal( V  , g ) ;	
	}
	cerr << "SUCCESS\n" ;
	return 0 ;
}