import java.util.*;

public class find_num {

    public static void main(String[] args) {

        int[] arr = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};

        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {

            int count = 0;

            for (int num : arr) {
                if ((num & (1 << bit)) != 0) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                ans = ans | (1 << bit);
            }
        }

        System.out.println(ans);
    }
}