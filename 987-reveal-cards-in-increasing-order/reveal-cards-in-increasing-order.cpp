class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        queue<int> position;
        for (int i = 0; i < n; i++) {
            position.push(i);
        }
        vector<int> result(n);
        int cardIndex = 0;
        while (!position.empty()) {
            // Place the next card at the front position
            int pos = position.front();
            position.pop();
            result[pos] = deck[cardIndex++];
            
            // If there are more position, move the next one to the back
            if (!position.empty()) {
                int nextPos = position.front();
                position.pop();
                position.push(nextPos);
            }
        }
        
        return result;
    }
}; 