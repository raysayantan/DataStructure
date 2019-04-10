
public class CoinChange {
	
	static int [][] arr = new int[3][6];
    static int [] dinno = {2,3,4};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(getNumWays(5));

	}
	
	public static int getNumWays(int n) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 6; j++) {
				if(i == 0) {
					if( j == 0) {
						arr[i][j] = 1;
					} else if((j)%dinno[i] == 0) {
						arr[i][j] = 1;
					} else {
						arr[i][j] = 0;
					}
				} else if(j == 0) {
					arr[i][j] = 1;
				} else {
					if(j < dinno[i]) {
						arr[i][j] = arr[i-1][j];
					} else {
						arr[i][j] = arr[i-1][j] + arr[i][j-dinno[i]];
					}
				}
			}
		}
		
		return arr[2][5];
	}

}
