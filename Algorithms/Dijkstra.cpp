#include<bits/stdc++.h>
#define int long long
using namespace std ;
#define V 9


int find_min( int distance[ ] , bool visited[ ] )
{
    int mn = INT_MAX ;
    int pos = -1 ;
    for( int i = 0 ; i < V ; i++ )
    {
        if( mn > distance[ i ] && visited[ i ] == false )
        {
            pos = i ;
            mn = distance[ i ] ;
        }
    }
    visited[ pos ] = true ;
    return pos ;
}


void dijkstra( int graph[][V] , int src )
{
    int distance[ V ] = { 0 };
    bool visited[ V ] = { 0 } ;
    for( auto &i : distance )
    {
        i = INT_MAX ;
    }
    distance[ 0 ] = 0;
    for( int i = 0 ; i < V - 1 ; i ++ ) 
    {
        int s = find_min( distance , visited ) ;
        for( int j = 0 ; j < V ; j ++ )
        {
            if( !visited[ j ] && graph[ s ][ j ] != 0 && graph[ s ][ j ] + distance[ s ] < distance[ j ] )
            {
                distance[ j ] = distance[ s ] + graph[ s ][ j ] ;
            }
        }
    }
    for( int i = 0 ; i < V ; i ++ )
    {
        cout << i << " " << distance[ i ] << endl ;
    }
}

signed main( )
{

    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra( graph , 0 ) ;
    }
    cerr << "SUCCESS\n" ;
    return 0 ;
}

/*
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14
*/