#include <iostream>
#include <cstdint>
#include <climits>
#include <cstring>

using namespace std;

class CMyString
{
    private:
        char *m_pData;
    public:
        CMyString(char *pData=NULL);
        CMyString(const CMyString& str);
        ~CMyString(void);
        CMyString& operator=(const CMyString &str);
        void out(void)
        {
            cout << m_pData << endl;
        }
};

CMyString::CMyString(char *pData)
{
    m_pData = pData;
}

CMyString::CMyString(const CMyString &str)
{
    if(this==&str)
        return;
    
    m_pData = (char *)malloc(strlen(str.m_pData)+1);
    strcpy(m_pData, str.m_pData);
}


CMyString::~CMyString(void)
{
    delete m_pData;
}

CMyString& CMyString::operator=(const CMyString &str)
{
    if(this!=&str)
    {
        CMyString strTmp(str);
        char *pTmp = m_pData;
        m_pData = strTmp.m_pData;
        strTmp.m_pData = pTmp;
    }
    return *this;
}


int main(int argc, char *argv[])
{
    char *s1 = (char *)malloc(4);
    strcpy(s1, "123");
    char *s2 = (char *)malloc(5);
    strcpy(s2, "4321");
    cout << "s2=" << s2 << endl;

    CMyString str1(s1);
    CMyString str2(str1);
    CMyString str3(s2);
    str1.out();
    str2.out();
    str3.out();
    str1 = str2 = str3;
    str1.out();
    str2.out();
    str3.out();
    return 0;
}

