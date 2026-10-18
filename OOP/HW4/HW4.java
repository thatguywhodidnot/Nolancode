import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class HW4{

    public static void main(String[] args){
        while(true){
            String currentBookInfo, currentBookType;
            int bookCount = 0;
            ArrayList<Book> bookList = new ArrayList<>();
            


            System.out.println("Would you like to create a book object? (yes/no): ");
            String userOption =  (new Scanner(System.in).nextLine()).toLowerCase();

            if(userOption.equals("yes")){
                System.out.println("Enter the author, title and the isbn of the book separated by /:");
                currentBookInfo = (new Scanner(System.in).nextLine()).toLowerCase();
                while(true){
                    if(Book.getBookType().equals("bb")){
                        bookList.add(new BookstoreBook(currentBookInfo));
                    }
                    else if(Book.getBookType().equals("lb")){
                        bookList.add(new LibraryBook(currentBookInfo));
                    }
                    else{
                        System.out.println("Oops! That’s not a valid entry. Please try again: ");
                    }
                }
            }
            else if(userOption.equals("no")){
             
                break;
            }
            else{
                System.out.println("Oops! That’s not a valid entry. Please try again: ");
            }
        }
    }
}

abstract class Book{
    private String author, title, isbn;

    public static String getBookType(){
        System.out.println("Got it!");
        System.out.println("Now, tell me if it is a bookstore book or a library book (enter BB for bookstore book or LB for library book): ");
        return (new Scanner(System.in).nextLine()).toLowerCase();
    }
    public String getAuthor(){return author;}
    public void setAuthor(String author){this.author = author;}

    public String getTitle(){return title;}
    public void setTitle(String title){this.title = title;}

    public String getIsbn(){return isbn;}
    public void setIsbn(String isbn){this.isbn = isbn;}

    @Override
    public String toString() {
        return (author + title + isbn);
    }
}

class BookstoreBook extends Book{
    private double price, saleRate;
    private boolean onSale;

    public void BookstoreBook(String bookInfo){
        String[] splitInfo = bookInfo.split("/");
        setAuthor(splitInfo[0]);
        setTitle(splitInfo[1]);
        setIsbn(splitInfo[2]);

        System.out.println("Enter the list price of " + getTitle().toUpperCase() +" by " + getAuthor().toUpperCase() +": ");
        price = (new Scanner(System.in).nextDouble());
        

    }
    
    @Override
    public String toString() {

        return super.toString();
    }

}

class LibraryBook extends Book{
    private String Subject, callNumber;
    //call number format = <subject code>.<floor number>.<author name>.<last char of isbn>

    public void LibraryBook(String bookInfo){
        String[] splitInfo = bookInfo.split("/");
        setAuthor(splitInfo[0]);
        setTitle(splitInfo[1]);
        setIsbn(splitInfo[2]);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}