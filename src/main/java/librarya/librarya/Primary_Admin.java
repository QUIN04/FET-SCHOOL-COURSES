package librarya.librarya;

public class Primary_Admin extends Admin{

    public Primary_Admin(){
        this.ID="";
        this.name="";
        this.password="";
        this.isLoggedIn=false;
    }

    public boolean CreateAccount(String ID, String name, String Password){
      return adminDb.AddAdmin(ID,name, Password);
    }

    public boolean AddAdmin(String ID, String name, String Password){
        return adminDb.AddAdmin(ID,name,Password);
    }
}
