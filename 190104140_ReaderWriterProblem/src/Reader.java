
public class Reader extends Thread {
    int ReaderID;

    Reader(int readerID) {
        this.ReaderID = readerID;
    }

    @Override
    public void run() {
        do {
            try {

                SharedResource.mutex.acquire();

                SharedResource.readCount++;
                if (SharedResource.readCount == 1) {
                    SharedResource.write.acquire();
                }

                SharedResource.mutex.release();

                System.out.println("Reader #" + ReaderID + " performing read. " + "Top value is: " + SharedResource.buffer.peek());

                SharedResource.mutex.acquire();

                SharedResource.readCount--;
                if (SharedResource.readCount == 0) {
                    SharedResource.write.release();
                }

                SharedResource.mutex.release();

                Thread.sleep(3000);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        } while (true);
    }
}
