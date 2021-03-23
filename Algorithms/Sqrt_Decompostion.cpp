#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int block[ 1001 ] ;
int blk_size = 0 ;
int blk_idx = -1 ;

void preprocess( std::vector<int> &v , int n )
{
    blk_size = sqrt( n ) ;
    for (int i = 0; i < n; ++i)
    {
        if( i % blk_size == 0 )
        {
            blk_idx ++ ;
        }
        block[ blk_idx ] += v[ i ] ;
    }
}

void update( std::vector<int> &v, int loc , int val )
{
    int block_no = loc / blk_size ;
    block[ block_no ] -= v[ loc ] ;
    block[ block_no ] += val ;
    v[ loc ] = val ;
}


int Query( std::vector<int> &v ,int l , int r )
{
    int sum = 0 ;
    while( l % blk_size != 0 && l <= r )
    {
        sum += v[ l ++ ] ;
    }
    int block_no = l / blk_size ;
    while( l + blk_size <= r )
    {
        sum += block[ block_no ++ ] ;
        l += blk_size ;
    }
    while( l <=r ) 
    {
        sum += v[ l ++ ] ;
    }
    return sum ;
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
        int n ;
        cin >> n ;
        std::vector<int> v( n );
        
        for (int i = 0; i < n; ++i)
        {
            cin >> v[ i ] ;
        }

        preprocess( v , n ) ;
        int q ;

        cin >> q ;
        while( q-- )
        {
            int query , l ,r ;
            cin >> query ; 
            cin >> l >> r ;
            if( !query )
            {
                update( v , l , r ) ;

            }
            else 
                cout << Query( v , l  , r  ) << endl ;
        }
        cout << endl ;
    }
    cerr << "SUCCESS\n" ;
    return 0 ;
}