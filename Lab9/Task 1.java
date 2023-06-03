import java.util.*;
import java.math.*;
class Main
{

    static void generateGrayarr(int n)
    {
        if (n <= 0)
            return;

        ArrayList<String> arr = new ArrayList<String> ();


        arr.add("0");
        arr.add("1");

        int i, j;
        for (i = 2; i < (Math.pow(2, n)); i *= 2)
        {
            for (j = i-1 ; j >= 0 ; j--)
                arr.add(arr.get(j));

            for (j = 0 ; j < i ; j++)
                arr.set(j, "0" + arr.get(j));

            for (j = i ; j < 2*i ; j++)
                arr.set(j, "1" + arr.get(j));
        }

        for (i = 0 ; i < arr.size() ; i++ )
            System.out.println(arr.get(i));
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        generateGrayarr(n);
    }
}
