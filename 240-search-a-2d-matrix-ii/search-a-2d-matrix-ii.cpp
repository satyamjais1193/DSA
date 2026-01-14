class Solution {
public:
    int bs( vector<int>& arr,  int target){
        int ans =- 1;
        int s =0; 
        int e = arr.size()-1;
        
        while( s<= e){
            int mid = s + ( e-s)/2;
            if(arr[mid]== target){
                return mid;
            }
            else if (arr[mid] < target){
                s = mid +1;
                // ans = mid;
            }
            else {
                e = mid -1;
            }
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int validloop = bs(matrix[0], 0, matrix[0].size(), target);
        // int e = bs(matrix[0], 0, matrix[0].size(), target);

        // int e = matrix.size();
        int index =-1;

        for(int i =0; i< matrix.size(); i++){
            index =  bs(matrix[i],  target);
            if ( index != -1)  return true;
        }
        return false;

        
    }
};