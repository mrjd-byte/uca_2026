import java.util.*;

public class kClinics{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of villages: ");
        int n = sc.nextInt();
        System.out.print("Enter the number of clinics: ");
        int k = sc.nextInt();
        int[] population = new int[n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a , b) -> Double.compare((double) b[0]/b[1] , (double) a[0]/a[1]));

        for(int i = 0; i < population.length ; i++) {
            System.out.print("Enter the population of village "+i+": ");
            population[i] = sc.nextInt();
            pq.offer(new int[]{population[i] , 1});
            k--;
        }

        while (k > 0) {
            int[] village = pq.poll();
            village[1]++;
            System.out.println(Arrays.toString(village));
            k--;
            pq.offer(village);
        }

        System.out.printf("%.2f" , (float)pq.peek()[0] / pq.peek()[1]);
        System.out.println();
    }
}