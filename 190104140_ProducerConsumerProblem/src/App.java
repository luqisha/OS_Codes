import java.util.concurrent.Semaphore;

public class App {
    public static void main(String args[]) throws InterruptedException {
        Semaphore full = new Semaphore (0, true);
        Semaphore empty = new Semaphore (5, true);
        Semaphore mutex = new Semaphore (1, true);
        

        Producer P1 = new Producer (empty, full, mutex);
        Consumer C1 = new Consumer (empty, full, mutex);
        
        P1.start();
        C1.start();
        
        P1.join();
        C1.join();
      }
}
