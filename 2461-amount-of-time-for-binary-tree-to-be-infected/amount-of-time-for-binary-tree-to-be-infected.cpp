/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void  convertToGraph(TreeNode* current,int parent,  unordered_map<int,vector<int>>&adj){
        if(current == nullptr){
            return;
        }
        if(parent != -1){
            adj[current->val].push_back(parent);
        }
        if(current->left){
            adj[current->val].push_back(current->left->val);
        }
         if(current->right){
            adj[current->val].push_back(current->right->val);
        }
        
         convertToGraph(current->left,current->val,adj);
         convertToGraph(current->right,current->val,adj);
        
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
//        step 1 --- tree ke graph e convert korte hobe to traverse back
//         to do that we need to make an adjacency list
        
        unordered_map<int,vector<int>>adj;
        convertToGraph(root,-1,adj); // child baba adj
        
//         step 2 --- bfs as level order traversal hoccche 
//         as infected node ta nijer next level ke infect korche
        
        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        int mins=0;
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();
                
                for(int &neighbour : adj[curr]){
                    if(visited.find(neighbour)==visited.end()){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
            mins++;
        }
        
        return mins-1;  
//         as ekta extra min add hoyegeche jokhun amra starting node take pop kori queue theke
        
        
    }
};