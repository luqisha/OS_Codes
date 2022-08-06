import java.util.Stack;
import java.util.concurrent.Semaphore;

public class SharedResource {
    static int readCount = 0 ;
    static Semaphore mutex = new Semaphore(1);
    static Semaphore write = new Semaphore(1);
    static Stack<Integer> buffer = new Stack<Integer>();
}
