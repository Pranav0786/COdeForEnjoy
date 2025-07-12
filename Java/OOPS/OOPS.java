package OOPS;
public class OOPS {
    public static void main(String[] args) {
        // Constructor();
        Static() ;
    }
}
public static class Students {
    int rollno ;
    String name ;  

    Students(){
        this(15,"Soham") ; // call the other constructor
    }   
    Students( int r , String n ){
        rollno = r ;
        name = n ;
    }
}
public static void Constructor(){
    Students arpit = new Students(10,"Arpit") ;
    Students soham = new Students() ;
    System.out.println(arpit.name + " " + arpit.rollno + " ");
    System.out.println(soham.name + " " + soham.rollno + " ");
}

public class  A {
    String name ;
    public A(String name ){
        this.name = name ;
        System.out.println(name);
    }
    protected void finalize() throws Throwable {
        System.out.println("Ended");
    };
}

public static void Static(){
    static int a = 4 ;
    static int b ;
    static{
        b = 10 ;
    }
    System.out.println(b);
}








