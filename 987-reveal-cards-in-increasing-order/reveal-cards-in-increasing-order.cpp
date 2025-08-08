class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> position;
        int n = deck.size();
        sort(deck.begin(), deck.end());
        for (int i = 0; i < n; i++) {
            position.push(i);
        }
        vector<int> result(n);
        int cardIdx = 0;
        while (!position.empty()) {
            // Place the next card at the front position
            int pos = position.front();
            position.pop();
            result[pos] = deck[cardIdx++];
            //move the next one to the back, If there are more position 
            if (!position.empty()) {
                int nextPos = position.front();
                position.pop();
                position.push(nextPos);
            }
        }
        return result;
    }
}; 