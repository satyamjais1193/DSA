class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        // else return true;

        unordered_map<int, int> freq;
        priority_queue<int, vector<int> , greater<int> > minHeap;

        for(int n : hand){
            freq[n] ++;
            if(freq[n] == 1){
                minHeap.push(n);
            }
        }

        while(!minHeap.empty()){
            // int prev = -1;
            vector<int> hand;
            for( int i =0; i<groupSize; i++){
                hand.push_back(minHeap.top());
                minHeap.pop();
                cout<<minHeap.top()<<" ";
            }
            cout<<endl;
            for(int i =1; i< hand.size(); i++){
                if(hand[i] - hand[i-1] != 1) return false;
            }
            for(int i =0; i< hand.size(); i++){
                freq[hand[i]] --;
                if(freq[hand[i]] > 0) minHeap.push(hand[i]);
            }
        }
        return true;


    }
};