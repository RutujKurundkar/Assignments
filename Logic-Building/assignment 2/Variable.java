class Variable{
	public static void main (String args[]){
		byte a=16;
		short b=10;
		int c=50000;
		long d=866875744;
		float e=3.14f;
		double f=2.500000;
		char g='A';
		Boolean h=true;
		System.out.println (a);
		System.out.println (b);
		System.out.println (c);
		System.out.println (d);
		System.out.println (e);
		System.out.println (f);
		System.out.println (g);
		System.out.println (h);

}}

/*Output:- when not initialised:-
Variable.java:11: error: variable a might not have been initialized
                System.out.println (a);
                                    ^
Variable.java:12: error: variable b might not have been initialized
                System.out.println (b);
                                    ^
Variable.java:13: error: variable c might not have been initialized
                System.out.println (c);
                                    ^
Variable.java:14: error: variable d might not have been initialized
                System.out.println (d);
                                    ^
Variable.java:15: error: variable e might not have been initialized
                System.out.println (e);
                                    ^
Variable.java:16: error: variable f might not have been initialized
                System.out.println (f);
                                    ^
Variable.java:17: error: variable g might not have been initialized
                System.out.println (g);
                                    ^
Variable.java:18: error: variable h might not have been initialized
                System.out.println (h);
                                    ^
8 errors*/

