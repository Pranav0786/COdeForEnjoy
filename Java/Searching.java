public class Searching {
    public static void main(String[] args) {
        
    }

    // Linear search function -------------- TC O(n)
    // static boolean linear_search( String s , char ch ){
    //     if( s.length() == 0 )
    //         return false ;
    //     for (int i = 0; i < s.length(); i++) {
    //         if( ch == s.charAt(i) )
    //             return true ;
    //     }
    //     return false ;
    // }

    // Linear search in 2D Arrays -------------- TC o(n*m)
    // static int[] search( int[][] arr , int key ){
    //     for (int i = 0; i < arr.length; i++) {
    //         for (int j = 0; j < arr[i].length; j++) {
    //             if( arr[i][j] == key )
    //                 return new int[]{i,j} ;
    //         }
    //     }
    //     return new int[]{-1,-1} ;
    // }

    // Binary Search ------------------ TC O(log(n))
    // static boolean binary_search( int []arr , int key , int s  , int e ){
    //     while( s <= e ){
    //         int mid = s/2 + e/2 ;
    //         if( key == arr[mid] )
    //             return true ;
    //         else if( key < arr[mid] )
    //             e = mid - 1 ;
    //         else
    //             s = mid +1 ;
    //     }
    //     return false ;
    // }

    // Binary Search on InfiniteArray----------- TC O(log(n) * log(n))
    // static int ans( int[] arr , int key ){
    //     // find range
    //     int s = 0 ;
    //     int e = 3 ;
    //     // condition
    //     while( key > arr[e] ) {
    //         int start = e +1 ;
    //         e = e + (e-s+1)*2 ;
    //         s = start ;
    //     }
    //     return InfiniteArray(arr, key, s, e) ;
    // }
    // static int InfiniteArray( int[] arr , int key , int s , int e){
    //     while( s <= e ){
    //         int mid = s/2 + e/2 ;
    //         if( key == arr[mid] )
    //             return mid ;
    //         else if( key < arr[mid] )
    //             e = mid - 1 ;
    //         else
    //             s = mid +1 ;
    //     }
    //     return -1 ;
    // }



    // 744. Find Smallest Letter Greater Than Target
    // class Solution {
    //     public char nextGreatestLetter(char[] letters, char target) {
    //         int s = 0;
    //         int e = letters.length - 1;
    //         while (s <= e) {
    //             int mid = s + (e - s) / 2;
    //             if (target < letters[mid]) {
    //                 e = mid - 1;
    //             } else {
    //                 s = mid + 1;
    //             }
    //         }
    //         return letters[s % letters.length];
    //     }
    // }
    

    // 34. Find First and Last Position of Element in Sorted Array
    // class Solution {
    //     public int[] searchRange(int[] nums, int target) {
    //         int[] ans = {-1,-1} ;
    //         int low = search( nums , target , true ) ;
    //         int high = search( nums , target , false ) ;
    //         ans[0] = low ;
    //         ans[1] = high ;
    //         return ans  ;
    //     }
    //     int search( int[] nums , int target , boolean start ){
    //         int ans = -1 ;
    //         int s = 0 ; int e = nums.length -1 ;
    //         while( s <= e ){
    //             int mid = s + (e-s)/2 
    //             if( target == nums[mid] ){
    //                 ans = mid ;
    //                 if( start )
    //                     e = mid -1 ;
    //                 else
    //                     s = mid +1 ;
    //             }
    //             else if( target < nums[mid])
    //                 e = mid -1 ;
    //             else
    //                 s = mid +1 ;
    //         }    
    //         return ans ;
    //     }
    // }


    // 852. Peak Index in a Mountain Array
    // class Solution {
    //     public int peakIndexInMountainArray(int[] arr) {
    //         int s = 0 ;
    //         int e = arr.length - 1 ;
    //         while( s < e )
    //         {
    //             int mid = s + (e-s)/2 ;
    //             if( arr[mid] > arr[mid+1]) // decresing part
    //                 e = mid ;
    //             else
    //                 s = mid +1 ;
    //         }
    //         return s ;
    //     }
    // }


    // 1095. Find in Mountain Array
    // class Solution {
    //     public int findInMountainArray(int target, MountainArray mountainArr) {
    //         int peak = peak_element( mountainArr ) ;
    //         int first = binary_search(mountainArr , target , 0 , peak ) ;
    //         if( first != -1 )
    //             return first ;
    //         else
    //             return binary_search( mountainArr , target , peak+1 , mountainArr.length() -1) ;
    //     }
    //     static int binary_search( MountainArray arr , int key , int s  , int e ){
    //         while( s <= e ){
    //             int mid = s/2 + e/2 ;
    //             if( key == arr.get(mid) )
    //                 return mid ;
    //             else if( key < arr.get(mid) )
    //                 e = mid - 1 ;
    //             else
    //                 s = mid +1 ;
    //         }
    //         return -1 ;
    //     }
    //     public int peak_element(MountainArray mountainArr){
    //         int s = 0 ;
    //         int e = mountainArr.length() -1 ;
    //         while( s < e ){
    //             int mid = s + (e-s)/2 ;
    //             if( mountainArr.get(mid) > mountainArr.get(mid) )
    //                 e = mid ;
    //             else 
    //                 s = mid +1 ;
    //         }
    //         return s ;
    //     }
    // }


    // 33. Search in Rotated Sorted Array
    // class Solution {
    //     public int search(int[] nums, int target) {
    //         int peak = get_peak( nums ) ;
    //         if( peak == -1 ){
    //             return binary_search(nums , target , 0 , nums.length -1  ) ;
    //         }
    //         // if peak is found
    //         if( nums[peak] == target )
    //             return peak ;
    //         else if( target >= nums[0] )
    //             return binary_search( nums , target , 0 , peak-1 ) ;
    //         else
    //             return binary_search( nums , target , peak+1 , nums.length -1 ) ;
    //     }
    //     public int binary_search( int[] arr , int target , int s , int e ){
    //         while( s <= e ){
    //             int mid = s + (e-s)/2 ;
    //             if (target < arr[mid]) 
    //                 e = mid - 1;
    //             else if (target > arr[mid]) 
    //                 s = mid + 1;
    //             else
    //                 return mid;
    //         }
    //         return -1;
    //     }
    //     public int get_peak( int[] nums ){
    //         int s = 0 ;
    //         int e = nums.length -1 ;
    //         while( s <= e )
    //         {
    //             int mid = s+ (e-s)/2 ;
    //             if( mid < e && nums[mid] > nums[mid+1] )
    //                 return mid ;
    //             if( mid > s && nums[mid] < nums[mid -1] )
    //                 return mid-1 ;
    //             if( nums[mid] <= nums[s] )
    //                 e = mid -1 ;
    //             else
    //             s = mid +1 ;  
    //         }
    //         return -1 ;
    //     }
    // }
    

    // Rotation Count
    // public static int Rotation_Count( int[] arr ){
    //     // int pivot = get_peak( arr ) ;
    //     if( pivot != -1 ){
    //         // arr is not rotated
    //         return 0 ;
    //     }
    //     return pivot +1 ;
    // }

    
    // 410. Split Array Largest Sum
    // class Solution {
    //     public int splitArray(int[] nums, int k) {
    //         int s =  0 ;
    //         int e = nums.length -1 ;
    //         for( int i = 0 ; i < nums.length ; i++ )
    //         {
    //             s = Math.max(s , nums[i] ) ;
    //             e += nums[i] ;
    //         }
    //         // binary search
    //         while( s < e )
    //         {
    //             int mid = s + (e-s)/2 ;
    //             // calculate how many pieces 
    //             int sum = 0 ;
    //             int pieces = 1 ;
    //             for( int num : nums )
    //             {
    //                 if( sum + num > mid )
    //                 {
    //                     // cant add
    //                     sum = num ;
    //                     pieces++ ;
    //                 }
    //                 else
    //                     sum += num ;
    //             }
    //             if( pieces > k )
    //                 s = mid +1 ;
    //             else
    //                 e = mid ;
    //         }
    //         return e ;
    //     }
    // }


    // ------------ BinarySearch in 2D Arrays----------------
    
    // static int[] binary_search_matrix( int[][] arr  , int target ){
    //     int r = 0  ;
    //     int c = arr.length -1  ;
    //     while( r < arr.length && c >= 0 )
    //     {
    //         if(arr[r][c] == target )
    //             return new int[]{r,c} ;
    //         else if(arr[c][r] < target )
    //             r++ ;
    //         else 
    //             c-- ;
    //     }
    //     return new int[] {-1,-1} ;
    // }

    
    
}