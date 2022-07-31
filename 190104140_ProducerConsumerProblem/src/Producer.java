import java.util.concurrent.Semaphore;

public class Producer extends Thread {
    int id = 1;
    Semaphore empty, full, mutex;
    
    Producer (Semaphore empty, Semaphore full, Semaphore mutex)
    {
        this.empty = empty;
        this.full = full;
        this.mutex = mutex;
    }
    
    @Override
    public void run() {
        do{
            try {
                empty.acquire();
                mutex.acquire();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            
            System.out.println("Producer produced item " + id );
            Shared.buffer.add(id++);
            System.out.println("Empty: " + (5- Shared.buffer.size()) );
            System.out.println("Full: " +  Shared.buffer.size() );
            
            mutex.release();
            full.release();

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }while(true);
    }
}