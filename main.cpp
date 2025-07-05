#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// check for duplicate values
bool containDuplicate(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(nums[i]) != mp.end()) {
            return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

// find missing numbers form [1, n]
vector<int> findMissingNumbers(vector<int>& nums) {
    vector<int> ans;
    
    set<int> s(nums.begin(), nums.end());

    for(int i=1; i<=nums.size(); i++) {
        if(!s.count(i)) {
            ans.push_back(i);
        }
    }
    return ans;    
}

vector<int> bfsOfGraph(int V, vector<int> adj[], int start = 0) {
    vector<int> vis(V, 0);
    vector<int> bfs;
    queue<int> q;
    
    q.push(start);
    vis[start] = 1;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfsOfGraphUtil(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsList) {   
    vis[node] = 1;
    dfsList.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfsOfGraphUtil(it, vis, adj, dfsList);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfsList;
    int start = 0;
    dfsOfGraphUtil(start, vis, adj, dfsList);
    return dfsList;
}



int main() {
    // check bfs traversal
    vector<int> adj[5] = {{1, 2}, {0, 2}, {0, 1, 3}, {2}, {1}};
    vector<int> result = dfsOfGraph(5, adj);

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}