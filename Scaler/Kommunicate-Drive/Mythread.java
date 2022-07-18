public class Mythread {
    public static void main(String[] args) {
        ShotThread shot = new ShotThread();
        MissThread miss = new MissThread();
        shot.start();
        miss.start();
    }

}

   class ShotThread extends Thread {
        public void run(){
            for(int i=0;i<6;i++){
                System.out.println("Shot");
            }
        }
   
    }

 class MissThread extends Thread {
    public void run(){
            System.out.println("Miss");

    }
   

}


