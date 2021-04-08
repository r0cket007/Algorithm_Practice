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
public:
    Graph( int v )
    {
        this->v = v ;
        adj = new std::vector<int>[ this->v ];
        visited = new bool[ this->v ] ;
        for( int i = 0 ; i < v ; i ++ )
        {
            visited[ i ] = false ;
        }
    }
    bool addEdge( int s , int d )
    {
        adj[ s ].push_back( d ) ;
        adj[ d ].push_back( s ) ;
    } 
    bool isCyclic( int x , int parent = -1 )
    {

        visited[ x ] = true ;
        for( auto i : adj[ x ] )
        {
            if( !visited[ i ]  )
            {
                if( isCyclic( i , x ) ) 
                    return true ;
            }
            else if( parent != i )
            {
                return true ;
            }
        }
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
        // cout << 1 ;
        Graph g1(5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);
        cout << ( g1.isCyclic( 0 ) ? "YES" : "NO" );
        cout << endl ;
        Graph g2(3);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        cout << ( g2.isCyclic( 0 ) ? "YES" : "NO" );
    }
    cerr << "SUCCESS\n" ;
    return 0 ;
}
