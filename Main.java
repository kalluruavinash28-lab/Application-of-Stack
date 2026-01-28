public class Main {
    public static void main(String[] args) {

        BrowserHistory browser = new BrowserHistory("google.com");

        browser.visit("youtube.com");
        browser.visit("github.com");
        browser.showStatus();

        browser.back();
        browser.showStatus();

        browser.forward();
        browser.showStatus();
    }
}
