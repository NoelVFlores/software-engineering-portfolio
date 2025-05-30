import java.util.Scanner;

public class compoundInterest {
    public static void main(String[] args){

        // Compound Interest calculator

        Scanner scanner = new Scanner(System.in);


        double principal;
        double rate;
        int timesCompounded;
        int years;
        double amount;


        System.out.print("Enter the principal amount: ");
        principal = scanner.nextDouble();

        System.out.print("Enter the interest rate (in %): ");
        rate = scanner.nextDouble() / 100; // turn to decimal

        System.out.print("Enter the # of times compounded per year: ");
        timesCompounded = scanner.nextInt();

        System.out.print("Enter the number of years: ");
        years = scanner.nextInt();

        amount = principal * Math.pow(1 + rate / timesCompounded, timesCompounded * years);


        System.out.printf("The amount after %d years is: $%,.2f \n", years, amount);

        scanner.close();
    }
}
