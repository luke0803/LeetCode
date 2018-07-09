
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

#分析:
return 一個 vector<int> result

首先建立一個存int的Hash Map，Key is the number and value is its index in the vector
從i=0~nums.size()-1，定義一個int numberToFind = target - nums[i]
如果在Hash Map中有找到numberToFind 就把index丟進result中，如果沒找到則把這個number放到Hash Map的key中，index放到對應的value中
-------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		int numberToFind = target - nums[i];

                //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

                //number was not found. Put it in the map.
		hash[nums[i]] = i;
	}
	return result;
    }
};
