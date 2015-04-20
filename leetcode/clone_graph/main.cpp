#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:

        unordered_map<int, UndirectedGraphNode*> mNodeMap;
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
#if 0
            if(node==NULL)
                return NULL;

            UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
            if(node->neighbors.empty())
            {
                return ret;
            }
            stack<UndirectedGraphNode *> s;
            unordered_map<int, UndirectedGraphNode*> m;
            m[ret->label] = ret;
            vector<UndirectedGraphNode*>::iterator it;
            s.push(node);
            UndirectedGraphNode *t;
            while(!s.empty())
            {
                t = s.top();
                s.pop();
                for(it=t->neighbors.begin();it!=t->neighbors.end();++it)
                {
                    if(m.find((*it)->label)!=m.end())
                    {
                        m[t->label]->neighbors.push_back(m[(*it)->label]);
                    }
                    else
                    {
                        UndirectedGraphNode *n = new UndirectedGraphNode((*it)->label);
                        m[n->label] = n;
                        m[t->label]->neighbors.push_back(n);
                        s.push((*it));
                    }
                }
            }

            return ret;
#endif
            if(!node) return node;

            unordered_map<int, UndirectedGraphNode*>::iterator itr = mNodeMap.find(node->label);
            if(itr == mNodeMap.end()){
                UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
                mNodeMap[node->label] = newNode;
                for(int i = 0; i < node->neighbors.size(); ++i){
                    newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));   
                }
                return newNode;
            }else{
                return itr->second;
            }    
        }        
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();
    return 0;
}

