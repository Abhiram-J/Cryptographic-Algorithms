import java.util.*;


public class affineCipher {


    private static int modInverse(int a, int mod){
        for (int i = 1; i < mod; i++){
            if (((a % mod) * (i % mod)) % mod == 1){
                return i;
            }
        }
        return -1;
    }
   

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("1. Encrypt");
        System.out.println("2. Decrypt");
        System.out.println("Enter your choice: ");
        int choice = sc.nextInt();
        sc.nextLine();

        if ( choice == 1){
            System.out.println("Enter the string to be encrypted : ");
            char[] p = sc.next().toCharArray();

            for ( int i = 0 ; i < p.length ; i++){
                p[i] = Character.toUpperCase(p[i]);
            }

            System.out.println("Enter the value of a: ");
            int a = sc.nextInt();
            System.out.println("Enter the value of b: ");
            int b = sc.nextInt();

            char[] c = new char[p.length]; 

            for (int i = 0 ; i < p.length ; i++){
                c[i] = (char)((a*(p[i] -'A') + b)%26 + 'A');
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
            System.out.println("Enter the value of a: ");
            int a = sc.nextInt();
            System.out.println("Enter the value of b: ");
            int b = sc.nextInt();

            char[] p = new char[c.length]; 

            for (int i = 0 ; i < c.length ; i++){
                p[i] = (char)((modInverse(a,26)*(c[i] -'A' - b + 26))%26 + 'A');
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