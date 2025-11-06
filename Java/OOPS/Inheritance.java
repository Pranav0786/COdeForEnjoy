public class Inheritance {

    public class A {
        public int data = 10;
        A () {} ;

        public void msg() {
            System.out.println("Hello A");
        }
    }
    public class B extends A {
        public int data = 20;
        B() {} ;

        public void msg() {
            System.out.println("Hello B");
        }

        public void display() {
            System.out.println(super.data);
        }
    }

    public static void main(String[] args) {
        Inheritance obj = new Inheritance();
        A a = obj.new B();
        System.out.println(a.data);
        a.msg();
        
    }
}
