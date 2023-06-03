import java.util.Scanner;

public class Main
{

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int summ = 0;
        for (String numOrOperat : scanner.nextLine().split(" "))
        {
            if (Character.isDigit(numOrOperat.charAt(0)))
                summ += Integer.parseInt(numOrOperat);
        }
        System.out.print(summ);
    }
}
