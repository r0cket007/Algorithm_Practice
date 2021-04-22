/*
	TRIPLET SUM IN AN ARRAY 
	Expected Time Complexity: O(n2)
	Expected Auxiliary Space: O(1)

	Q.Given an array arr of size n and an integer X. 
	Find if there's a triplet in the array which sums up to the given integer X.

	Input:
	n = 6, X = 13
	arr[] = {1,4,45,6,10,8}
	
	Output:
	1

	Explanation:
	The triplet {1, 4, 8} in 
	the array sums up to 13.
*/


#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

//Function
bool exsist( int arr[ ] , int left , int right , int value )
{
    while( left < right )
    {
        if( arr[ left ] + arr[ right ] == value )
        {
            return true ;
        }
        if( arr[ left ] + arr[ right ] > value )
        {
            right -- ;
        }
        else
        {
            left ++ ;
        }
    }
    return false ;
}
     
bool find_triplet(int A[], int n, int X)
{
    sort( A , A + n ) ;
    int answer = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        answer += exsist( A , i + 1 , n - 1 , X - A[ i ] ) ;    
    }
    return answer ;
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
		int x ;
		cin >> x ;
		int arr[ n ] ;
		for( int i = 0 ; i < n ; i ++ )
		{
			cin >> arr[ i ] ;
		}
		// cout << find_triplet( arr , n , x );
		cout << endl ;
	}
	cerr << "DONE" ;
	return 0 ;
}