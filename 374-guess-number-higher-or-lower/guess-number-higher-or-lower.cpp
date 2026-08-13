/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 1;
        int e = n;

        while(s<=e){
            int myguss = s + ( e-s)/2;
            int mygussresult = guess(myguss);
            if(mygussresult == 0){
                return myguss;
            }
            else if(mygussresult == 1){
                s = myguss + 1;
            }
            else{
                e = myguss -1;
            }
        }
        return -1;
        
    }
};