/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> seen = {};

    void dfsCloneGraph(Node* node) {
        if (seen.count(node)) {
            return; 
        }
        Node* newNode = new Node(node->val);
        seen[node] = newNode;

        for (Node* neighbor : node->neighbors) {
            dfsCloneGraph(neighbor);
            newNode->neighbors.push_back(seen[neighbor]);
        }
    }

    Node* cloneGraph(Node* node) {
        // DFS:
        if (!node) { return nullptr; }
        if (node->val == 0) {
            return new Node();
        }
        dfsCloneGraph(node);
        return seen[node];
    }
};
