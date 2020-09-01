package random;

import java.util.Scanner;

public class HelloJava {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (s.hasNextLine()) {
            System.out.println(s.nextLine().split(" ")[0]);
        }
        s.close();
    }
}
