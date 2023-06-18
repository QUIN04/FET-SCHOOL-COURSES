package librarya.librarya;

import java.sql.ResultSet;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Student extends Users{

    private String Gender;
    private Database db;

    public Student(){
        this.ID="";
        this.name="";
        this.password="";
        this.Gender="";
    }

    public boolean BorrowBook(String ID, String UseDuration){
       boolean BookBorrowed=false;
       int days;

       try{
           days=Integer.parseInt(UseDuration);  //Converts string Duration to integer
           LocalDate TakenDate= LocalDate.now();  // Get current Date
           LocalDate returnDate= TakenDate.plusDays(days);  // Add Take duration to it
           DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
           String CDate=formatter.format(TakenDate);   //format as String in form yyyy-mm-dd
           String RDate=formatter.format(returnDate);   //format as String in form yyyy-mm-dd

           if(this.db.InsertBorrowRecord(this.ID,ID,CDate, RDate)) BookBorrowed=true;
       }
       catch(Exception e){

       }
       return BookBorrowed;
    }

    public boolean ReturnBook(String ID, String Borrow_ID){
        return db.UpdateReturned(ID,Borrow_ID);
    }

    public boolean ReportMissing(String ID, int Borrow_ID){
       return db.UpdateMissing(ID,Borrow_ID);
    }

    public boolean CreateAccount(String ID, String name, String Password,String gender){
       return db.InsertStudentRecord(ID,name,Password,gender);
    }

    public boolean SecureBook(String ID, String Duration){
        return db.InsertToSecure(this.ID, ID,Duration);
    }

    public boolean UnsecureBook(int ID){
        return db.Unsecure(ID);
    }

}


