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


int modInverse(int a, int mod){
        for (int i = 1; i < mod; i++){
            if (((a % mod) * (i % mod)) % mod == 1){
                return i;
            }
        }
        return -1;
}

// e(x) = (ax+b)mod26
// d(y) = (a^-1)(y-b)mod26

void affineDecryptor()
{
    // string t,s = "CCCYTWACWKYWSARTIBMHZAEKFGZPDGBFWKAFKELXCCGSDBTUBNLUGANEDJBRFDEOCCCYTMAKFBRYAOBUPHOFTWNP";
    string c = "NUTALDQIQTAYRQNJDHHNLDMTLDHYVNAEDPHDMYRDAHPQDYCDTAYDLQTYFRUNMRVPJDAYRQNJDHHNLDYRDAHPQDYCDTAYDLQTYFRUNJDHHNLDERYCYCDJDHHNLDNAMYCDJDHHNLDMTLDHYNQDADDMDM";
    // string t,s = "IYEGXPXMMOETTNZKAYAUYYTTBBMVFFYYKKKCIGXELZFXBAVSIJZOXQBBNXUWIOYZVTFRVABXMZXWYROXAZRTXOEOLSKUTJAEKMGWABWHVAMYKPHQVCQLFMQNWOEOBRMETXOFVTQMGHJIIGIRWTKEVYQVFIFAJAEKMGWALYYVAVMUCKIYJQHLNHGGZZWGQBUTXGIMFYLRYVUDAVPIGVL";
    string p = string(c.size(),0);
    
    cout << newl << "Decrypting..." << newl;
    cout << newl;
    sleep(1);

    cout << "Possible Plaintexts are: " << newl;
    sleep(1);
    cout << newl;

    for (int a = 1 ; a <= 25 ; a+=2){
        if ( a == 13) continue;
        for (int b = 0 ; b < 26 ; b++){
            for (int i = 0 ; i < c.size() ; i++){
                p[i] = (modInverse(a,26)*(c[i] -'A' - b + 26))%26 + 'A';
            }
            cout << a << " " << b << newl;
            cout << p << newl;
        }
    }

    cout << newl;
    cout << "Meaning full plaintxt is " << newl;
    sleep(1);
    cout << "AFINGERPRINTORAMESSAGEDIGESTCANBEUSEDTOENSURETHEINTEGRITYOFADOCUMENTORAMESSAGETOENSURETHEINTEGRITYOFAMESSAGEBOTHTHEMESSAGEANDTHEMESSAGEDIGESTARENEEDED" << newl;
    cout << newl;
    cout << "Keys are a = 17 and b =13 " << newl << newl;
   
}

int32_t main()
{
    affineDecryptor();
    return 0;
}
