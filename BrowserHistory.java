import java.util.Stack;

public class BrowserHistory {
    private String currentPage;
    private Stack<String> backStack;
    private Stack<String> forwardStack;

    // Constructor
    public BrowserHistory(String homepage) {
        this.currentPage = homepage;
        this.backStack = new Stack<>();
        this.forwardStack = new Stack<>();
    }

    // Visit a new page
    public void visit(String url) {
        backStack.push(currentPage);
        currentPage = url;
        forwardStack.clear();
    }

    // Go back to previous page
    public String back() {
        if (backStack.isEmpty()) {
            System.out.println("No page to go back to");
            return currentPage;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.pop();
        return currentPage;
    }

    // Go forward to next page
    public String forward() {
        if (forwardStack.isEmpty()) {
            System.out.println("No page to go forward to");
            return currentPage;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.pop();
        return currentPage;
    }

    // Display current status
    public void showStatus() {
        System.out.println("Current Page: " + currentPage);
        System.out.println("Back Stack: " + backStack);
        System.out.println("Forward Stack: " + forwardStack);
        System.out.println("--------------------------------");
    }
}
