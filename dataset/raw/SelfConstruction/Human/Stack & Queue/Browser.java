import java.util.*;
import java.util.Stack;

public class Browser {

    Stack<String> backPages = new Stack<>();
    Stack<String> forwardPages = new Stack<>();
    String currentPage = " ";

    public void visitPage(String url) {
        backPages.push(currentPage);
        currentPage = url;
        forwardPages.clear();
        System.out.println("You are now visiting: " + currentPage);
    }

    public void goBack() {
        if (backPages.isEmpty()) {
            System.out.println("No page to go back to.");
            return;
        }
        forwardPages.push(currentPage);
        currentPage = backPages.pop();
        System.out.println("You went back to: " + currentPage);
    }

    public void goForward() {
        if (forwardPages.isEmpty()) {
            System.out.println(" No forward page available.");
            return;
        }
        backPages.push(currentPage);
        currentPage = forwardPages.pop();
        System.out.println(" You moved forward to: " + currentPage);
    }

    public void showCurrentPage() {
        System.out.println(" Current page: " + currentPage);
    }

    public static void main(String[] args) {
        Browser browser = new Browser();
        Scanner sc = new Scanner(System.in);
        int choice;

        

        while (true) {
            System.out.println("\nChoose an option:");
            System.out.println("1. Visit a new page");
            System.out.println("2. Go back");
            System.out.println("3. Go forward");
            System.out.println("4. Show current page");
            
            System.out.print("Your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter URL to visit: ");
                    String url = sc.next();
                    browser.visitPage(url);
                    break;
                case 2:
                    browser.goBack();
                    break;
                case 3:
                    browser.goForward();
                    break;
                case 4:
                    browser.showCurrentPage();
                    break;
                
                default:
                    System.out.println(" Invalid choice");
            }
        }
    }
}
