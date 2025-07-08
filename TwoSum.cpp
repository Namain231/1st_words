#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Maps number to its index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Found the two indices
        }
        num_map[nums[i]] = i; // Store the index of the current number
    }
    return {}; // Return empty vector if no solution found
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n >> target; // Read number of elements and target sum
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; // Read the elements of the array
    }

    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl; // Output the indices
    } else {
        cout << "No solution found" << endl; // If no solution exists
    }
  return 0;
}