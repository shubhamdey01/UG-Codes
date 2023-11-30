package executable;

public class ComplexMatrix extends Complex {
	private int row,col;
	private Complex mat[][];

	public ComplexMatrix() {
		;
	}
	private ComplexMatrix(int row,int col) {
		this.row = row;
		this.col = col;
		mat = new Complex[row][col];
	}
	private void input() {
		System.out.println("NOTE : Plese do not enter white spaces between a complex number");
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				mat[i][j] = new Complex(sc.next());
	}
	protected void display() {
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				System.out.print("\t");
				mat[i][j].display();
				System.out.print("\t");
			}
			System.out.println();
		}
	}
	private ComplexMatrix multiply(ComplexMatrix x) {
		if(col != x.row) {
			System.out.println("\nCan't multiply these matrices.");
			
			for(int i=0; i<30; i++)
				System.out.print("=");
			System.out.println();
			System.exit(1);
		}
		ComplexMatrix res = new ComplexMatrix(row,x.col);
		for(int i=0;i<row;i++)
			for(int j=0;j<x.col;j++) {
				res.mat[i][j] = new Complex();
				for(int k=0;k<col;k++)
					res.mat[i][j] = res.mat[i][j].add(mat[i][k].multiply(x.mat[k][j]));
			}
		return res;
	}
	public void start() {
		System.out.println("Enter dimensions of the matrix A :");
		ComplexMatrix A = new ComplexMatrix(sc.nextInt(),sc.nextInt());
		System.out.println("\nEnter elements for matrix A (a+bi) :");
		A.input();
		System.out.println("\nEnter dimensions of the matrix B :");
		ComplexMatrix B = new ComplexMatrix(sc.nextInt(),sc.nextInt());
		System.out.println("\nEnter elements for matrix B (a+bi) :");
		B.input();
		System.out.println("\nMatrix A =");
		A.display();
		System.out.println("\nMatrix B =");
		B.display();
		ComplexMatrix C = A.multiply(B);
		System.out.println("\nProduct matrix C =");
		C.display();
		
		for(int i=0; i<30; i++)
			System.out.print("=");
		System.out.println();
	}
}