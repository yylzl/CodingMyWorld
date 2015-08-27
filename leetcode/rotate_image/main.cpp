#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void dumpMatrix(vector<vector<int> >& matrix)
        {
            for(int i=0; i<matrix.size();++i)
            {
                for(int j=0;j<matrix[i].size();++j)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void rotate(vector<vector<int> >& matrix) {
            reverse(matrix.begin(), matrix.end());
            for(int i=0;i<matrix.size();++i)
            {
                for(int j=0;j<i;++j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
};

int main(int argc, char *argv[])
{
    Solution *S = new Solution();

    {
        int a[] = {1};
        vector<int> va(a, a+sizeof(a)/sizeof(int));

        vector<vector<int> > m;
        m.push_back(va);


        S->dumpMatrix(m);
        S->rotate(m);
        cout << endl;
        S->dumpMatrix(m);
    }
    cout << endl;
    {
        int a[] = {1, 2};
        int b[] = {3, 4};
        vector<int> va(a, a+sizeof(a)/sizeof(int));
        vector<int> vb(b, b+sizeof(b)/sizeof(int));

        vector<vector<int> > m;
        m.push_back(va);
        m.push_back(vb);


        S->dumpMatrix(m);
        S->rotate(m);
        cout << endl;
        S->dumpMatrix(m);
    }
    cout << endl;
    {
        int a[] = {1, 2, 3};
        int b[] = {4, 5, 6};
        int c[] = {7, 8, 9};
        vector<int> va(a, a+sizeof(a)/sizeof(int));
        vector<int> vb(b, b+sizeof(b)/sizeof(int));
        vector<int> vc(c, c+sizeof(c)/sizeof(int));

        vector<vector<int> > m;
        m.push_back(va);
        m.push_back(vb);
        m.push_back(vc);


        S->dumpMatrix(m);
        S->rotate(m);
        cout << endl;
        S->dumpMatrix(m);
    }

    cout << endl;

    {
        int a[] = {1, 2, 3, 4};
        int b[] = {4, 5, 6, 7};
        int c[] = {7, 8, 9, 0};
        int d[] = {2, 3, 4, 5};
        vector<int> va(a, a+sizeof(a)/sizeof(int));
        vector<int> vb(b, b+sizeof(b)/sizeof(int));
        vector<int> vc(c, c+sizeof(c)/sizeof(int));
        vector<int> vd(d, d+sizeof(d)/sizeof(int));

        vector<vector<int> > m;
        m.push_back(va);
        m.push_back(vb);
        m.push_back(vc);
        m.push_back(vd);


        S->dumpMatrix(m);
        S->rotate(m);
        cout << endl;
        S->dumpMatrix(m);
    }

    cout << endl;
    {
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {4, 5, 6, 7, 8};
        int c[] = {7, 8, 9, 0, 1};
        int d[] = {2, 3, 4, 5, 6};
        int e[] = {5, 6, 7, 8, 9};
        vector<int> va(a, a+sizeof(a)/sizeof(int));
        vector<int> vb(b, b+sizeof(b)/sizeof(int));
        vector<int> vc(c, c+sizeof(c)/sizeof(int));
        vector<int> vd(d, d+sizeof(d)/sizeof(int));
        vector<int> ve(e, e+sizeof(e)/sizeof(int));

        vector<vector<int> > m;
        m.push_back(va);
        m.push_back(vb);
        m.push_back(vc);
        m.push_back(vd);
        m.push_back(ve);


        S->dumpMatrix(m);
        S->rotate(m);
        cout << endl;
        S->dumpMatrix(m);
    }

    return 0;
}

