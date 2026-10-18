import java.util.Scanner;



public class HW2_Milligan {
    //initialization of letter score counters
    public static int As = 0, Bs = 0, Cs = 0, Ds = 0, Fs = 0;
    public static int total_score = 0;

    public static void check_score(int score){
        total_score += score;
        if(score >= 90){
            As += 1;
            return;
        }
        else if(score >= 80){
            Bs += 1;
            return;
        }
        else if(score >= 70){
            Bs += 1;
            return;
        }
        else if(score >= 60){
            Bs += 1;
            return;
        }
        else{
            Fs += 1;
            return;
        }
    }

    public static void main(String[] args){
        int x = 0, score_count = 0;

        System.out.println("Welcome to my program. You will be asked to enter the scores of a test one by one, and to enter -1 to stop.");
        //main while loop to keep asking for scores
        while(x != -1){

            System.out.println("Enter Score (Enter -1 to Stop): ");
            x = (new Scanner(System.in)).nextInt();

            if (x == -1) {
                break;
            }
            //if score is within the valid range it is checked
            //a corresponding letter grade variable is incremented as well as the total scores variable
            if(x <= 100 && x > -1){
                check_score(x);
                score_count += 1;
            }
            //if entered score value is invalid print rejectm message
            else{
                System.out.println("Score " + x + " Rejected");
            }
        }
        int passing = score_count - (Fs + Ds);
        double average = (double)total_score/(double)score_count;
        //print grade report info
        System.out.println("Here is your report:");
        System.out.println("\tA total of " + score_count + " scores entered. " + passing + " of them are 70 or higher.\n");

        System.out.println("\tLetter Grade distribution of the scores: ");

        System.out.println("\t\t" + As + " Students earned the letter grade of A (90-100)");
        System.out.println("\t\t" + Bs + " Students earned the letter grade of B (80-89)");
        System.out.println("\t\t" + Cs + " Students earned the letter grade of C (70-79)");
        System.out.println("\t\t" + Ds + " Students earned the letter grade of D (60-69)");
        System.out.println("\t\t" + Fs + " Students earned the letter grade of F (50 or below)");

        System.out.printf("\n\tThe average score is: %.2f", average);




    }

    
}

