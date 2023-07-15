public class Student extends Trainee implements Performance
{
	//Instance Fields
	private String institution;
	private int credit;
	
	//Mutators
	public String getInstitution() 
	{
		return institution;
	}

	public void setInstitution(String institution) 
	{
		this.institution = institution;
	}

	@Override
	public float credit() 
	{
		return 0;
	}

	@Override
	public float monthlyFee()
	{
		return 0;
	}
	
	//Constructor
	public Student(String name, char gender, int age, String email, String password, String institution) 
	{
		super(name, gender, age, email);
		this.institution = institution;
		this.password = password;
	}
	
	public Student(String name, char gender, int age, String email, String password, String institution, boolean premium) 
	{
		super(name, gender, age, email);
		this.institution = institution;
		this.password = password;
		this.premium = premium;
	}
	
	public Student()
	{
		super();
	}
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Term