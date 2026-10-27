// mysql connector jar must be in classpath otherwise driver not found
import java.sql.*;

public class JdbcDemo {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/training", "root", "root");

            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("select * from students");

            while (rs.next()) {
                System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3));
            }

            con.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
