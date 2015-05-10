#include <iostream>
#include <cstdint>
#include <climits>
#include <queue>

using namespace std;

class TrieNode {
    public:
        TrieNode *child[26];
        //可以不用保存ch child的idx可以代表a-z
        char ch;
        bool word;
        // Initialize your data structure here.
        TrieNode(char c='\0') {
            for(int i=0;i<26;++i)
            {
                child[i] = NULL;
            }
            word = false;
            ch = c;
        }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string s) {
            if(s.empty())
                return;
            insert(root, s);
        }

        // Returns if the word is in the trie.
        bool search(string key) {
            if(key.empty())
                return false;
            return search(root, key);
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            if(prefix.empty())
                return false;
            return startsWith(root, prefix);
        }

    private:
        TrieNode* root;
        void insert(TrieNode *root, string s)
        {
            char c;
            int idx;
            for(int i=0;i<s.size();++i)
            {
                c = s[i];
                idx = c - 'a';
                if(root->child[idx]==NULL)
                {
                    root->child[idx] = new TrieNode(c);
                }
                root=root->child[idx];
            }
            root->word = true;
        }
        bool search(TrieNode *root, string key)
        {
            char c;
            int idx;
            for(int i=0;i<key.size();++i)
            {
                c = key[i];
                idx = c - 'a';
                if(root->child[idx]==NULL)
                {
                    return false;
                }
                root=root->child[idx];
            }
            return root->word;
        }
        bool startsWith(TrieNode *root, string prefix) 
        {
            char c;
            int idx;
            for(int i=0;i<prefix.size();++i)
            {
                c = prefix[i];
                idx = c - 'a';
                if(root->child[idx]==NULL)
                {
                    return false;
                }
                root=root->child[idx];
            }
            return true;
        }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char *argv[])
{
    Trie *trie = new Trie();
    trie->insert("abc");
    trie->insert("and");
    trie->insert("dnt");
    cout<<trie->search("abd")<<endl;
    cout<<trie->search("abc")<<endl;
    cout<<trie->startsWith("ab")<<endl;
    cout<<trie->startsWith("a")<<endl;
    cout<<trie->startsWith("ae")<<endl;
    return 0;
}

