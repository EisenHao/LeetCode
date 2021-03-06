/**
 * No34. 在排序数组中查找元素的第一个和最后一个位置
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 你的算法时间复杂度必须是O(log n) 级别。如果数组中不存在目标值，返回[-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myTools.h"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int size = nums.size();
        if (size < 2) {
            if (size == 1 && nums[0] == target) {
                ans[0] = ans[1] = 0;
            }
            return ans;
        }
        int left = 0, right = size - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] <= target) {
                left = mid + 1;
            }
        }
        if (left < size && nums[left] == target) {
            ans[1] = left;
        } else if (left > 0 && left < size + 1 && nums[left - 1] == target) {
            ans[1] = left - 1;
        }
        left = 0;
        right = size - 1;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (right > -1 && nums[right] == target) {
            ans[0] = right;
        } else if (right > -2 && right < size - 1 && nums[right + 1] == target) {
            ans[0] = right + 1;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int arr[] = {2, 2};
    int target = 3;
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> result = solution.searchRange(nums, target);
    MyTools::printVec(result);
    return 0;
}
