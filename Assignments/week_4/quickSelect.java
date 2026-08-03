import java.util.*;

public class quickSelect {

    private static final Random rand = new Random();

    public static int[] smallestK(int[] arr, int k) {
        if (k <= 0) return new int[0];
        if (k >= arr.length) return arr;

        quickSelect(arr, 0, arr.length - 1, k - 1);

        return Arrays.copyOf(arr, k);
    }

    private static void quickSelect(int[] arr, int left, int right, int k) {
        while (left <= right) {
            int pivotIndex = partition(arr, left, right);

            if (pivotIndex == k) {
                return;
            } else if (pivotIndex < k) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
    }

    private static int partition(int[] arr, int left, int right) {
        int randomIndex = left + rand.nextInt(right - left + 1);
        swap(arr, randomIndex, right);

        int pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, right);
        return i;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {

        Random random = new Random();

        System.out.println("N,Time(ms)");

        for (int n = 10000; n <= 1000000; n *= 2) {

            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = random.nextInt();
            }

            int k = n / 10;

            long start = System.nanoTime();

            smallestK(arr, k);

            long end = System.nanoTime();

            double time = (end - start) / 1_000_000.0;

            System.out.printf("%d,%.3f%n", n, time);
        }
    }
}