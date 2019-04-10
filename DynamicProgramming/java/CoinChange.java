
public class LeveshteinDistance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String s1 = "abcdef";
		String s2 = "azced";
		
		System.out.println(getDistance(s1, s2));

	}
	
	public static int getDistance(String str1, String str2) {
		int dist = 0;
		int l2 = str1.length();
		int l1 = str2.length();
		
		int [][] arr = new int[l1+1][l2+1];
		
		for(int i = 0; i <= l1; i++) {
			for(int j = 0; j <= l2; j++) {
				if(i == 0 && j ==0) {
					arr[i][j] = 0;
				} else if(i == 0) {
					arr[i][j] = arr[i][j-1] + 1;
				} else if (j == 0) {
					arr[i][j] = arr[i-1][j]+1;
				} else {
					if(str1.charAt(j-1) == str2.charAt(i-1)) {
						arr[i][j] = arr[i-1][j-1];
					} else {
						arr[i][j] = minNum(arr[i-1][j], arr[i-1][j-1], arr[i][j-1]) + 1;
					}
				}
			}
		}
		dist = arr[l1][l2];
		return dist;
	}
	
	public static int minNum(int a, int b, int c) {
		if(a<b) {
			if(a<c) return a;
			else return c;
		} else {
			if(b < c) return b;
			else return c;
		}
	}

}

