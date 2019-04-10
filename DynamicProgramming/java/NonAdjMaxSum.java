
public class NonAdjMaxSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {4,1,1,4,2,1};
		
		System.out.println(getNonAdjMaxSum(arr));

	}
	
	public static int maxNum(int a, int b) {
		if(a > b) return a;
		else return b;
	}
	
	public static int getNonAdjMaxSum(int[] arr) {
		int sum = 0;
		
		int incl = arr[0];
		int excl = 0;
		
		for(int i = 1; i < arr.length; i++) {
			sum = maxNum(incl, excl + arr[i]);
			excl = incl;
			incl = sum;
		}
		return incl;
	}

}
