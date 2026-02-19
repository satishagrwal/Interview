class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
      
        for( int i = 0; i < size; i++ )
        {
            for( int j = i+1; j < size; j++ )
            {
               if( (nums[i] + nums[j]) == target)
               {
                  return {i , j};
               }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> map;

        for( int i = 0; i < size; i++ )
        {
            int compliment = target - nums[i];

            if( map.count(compliment) )
            {
               return{map[compliment], i}; 
            }

            map[nums[i]] = i;    
        }
        return{};
    }
};
