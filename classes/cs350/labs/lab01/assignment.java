import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Locale;

class Level { 
  int spaces;
}

public class Assignment {

  /**
   * @param args
   */
  public static void main(String[] args)  {
        Level l1 = new Level();
        Level l2 = new Level();
        l1.spaces = 10;
        l2.spaces = 3;

        System.out.println("After initialization:");
        System.out.println("1: l1.spaces: " + l1.spaces +  ", l2.spaces: " + l2.spaces);
        l2 = l1;
        System.out.println("After assignment:");
        System.out.println("2: l1.spaces: " + l1.spaces +  ", l2.spaces: " + l2.spaces);
        l2.spaces = 0;
        System.out.println("3: l1.spaces: " + l1.spaces +  ", l2.spaces: " + l2.spaces);
    }

}
