#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vpi;

#define forl(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define fore(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define foreach(a, b) for (auto &(a) : (b))
#define reset(a, b) memset(a, b, sizeof(a))
#define all(v) v.begin(), v.end()

const char newl = '\n';
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const ll inf = 2e18;


// d(y) = (x-k)mod26

void vigenereDecryptor()
{
    // string t,s = "CCCYTWACWKYWSARTIBMHZAEKFGZPDGBFWKAFKELXCCGSDBTUBNLUGANEDJBRFDEOCCCYTMAKFBRYAOBUPHOFTWNP";
    // string t, s = "NUTALDQIQTAYRQNJDHHNLDMTLDHYVNAEDPHDMYRDAHPQDYCDTAYDLQTYFRUNMRVPJDAYRQNJDHHNLDYRDAHPQDYCDTAYDLQTYFRUNJDHHNLDERYCYCDJDHHNLDNAMYCDJDHHNLDMTLDHYNQDADDMDM";
    string c = "IYEGXPXMMOETTNZKAYAUYYTTBBMVFFYYKKKCIGXELZFXBAVSIJZOXQBBNXUWIOYZVTFRVABXMZXWYROXAZRTXOEOLSKUTJAEKMGWABWHVAMYKPHQVCQLFMQNWOEOBRMETXOFVTQMGHJIIGIRWTKEVYQVFIFAJAEKMGWALYYVAVMUCKIYJQHLNHGGZZWGQBUTXGIMFYLRYVUDAVPIGVL";
    string key = "INTEGRITY";
    string p = string(c.size(),0);
  
    for (int i = 0 ; i < c.size() ; i++){
        p[i] = ((c[i]-'A') - (key[i%key.size()] -'A') + 26)%26 + 'A';
    }
    cout << newl;
    cout << "Decrypting..." << newl;
    cout << newl;
    sleep(1);

    cout << "The plain text is " << newl;
    cout << p << newl;
    cout << newl;
    cout << "The key is " << key << newl;
    cout << newl;
 
   
}

int32_t main()
{
    vigenereDecryptor();

    return 0;
}
