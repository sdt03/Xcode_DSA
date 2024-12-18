#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode* left, TreeNode* right) : data(x), left(left), right(right){}
};

class Solution{
public:
    vector<vector<int>> LevelOrderTraversal(TreeNode* root){
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->data);
                
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
    
    vector<int> IPreorder(TreeNode* root){
        vector<int> preorder;
        if(root==nullptr) return preorder;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            
            preorder.push_back(root->data);
            
            if(root->right!=nullptr) st.push(root->right);
            if(root->left!=nullptr) st.push(root->left);
        }
        return preorder;
    }
    
    vector<int> Post2Stackorder(TreeNode* root){
        vector<int> post;
        if(root==nullptr) return post;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            
            if(root->left!=nullptr) st1.push(root->left);
            if(root->right!=nullptr) st1.push(root->right);
            
        }
        while(!st2.empty()){
            post.push_back(st2.top()->data);
            st2.pop();
        }
        return post;
    }
    
    vector<int> post1stackorder(TreeNode* root){
        vector<int> post;
        return post;
    }
    
    int maxHeight(TreeNode* root){
        if(root==NULL) return 0;
        int x = maxHeight(root->left);
        if(x==-1) return -1;
        int y = maxHeight(root->right);
        if(y==-1) return -1;
        
        if(abs(x-y) > 1) return -1;
        return 1+max(x,y);
    }
    
    bool checkBalanced(TreeNode* root){
        return maxHeight(root) != -1;
    }
    
    int diameterTree(TreeNode* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter){
        if(root==NULL) return 0;
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh+rh);
        
        return 1+max(lh,rh);
    }
    
};

void printVector(const vector<int>& vec){
    for(int num:vec){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(6);
    root->right->right->right->right = new TreeNode(7);
    
    Solution obj;
    vector<vector<int>> ans = obj.LevelOrderTraversal(root);
    
    cout<<"Level order traversal of tree: ";
    for(const vector<int>& level : ans){
        printVector(level);
    }
    vector<int> preorder = obj.IPreorder(root);
    cout<<"Iterative preorder: ";
    for(int num : preorder){
        cout<<num<<" ";
    }
    cout<<endl;
    cout << "Tree is balanced? : " << obj.checkBalanced(root)<<endl;
    
    cout << "Diameter of the tree is: " << obj.diameterTree(root) << endl;
    
    return 0;
}
