 {

  private:

    char name[20];

    char sub[10];

    float attendance, number_of_students;

    float bonus;

    int calculate()

     {

     bonus= attendance + number_of_students;

      return bonus;

     }

  public:

     void readdata();

     void dispdata();

  };

 

void teacher::readdata()

  {

  clrscr();

  cout<<" enter your name "<<"\n";

  gets(name);

  cout<<" enter the course title you teach "<<"\n";

  cin>>sub;

  cout<<" enter the basic bonus "<<"\n";

  cin>>basic;

  cout<<" enter the house rent allowance "<<"\n";

  cin>>hra;

  cout<<" enter the dearance allowance"<<"\n";

  cin>>da;

   }

 

void teacher::dispdata()

  {

  clrscr();

  cout<<" The name is :"<

  cout<<" The course title you teach is :"<

  calculate();

  cout<<" The bonus you get is : "<

  }

 

 void main()

  {

  clrscr();

  teacher info;

  info.readdata();

  info.dispdata();

  }

