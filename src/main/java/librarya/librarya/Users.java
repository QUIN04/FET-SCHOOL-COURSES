package librarya.librarya;
import java.sql.*;
public class Users {
    protected String name;
    protected String ID;
    protected String password;
    protected boolean isLoggedIn;
    protected int Status;

    private Database db;

    public Users(){
        this.name="";
        this.password="";
        this.ID="";
        this.isLoggedIn=false;
    }

    public void SetUser(String name, String ID, String password) {
        this.name = name;
        this.ID = ID;
        this.password = password;
    }

    public boolean login(String ID,String password) {
         ResultSet rs;
         try {
             rs = db.GetStudentRecord(ID);
             this.password=rs.getString("password");
             if (this.password.equals(password)) {
                 //Connect Update
                 this.isLoggedIn = true;
             }
             else {this.password="";}
         }

         catch(Exception e){

         }
         return this.isLoggedIn;
    }

    public boolean logout() {

        if (this.isLoggedIn) {
            this.name = "";
            this.ID = "";
            this.password = "";
            this.isLoggedIn = false;
            return true;
        } else {
            return false;
        }
    }

    public String getName() {
        return this.name;
    }

    public String getID() {
        return this.ID;
    }
    public boolean GetLoginStatus(){
        return this.isLoggedIn;
    }

    public ResultSet viewCatalogue(){
       return db.getAllBooks();
    }
}
