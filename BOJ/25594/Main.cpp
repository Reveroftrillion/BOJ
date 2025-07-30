#include <iostream>
#include <string>
using namespace std;

string HG[128];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    HG['a'] = "aespa";
    HG['b'] = "baekjoon";
    HG['c'] = "cau";
    HG['d'] = "debug";
    HG['e'] = "edge";
    HG['f'] = "firefox";
    HG['g'] = "golang";
    HG['h'] = "haegang";
    HG['i'] = "iu";
    HG['j'] = "java";
    HG['k'] = "kotlin";
    HG['l'] = "lol";
    HG['m'] = "mips";
    HG['n'] = "null";
    HG['o'] = "os";
    HG['p'] = "python";
    HG['q'] = "query";
    HG['r'] = "roka";
    HG['s'] = "solvedac";
    HG['t'] = "tod";
    HG['u'] = "unix";
    HG['v'] = "virus";
    HG['w'] = "whale";
    HG['x'] = "xcode";
    HG['y'] = "yahoo";
    HG['z'] = "zebra";

    string s;
    cin >> s;
    int slen = s.length();
    int idx = 0;
    string ans = "";
    while (idx < slen)
    {
        string &tmp = HG[s[idx]];
        int tmplen = tmp.length();
        if (idx + tmplen <= slen)
        {
            if (s.substr(idx, tmplen) == tmp)
            {
                ans += s[idx];
                idx += tmplen;
            }
            else
            {
                cout << "ERROR!";
                return 0;
            }
        }
        else
        {
            cout << "ERROR!";
            return 0;
        }
    }

    cout << "It's HG!\n";
    cout << ans;
}