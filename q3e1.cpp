#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int int64;
typedef unsigned int int32;

typedef long long ll;
typedef pair<int64, int64> pii;
typedef vector<int64> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vpi;

#define forl(a, b, c) for (int64(a) = (b); (a) < (c); (a)++)
#define fore(a, b, c) for (int64(a) = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int64(a) = (b); (a) >= (c); --(a))
#define foreach(a, b) for (auto &(a) : (b))
#define reset(a, b) memset(a, b, sizeof(a))
#define all(v) v.begin(), v.end()

const char newl = '\n';
const int64 N = 2e5 + 10;
const int64 mod = 1e9 + 7;
const ll inf = 2e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64 getRandomNumber(int64 l, int64 r) { return uniform_int_distribution<int64>(l, r)(rng); }

// class RSA{

//    vector<pair<int,int>> pairs =
//    {
//     {},{}
//     };

//     public:

//     int64 gcd(int64 a, int64 b, int64& x, int64& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int64 x1, y1;
//     int64 d = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//         return d;
//     }

//     int64 modInverse(int64 a, int64 m){

//             int64 x=0, y=0;
//             int64 g = gcd(a, m, x, y);
//             // cout << g << newl;
//             x = (x % m + m) % m;
//             return x;

//     }

//     int64 mod_expo(int64 a, int64 b, int64 mod)
//         {
//             if (b == 0)
//                 return a;
//             if (b == 1)
//                 return a;
//             else if (b & 1)
//             {
//                 int64 ans = mod_expo(a, b / 2, mod) % mod;
//                 return (((1LL * ans * ans) % mod) * a) % mod;
//             }
//             else
//             {
//                 int64 ans = mod_expo(a, b / 2, mod) % mod;
//                 return (1LL * ans * ans) % mod;
//             }
//     }

//     vector<int64> generateKey(){
//         vector<int64> v(3);

//         // int64 p = PrimeTable[getRandomNumber(0,550)];
//         // int64 q = PrimeTable[getRandomNumber(0,550)];
//         int64 p = 9241;
//         int64 q = 464773;
//         int64 n = p*q;
//         int64 phi = (p-1)*(q-1);
//         int64 e = 65537;
//         int64 d = modInverse(e,phi);
//         cout << e << endl;
//         cout << d << endl;
//         cout << phi << endl;
//         cout << n << endl;
//         cout << endl;
//         v[0] = e;
//         v[1] = d;
//         v[2] = n;
//         return v;
//     }

//     string createDigSig(string digest, int64 d, int64 n){
//         string dig = "";
//         for ( int64 i = 0 ; i < digest.length(); i+=8){
//             string subdigest = digest.substr(i,8);
//             string pbin = hexToBin(subdigest);
//             int64 p = bitset<32>(pbin).to_ulong();
//             cout << subdigest << endl;
//             cout << pbin << endl;
//             cout << p << endl;
//             cout << d << endl;
//             cout << n  << endl;
//             int64 c = mod_expo(p,d,n);
//             string cbin  = bitset<32>(c).to_string();
//             string chex = binToHex(cbin);
//             dig += chex;
//             cout << c << endl;
//             cout << chex << endl;
//         }
//         return dig;
//     }

// };

// string string_to_hex(string in) {
//     stringstream ss;

//     ss << hex << setfill('0');
//     for (int64 i = 0; i < in.length() ; ++i) {
//         ss << std::setw(2) << static_cast<int64>(static_cast<unsigned char>(in[i]));
//     }

//     return ss.str();
// }

string decToBin(int64 n)
{
	string bin = "";
	while (n > 0)
	{
		bin = (char)(n % 2 + '0') + bin;
		n /= 2;
	}
	while (bin.size() < 4)
		bin = '0' + bin;
	return bin;
}

string binToHex(string s)
{
	string hex = "";
	for (int i = 0; i < s.size(); i += 4)
	{
		string k = s.substr(i, 4);
		if (k == "0000") hex += '0';
		else if (k == "0001") hex += '1';
		else if (k == "0010") hex += '2';
		else if (k == "0011") hex += '3';
		else if (k == "0100") hex += '4';
		else if (k == "0101") hex += '5';
		else if (k == "0110") hex += '6';
		else if (k == "0111") hex += '7';
		else if (k == "1000") hex += '8';
		else if (k == "1001") hex += '9';
		else if (k == "1010") hex += 'a';
		else if (k == "1011") hex += 'b';
		else if (k == "1100") hex += 'c';
		else if (k == "1101") hex += 'd';
		else if (k == "1110") hex += 'e';
		else if (k == "1111") hex += 'f';
	}
	return hex;
}

string hexToBin(string s)
{
	string bin = "";
	for (int64 i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '0': bin += "0000"; break;
		case '1': bin += "0001"; break;
		case '2': bin += "0010"; break;
		case '3': bin += "0011"; break;
		case '4': bin += "0100"; break;
		case '5': bin += "0101"; break;
		case '6': bin += "0110"; break;
		case '7': bin += "0111"; break;
		case '8': bin += "1000"; break;
		case '9': bin += "1001"; break;
		case 'A': bin += "1010"; break;
		case 'B': bin += "1011"; break;
		case 'C': bin += "1100"; break;
		case 'D': bin += "1101"; break;
		case 'E': bin += "1110"; break;
		case 'F': bin += "1111"; break;
        case 'a': bin += "1010"; break;
        case 'b': bin += "1011"; break;
        case 'c': bin += "1100"; break;
        case 'd': bin += "1101"; break;
        case 'e': bin += "1110"; break;
        case 'f': bin += "1111"; break;

		}
	}
	return bin;
}


string decimalToHex(int64 deci)
{
    string bin = bitset<64>(deci).to_string();
    string hex = binToHex(bin);
    return hex;
}

class SHA512
{
    int64 initA = 0x6a09e667f3bcc908;
    int64 initB = 0xbb67ae8584caa73b;
    int64 initC = 0x3c6ef372fe94f82b;
    int64 initD = 0xa54ff53a5f1d36f1;
    int64 initE = 0x510e527fade682d1;
    int64 initF = 0x9b05688c2b3e6c1f;
    int64 initG = 0x1f83d9abfb41bd6b;
    int64 initH = 0x5be0cd19137e2179;
    
    const int64 constants[80] = {
        0x428a2f98d728ae22, 0x7137449123ef65cd,
        0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019,
        0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe,
        0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
        0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
        0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
        0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210,
        0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725,
        0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926,
        0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8,
        0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001,
        0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910,
        0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
        0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
        0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60,
        0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9,
        0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207,
        0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6,
        0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493,
        0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
        0x5fcb6fab3ad6faec, 0x6c44198c4a475817
    };

    int64 Word[80];

    int64 majority(int64 a, int64 b, int64 c){ return (a & b) ^ (b & c) ^ (c & a);}
    int64 conditional(int64 e, int64 f, int64 g){ return (e & f) ^ (~e & g);}
    int64 rotateE(int64 e){ return rotate_right(e, 14) ^ rotate_right(e, 18) ^ rotate_right(e, 41);}
    int64 rotateA(int64 a){ return rotate_right(a, 28) ^ rotate_right(a, 34) ^ rotate_right(a, 39);}
    int64 rotate_right(int64 x, int64 n){return (x >> n) | (x << (64 - n));}

    void wordExpander(string b)
    {
        int64 wordA, wordB, wordC, wordD;
        for (int64 i = 0; i < b.length();i += 64) Word[i/64] = bitset<64>(b.substr(i, 64)).to_ullong();

        for (int64 i = 16; i < 80; i++){
            wordA = Word[i - 16];
            wordB = rotate_right(Word[i - 15], 1) ^ rotate_right(Word[i - 15], 8) ^ (Word[i - 15] >> 7);
            wordC = Word[i - 7];
            wordD = rotate_right(Word[i - 2], 19) ^ rotate_right(Word[i - 2], 61) ^ (Word[i - 2] >> 6);

            Word[i] = wordA + wordB + wordC + wordD;
        }
    }

    void compressionFunc(int64 a, int64 b, int64 c,int64 &d, int64 e, int64 f,int64 g, int64 &h, int64 K)
    {
        int64 T2 = h + conditional(e, f, g) + rotateE(e) + Word[K] + constants[K];
        int64 T1 = rotateA(a) + majority(a, b, c);

        h = T1 + T2;
        d = d + T2;
    }

public:

    string createDigest(string s)
    {

        string s_bin = "";

        for (int64 i = 0;i < s.size(); ++i) s_bin += bitset<8>(s[i]).to_string();
        

        int64 len = s_bin.length();
        string len_bin = std::bitset<128>(len).to_string();


        int64 padding;

        if (1024 - (s_bin.length() % 1024) >= 128) padding = 1024 - (s_bin.length() % 1024);
        else  padding = 2048 - (s_bin.length() % 1024);
    

       
        for (int64 i = 0; i < padding - 128; i++)
        {
            if ( i == 0 ) s_bin += "1";
            else s_bin += "0";
        }

    
        s_bin += len_bin;

        int64 blocks = s_bin.length() / 1024;
        string hashBlocks[blocks];


        for (int64 i = 0; i < s_bin.length(); i += 1024) hashBlocks[i/1024] = s_bin.substr(i, 1024);
        

        int64 A,B,C,D,E,F,G,H;

        for (int64 j = 0; j < blocks; ++j){

       
            wordExpander(hashBlocks[j]);

            A = initA; B = initB; C = initC; D = initD; E = initE; F = initF; G = initG;H = initH;
         
            for (int64 i = 0; i < 10; i++)
            {
                compressionFunc(A, B, C, D, E, F, G, H, i*8 + 0);
                compressionFunc(H, A, B, C, D, E, F, G, i*8 + 1);
                compressionFunc(G, H, A, B, C, D, E, F, i*8 + 2);
                compressionFunc(F, G, H, A, B, C, D, E, i*8 + 3);
                compressionFunc(E, F, G, H, A, B, C, D, i*8 + 4);
                compressionFunc(D, E, F, G, H, A, B, C, i*8 + 5);
                compressionFunc(C, D, E, F, G, H, A, B, i*8 + 6);
                compressionFunc(B, C, D, E, F, G, H, A, i*8 + 7);
            }

            A += initA; B += initB; C += initC; D += initD; E += initE; F += initF; G += initG; H += initH;

           
        }

        string digest = decimalToHex(A) + decimalToHex(B) + decimalToHex(C) + decimalToHex(D) + decimalToHex(E) + decimalToHex(F) + decimalToHex(G) + decimalToHex(H);

        return digest;
    }
};

int32_t main()
{
    string M = "GeeksForGeeks";
    SHA512 sha;
    string digest = sha.createDigest(M);
    cout << digest << endl;
    cout << endl;

    // // rsa
    // int64 e,d,n;
    // RSA rsa;
    // vector<int64> keys = rsa.generateKey();
    // e = keys[0];
    // d = keys[1];
    // n = keys[2];

    // // cout << e << " " << d << " " << n << endl;
    // string sig = rsa.createDigSig(digest,d,n);

    // // cout << plain_text.size() << endl;

    // cout << sig << endl;

    // cout << sig.size() << endl;
    // cout << endl;

    // string M1 = M;

    // while(M1.size()%32!=0){
    //     M1 = "."  +M1;
    // }

    // string M_hex = string_to_hex(M1);
    // cout << M_hex << endl;
    // cout << M_hex.size() << endl;
    // cout << endl;

    // string plain_text = M_hex;

    // plain_text += sig;

    // cout << plain_text << endl;

    // DES_Encryption des;
    // string key;
    // cin >> key;

    // string cipher_text = "";
    // cout << endl;
    // for(int64 i=0; i<plain_text.size(); i+=16){
    //     string subplain = plain_text.substr(i,16);
    //     string ensubplain = des.encrypt(subplain,key);
    //     cipher_text += ensubplain;
    // }
    // cout << cipher_text << endl;

    return 0;
}
