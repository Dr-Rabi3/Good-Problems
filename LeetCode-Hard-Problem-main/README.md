# LeetCode-Daily-Chanalge

## problem (790. Domino and Tromino Tiling)
![image_1519740030](https://user-images.githubusercontent.com/91884590/209445904-3824e74e-5c41-4b96-8423-811dafcdbc8f.png)


## problem (918. Maximum Sum Circular Subarray)

# Approach
  There are 2 possibility of The maximum subarray sum in circular array

# 1.Maximum subarray sum in non circular array
  If max subarray sum in non circular array then we can simply apply Kadane's Algorithm and we will calculate the max_sum_subarray
  Example A=[-3,-5,3,5,7,3,5,-9] ans= 23

# 2.Maximum subarray sum in circular array.
  If max subarray sum in circular array then we will calculate the minimum sum of subarray and Subtract it from total_sum of array.
  Example A=[11,1,-17,2,-15,9,13]
  ![7ef7d266-0bc5-41d0-9c75-44b77a1f9000_1674004416 8592637](https://user-images.githubusercontent.com/91884590/213264514-6c1e555a-232c-4f16-85e7-5a627f737dd0.png)
  Here we will remove {17,2,-15} from our total sum that will give us max subarray sum because max sum include some prefix and suffix part:-
  Ans= max(prefix+suffix)
  Ans= max(total sum - subarray)
  Ans=total sum + max(-subarray)
  Ans= total sum - min(subarray)
# 3.Corner case -When all the element in the array are negative then our answer will be max_sum_subarray because if when all the element are negative at that time our      total_sum - minsum_subary=0
   and it will return 0 means empty subarray thats why we will return max sum of subarray

# 4.At last we will return
    max(subarray sum in non circular array,Maximum subarray sum in circular array)

## 974. Subarray Sums Divisible by K
      // Take modulo twice to avoid negative remainders.
      cursum = (cursum + num % k + k) % k;
      
