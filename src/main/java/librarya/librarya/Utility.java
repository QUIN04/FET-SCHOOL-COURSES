package librarya.librarya;

public class Utility {

    public boolean isValidName(String input) {
        if (input == null || input.isEmpty()) {
            return false;
        }
        int i;
        for (i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (!Character.isLetter(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    public boolean isValidPassword(String input) {
        if (input == null || input.isEmpty()) return false;

        // Check length
        if(input.length() < 8) return false;

        return true;
    }

    public boolean isValidMatricule(String input) {
        if (input == null || input.isEmpty()) return false;
        // Check length
        if(input.length()!=8) return false;
        return true;
    }

    public boolean TransitToFine(){
        boolean Transited=false;
        try{

          Transited=true;
        }

        catch(Exception e){

        }
        return Transited;
    }


}
