/* Lab Program 12
   Write a Java program to copy the contents of one text file to another
   and report the number of characters copied. Handle file not found.
   javac Lab12_FileCopy.java && java Lab12_FileCopy source.txt dest.txt */

import java.io.*;

class Lab12_FileCopy {
    public static void main(String[] args) {
        if(args.length != 2) {
            System.out.println("usage: java Lab12_FileCopy source dest");
            return;
        }

        try {
            FileReader fr = new FileReader(args[0]);
            FileWriter fw = new FileWriter(args[1]);

            int ch, count = 0;
            while((ch = fr.read()) != -1) {
                fw.write(ch);
                count++;
            }

            fr.close();
            fw.close();
            System.out.println(count + " characters copied to " + args[1]);
        }
        catch(FileNotFoundException e) {
            System.out.println("file " + args[0] + " not found");
        }
        catch(IOException e) {
            System.out.println("io error: " + e.getMessage());
        }
    }
}
