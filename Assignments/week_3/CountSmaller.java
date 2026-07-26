import java.util.*;

public class CountSmaller {

    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static int[] ans;

    public static void countPairs(Pair[] arr, int low, int mid, int high) {

        int right = mid + 1;

        for (int left = low; left <= mid; left++) {

            while (right <= high && arr[right].value < arr[left].value) {
                right++;
            }

            ans[arr[left].index] += right - (mid + 1);
        }
    }

    public static void merge(Pair[] arr, int low, int mid, int high) {

        int left = low;
        int right = mid + 1;

        ArrayList<Pair> temp = new ArrayList<>();

        while (left <= mid && right <= high) {

            if (arr[left].value <= arr[right].value) {
                temp.add(arr[left]);
                left++;
            } else {
                temp.add(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.add(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.add(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }
    }

    public static void mergeSort(Pair[] arr, int low, int high) {

        if (low >= high)
            return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Pair[] arr = new Pair[n];

        ans = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(sc.nextInt(), i);
        }

        mergeSort(arr, 0, n - 1);

        for (int x : ans)
            System.out.print(x + " ");
    }
}
