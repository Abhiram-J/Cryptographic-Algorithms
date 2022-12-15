import java.util.*;

public class vigenereCipher {
    
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

            char[] c = new char[p.length]; 

            
            for (int i = 0 ; i < c.length ; i++){
                c[i] = (char)(((p[i]-'A') + (key[i%key.length] -'A'))%26 + 'A');
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
            
            char[] p = new char[c.length]; 

            for (int i = 0 ; i < c.length ; i++){
                p[i] = (char)(((c[i]-'A') - (key[i%key.length] -'A') + 26)%26 + 'A');
                // System.out.println(i);
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
