package librarya.librarya;
import java.security.Key;
import java.sql.*;
import java.util.ArrayList;

public class  Database {

            //Connection object
            Connection connect;
            public Database() {

                // Database credentials
                String url = "jdbc:mysql://localhost:3306/library";
                String user = "root";
                String password = "#839jke7tdgiw981ksnjk.g";

                // Establish a connection
                try{
                    connect= DriverManager.getConnection(url, user, password);
                    System.out.println("Connected to the database!");

                    // Perform database operations here

                } catch (SQLException e) {
                    System.out.println("Connection failed!");
                    e.printStackTrace();
                }
            }

            public ResultSet GetStudentRecord(String ID){
                PreparedStatement pst;
                ResultSet rs=null;
                String Query="select * from student where id=?";
                try{
                    pst=connect.prepareStatement(Query);
                    pst.setString(1,ID);
                    rs=pst.executeQuery();
                    rs.next();
                }
                catch (SQLException e){
                   System.out.println(e);
                }
              return rs;
            }

            public boolean InsertStudentRecord(String ID, String Name, String Password, String gender){
                PreparedStatement pst;
                boolean succeeded=false;

                String Query="insert into student values (?,?,?,?)";
                try{
                    pst=connect.prepareStatement(Query);
                    pst.setString(1,ID);
                    pst.setString(2,Name);
                    pst.setString(3,Password);
                    pst.setString(4,gender);
                    pst.executeUpdate();
                    succeeded=true;
                }

                catch(SQLException e){
                    System.out.println(e);
                }
                return succeeded;
            }

            public boolean InsertBorrowRecord(String S_ID, String B_ID, String CDate, String RDate){
                PreparedStatement pst;
                boolean succeeded=false;
                try{
                    String Query="insert into borrow (s_id, b_id, taken_date, return_date, return_status) values(?,?,?,?)";
                    pst=connect.prepareStatement(Query);
                    pst.setString(1,S_ID);
                    pst.setString(2,B_ID);
                    pst.setString(3,CDate);
                    pst.setString(4,RDate);
                    pst.executeUpdate();

                    succeeded=true;
                }
                catch(SQLException e){
                    System.out.println(e);
                }

                return succeeded;
            }

            public boolean InsertToSecure(String S_ID, String B_ID, String Duration){
                boolean succeeded=false;
                PreparedStatement pst;

                try{
                    String Query="insert into secure (s_id, b_id, duration) values (?,?,?)";
                    pst=connect.prepareStatement(Query);
                    pst.setString(1,S_ID);
                    pst.setString(2,B_ID);
                    pst.setString(3,Duration);
                    pst.executeUpdate();

                    succeeded=true;
                }
                catch(SQLException e){
                    System.out.println(e);
                }
                return succeeded;
            }

            public ResultSet getAllStudents(){
                PreparedStatement pst;
                ResultSet rs = null;

                try {
                    String Query = "select * from student order by name asc";
                    pst = connect.prepareStatement(Query);
                    rs = pst.executeQuery();
                    rs.next();
                } catch (SQLException e) {
                    System.out.println(e);
                }
             return rs;
            }

            public ResultSet getAllBooks() {
                ResultSet rs = null;
                PreparedStatement pst;

                try {
                    String Query = "select * from student order by title asc";
                    pst = connect.prepareStatement(Query);
                    rs = pst.executeQuery();
                    rs.next();
                } catch (SQLException e) {
                    System.out.println(e);
                }
                return rs;
            }

            public boolean RemoveStudentRecord(String S_ID){
                boolean succeeded=false;
                PreparedStatement pst;

                try{
                    String Query="delete from student where s_id=?";
                    pst=connect.prepareStatement(Query);
                    pst.setString(1,S_ID);
                    pst.executeUpdate();
                    succeeded=true;
                }
                catch(SQLException e){
                    System.out.println(e);
                }
               return succeeded;
            }

            public boolean InsertToFine(int Borrow_ID) {
                boolean succeeded=false;
                PreparedStatement pst;

                try{
                    String Query="insert into fine (borrow_id) values(?)";
                    pst=connect.prepareStatement(Query);
                    pst.setInt(1,Borrow_ID);
                    pst.executeUpdate();
                    succeeded=true;
                }
                catch(SQLException e){
                    System.out.println(e);
                }

                return succeeded;
            }

            public boolean UpdateMissing(String B_ID,int Borrow_ID){
                boolean succeeded=false;
                PreparedStatement pst;

                try{
                    String Query="update borrow set missing=true where id=?";
                    String Query2="update books set missing=true where b_id=?";
                    pst=connect.prepareStatement(Query2);
                    pst.setString(1,B_ID);
                    pst.executeUpdate();
                    pst=connect.prepareStatement(Query);
                    pst.setInt(1,Borrow_ID);
                    pst.executeUpdate();
                    succeeded=true;
                }
                catch(SQLException e){
                    System.out.println(e);
                }

                return succeeded=true;
            }

           public boolean UpdateReturned(String B_ID,String Borrow_ID){
               boolean succeeded=false;
               PreparedStatement pst;

               try{
                   String Query="update borrow set returned=true where id=?";
                   String Query2="update books set borrowed=true where b_id=?";
                   pst=connect.prepareStatement(Query2);
                   pst.setString(1,B_ID);
                   pst.executeUpdate();
                   pst=connect.prepareStatement(Query);
                   pst.setString(1,Borrow_ID);
                   pst.executeUpdate();
                   succeeded=true;
               }
               catch(SQLException e){
                   System.out.println(e);
               }

               return succeeded=true;
           }

           public ResultSet getReturnValue(String B_ID){
                ResultSet rs=null;
                PreparedStatement pst;
                try{
                    String Query="select returned from books where id=?";
                    pst= connect.prepareStatement(Query);
                    pst.setString(1,B_ID);
                    rs=pst.executeQuery();
                    rs.next();
                }

                catch(SQLException e){

                }
                return rs;
           }

           public ResultSet getMissingValue(String B_ID){
               ResultSet rs=null;
               PreparedStatement pst;
               try{
                   String Query="select missing from books where id=?";
                   pst= connect.prepareStatement(Query);
                   pst.setString(1,B_ID);
                   rs=pst.executeQuery();
                   rs.next();
               }

               catch(SQLException e){

               }
               return rs;
           }

           public boolean EditTitle(String B_ID, String newTitle){
                 boolean succeeded=false;
                 PreparedStatement pst;
                try{
                  String Query="update books set title=? where b_id=?";
                  pst=connect.prepareStatement(Query);
                  pst.setString(1,newTitle);
                  pst.setString(2,B_ID);
                  pst.executeUpdate();
                  succeeded=true;
                }
                catch(SQLException e){

                }
                return succeeded;
           }

           public boolean EditAuthor(String B_ID, String newAuthor){
               boolean succeeded=false;
               PreparedStatement pst;

               try{
                   String Query="update books set author=? where b_id=?";
                   pst=connect.prepareStatement(Query);
                   pst.setString(1,newAuthor);
                   pst.setString(2,B_ID);
                   pst.executeUpdate();
                   succeeded=true;
               }
               catch(SQLException e){
                System.out.println(e);
               }
               return succeeded;
           }

           public ResultSet SearchBook(String Keyword){
               ResultSet rs=null;
             PreparedStatement pst;

             try{
                 String Query="select from books where id like '?%' or title like '?%' or author like '?%'";
                 pst=connect.prepareStatement(Query);
                 pst.setString(1, Keyword);
                 rs=pst.executeQuery();
                 rs.next();
             }
             catch(SQLException e){
                 System.out.println(e);
             }
             return rs;
           }

           public boolean DescribeFine(int ID, String Description){
              boolean succeeded=false;
              PreparedStatement pst;
              try{
                  String Query="update fine set description=? where id=?";
                  pst=connect.prepareStatement(Query);
                  pst.setString(1, Description);
                  pst.setInt(2, ID);
                  pst.executeUpdate();
                  succeeded=true;
              }
              catch(SQLException e){

              }
              return succeeded;
           }

           public boolean removeFine(int ID){
                boolean removed=false;
                PreparedStatement pst;
                try{
                    String Query="delete from fine where id=?";
                    pst=connect.prepareStatement(Query);
                    pst.setInt(1, ID);
                    pst.executeUpdate();
                    removed=true;
                }

                catch(SQLException e){

                }
                return removed;
           }

           public boolean AddBook(String ID, String Title, String Author){
                boolean Added=false;
                PreparedStatement pst;
                try{
                    String Query="insert into books (b_id, title, author) values(?,?,?)";
                    pst= connect.prepareStatement(Query);
                    pst.setString(1, ID);
                    pst.setString(2, Title);
                    pst.setString(3, Author);
                    pst.executeUpdate();
                    Added=true;
                }
                catch(SQLException e){

                }
                return Added;
           }

           public boolean Unsecure(int ID){
                boolean deleted=false;
                PreparedStatement pst;
                try{
                    String Query="update secure set status=false where id=?";
                    pst=connect.prepareStatement(Query);
                    pst.setInt(1, ID);
                    pst.executeUpdate();
                    deleted=true;
                }
                catch(SQLException e){

                }
                return deleted;
           }

}

