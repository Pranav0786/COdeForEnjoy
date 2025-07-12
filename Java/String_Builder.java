public class String_Builder {
    public static void main(String[] args) {

        // String a = "Om" ;
        // String b = "Om" ;
        // System.out.println( a == b );    // true 

        // String a = new String( "Sujal" ) ;
        // String b = new String("Sujal") ;
        // System.out.println( a == b );    // fasle
        // System.out.println( a.equals(b));  // true
        // System.out.println(a.charAt(0));

        // PrettyPrinting ------------
        // float a = 123.3456f ;
        // System.out.printf("%.2f\n" , a);
        // System.out.println('a'+'b'); // ascii value addition
        // System.out.println("a"+"b"); // print "ab" 
        // System.out.println('a'+3); // print ascii value 
        // System.out.println("a"+3); // print "a3"
        // System.out.println("Kunal" + new ArrayList<>());
        // System.out.println("Kunal" + new Integer(43));
        // String ans = new ArrayList<>() + " " + new Integer(67) ;    
        // System.out.println(ans);
    
        // Performance diff String and StringBuilder
        // ****making new object every time and add to new char to it 
        // ****copy previous add new char
        // String q = "" ;
        // for (int i = 0; i < 26; i++) {
        //     char ch = (char) ('a' + i) ;
        //     q = q + ch ;
        // }
        // System.out.println(q);
        // ***** StringBuilder
        // Create only one object and make changes into it
        // StringBuilder s = new StringBuilder() ;
        // for (int i = 0; i < 26 ; i++) {
        //     char ch = (char) ('a' + i) ;
        //     s.append(ch) ;
        // }
        // System.out.println(s);


    }
}
