import java.util.*;

public class hillCipher {
    private static int modInverse(int a, int mod){
        for (int i = 1; i < mod; i++){
            if (((a % mod) * (i % mod)) % mod == 1){
                return i;
            }
        }
        return -1;
    }


    private static void getCfactor(int M[][], int t[][], int p, int q, int n) {
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

    private static int DET(int M[][], int n) {
    int D = 0;
    if (n == 1)
        return M[0][0];
    int[][] t = new int[n][n]; 
    int s = 1; 
    for (int f = 0; f < n; f++) {
            getCfactor(M, t, 0, f, n);
            D += ((s) * (M[0][f]) * (DET(t, n - 1)));
        s = -s;
    }
    return D;
    }

    private static void ADJ(int M[][],int adj[][]) {
    
    int s = 1;
    int[][] t = new int[M.length][M.length];
    for (int i=0; i<M.length; i++) {
        for (int j=0; j<M.length; j++) {
            
            getCfactor(M, t, i, j, M.length);
            s = ((i+j)%2==0)? 1: -1; 
            adj[j][i] = (s)*(DET(t, M.length-1)); 
        }
    }
    }

    private static void INV(int M[][], int inv[][]) {
    int det = DET(M, M.length);
    int[][] adj = new int[M.length][M.length];
    ADJ(M, adj);
    for (int i=0; i<M.length; i++) 
        for (int j=0; j<M.length; j++) 
            inv[i][j] = (( adj[i][j]*modInverse(det,26))%26 + 26 )%26;

    }


    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("1. Encrypt");
        System.out.println("2. Decrypt");
        System.out.println("Enter your choice: ");
        int choice = sc.nextInt();
        sc.nextLine();

        if ( choice == 1){
            System.out.println("Enter the string to be encrypted: ");
            char[] p = sc.next().toCharArray();
            for ( int i = 0 ; i < p.length ; i++){
                p[i] = Character.toUpperCase(p[i]);
            }

            System.out.println("Enter the key : ");
            char[] key = sc.next().toCharArray();
            for( int i = 0 ; i < key.length ; i++){
                key[i] = Character.toUpperCase(key[i]);
            }

            int n = (int)Math.sqrt(key.length);
            
            int[][] e = new int[n][n];
            
            for ( int i = 0 ; i < n ; i++){
                for ( int j = 0 ; j < n ; j++){
                    e[i][j] = key[i*n + j] - 'A';
                }
            }
            char[] c = new char[p.length]; 

            
            for(int i=0; i < p.length; i+=n){
                for (int j = 0 ; j < n ; j++){
                    for ( int k = 0 ; k < n ; k++){
                        c[i+j] += (e[j][k]*(p[i+k] -'A'))%26;
                    }
                    c[i+j] = (char)(c[i+j]%26 + 'A');
                }
            }

            System.out.println("The encrypted string is: ");
            for (int i = 0 ; i < c.length ; i++){
                System.out.print(c[i]);
            }
            System.out.println();

            
        }else{

            System.out.println("Enter the string to be decrypted: ");
            char[] c = sc.next().toCharArray();
            for ( int i = 0 ; i < c.length ; i++){
                c[i] = Character.toUpperCase(c[i]);
            }
            System.out.println("Enter the key : ");
            char[] key = sc.next().toCharArray();
            for( int i = 0 ; i < key.length ; i++){
                key[i] = Character.toUpperCase(key[i]);
            }
            

            int n = (int)Math.sqrt(key.length);
            
            int[][] e = new int[n][n];
            
            for ( int i = 0 ; i < n ; i++){
                for ( int j = 0 ; j < n ; j++){
                    e[i][j] = key[i*n + j] - 'A';
                }
            }
            
            int[][] d = new int[n][n];
            INV(e,d);
            char[] p = new char[c.length]; 

            for(int i=0; i < p.length; i+=n){
                for (int j = 0 ; j < n ; j++){
                    for ( int k = 0 ; k < n ; k++){
                        p[i+j] += (d[j][k]*(c[i+k] -'A'))%26;
                    }
                    p[i+j] = (char)(p[i+j]%26 + 'A');
                }
            }


            System.out.println("The decrypted string is: ");
            for (int i = 0 ; i < p.length ; i++){
                System.out.print(p[i]);
            }
            System.out.println();
        }
        sc.close();
    }
    
}
