import java.util.*;

public class count_reverse_pair {

    static long count = 0;

    public static void countPairs(int[] arr, int low, int mid, int high) {
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2L * arr[right]) {
                right++;
            }

            count += right - (mid + 1);
        }
    }

    public static void merge(int[] arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;

        ArrayList<Integer> temp = new ArrayList<>();

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
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

    public static void mergeSort(int[] arr, int low, int high) {

        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);
    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter size of Array: ");
	int size = sc.nextInt();

        int[] nums = new int[size];

	System.out.println("Enter " + size + " integers:");
        for (int i = 0; i < size; i++) {
            nums[i] = sc.nextInt();
        }

        mergeSort(nums, 0, nums.length - 1);

        System.out.println(count);
    }
}
