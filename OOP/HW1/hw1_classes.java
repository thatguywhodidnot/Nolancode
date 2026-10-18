import java.util.Scanner;

class currency{

    public double div; 


    public double calc(double div, double num){
        
        double currency_amount = num/div;
        System.out.println((int)currency_amount);
        
        double new_num = num - (int)currency_amount * div;

        return new_num;
    }
}


public class hw1_classes{
    public static void main(){

        double x = (new Scanner(System.in)).nextDouble();
        currency hundreds = new  currency();
        
        hundreds.div = 100;

        System.out.println("- ");
        x = hundreds.calc(100.0, x);
        System.out.println(" hundred(s)");


    }
}