
import java.util.Scanner;

// You have:
// - 0 hundred(s)
// - 0 fifty(s)
// - 0 twenty(s)
// - 0 ten(s)
// - 1 five(s)
// - 1 one(s)
// - 3 quarter(s)
// - 0 dime(s)
// - 1 nickel(s)
// - 3 cent(s)



public class HW1_Milligan {


    public static void main(String[] args){

        //create scanner object and read the usrs number into a double variable with the scanner object
        Scanner usr_input = new Scanner(System.in);
        System.out.println("Enter your dollar amount: ");
        double number = usr_input.nextFloat();

   

        double div = 100;
        double hundreds = number/div;
        number = number - ((int)hundreds*div);

        div =  50;
        double fiftys = number/div;
        number = number - ((int)fiftys*div);

        div =  20;
        double twentys = number/div;
        number = number - ((int)twentys*div);

        div =  10;
        double tens = number/div;
        number = number - ((int)tens*div);

        div =  5;
        double fives = number/div;
        number = number - ((int)fives*div);

        div =  1;
        double ones = number/div;
        number = number - ((int)ones*div);

        div =  .25;
        double quarters = number/div;
        number = number - ((int)quarters*div);

        div =  .1;
        double dimes = number/div;
        number = number - ((int)dimes*div);

        div =  .05;
        double nickels = number/div;
        number = number - ((int)nickels*div);

        System.out.println(number);
        div =  .009999;
        double pennies = number/div;
        


        System.out.println("You have:");
        System.out.println("- " + (int)hundreds + " hundred(s)");
        System.out.println("- " + (int)fiftys + " fifty(s)");
        System.out.println("- " + (int)twentys + " twenty(s)");
        System.out.println("- " + (int)tens + " ten(s)");
        System.out.println("- " + (int)fives + " five(s)");
        System.out.println("- " + (int)ones + " one(s)");
        System.out.println("- " + (int)quarters + " quarter(s)");
        System.out.println("- " + (int)dimes + " dime(s)");
        System.out.println("- " + (int)nickels + " nickel(s)");
        System.out.println("- " + (int)pennies + " cent(s)");

        System.out.println("Goodbye!");


    }
}