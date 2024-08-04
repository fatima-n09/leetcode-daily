class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        
        // Initialize the queue with the tickets count
        for (int i = 0; i < tickets.size(); ++i) {
            q.push({i, tickets[i]});
        }
        
        int time = 0;
        
        // Process the queue
        while (!q.empty()) {
            auto person = q.front();
            q.pop();
            int index = person.first;
            int ticketCount = person.second;
            ++time;

            // If the current person is the k-th person and they buy their last ticket, return the time
            if (index == k && ticketCount == 1) {
                break;
            }
            
            // If the current person still has tickets left, requeue them with one less ticket
            if (ticketCount > 1) {
                q.push({index, ticketCount - 1});
            }
        }
        
        return time;
    }
};

