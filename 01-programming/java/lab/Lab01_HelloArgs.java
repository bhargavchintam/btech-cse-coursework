/* Lab Program 1
   Write a Java program to display a welcome message and print all the
   command line arguments passed to it.
   javac Lab01_HelloArgs.java && java Lab01_HelloArgs one two three */

class Lab01_HelloArgs {
    public static void main(String args[]) {
        System.out.println("Hello Java");
        System.out.println("Number of arguments : " + args.length);
        for(int i = 0; i < args.length; i++) {
            System.out.println("arg[" + i + "] = " + args[i]);
        }
    }
}
