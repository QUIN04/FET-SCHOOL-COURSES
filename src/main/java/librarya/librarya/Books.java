package librarya.librarya;

public class Books {
    Database database;
    private String Book_ID;
    private String Title;
    private String Author;

    public Books(){
        this.Book_ID="";
        this.Title="";
        this.Author="";
    }

    public void SetBook(String ID, String Title, String Author){
        this.Book_ID=ID;
        this.Title=Title;
        this.Author=Author;
    }

    public String getID(){
        return this.Book_ID;
    }

    public String getTitle(){
        return this.Title;
    }

    public String getAuthor(){
        return this.Author;
    }

    public boolean AddBook(String ID, String Title, String Author){
     return database.AddBook(ID, Title, Author);
    }
}
