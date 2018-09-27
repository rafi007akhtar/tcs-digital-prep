/**
Try and test the following topics discussed in PPT (Pre-Placement Training):
    * static block
    * variable length parameters 
    * private constructors
    * ragged arrays
in Java 
*/

class PPT
{
    int var;
    private PPT(int var)
    {
        this.var = var;
    }

    public static void main(String...args)
    {
        // The following statements will be loaded after the static block
        System.out.println("\nStatement inside main.");
        // variable length parameters in args
        for (String arg : args)
            System.out.print(arg + " ");
        System.out.println();

        // Ragged arrays
        System.out.println("\nTest for ragged arrays \n--------------");
        int ragged[][] = new int[2][];
        ragged[0] = new int[2]; // initialized to zeroes by default
        ragged[1] = new int[3]; // initialized to zeroes by default
        /* Shape of the array:
            # #
            # # #
        */
        for (int i = 0; i < 2; i++)
        {
            for (int j: ragged[i])
                System.out.print(j + " ");
            System.out.println();
        }
    }

    static
    {
        System.out.println("Statement inside static block.");
        PPT obj = new PPT(5);
        System.out.println("Private instance of this class has value " + obj.var + ".");
    }
}
