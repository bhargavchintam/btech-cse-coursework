// new date time api in java 8, better than old Date class
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class DateTimeDemo {
    public static void main(String[] args) {
        LocalDate today = LocalDate.now();
        LocalTime now = LocalTime.now();

        System.out.println("Date : " + today);
        System.out.println("Time : " + now);
        System.out.println("Day : " + today.getDayOfWeek());
        System.out.println("Month : " + today.getMonth());

        System.out.println("after 30 days : " + today.plusDays(30));

        LocalDate bday = LocalDate.of(2000, 1, 26);
        System.out.println("birthday : " + bday);

        DateTimeFormatter f = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        System.out.println("formatted : " + today.format(f));
    }
}
