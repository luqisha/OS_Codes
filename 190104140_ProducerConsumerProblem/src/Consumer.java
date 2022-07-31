import java.util.concurrent.Semaphore;

public class Consumer extends Thread {
    Semaphore empty, full, mutex;
        
    Consumer (Semaphore empty, Semaphore full, Semaphore mutex)
    {
        this.empty = empty;
        this.full = full;
        this.mutex = mutex;    
    }
    
    @Override
    public void run() {
        do{
            try {
                full.acquire();
                mutex.acquire();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Consumer Consumed item : " + Shared.buffer.get(0));
            Shared.buffer.remove(0);
            System.out.println("Empty: " + (5- Shared.buffer.size()) );
            System.out.println("Full: " +  Shared.buffer.size() );

            mutex.release();
            empty.release();

            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }while(true);           
    }
}