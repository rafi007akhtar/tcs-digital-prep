/** Redo thread-class.java, but using Runnable interface instead. */

class ThreadDemo implements Runnable
{
    int task, num1, num2;

    ThreadDemo(int task, int num1, int num2)
    {
        this.task = task;
        this.num1 = num1;
        this.num2 = num2;
    }

    void add()
    {
        int sum = num1 + num2;
        System.out.println(num1 + " + " + num2 + " = " + sum);
    }

    void multiply()
    {
        int prod = num1 * num2;
        System.out.println(num1 + " x " + num2 + " = " + prod);
    }

    void subtract()
    {
        int diff = num1 - num2;
        System.out.println(num1 + " - " + num2 + " = " + diff);
    }

    public void run()
    {
        // Defines what actions will a thread perform
        try 
        {
            switch(this.task)
            {
                case 0:
                    add();
                    break;
                case 1:
                    subtract();
                    break;
                case 2:
                    multiply();
                    break;
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}

class ThreadTest
{
    public static void main(String[] args)
    {
        int nThreads = 3; // number of threads
        int a = 5, b = 3; // use multithreading to perform operations with these numbers

        for (int i = 0; i < nThreads; i++)
        {
            // create an object of the Demo class
            ThreadDemo demo = new ThreadDemo(i, a, b);

            // create an object of the Thread class with Demo parameter
            Thread th = new Thread(demo);

            // start the execution of this thread
            th.start();
        }
    }
}


