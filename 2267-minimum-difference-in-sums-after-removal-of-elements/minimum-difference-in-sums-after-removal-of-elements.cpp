class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long> min_sum(nums.size(), -1);//fro sum1- of n elelment
        vector<long long> max_sum(nums.size(), -1);// for sum2

        long long sum =0; // store sum of first n elemnts such that their sum is min
        priority_queue<long long> maxHeap;
        for(int i =0; i<nums.size(); i++){
            sum += nums[i]; 
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n){
                sum -=maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == n){
                min_sum[i] = sum;
            }
        }

        sum =0;//now for min of n elements
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(int i =nums.size()-1;i>=0; i--){
            sum += nums[i]; 
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                sum -=minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n){
                max_sum[i] = sum;
            }
        }

        long long ans= LONG_LONG_MAX;
        //loops rum such that it avoid previos n and last n 
        for(int i= n-1; i<2*n; ++i){
            ans = min(ans, min_sum[i] - max_sum[i+1]);
        }

        return ans;




        
    }
};