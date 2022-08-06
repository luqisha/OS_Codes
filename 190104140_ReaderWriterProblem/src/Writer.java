import java.util.Random;

public class Writer extends Thread {
    int WriterID;

    Writer(int writerID)
    {
        this.WriterID = writerID;
    }

    @Override
    public void run()
    {
        do{

            try {

                SharedResource.write.acquire();
                System.out.println("Writer #" + WriterID + " performing writing.");
                SharedResource.buffer.push(new Random().nextInt()) ; 

                SharedResource.write.release();

                Thread.sleep(5000);

            }catch (InterruptedException e){
                e.printStackTrace();
            }

        }while(true);
    } 
}
