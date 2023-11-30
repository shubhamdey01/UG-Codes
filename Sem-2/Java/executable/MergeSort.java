package executable;

import java.util.Scanner;

public class MergeSort {
	private Scanner sc = new Scanner(System.in);
	private void sort(int[] ar, int l, int u) {
		if(l<u) {
			int m = l + (u-l)/2;
			sort(ar, l, m);
			sort(ar, m+1, u);
			merge(ar, l, m, u);
		}
	}
	private void merge(int[] ar, int l, int m, int u) {
		int l1 = m-l+1;
		int l2 = u-m;
		int L[] = new int[l1];
		int R[] = new int[l2];
		
		for(int i=0; i<l1; i++)
			L[i] = ar[l+i];
		for(int i=0; i<l2; i++)
			R[i] = ar[m+i+1];
		
		int i=0, j=0, k=l;
		while(i<l1 && j<l2) {
			if(L[i]<=R[j]) {
				ar[k] = L[i];
				i++;
			}
			else {
				ar[k] = R[j];
				j++;
			}
			k++;
		}
		while(i<l1) {
			ar[k] = L[i];
			i++;
			k++;
		}
		while(j<l2) {
			ar[k] = R[j];
			j++;
			k++;
		}
	}
	private void display(int[] ar) {
		for(int i : ar)
			System.out.print(i + "  ");
		System.out.println();
	}
	private int[] input(int n) {
		int[] ar = new int[n];
		for(int i=0; i<n; i++)
			ar[i] = sc.nextInt();
		return ar;
	}
	public void run() {
		System.out.println("\nHow many numbers ? :\t");
		int n = sc.nextInt();
		MergeSort ms = new MergeSort();
		System.out.printf("Enter %d numbers :\n",n);
		int[] arr = ms.input(n);
		System.out.println("Given array :");
		ms.display(arr);
		ms.sort(arr, 0, arr.length-1);
		System.out.println("\nSorted array :");
		ms.display(arr);
		
		for(int i=0; i<30; i++)
			System.out.print("=");
		System.out.println();
	}
}