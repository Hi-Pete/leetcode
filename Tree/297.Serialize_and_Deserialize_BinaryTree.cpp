// 297. 二叉树的序列化与反序列化
// 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中
// 同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据
// 请设计一个算法来实现二叉树的序列化与反序列化
// 这里不限定你的序列 / 反序列化算法执行逻辑
// 你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构
//

#include <string>
#include <sstream>
#include <deque>
#include <vector>

using std::string;
using std::deque;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PreOder {
    void serializeTree(TreeNode* root, string &str){
        if (!root){
            str.append("#,");
            return;
        }

        str.append(std::to_string(root->val) + ',');

        serializeTree(root->left, str);
        serializeTree(root->right, str);
    }

    TreeNode* deserializeTree(deque<string> &nVals){
        if (nVals.empty())
            return nullptr;

        string sVal = nVals.front();
        nVals.pop_front();

        if(sVal == "#")
            return nullptr;

        TreeNode* node = new TreeNode(std::stoi(sVal));

        node->left = deserializeTree(nVals);
        node->right = deserializeTree(nVals);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;

        serializeTree(root, str);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream stt(data);
        string parStr;
        deque<string> nodeVal;
        while(getline(stt, parStr, ',')){
            nodeVal.push_back(parStr);
        }

        return deserializeTree(nodeVal);
    }
};

class InOrder{
    void serializeTree(TreeNode* root, string &str){
        if (!root){
            str.append("#,");
            return;
        }

        serializeTree(root->left, str);
        serializeTree(root->right, str);

        str.append(std::to_string(root->val) + ',');

    }

    TreeNode* deserializeTree(deque<string> &nVals){
        if (nVals.empty())
            return nullptr;

        string sVal = nVals.back();
        nVals.pop_back();

        if(sVal == "#")
            return nullptr;

        TreeNode* node = new TreeNode(std::stoi(sVal));

        node->right = deserializeTree(nVals);
        node->left = deserializeTree(nVals);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;

        serializeTree(root, str);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream stt(data);
        string parStr;
        deque<string> nodeVal;
        while(getline(stt, parStr, ',')){
            nodeVal.push_back(parStr);
        }

        return deserializeTree(nodeVal);
    }
};

class Layer{
public:
    string serialize(TreeNode* root){
        string str;
        if(!root)
            return str;

        deque<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()){
            TreeNode* pNode = queue.front();
            queue.pop_front();

            if(!pNode){
                str.append("#,");
                continue;
            }

            str.append(std::to_string(pNode->val) + ',');

            queue.push_back(pNode->left);
            queue.push_back(pNode->right);
        }

        return str;
    }

    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        std::stringstream stt(data);
        string parStr;
        vector<string> nodeVal;
        while(getline(stt, parStr, ',')){
            nodeVal.push_back(parStr);
        }

        TreeNode* root = new TreeNode(std::stoi(nodeVal[0]));
        deque<TreeNode*> queue;
        queue.push_back(root);

        for (int i = 1; i < nodeVal.size(); ) {
            TreeNode* parent = queue.front();
            queue.pop_front();

            string leftN = nodeVal[i++];
            if(leftN != "#"){
                parent->left = new TreeNode(std::stoi(leftN));
                queue.push_back(parent->left);
            } else
                parent->left = nullptr;

            string rightN = nodeVal[i++];
            if(rightN != "#"){
                parent->right = new TreeNode(std::stoi(rightN));
                queue.push_back(parent->right);
            } else
                parent->right = nullptr;

        }

        return root;
    }
};


int main(){
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    TreeNode* node3 = new TreeNode(3, node4, node5);
    TreeNode* node2 = new TreeNode(2);

    TreeNode* node1 = new TreeNode(1, node2, node3);

    Layer solve;
    string str = solve.serialize(node1);
    TreeNode* res = solve.deserialize(str);

    return 0;
}