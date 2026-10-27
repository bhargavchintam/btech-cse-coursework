import java.util.ArrayList;
import java.util.Scanner;

class Book {
    int id;
    String title;
    String author;
    boolean avail;

    Book(int id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        avail = true;
    }
}

public class LibraryManagement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Book> books = new ArrayList<>();

        books.add(new Book(1, "The Complete Reference", "Herbert Schildt"));
        books.add(new Book(2, "Let Us C", "Yashavant Kanetkar"));
        books.add(new Book(3, "Programming in ANSI C", "Balagurusamy"));

        while (true) {
            System.out.println("1. Add book");
            System.out.println("2. Display books");
            System.out.println("3. Issue book");
            System.out.println("4. Return book");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Enter book id: ");
                    int id = sc.nextInt();
                    sc.nextLine();   // nextInt leaves the newline
                    System.out.print("Enter title: ");
                    String t = sc.nextLine();
                    System.out.print("Enter author: ");
                    String a = sc.nextLine();
                    books.add(new Book(id, t, a));
                    System.out.println("Book added");
                    break;

                case 2:
                    if (books.size() == 0) {
                        System.out.println("No books in library");
                    } else {
                        System.out.printf("%-5s %-25s %-22s %s\n", "Id", "Title", "Author", "Status");
                        for (int i = 0; i < books.size(); i++) {
                            Book b = books.get(i);
                            String st;
                            if (b.avail) {
                                st = "Available";
                            } else {
                                st = "Issued";
                            }
                            System.out.printf("%-5d %-25s %-22s %s\n", b.id, b.title, b.author, st);
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter book id to issue: ");
                    int iid = sc.nextInt();
                    boolean f1 = false;
                    for (int i = 0; i < books.size(); i++) {
                        if (books.get(i).id == iid) {
                            f1 = true;
                            if (books.get(i).avail) {
                                books.get(i).avail = false;
                                System.out.println("Book issued: " + books.get(i).title);
                            } else {
                                System.out.println("Book is already issued");
                            }
                            break;
                        }
                    }
                    if (!f1) {
                        System.out.println("Book not found");
                    }
                    break;

                case 4:
                    System.out.print("Enter book id to return: ");
                    int rid = sc.nextInt();
                    boolean f2 = false;
                    for (int i = 0; i < books.size(); i++) {
                        if (books.get(i).id == rid) {
                            f2 = true;
                            if (!books.get(i).avail) {
                                books.get(i).avail = true;
                                System.out.println("Book returned: " + books.get(i).title);
                            } else {
                                System.out.println("This book was not issued");
                            }
                            break;
                        }
                    }
                    if (!f2) {
                        System.out.println("Book not found");
                    }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
            }
            System.out.println();
        }
    }
}
