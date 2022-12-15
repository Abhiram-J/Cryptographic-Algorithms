import java.util.*;
import java.math.BigInteger;
import java.security.SecureRandom;


class RSA1024bit{

    private static void generateKeyPair(Scanner sc) {
        Random rand = new SecureRandom();
        BigInteger p = BigInteger.probablePrime(512, rand);
        BigInteger q = BigInteger.probablePrime(512, rand);
        BigInteger n = p.multiply(q);
        BigInteger phi = p.subtract(new BigInteger("1")).multiply(q.subtract(new BigInteger("1")));

        BigInteger e = new BigInteger("65537");
        BigInteger d = e.modInverse(phi);

        System.out.println();
        System.out.println("The private key d is ");
        System.out.println(d);

        System.out.println();
        System.out.println("The public key e is ");
        System.out.println(e);

        System.out.println();
        System.out.println("The modulus n is ");
        System.out.println(n);
    }

    private static void encrypt(Scanner sc) {
        sc.nextLine();

        System.out.println();
        System.out.println("Enter the message");
        String pt = sc.nextLine();

        System.out.println();
        System.out.println("Enter the public key e");
        BigInteger e = sc.nextBigInteger();

        System.out.println();
        System.out.println("Enter the modulus n");
        BigInteger n = sc.nextBigInteger();
        
        BigInteger pNo = new BigInteger("1");

        for(int i=0; i < pt.length(); i++){
            pNo = pNo.shiftLeft(8);
            pNo = pNo.add(new BigInteger(String.valueOf((int)pt.charAt(i))));
        }

        BigInteger c = pNo.modPow(e, n);

        System.out.println();
        System.out.println("The encrypted message is ");
        System.out.println(c);

    }

    private static void decrypt(Scanner sc){

        System.out.println();
        System.out.println("Enter the encrypted message");
        BigInteger c = sc.nextBigInteger();

        System.out.println();
        System.out.println("Enter the private key d");
        BigInteger d = sc.nextBigInteger();

        System.out.println();
        System.out.println("Enter the modulus n");
        BigInteger n = sc.nextBigInteger();

        BigInteger Mod = new BigInteger("256");
        String m = "";

        BigInteger pNo = c.modPow(d, n);

        while(pNo.compareTo(new BigInteger("0")) == 1){
            BigInteger temp = pNo.mod(Mod);
            m = (char)temp.intValue() + m;
            pNo = pNo.shiftRight(8);
        }

        System.out.println();
        System.out.println("The decrypted message is" );
        System.out.println(m);


    }

    
    public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);
    
    System.out.println("1. Generate key pair");
    System.out.println("2. Encrypt");
    System.out.println("3. Decrypt");
    System.out.println("Enter your choice: ");
    int choice = sc.nextInt();

    if ( choice == 1){
        generateKeyPair(sc);
    }else if ( choice == 2){
        encrypt(sc);
    }else{
        decrypt(sc);
    }

    sc.close();

    }
}


