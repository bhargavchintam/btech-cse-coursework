// copy constructor by passing object to constructor

class Book {
    int id;
    String title;

    Book(int i, String t) {
        id = i;
        title = t;
    }

    Book(Book b) {
        id = b.id;
        title = b.title;
    }

    void show() {
        System.out.println(id + " " + title);
    }
}

public class CopyConstructor {
    public static void main(String[] args) {
        Book b1 = new Book(1, "Complete Reference");
        Book b2 = new Book(b1);

        b1.show();
        b2.show();
    }
}
