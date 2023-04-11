public class Student {
    private String first;     // first name
    private String last;      // last name
    private String email;     // email address
    private string course;      // course title

    // construct a new student with given fields
    public Student(String first, String last, String email, string course) {
        this.first   = first;
        this.last    = last;
        this.email   = email;
        this.course = course;
    }

   

    // return a string representation of the invoking object
    public String toString() {
        return ""+ course + " " + first + " " + last + " " + email;
    }



    // sample client
    public static void main(String[] args) {

        // number of students
        int n = Integer.parseInt(args[0]);

        // initialize an arary that holds n objects of type Student
        Student[] students = new Student[n];

        // read in the data
        for (int i = 0; i < n; i++) {
            String first   = StdIn.readString();
            String last    = StdIn.readString();
            String email   = StdIn.readString();
            int section    = StdIn.readInt();
            students[i] = new Student(first, last, email, section);
        }

        // insertion sort students in ascending order of section
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (students[j].less(students[j-1])) {
                    Student swap  = students[j];
                    students[j]   = students[j-1];
                    students[j-1] = swap;
                }
            }
        }

        // print results
        for (int i = 0; i < n; i++) {
            StdOut.println(students[i]);
        }
    }

}
