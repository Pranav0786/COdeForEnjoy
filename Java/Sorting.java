public class Sorting {
    public static void main(String[] args) {
        
    }

    // Bubble Sort ---------- SC O(1) TC O(n*n) / (n)
    // static void Bubble_sort( int[] arr ){
    //     for (int i = 0; i < arr.length ; i++) {
    //         for (int j = 0 ; j < arr.length - i ; j++) {
    //             if( arr[j] > arr[j+1] ){
    //                 int temp = arr[j] ;
    //                 arr[j] = arr[j+1] ;
    //                 arr[j+1] = temp ;
    //             }
    //         }
    //     }
    // }

    // Selection Sort ---------- SC O(1) TC O(n*n) / (n*n)
    // static void Selection_sort( int[] arr ){
    //     for (int i = 0; i < arr.length; i++) {
    //         // find max element in remaining arr and placed on right pos
    //         int last = arr.length -i-1 ;
    //         int maxidx = getmax(arr , 0 , last ) ;
    //         swap(arr , maxidx , last) ;
    //     }
    // }
    // private static int getmax(int[] arr , int start , int end){
    //     int max = start ;
    //     for (int i = start+1; i <= end ; i++) {
    //         if(arr[max] < arr[i] ) 
    //             max = i ;
    //     }
    //     return max ;
    // }
    // static void swap( int[] arr , int first , int second ){
    //     int temp = arr[first] ;
    //     arr[first] = arr[second] ;
    //     arr[second] = temp ;
    // }

    // Insertion Sort ---------- SC O(1) TC 
    // static void Insertion_Sort( int[] arr ){
    //     for (int i = 0; i < arr.length - 1 ; i++) {
    //         for (int j = i+1; j > 0 ; j-- ) {
    //             if( arr[j] < arr[j-1] )
    //                 swap(arr , j , j-1) ;
    //             else    
    //                 break ;
    //         }
    //     }
    // }
    
    // Cycle Sort --------------- 
    // use when given range in 1 to n continue
    // static void Cycle_Sort( int[] arr ){
    //     int i = 0 ;
    //     while( i < arr.length ){
    //         int correct_idx = arr[i] -1 ;
    //         if( arr[i] != arr[correct_idx])
    //             swap( arr , i , correct_idx ) ;
    //         else
    //             i++ ;
    //     }
    // }
    // static void swap(int[] arr , int a , int b){
    //     int temp = arr[a] ;
    //     arr[a] = arr[b] ;
    //     arr[b] = temp ;
    // }

    
    // 268. Missing Number
    // class Solution {
    //     public int missingNumber(int[] nums) {
    //         int i = 0 ;
    //         while( i < nums.length ){
    //             if(nums[i] < nums.length && nums[i] != i && nums[i] != nums[nums[i]])
    //                swap(nums,i,nums[i]) ;
    //             else
    //                 i++ ;
    //         }
    //         for( int j = 0 ; j < nums.length ; j++ ){
    //             if( nums[j] != j )
    //                 return j ;
    //         }
    //         return nums.length ;    
    //     }
    //     public void swap(int[] nums ,int a, int b ){
    //         int temp = nums[a] ;
    //         nums[a] = nums[b] ;
    //         nums[b] = temp ;
    //     }
    // }

    // 448. Find All Numbers Disappeared in an Array
    // class Solution {
    //     public List<Integer> findDisappearedNumbers(int[] nums) {
    //         int i = 0 ;
    //         while( i < nums.length ){
    //             int c = nums[i] - 1 ;
    //             if(nums[i]!= nums[c])
    //                 swap(nums,i,c) ;
    //             else
    //                 i++ ;
    //         }
    //         List<Integer> ans = new ArrayList<>() ;
    //         for( int j = 0 ; j < nums.length ; j++ )
    //         {
    //             if( nums[j] != j+1 )
    //                 ans.add(j+1) ;
    //         }
    //         return ans ;
    //     }
    //     public void swap(int[]nums , int a , int b ){
    //         int temp = nums[a] ;
    //         nums[a] = nums[b] ;
    //         nums[b] = temp ;
    //     }
    // }

    // 287. Find the Duplicate Number
    // class Solution {
    //     public int findDuplicate(int[] nums) {
    //         int i = 0 ;
    //         while( i < nums.length ){
    //             if(nums[i] != i+1 )
    //             {
    //                 int c = nums[i] - 1 ;
    //                 if(nums[i]!= nums[c])
    //                     swap(nums,i,c) ;
    //                 else
    //                     return nums[i] ;
    //             }
    //             else
    //                 i++ ;
    //         }
    //         return -1 ;
    //     }
    //     public void swap(int[]nums , int a , int b ){
    //         int temp = nums[a] ;
    //         nums[a] = nums[b] ;
    //         nums[b] = temp ;
    //     }
    // }

    // 442. Find All Duplicates in an Array
    // class Solution {
    //     public List<Integer> findDuplicates(int[] nums) {
    //         int i = 0 ;
    //         List<Integer> ans = new ArrayList<>() ;
    //         while( i < nums.length ){
    //             int c = nums[i] - 1 ;
    //             if(  nums[i]!= nums[c])
    //                 swap(nums,i,c) ;
    //             else
    //                 i++ ;
    //         }
    //         for( int j = 0 ; j < nums.length ; j++ ){
    //             if(nums[j] != j+1 )
    //                 ans.add(nums[j]) ;
    //         }
    //         return ans ;
    //     }
    //     public void swap(int[]nums , int a , int b ){
    //             int temp = nums[a] ;
    //             nums[a] = nums[b] ;
    //             nums[b] = temp ;
    //         }
    // }

    // 41. First Missing Positive
    // class Solution {
    //     public int firstMissingPositive(int[] nums) {
    //         int i =0 ;
    //         while( i < nums.length ){
    //             int c = nums[i] -1 ;
    //             if( nums[i]>0 && nums[i]<=nums.length && nums[i]!= nums[c])
    //                 swap(nums,i,c) ;
    //             else
    //                 i++ ;
    //         }
    //         for( int j= 0 ; j < nums.length ; j++ ){
    //             if( nums[j] != j+1 )
    //                 return j+1;
    //         }
    //         return nums.length +1 ;
    //     }
    //     public void swap( int[] nums , int a ,int b ){
    //         int temp = nums[a] ;
    //         nums[a] = nums[b] ;
    //         nums[b]= temp ;
    //     }
    // }


    
}
