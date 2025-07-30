class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.length();
        // Initializing queues with senator positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int rPos = radiant.front();
            int dPos = dire.front();
            radiant.pop();
            dire.pop();
            // Radiant senator comes first, bans Dire senator
            // Radiant senator gets another turn (add to queue with position + n)
            if (rPos < dPos) {

                radiant.push(rPos + n);
            } else
            // Dire senator comes first, bans Radiant senator
            // Dire senator gets another turn (add to queue with position + n)
            {
                
                dire.push(dPos + n);
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
}; 