// 208. Implement Trie (Prefix Tree)
// 实现一个 Trie (前缀树)
// 包含 insert, search, 和 startsWith 这三个操作
//

#include <string>
#include <string>

class TrieNode {
public:
    TrieNode* childNode[26];        // 指针数组
    bool isVal;
    TrieNode(): isVal(false) {
        for (int i = 0; i < 26; ++i) {
            childNode[i] = nullptr;     // 子节点不为空代表相应字母
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie(): root(new TrieNode()) {}
    // 向字典树插入一个词
    void insert(std::string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!temp->childNode[word[i]-'a'])      // 如果字典树中没有
                temp->childNode[word[i]-'a'] = new TrieNode();
            temp = temp->childNode[word[i]-'a'];
        }
        temp->isVal = true;     // 最后一个子节点 isVal 设为 true
    }

    // 判断字典树里是否有一个词
    bool search(std::string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!temp)
                break;
            temp = temp->childNode[word[i]-'a'];
        }
        return temp? temp->isVal: false;
    }

    // 判断字典树是否有一个以词开始的前缀
    bool startsWith(std::string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (!temp)
                break;
            temp = temp->childNode[prefix[i]-'a'];
        }
        return temp;        // 前缀，temp-> 不一定为 true
    }
};

int main(){
    Trie* obj = new Trie();
    obj->insert("word");
    bool param_2 = obj->search("word");
    bool param_3 = obj->startsWith("prefix");
    return 0;
}