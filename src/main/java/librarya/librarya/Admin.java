package librarya.librarya;

import java.sql.*;
public class Admin extends Users{

    Database database;
    AdminDatabase adminDb;
    public Admin(){
        this.name="";
        this.ID="";
        this.password="";
        this.isLoggedIn=false;
    }

    public void SetAdmin(String ID, String name, String password){
        this.name=ID;
        this.password= password;
        this.ID=ID;
    }

    public boolean RemoveStudent(String S_ID){
         return database.RemoveStudentRecord(S_ID);
    }

    public boolean Fine(int ID, String Description){
        return database.DescribeFine(ID, Description);
    }

    public ResultSet viewLogs(){
        ResultSet LogsDisplayed;
        LogsDisplayed=adminDb.GetLogs();
        return LogsDisplayed;
    }

    public boolean removeFromFineList(int ID){
            return database.removeFine(ID);
    }
}
