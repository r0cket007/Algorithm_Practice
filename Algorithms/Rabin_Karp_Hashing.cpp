#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

int m = 1e9 + 7 ;
int p = 31 ;


void RKA( const string &txt , const string &pat ) 
{

    int t = txt.length( ) ;
    int s = pat.length( ) ;
    int n = max( s , t ) ;
    std::vector<int> pow_p( n , 0 );
    pow_p[ 0 ] = 1 ;
    for (int i = 1; i < n; ++i)
    {
        pow_p[ i ] = ( pow_p[ i - 1 ] * p ) % m ;
    }
    int hash_txt[ t + 1 ] = { 0 } ;

    for (int i = 0; i < t; ++i)
    {
        hash_txt[ i + 1 ] = ( hash_txt[ i ] + ( txt[ i ] - 'a' )*pow_p[ i ] ) % m ;
    }

    int hash_pat = 0 ;

    for( int i = 0 ; i < s ; i ++ )
    {
        hash_pat = ( hash_pat + ( pat[ i ] - 'a')* pow_p[ i ] ) % m ;
    }

    for (int i = 0; i + s - 1 < t ; ++i)
    {
        int curr_hash = ( hash_txt[ i + s ] + m - hash_txt[ i ] ) % m;
        if( curr_hash == ( hash_pat * pow_p [ i ] ) % m )
        {
            cout << "YES" ;
            return ;
        }
    }
    cout << "NO" ;
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
        string s , t ;
        cin >> s >> t ;
        RKA( s , t ) ; 
        cout << endl ;
    }
    cerr << "SUCCESS\n" ;
    return 0 ;
}