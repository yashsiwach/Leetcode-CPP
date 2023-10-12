class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Step 1: Find the peak index using binary search
        int peakIndex = findPeak(mountainArr, 0, n - 1);
        
        // Step 2: Search for the target in the ascending and descending subarrays
        int ascendingResult = binarySearchAscending(target, mountainArr, 0, peakIndex);
        if (ascendingResult != -1) {
            return ascendingResult;
        }
        
        int descendingResult = binarySearchDescending(target, mountainArr, peakIndex, n - 1);
        
        // Step 3: Return the result
        return descendingResult;
    }
    
    // Binary search to find the peak element (maximum)
    int findPeak(MountainArray &mountainArr, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    // Binary search in the ascending subarray
    int binarySearchAscending(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    // Binary search in the descending subarray
    int binarySearchDescending(int target, MountainArray &mountainArr, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid;
            } else if (midValue > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
