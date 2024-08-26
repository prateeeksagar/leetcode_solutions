/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void dfs(Node* root, vector<int> & result) {
        if(root->children.size() == 0) {
            result.push_back(root->val);
            return;
        }

        for(auto &it: root->children) dfs(it, result);
        result.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if(root == NULL) return result;        
        dfs(root, result);
        return result;
    }
};