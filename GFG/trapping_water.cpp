/*
	Trapping Rain Water 
	Link - https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
	
	Q. Given an array arr[] of N non-negative integers representing the 
	   height of blocks. If width of each block is 1, compute how much 
	   water can be trapped between the blocks during the rainy season. 
	
	---------
	Input:
	N = 6
	arr[ ] = {3,0,0,2,0,4}
	
	Output:
	10
	---------
	Input:
	N = 3
	arr[] = {6,9,9}
	
	Output:
	0
	----------
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)


	-Two pointer approach
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;


//Function
int trappingWater(int arr[], int n)
{
    int water_stored = 0 ;
    int left = 0  , right = n - 1 ;
    while( left < right )
    {
        if( arr[ left ] < arr[ right ] )
        {
            int prev = arr[ left ] ;
            while( left < right && arr[ left ] <= prev )
            {
                water_stored += ( prev - arr[ left ] ) ;
                left ++ ;
            }
        }
        else
        {
            int prev = arr[ right ] ;
            while( right > left && arr[ right ] <= prev )
            {
                water_stored += ( prev - arr[ right ] ) ;
                right -- ;
            }
        }
    }
    return water_stored ;
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
		int arr[ n ] ;
		for( int i = 0 ; i < n ; i ++ )
		{
			cin >> arr[ i ] ;
		}
		cout << trappingWater( arr, n ) ;
		cout << endl ;
	}
	return 0 ;
}