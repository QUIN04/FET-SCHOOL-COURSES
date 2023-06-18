package librarya.librarya;

import java.sql.*;

public class AdminDatabase {
    Connection connect;
    //PreparedStatement object
    //Resultset object
    public AdminDatabase() {

        // Database credentials
        String url = "jdbc:mysql://localhost:3306/library_admin";
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

    public ResultSet getAdminRecord(){
        PreparedStatement pst;
        ResultSet rs=null;
        try{
           String Query="select id, name from admin";
           pst=connect.prepareStatement(Query);
           rs=pst.executeQuery();
           rs.next();
        }
        catch(SQLException e){

        }
        return rs;
    }

    public boolean AddAdmin(String ID, String Name, String Password){
        PreparedStatement pst;
        boolean added=false;

        try{
            String Query="insert into admin (id,name, password) values(?,?,?)";
            pst=connect.prepareStatement(Query);
            pst.setString(1,ID);
            pst.setString(2,Name);
            pst.setString(3,Password);
            pst.executeUpdate();
            added=true;
        }
        catch(SQLException e){

        }
        return added;
    }

    public boolean RemoveAdmin(String ID){
        PreparedStatement pst;
        boolean Removed=false;
        try{
            String Query="delete from admin where id=?";
            pst=connect.prepareStatement(Query);
            pst.setString(1,ID);
            pst.executeUpdate();
            Removed=true;
        }
        catch(SQLException e){

        }
        return Removed;
    }

    public ResultSet GetLogs(){
        PreparedStatement pst;
        ResultSet rs=null;

        try{
            String Query="select * from logs";
            pst=connect.prepareStatement(Query);
            rs=pst.executeQuery();
            rs.next();
        }
        catch(SQLException e){

        }
        return rs;
    }
}
