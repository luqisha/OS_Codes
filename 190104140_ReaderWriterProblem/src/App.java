public class App {
    public static void main(String[] args) throws InterruptedException {
    
        Writer w1 = new Writer(1);
        Writer w2 = new Writer(2);

        Reader r1 = new Reader(1);
        Reader r2 = new Reader(2);

        w1.start();
        r1.start();
        w2.start();
        r2.start();

    }
}
