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




#define N 4

int modInverse(int a, int mod){
        for (int i = 1; i < mod; i++){
            if (((a % mod) * (i % mod)) % mod == 1){
                return i;
            }
        }
        return -1;
}


void getCfactor(int M[N][N], int t[N][N], int p, int q, int n) {
   int i = 0, j = 0;
   for (int r= 0; r< n; r++) {
      for (int c = 0; c< n; c++) 
         if (r != p && c != q) { 
            t[i][j++] = M[r][c]; 
            if (j == n - 1) {
               j = 0; i++;
            }
         }
      }
   }

int DET(int M[N][N], int n) {
   int D = 0;
   if (n == 1)
      return M[0][0];
   int t[N][N]; 
   int s = 1; 
   for (int f = 0; f < n; f++) {
        getCfactor(M, t, 0, f, n);
        D += ((s) * (M[0][f]) * (DET(t, n - 1)));
      s = -s;
   }
   return D;
}

void ADJ(int M[N][N],int adj[N][N]) {
  
   int s = 1,t[N][N];
   for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
         
         getCfactor(M, t, i, j, N);
         s = ((i+j)%2==0)? 1: -1; 
         adj[j][i] = (s)*(DET(t, N-1)); 
      }
   }
}
void INV(int M[N][N], int inv[N][N]) {
   int det = DET(M, N);
   int adj[N][N]; ADJ(M, adj);
   for (int i=0; i<N; i++) for (int j=0; j<N; j++) inv[i][j] = (( adj[i][j]*modInverse(det,26))%26 + 26 )%26;

}

void hillDecryptor()
{
    string c = "CCCYTWACWKYWSARTIBMHZAEKFGZPDGBFWKAFKELXCCGSDBTUBNLUGANEDJBRFDEOCCCYTMAKFBRYAOBUPHOFTWNP";
    // string t, s = "NUTALDQIQTAYRQNJDHHNLDMTLDHYVNAEDPHDMYRDAHPQDYCDTAYDLQTYFRUNMRVPJDAYRQNJDHHNLDYRDAHPQDYCDTAYDLQTYFRUNJDHHNLDERYCYCDJDHHNLDNAMYCDJDHHNLDMTLDHYNQDADDMDM";
    // string t,s = "IYEGXPXMMOETTNZKAYAUYYTTBBMVFFYYKKKCIGXELZFXBAVSIJZOXQBBNXUWIOYZVTFRVABXMZXWYROXAZRTXOEOLSKUTJAEKMGWABWHVAMYKPHQVCQLFMQNWOEOBRMETXOFVTQMGHJIIGIRWTKEVYQVFIFAJAEKMGWALYYVAVMUCKIYJQHLNHGGZZWGQBUTXGIMFYLRYVUDAVPIGVL";
    string p = string(c.size(),0);
    int e[4][4] = {{2,14,13,13},{4,2,19,4},{3,6,17,0},{15,7,8,2}};     //  key = cyclicgraphic
    int d[4][4] ;
    INV(e,d);

    cout << newl << "Given key is CYCLICGRAPHIC" << newl << newl; 
   
   cout << "Key matrix is: " << "\n\n";

   for ( int i = 0 ; i < 4 ;i++){
      for ( int j = 0 ; j < 4 ; j++)
         cout << e[i][j] << " ";
      cout << newl;
    }
    cout << newl;

    cout << "Finding inverse of key matrix: " << "\n\n";
    sleep(1);
    cout << "Inverse of key matrix is: " << "\n\n";
    
    for ( int i = 0 ; i < 4 ;i++){
      for ( int j = 0 ; j < 4 ; j++)
         cout << d[i][j] << " ";
      cout << newl;
    }

    cout << newl;
   cout << "Decrypting..." << "\n\n";
    sleep(1);
    for(int i=0; i < c.size(); i+=4){
        for (int j = 0 ; j < 4 ; j++){
            p[i+j] += (d[j][0]*(c[i] -'A'))%26;
            p[i+j] += (d[j][1]*(c[i+1] -'A'))%26;
            p[i+j] += (d[j][2]*(c[i+2] -'A'))%26;
            p[i+j] += (d[j][3]*(c[i+3] -'A'))%26;
            p[i+j] = (p[i+j]%26 + 26)%26 + 'A';
        }
    }
    cout << "Decrypted text is: " << "\n";
    cout << p << newl;
    cout << newl;

   
}

int32_t main()
{
    hillDecryptor();
    return 0;
}

