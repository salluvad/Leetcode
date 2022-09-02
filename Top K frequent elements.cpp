  vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){    // map <num, freq>
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq;    // sorts based on freq
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
           /* if(pq.size() > (int)map.size() - k){    // this is to exit earlier , no need to use another loop to print k elements from heap 
                res.push_back(pq.top().second);
                pq.pop();
            }
            */
        }
        
        for(int i = 0 ; i <k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
