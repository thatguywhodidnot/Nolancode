import java.util.Scanner;

public class testing {

    public static void main(String[] args) {
        
        while(true){
            String userOption =  (new Scanner(System.in).nextLine()).toLowerCase();
            if(userOption.equals("yes") == false){
                System.out.println("Invalid option");
            }
            else{
                System.out.println(userOption);
                break;
            }
        }
    }
}