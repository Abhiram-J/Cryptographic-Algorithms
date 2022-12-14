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
const int64 mod = 1e9+7;
const ll inf = 2e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int64 getRandomNumber(int64 l, int64 r) {return uniform_int_distribution<int64>(l, r)(rng);}


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
	for (int64 i = 0; i < s.size(); i += 4)
	{
		string k = "";
		for (int64 j = i; j < i + 4; j++) k += s[j];
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


int64 Message[80];



class SHA512
{
    const int64 Constants[80]
    = { 0x428a2f98d728ae22, 0x7137449123ef65cd,
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
 



    string decimaltohex(int64 deci)
    {
        string EQBIN = bitset<64>(deci).to_string();
    
        string hexstring = "";
        string temp;
    
        for (int64 i = 0;
            i < EQBIN.length(); i += 4) {
            temp = EQBIN.substr(i, 4);
            hexstring += binToHex(temp);
        }
    
        return hexstring;
    }
    
    int64 BintoDec(string bin)
    {
    
        int64 value = bitset<64>(bin)
                        .to_ullong();
        return value;
    }
    
    int64 rotate_right(int64 x, int64 n)
    {
        return (x >> n) | (x << (64 - n));
    }
    
    int64 shift_right(int64 x, int64 n)
    {
        return (x >> n);
    }
    
    void separator(string getBlock)
    {
        int64 chunknum = 0;
    
        for (int64 i = 0;
            i < getBlock.length();
            i += 64, ++chunknum) {
    
            Message[chunknum]
                = BintoDec(getBlock.substr(i, 64));
        }
    
        for (int64 g = 16; g < 80; ++g) {
    
            int64 WordA = rotate_right(Message[g - 2], 19)
                        ^ rotate_right(Message[g - 2], 61)
                        ^ shift_right(Message[g - 2], 6);
    
            int64 WordB = Message[g - 7];
    
            int64 WordC = rotate_right(Message[g - 15], 1)
                        ^ rotate_right(Message[g - 15], 8)
                        ^ shift_right(Message[g - 15], 7);
    
            int64 WordD = Message[g - 16];
    
            int64 T = WordA + WordB + WordC + WordD;
    
            Message[g] = T;
        }
    }
    
    int64 maj(int64 a, int64 b, int64 c)
    {
        return (a & b) ^ (b & c) ^ (c & a);
    }
    
    int64 Ch(int64 e, int64 f, int64 g)
    {
        return (e & f) ^ (~e & g);
    }
    
    int64 sigmaE(int64 e)
    {
        return rotate_right(e, 14)
            ^ rotate_right(e, 18)
            ^ rotate_right(e, 41);
    }
    
    int64 sigmaA(int64 a)
    {
    
        return rotate_right(a, 28)
            ^ rotate_right(a, 34)
            ^ rotate_right(a, 39);
    }
    
    void Func(int64 a, int64 b, int64 c,
            int64& d, int64 e, int64 f,
            int64 g, int64& h, int64 K)
    {
        int64 T1 = h + Ch(e, f, g) + sigmaE(e) + Message[K]
                + Constants[K];
        int64 T2 = sigmaA(a) + maj(a, b, c);
    
        d = d + T1;
        h = T1 + T2;
    }

    public:
    string digestString(string myString)
    {
        int64 A = 0x6a09e667f3bcc908;
        int64 B = 0xbb67ae8584caa73b;
        int64 C = 0x3c6ef372fe94f82b;
        int64 D = 0xa54ff53a5f1d36f1;
        int64 E = 0x510e527fade682d1;
        int64 F = 0x9b05688c2b3e6c1f;
        int64 G = 0x1f83d9abfb41bd6b;
        int64 H = 0x5be0cd19137e2179;
    
        int64 AA, BB, CC, DD, EE, FF, GG, HH;
    
        stringstream fixedstream;
    
        for (int64 i = 0;
            i < myString.size(); ++i) {
    
            fixedstream << bitset<8>(myString[i]);
        }
    
        string s1024;
    
        s1024 = fixedstream.str();
    
        int64 orilen = s1024.length();
        int64 tobeadded;
    
        int64 modded = s1024.length() % 1024;
    
        if (1024 - modded >= 128) {
            tobeadded = 1024 - modded;
        }

        else if (1024 - modded < 128) {
            tobeadded = 2048 - modded;
        }
    
        s1024 += "1";
    
        // Append tobeadded-129 zeros
        // in the string
        for (int64 y = 0; y < tobeadded - 129; y++) {
            s1024 += "0";
        }
    
        // Stores the binary representation
        // of string length
        string lengthbits
            = std::bitset<128>(orilen).to_string();
    
        // Append the lengthbits to string
        s1024 += lengthbits;
    
        // Find the count of chunks of
        // size 1024 each
        int64 blocksnumber = s1024.length() / 1024;
    
        // Stores the numbering of chunks
        int64 chunknum = 0;
    
        // Stores hash value of each blocks
        string Blocks[blocksnumber];
    
        // Traverse the string s1024
        for (int64 i = 0; i < s1024.length();
            i += 1024, ++chunknum) {
            Blocks[chunknum] = s1024.substr(i, 1024);
        }
    
        // Traverse tha array Blocks[]
        for (int64 letsgo = 0;
            letsgo < blocksnumber;
            ++letsgo) {
    
            // Divide the current string
            // into 80 blocks size 16 each
            separator(Blocks[letsgo]);
    
            AA = A;
            BB = B;
            CC = C;
            DD = D;
            EE = E;
            FF = F;
            GG = G;
            HH = H;
    
            int64 count = 0;
    
            // Find hash values
            for (int64 i = 0; i < 10; i++) {
    
                // Find the Hash Values
    
                Func(A, B, C, D, E, F, G, H, count);
                count++;
                Func(H, A, B, C, D, E, F, G, count);
                count++;
                Func(G, H, A, B, C, D, E, F, count);
                count++;
                Func(F, G, H, A, B, C, D, E, count);
                count++;
                Func(E, F, G, H, A, B, C, D, count);
                count++;
                Func(D, E, F, G, H, A, B, C, count);
                count++;
                Func(C, D, E, F, G, H, A, B, count);
                count++;
                Func(B, C, D, E, F, G, H, A, count);
                count++;
            }
    
            // Update the value of A, B, C,
            // D, E, F, G, H
    
            A += AA;
            B += BB;
            C += CC;
            D += DD;
            E += EE;
            F += FF;
            G += GG;
            H += HH;
        }
    
        stringstream output;
    
        // Print the hexadecimal value of
        // strings as the resultant SHA-512
        output << decimaltohex(A);
        output << decimaltohex(B);
        output << decimaltohex(C);
        output << decimaltohex(D);
        output << decimaltohex(E);
        output << decimaltohex(F);
        output << decimaltohex(G);
        output << decimaltohex(H);
    
        // Return the string
        return output.str();
    }

};


class DES_Decryption
{

	// constants regarding the keys

	const int64 pc_1[56] = {  57 ,49 ,41 ,33 ,25 ,17 ,9  ,
				1  ,58 ,50 ,42 ,34 ,26 ,18 ,
				10 ,2  ,59 ,51 ,43 ,35 ,27 ,
				19 ,11 ,3  ,60 ,52 ,44 ,36 ,
				63 ,55 ,47 ,39 ,31 ,23 ,15 ,
				7  ,62 ,54 ,46 ,38 ,30 ,22 ,
				14 ,6  ,61 ,53 ,45 ,37 ,29 ,
				21 ,13 ,5  ,28 ,20 ,12 ,4 };

	int64 num_leftShift[16] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 }; // number of bits to shift for each iteration

	const int64 pc_2[48] = {  14 ,17 ,11 ,24 ,1  ,5  ,
				3  ,28 ,15 ,6  ,21 ,10 ,
				23 ,19 ,12 ,4  ,26 ,8  ,
				16 ,7  ,27 ,20 ,13 ,2  ,
				41 ,52 ,31 ,37 ,47 ,55 ,
				30 ,40 ,51 ,45 ,33 ,48 ,
				44 ,49 ,39 ,56 ,34 ,53 ,
				46 ,42 ,50 ,36 ,29 ,32 };

	// constants regarding the plain text

	const int64 IP_t[64] = { 	58 ,50 ,42 ,34 ,26 ,18 ,10 ,2 ,  // intital permutation table
				60 ,52 ,44 ,36 ,28 ,20 ,12 ,4 ,
				62 ,54 ,46 ,38 ,30 ,22 ,14 ,6 ,
				64 ,56 ,48 ,40 ,32 ,24 ,16 ,8 ,
				57 ,49 ,41 ,33 ,25 ,17 ,9  ,1 ,
				59 ,51 ,43 ,35 ,27 ,19 ,11 ,3 ,
				61 ,53 ,45 ,37 ,29 ,21 ,13 ,5 ,
				63 ,55 ,47 ,39 ,31 ,23 ,15 ,7 };

	const int64 E_t[48] = { 	32 ,1  ,2  ,3  ,4  ,5  , // expantion table
				4  ,5  ,6  ,7  ,8  ,9  ,
				8  ,9  ,10 ,11 ,12 ,13 ,
				12 ,13 ,14 ,15 ,16 ,17 ,
				16 ,17 ,18 ,19 ,20 ,21 ,
				20 ,21 ,22 ,23 ,24 ,25 ,
				24 ,25 ,26 ,27 ,28 ,29 ,
				28 ,29 ,30 ,31 ,32 ,1 };

	int64 S[8][4][16] = {                        // S-box
		{
			{ 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 },
			{ 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8 },
			{ 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0 },
			{ 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 }
		},
		{
			{ 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10 },
			{ 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5 },
			{ 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15 },
			{ 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 }
		},
		{
			{ 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8 },
			{ 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1 },
			{ 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7 },
			{ 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 }
		},
		{
			{ 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15 },
			{ 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9 },
			{ 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4 },
			{ 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 }
		},
		{
			{ 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9 },
			{ 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6 },
			{ 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
			{ 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 }
		},
		{
			{ 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
			{ 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8 },
			{ 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6 },
			{ 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 }
		},
		{
			{ 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1 },
			{ 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6 },
			{ 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2 },
			{ 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 }
		},
		{
			{ 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7 },
			{ 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2 },
			{ 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8 },
			{ 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }
		}
	};

	const int64 P[32] = { 	16 ,7  ,20 ,21 ,
				29 ,12 ,28 ,17 ,
				1  ,15 ,23 ,26 ,
				5  ,18 ,31 ,10 ,
				2  ,8  ,24 ,14 ,
				32 ,27 ,3  ,9  ,
				19 ,13 ,30 ,6  ,
				22 ,11 ,4  ,25 };

	const int64 P_1[64] = { 	40 ,8  ,48 ,16 ,56 ,24 ,64 ,32 ,
				39 ,7  ,47 ,15 ,55 ,23 ,63 ,31 ,
				38 ,6  ,46 ,14 ,54 ,22 ,62 ,30 ,
				37 ,5  ,45 ,13 ,53 ,21 ,61 ,29 ,
				36 ,4  ,44 ,12 ,52 ,20 ,60 ,28 ,
				35 ,3  ,43 ,11 ,51 ,19 ,59 ,27 ,
				34 ,2  ,42 ,10 ,50 ,18 ,58 ,26 ,
				33 ,1  ,41 ,9  ,49 ,17 ,57 ,25 };


	// some functions

	string shift_bit(string s, int64 n)
	{
		string k = "";

		for (int64 i = n; i < s.size(); i++) k += s[i];
		for (int64 i = 0; i < n; i++) k += s[i];

		return k;
	}


	void expand_R(string r, string r32) // expanding according to expantion table E_t
	{
		r = "";
		for (int64 j = 0; j < 48; j++) r += r32[E_t[j] - 1];
		
	}


	string xor_add(string s1, string s2)
	{
		string result = "";
		for (int64 j = 0; j < s1.size(); j++) {
			if (s1[j] != s2[j]) result += '1';
			else result += '0';
		}
		return result;
	}

	string get_element_from_box(string s, int64 k)
	{
		int64 dec1 = 0, dec2 = 0, pwr = 0;
		dec1 = (int64)(s[0] - '0') * 2 + (int64)(s[5] - '0');
		for (int64 i = s.size() - 2; i >= 1; i--) dec2 += (int64)(s[i] - '0') * pow(2, pwr++);

		return decToBin(S[k][dec1][dec2]);
	}


public:

	string decrypt( string& cipher_txt, string& key)
	{
		// making sub-keys

		string key_64 = hexToBin(key);

		string key_56 = "";

		for (int64 i = 0; i < 56; i++) key_56 += key_64[pc_1[i] - 1];

		string key_firstHalf = key_56.substr(0,28), key_secondHalf = key_56.substr(28, 28);

		string L_key[16], R_key[16];

		for (int64 i = 0; i < 16; i++)
		{
			L_key[i] = shift_bit(((i == 0) ? key_firstHalf : L_key[i - 1]), num_leftShift[i]);
			R_key[i] = shift_bit((( i == 0) ? key_secondHalf : R_key[i - 1]), num_leftShift[i]);
		}


		string key_48[16], keys_56[16];

		for (int64 i = 0; i < 16; i++)
		{
			keys_56[i] = L_key[i] + R_key[i]; // making 56 bits keys
		}
		for (int64 i = 0; i < 16; i++)
		{
			key_48[i] = "";
			for (int64 j = 0; j < 48; j++) key_48[i] += keys_56[i][pc_2[j] - 1]; // making 48 bits keys
		}

        // key swapper

        for ( int64 i = 0 ; i < 8 ; i++){
            swap(key_48[i], key_48[15-i]);
        }

		// working on the plain text

		string cipher_txt_64 = hexToBin(cipher_txt); // transforming key from 16-bits hex to 64-bits bin

		string IP = ""; // permuted key

		for (int64 i = 0; i < 64; i++)
			IP += cipher_txt_64[IP_t[i] - 1];

		string L = IP.substr(0,32), R =IP.substr(32,32);

		string L_32[16], R_32[16];
		string R_xor_K[16];
		string R_48[16]; // making R_32 48 bits so that we can xor it with key_48 (wich is 48 bits)
		string S_R[16], s[16][8];
		string s_1[16];
		string P_R[16]; 

		R_48[0] = "";
		for (int64 j = 0; j < 48; j++)
			R_48[0] += R[E_t[j] - 1];

		R_xor_K[0] = xor_add(R_48[0], key_48[0]); // fill the R_xor_K array

		for (int64 j = 0; j < 48; j += 6) // dividing each value of R_xor_K to 8 string contaning 6 char each
			for (int64 k = j; k < j + 6; k++)
				s[0][j / 6] += R_xor_K[0][k];

		s_1[0] = "";
		for (int64 j = 0; j < 8; j++)
			s_1[0] += get_element_from_box(s[0][j], j);

		for (int64 j = 0; j < 32; j++)
			P_R[0] += s_1[0][P[j] - 1];

		L_32[0] = R;
		R_32[0] = "";
		R_32[0] = xor_add(P_R[0], L);

		for (int64 i = 1; i < 16; i++){
			R_48[i] = "";
			for (int64 j = 0; j < 48; j++)
				R_48[i] += R_32[i - 1][E_t[j] - 1];

			R_xor_K[i] = xor_add(R_48[i], key_48[i]); // fill the R_xor_K

			for (int64 j = 0; j <48; j += 6) // dividing each value of R_xor_K to 8 string contaning 6 char each
				for (int64 k = j; k < j + 6; k++)
					s[i][j / 6] += R_xor_K[i][k];

			s_1[i] = "";
			for (int64 j = 0; j < 8; j++)
				s_1[i] += get_element_from_box(s[i][j], j);

			for (int64 j = 0; j < 32; j++)
				P_R[i] += s_1[i][P[j] - 1];

			L_32[i] = R_32[i - 1];
			R_32[i] = "";
			R_32[i] = xor_add(P_R[i], L_32[i - 1]);

		}

		string decrypted_bin = "", RL;

		RL = R_32[15] + L_32[15];

		for (int64 i = 0; i < 64; i++) decrypted_bin += RL[P_1[i] - 1];

		string plain_txt = binToHex(decrypted_bin);
        return plain_txt;

	}


};

class RSA{

      uint64_t mulmod(uint64_t a, uint64_t b, uint64_t m) {
        int64_t res = 0;
    
        while (a != 0) {
            if (a & 1) {
    
                res = (res + b) % m;
            }
            a >>= 1;
            b = (b << 1) % m;
        }
        return res;
    }
    
    uint64_t powMod(uint64_t a, uint64_t b, uint64_t n) {
        uint64_t x = 1;
        
        a %= n;
    
        while (b > 0) {
            if (b % 2 == 1) {
                x = mulmod(x, a, n); // multiplying with base
            }
            a = mulmod(a, a, n); // squaring the base
            b >>= 1;
        }
        return x % n;
    }
    
    std::vector<int64> first_primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                                        31, 37, 41, 43, 47, 53, 59, 61, 67,
                                        71, 73, 79, 83, 89, 97, 101, 103,
                                        107, 109, 113, 127, 131, 137, 139,
                                        149, 151, 157, 163, 167, 173, 179,
                                        181, 191, 193, 197, 199, 211, 223,
                                        227, 229, 233, 239, 241, 251, 257,
                                        263, 269, 271, 277, 281, 283, 293,
                                        307, 311, 313, 317, 331, 337, 347, 349 };
    
    // going through all 64 bits and placing randomly 0s and 1s
    // setting first and last bit to 1 to get 64 odd number
    uint64_t getRandom64() {
        // the value need to be 63 bits because you can not using 64 bit values do a^2 which is needed
        constexpr int64 bits = 20;
        std::bitset<bits> a;
    
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<short> distr(0, 1);
    
        for (int64 i = 0; i < bits; i++) {
            a[i] = distr(gen);
        }
    
        a[0] = 1;
        a[bits - 1] = 1;
    
        return a.to_ullong();
    }
    
    uint64_t getLowLevelPrime() {
        while (true) {
            uint64_t candidate = getRandom64();
            bool is_prime = true;
            for (int64 i = 0; i < first_primes.size(); i++) {
                if (candidate == first_primes[i])
                    return candidate;
    
                if (candidate % first_primes[i] == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
                return candidate;
        }
    }
    
    bool trialComposite(uint64_t a, uint64_t evenC, uint64_t to_test, int64 max_div_2) {
        if (powMod(a, evenC, to_test) == 1)
            return false;
    
        for (int64 i = 0; i < max_div_2; i++) {
            uint64_t temp = static_cast<uint64_t>(1) << i;
            if (powMod(a, temp * evenC, to_test) == to_test - 1)
                return false;
        }
    
        return true;
    }
    
    bool MillerRabinTest(uint64_t to_test) {
        constexpr int64 accuracy = 20;
    
        int64 max_div_2 = 0;
        uint64_t evenC = to_test - 1;
        while (evenC % 2 == 0) {
            evenC >>= 1;
            max_div_2++;
        }
    
        // random numbers init
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<uint64_t> distr(2, to_test);
    
        for (int64 i = 0; i < accuracy; i++) {
            uint64_t a = distr(gen);
    
            if (trialComposite(a, evenC, to_test, max_div_2)) {
                return false;
            }
        }
    
        return true;
    }
    
    uint64_t getBigPrime() {
        while (true) {
            uint64_t candidate = getLowLevelPrime();
            if (MillerRabinTest(candidate))
                return candidate;
        }
    }

    public:


    int64 mod_expo(int64 a, int64 b, int64 mod)
        {
            if (b == 0)
                return a;
            if (b == 1)
                return a;
            else if (b & 1)
            {
                int64 ans = mod_expo(a, b / 2, mod) % mod;
                return (((1LL * ans * ans) % mod) * a) % mod;
            }
            else
            {
                int64 ans = mod_expo(a, b / 2, mod) % mod;
                return (1LL * ans * ans) % mod;
            }
    }

    int64 gcd(int64 a, int64 b, int64& x, int64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64 x1, y1;
    int64 d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
        return d;
    }

    int64 modInverse(int64 a, int64 m){
            
            int64 x, y;
            int64 g = gcd(a, m, x, y);
            x = (x % m + m) % m;
            return x;
        
    }

    vector<int64> generateKey(){
        vector<int64> v(3);

        // int64 p = PrimeTable[getRandomNumber(0,550)];
        // int64 q = PrimeTable[getRandomNumber(0,550)];
        int64 p = 1028081;
        int64 q = 810503;
        int64 n = p*q;
        int64 phi = (p-1)*(q-1);
        int64 e = 65537;
        int64 d = modInverse(e,phi);
        // cout << e << endl;
        // cout << d << endl;
        // cout << phi << endl;
        v[0] = e;
        v[1] = d;
        v[2] = n;
        return v;
    }


    string createDigSig(string digest, int64 d, int64 n){
        string dig = "";
        for ( int64 i = 0 ; i < digest.length(); i+=8){
            string subdigest = digest.substr(i,8);
            string pbin = hexToBin(subdigest);
            int64 p = bitset<32>(pbin).to_ulong();
            // cout << subdigest << endl;
            // cout << pbin << endl;
            // cout << p << endl;
            // cout << d << endl;
            // cout << n  << endl;
            int64 c = mod_expo(p,d,n);
            string cbin  = bitset<32>(c).to_string();
            string chex = binToHex(cbin);
            dig += chex;
            // cout << c << endl;
            // cout << chex << endl;
        }
        return dig;
    }

    string verifyDigSig(string sig, int64 e, int64 n){
        string dig = "";
        for ( int64 i = 0 ; i < sig.length(); i+=4){
            string subsig = sig.substr(i,4);
            string cbin = hexToBin(subsig);
            int64 c = bitset<32>(cbin).to_ulong();
            // cout << subsig << endl;
            // cout << cbin << endl;
            // cout << c << endl;
            // cout << e << endl;
            // cout << n << endl;
            int64 p = mod_expo(c,e,n);
            string pbin  = bitset<32>(p).to_string();
            string phex = binToHex(pbin);
            dig += phex;
            // cout << p << endl;
            // cout << phex << endl;
        }
        return dig;
    }

};


string string_to_hex(string in) {
    stringstream ss;

    ss << hex << setfill('0');
    for (int64 i = 0; i < in.length() ; ++i) {
        ss << std::setw(2) << static_cast<int64>(static_cast<unsigned char>(in[i]));
    }

    return ss.str(); 
}





string hex_to_string( string& in) {
    string output;

    size_t cnt = in.length() / 2;

    for (int32 i = 0; cnt > i; ++i) {
        int32 s = 0;
        stringstream ss;
        ss << hex << in.substr(i * 2, 2);
        ss >> s;
        output.push_back(static_cast<unsigned char>(s));
    }

    return output;
}


int32_t main()
{
    string cipher_text;
    cin >> cipher_text;

    DES_Decryption des;
    string key  = "1234567890ABCDEF";
    // cin >> key;

    string plain_text = "";
    // int64 i = 0;
    // while(cipher_text[i] == '0') i++;
    for(int64 i = 0; i <cipher_text.size(); i+=16){
        string subcipher = cipher_text.substr(i,16);
        plain_text += des.decrypt(subcipher,key);
    }
    // cout << cipher_text << endl;
    cout << plain_text << newl;

    cout << newl;

    string M1 = plain_text.substr(0,plain_text.size()-256);
    string sig = plain_text.substr(plain_text.size()-256,plain_text.size());

    string M1_plain = hex_to_string(M1);

    string M = "";
    for(int64 i = 0; i < M1_plain.size(); i++){
        if(M1_plain[i] == '.') continue;
        M += M1_plain[i];
    }

    cout << M << endl;

    SHA512 sha;
    string digest = sha.digestString(M);
    cout << digest << endl;


    // rsa
    int64 e,d,n;
    RSA rsa;
    cin >> e >> d >> n;

    cout << newl;
    cout << sig << newl;

    string dig = rsa.verifyDigSig(sig,e,n);
    cout << dig << endl;

    

    return 0;
}





