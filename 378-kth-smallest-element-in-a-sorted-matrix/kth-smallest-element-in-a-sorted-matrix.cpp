class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Min-heap: (value, row, col)
        priority_queue< int > maxHeap ;
        // int row = i<k/n;
        // int col = j<k%n;
        for(int i= 0; i<n ; i++){
            for(int j =0; j < n; j++){
                if(k != 0){
                    maxHeap.push(matrix[i][j]);
                    k--;
                }
                else{
                    if(maxHeap.top() >= matrix[i][j]){
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }
        }
        return maxHeap.top();
    }
};
