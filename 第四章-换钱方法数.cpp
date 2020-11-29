//换钱方法数

//给定arr货币面值数组，给定一个目标钱数，求换钱有多少种方法
//arr[5,10,25,1],aim=0, return 0;
//arr[5,10,25,1],aim=15,return 6;
//arr[3,5],aim=2,return 0;

class Solution {
public:
    int coins(std::vector<int> arr, int aim) {
    	std::vector<int> oDp(aim + 1, 0);
    	for(int i = 0; arr[0] * i <= aim; i++)
    	{
    		oDp[arr[0] * i] = 1;
    	}

    	for (int i = 1; i < arr.size(); i++)
    	{
    		for(int j = 0; j <= aim; j++)
    		{
    			oDp[j] = j - arr[i] >=0 ? oDp[j - arr[i]] + oDp[j] : oDp[j];
    		}
    	}
    	return oDp[aim];
    }
};