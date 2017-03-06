//Zack Shumate
//AP Java
//Lab 4

import java.util.Random;
public class Sort{
	public static void main(String [] args){
		int[] a1=new int[10];
		int[] a2=new int[10];
		populate(a1);

		printArray(a1);
		selectionSort(a1);
		printArray(a1);
		populate(a2);
		printArray(a2);
		bubbleSort(a2);
		printArray(a2);
	}

	public static void selectionSort(int[] a){
		for(int i=0; i<a.length-1; i++){
			int minIndex=findMinimum(a, i);
			if(minIndex !=i){
				swap(a, i, minIndex);
			}
		}
		return;
	}

	private static int findMinimum(int[] a, int first){
		int minIndex=first;
		for(int i=first+1; i<a.length; i++){
			if(a[i]<a[minIndex]){
				minIndex=i;
			}
		}
		return minIndex;
	}

	private static void swap(int[] a, int x, int y){
		int temp=a[x];
		a[x]=a[y];
		a[y]=temp;
	}

	public static void bubbleSort(int[] a){
		int k=0;
		boolean exchangeMade=true;
		while((k<a.length-1)&&exchangeMade){
			exchangeMade=false;
			k++;
			for(int j=0; j<a.length-k; j++){
				if(a[j]>a[j+1]){
					swap(a, j, j+1);
					exchangeMade=true;
				}
			}
		}
	}

	public static void populate(int[] a){
		Random rand=new Random();
		for(int i=0; i<a.length; i++){
			a[i]=rand.nextInt(100)+1;
		}
	}

	public static void printArray(int[] a){
		for(int i=0; i<a.length; i++){
			System.out.println("Cell "+i+" contains "+a[i]);
		}
		System.out.print("\n");
	}
}