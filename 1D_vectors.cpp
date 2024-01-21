#include<bits/stdc++.h>

using namespace std;

// find the duplicate number in the unsorted array where there is a extra number present in it
// (LC-287)
// method 1: negative marking
int findDuplicate_1(vector<int> &nums){
    int ans = -1;
    for (int n : nums){
        int index = abs(n);
        if (nums[index] < 0){
            ans = index;
            break;
        }
        nums[index] *= -1;
    }
    return ans;
}
// method 2: swaping
int findDuplicate_2(vector<int> &nums){
    while (nums[0] != nums[nums[0]])
        swap(nums[0], nums[nums[0]]);
    return nums[0];
}

// missing number (LC-268)
int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int totalSum = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + nums[i];
    return totalSum - sum;
}

// first missing positive (LC-41)
int firstMissingPositive(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n; ++i){
        while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; ++i){
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

// find pivot index - (LC-724)
int pivotIndex(vector<int> &nums) {
    vector<int> rightSum(nums.size(), 0);
    vector<int> leftSum(nums.size(), 0);
    for(int i=1; i<nums.size(); ++i)
        leftSum[i] = leftSum[i-1] + nums[i-1];
    for(int i=nums.size()-2; i>=0; --i)
        rightSum[i] = rightSum[i+1] + nums[i+1];
    for(int i=0; i<nums.size(); ++i) {
        if(leftSum[i] == rightSum[i])
            return i;
    }
    return -1;
}

// sort colors (LC-75)
void sortColors(vector<int> &nums) {
    int zeroCount=0, oneCount=0, twoCount=0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0)
            zeroCount++;
        else if (nums[i] == 1)
            oneCount++;
        else
            twoCount++;
    }
    int i = 0;
    while (zeroCount--)
        nums[i++] = 0;
    while (oneCount--)
        nums[i++] = 1;
    while (twoCount--)
        nums[i++] = 2;
}

// remove duplicates from sorted array - (LC-26)
int removeDuplicates(vector<int> &nums) {
    int i = 1, j = 0;
    while (i < nums.size()) {
        if (nums[i] != nums[j])
            nums[++j] = nums[i];
        ++i;
    }
    return j + 1;
}

// kth missing positive number (LC-1539)
int findKthPositive(vector<int> &arr, int k) {
    // naive approach
    // int num[k];
    // int j=0,s=arr.size(),l=1,i=0;
    // while(k!=j && i<s){
    //     if(arr[i]!=l){
    //         num[j++]=l++;
    //     }
    //     else{
    //         i++;
    //         l++;
    //         if(i==s){
    //             i=i-1;
    //         }
    //     }
    // }
    // return num[k-1];

    // binary search approach
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] - mid - 1 < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left + k;
}

// find missing element int the sorted array
int find_missing(vector<int> &nums) {
    int left=0, right=nums.size()-1, ans=-1;
    while(left <= right) {
        int mid = left + ((right-left) >> 1);
        if(nums[mid] - mid != 1) {
            ans = mid;
            right = mid-1;
        }
        else 
            left = mid+1;
    }
    if(ans+1 == 0)
        return nums.size()+1;
    return ans+1;
}

// find peak element
int find_peak_element(vector<int> &nums) {
    int start=0, end=nums.size()-1;
    while(start < end) {
        int mid = start + ((end-start) >> 1);
        if(nums[mid] > nums[mid+1])
            end = mid;
        else 
            start = mid+1;
    }
    return nums[start];
}

// find first and last occurrence of a digit
int firstOccurrence(vector<int> &nums, int x, int n) {
    int s = 0, e = n - 1, ans = -1;
    while (s <= e) {
        int mid = s + ((e - s) >> 1);
        if (nums[mid] == x) {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return ans;
}
int lastOccurrence(vector<int> &nums, int x, int n) {
    int s = 0, e = n - 1, ans = -1;
    while (s <= e) {
        int mid = s + ((e - s) >> 1);
        if (nums[mid] == x) {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}
vector<int> find_occurrence(vector<int> &nums, int x) {
    int n = nums.size();
    vector<int> ans;
    int first = firstOccurrence(nums, x, n);
    int last = lastOccurrence(nums, x, n);
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

int main() {

    int n;
    cout << "enter the size of vector : ";
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i)
        cin >> nums[i];

    cout << "the duplicate number in this array is : " << findDuplicate_1(nums) << endl;
    cout << "the duplicate number in this array is : " << findDuplicate_2(nums) << endl;

    cout << "the missing number is this array is : " << missingNumber(nums) << endl;

    cout << "the first missing positive number in this array is : " << firstMissingPositive(nums) << endl;

    cout << "the pivot index of the given array is : " << pivotIndex(nums) << endl;

    sortColors(nums);
    cout << "here is your sorted colors : " << "[ ";
    for(int n:nums)
        cout << n << " ";
    cout << "]" << endl;

    cout << "after removing the duplicates the length of the given array should be : " << removeDuplicates(nums) << endl;

    int k;
    cout << "enter the value of [k] : ";
    cin >> k;
    cout << "the missing kth positive number from the given array is : " << findKthPositive(nums, k) << endl;

    cout << "the missing number in the given array is : " << find_missing(nums) << endl;

    cout << "the peak element in the given array is : " << find_peak_element(nums) << endl;

    int x;
    cout << "enter the repeated element : ";
    cin >> x;
    vector<int> result = find_occurrence(nums, x);
    cout << "first and last occurrence : " << "[ ";
    for(int r:result)
        cout << r << " ";
    cout << "]" << endl;

    return 0;
}