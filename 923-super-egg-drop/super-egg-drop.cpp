class Solution {
public:
    // this funtion is used to find --- maximum number of floor can be indentified using the given egges and given moves
    int findtotalfloore(int eggs, int moves){
        if(eggs == 0 || moves == 0) return 0;
        if( moves == 1) return 1;

        return 1 + findtotalfloore(eggs -1 , moves -1) + findtotalfloore(eggs, moves-1);
    }
    int superEggDrop(int k, int n) {
        //range to movees to find floor----  1 to k
        int move = 1;
        while(true){
            int MaxFloorCanFind = findtotalfloore(k, move);
            if(MaxFloorCanFind < n){
                move ++;
            }
            else{
                return move;
            }
        }
        return move;
    }
};