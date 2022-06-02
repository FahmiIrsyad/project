#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctype.h>




using namespace std;

void WelcomeScreen(void);
void Title(void);
void MainMenu(void); 
void BookAppointment(void); 
void AddPatient(void);
void DisplayPatient(void); 
void SearchPatient(void); 
void EditPatient(void); 
void DeletePatient(void); 
void Ex_it(void);
void Uppercase(string name, string *p); 

int i;


struct patient 
{
	int Age;
	char Gender;
	char FirstName[20];
	char LastName[20]; 
	char ContactNo[15];
	char Problem[20];
};

struct patient p;

int main()
{
	
    WelcomeScreen();
	Title();
	MainMenu();
	return 0;
}

void WelcomeScreen(void) 
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t#################################################"
		 << "\n\t\t\t\t#\t\t WELCOME TO\t\t\t#"
		 << "\n\t\t\t\t#      HANNAH DENTAL CLINIC RECORD SYSTEM       #"
		 << "\n\t\t\t\t#################################################"
		 << "\n\n\n\n\n Press any key to continue......\n";
		 
	
	_getch();
	system("cls");
	
}

void Title(void)
{
	
	cout << "\n\n\t\t----------------------------------------------------------------------------------"
		 << "\n\t\t\t\t               CLINIC RECORD        "
		 << "\n\t\t----------------------------------------------------------------------------------";
	
}

void MainMenu(void)
{
	system("cls");
	int choose;
	Title();
	
	cout << "\n\n\n\n\n\t\t\t\t1. Book Appointment \n"
		 << "\n\t\t\t\t2. Add Patient \n"
		 << "\n\t\t\t\t3. Display Patients Record\n"
		 << "\n\t\t\t\t4. Search Patients Record\n"
		 << "\n\t\t\t\t5. Edit Patients Record\n"
		 << "\n\t\t\t\t6. Delete Patients Record\n"
		 << "\n\t\t\t\t7. Exit\n"
		 << "\n\n\n \n\t\t\t\tChoose from 1 to 7 : ";
	
	cin >> choose;
	
	switch(choose)
	{
		
		case 1:
			BookAppointment();
			break;
		case 2:
			AddPatient();
			break;
		case 3:
			DisplayPatient();
			break;
		case 4 :
			SearchPatient();
			break;
		case 5: 
		    EditPatient();
		    break;
		case 6 :
			DeletePatient();
			break;
		case 7 :
			Ex_it();
			break;
		default:
			cout << "\t\t\tInvalid entry. Please enter right option :)";
			getch();
			MainMenu();
	}
		
	
}

void BookAppointment( void )
{
	system("cls");
	
    cout<<"\n ----- Book Your Appointment ---- \n";	
    cout<<"\n ----- Available slots ---- \n";	 
	
	string filename = "appointment.txt";
	
    ifstream read;
    read.open(filename.c_str());
    
    int index, hours, i;
    int arr[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound = 0; 
    
    char key = 'A', temp;
     
    if(read)
    {     
		string line;
		       
		while(getline(read, line)) 
		{
			temp = line[0];
			index = (temp - 65); 
			arr[index]=1; 
			recordFound = 1;
		}
		
		if(recordFound == 1)
		{
			cout<<"\n Appointment Summary by hours:";
			key = 'A';
			hours = 9;
			
			for(i = 0; i<=12; i++)
			{
				if(i == 0)
				{
					if(arr[i] == 0) 
					cout<<"\n "<<key<<"-> 0"<<hours<<" - Available";
					else
					cout<<"\n "<<key<<"-> 0"<<hours<<" - Booked";
				}
				
				else
				{								           	
					if(arr[i] == 0) 
					cout<<"\n "<<key<<"->"<<hours<<" - Available";
					else
					cout<<"\n "<<key<<"->"<<hours<<" - Booked";
				}
				hours++; key++;
			}
	            
		}
			
		read.close();
    }
    
    if(recordFound == 0)
	{
		cout<<"\n Appointment Available for following hours :";
		key = 'A';
		
		for(i = 9; i<=21; i++)
		{
			if(i==9)
			cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
			else
			cout<<"\n "<<key<<" -> "<<i<<" - Available";
			key++;
		}
		
	}
    
    
    // CHOICE 
    
   char choice;
   int isBooked;
   
   cout<<"\n\n Input your choice : ";
   cin>>choice;
   
   if( !(choice >= 'A' && choice <='Z'))
   {
		cout<<"\n Error : Invalid Selection";
		cout<<"\n Please select correct value from menu A- Z";
		cout<<"\n Press any key to continue";
		getchar();getchar();
		system("cls");
		BookAppointment();
   }
   
   index = (choice-65 );
   isBooked = 1;
   
   if(arr[index] == 0) 
      isBooked = 0;
      
   if(isBooked ==1)
   {
	   	cout<<"\n Error : Appointment is already booked for this Hour";
	   	cout<<"\n Please select different time !!";
	   	cout<<"\n Press any key to continue!!";
	   	getchar(); getchar();
	   	system("cls");
	   	BookAppointment();
   }
   
   string name;
   
   cout<<"\n Enter your first name : ";
   cin>>name;  

   for( i=0; i <= name.length(); i++ )
   {
   	name[i]= ::toupper(name[i]);
   }
   
  
    
	
   
		 
		 }


void AddPatient(void)
{
	char name[20];
	system("cls");
    string filename = "patient.txt";;
    
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Patient Record ---------------------------------------------" << endl << endl;

	cout << "\n\t\t\tEnter Patient First Name : ";
	cin >> p.FirstName;
	for( i=0; i<=20; i++)
	{
		p.FirstName[i] = toupper(p.FirstName[i]);
	}
	
    
    cout << "\n\t\t\tEnter Patient Last Name: ";
    cin >> p.LastName;
    for( i=0; i<=20; i++)
	{
		p.LastName[i] = toupper(p.LastName[i]);
	}
    
    cout << "\n\t\t\tEnter Patient Age: ";
    cin >> p.Age;
    
    cout << "\n\t\t\tEnter Patient Gender [M/F]: ";
    cin >> p.Gender;
    
 	while ( p.Gender != 'M' && p.Gender != 'F' )
 	{
 		cout << "\n\t\tEnter M/F only...\n\n";
    	cout << "\n\t\t\tEnter Patient Gender [M/F]: ";
    	cin >> p.Gender;
	}
    
    
    cout << "\n\t\t\tEnter Patient Contact No : ";
    cin >> p.ContactNo;
    cout << "\n\t\t\tEnter Patient Problem : ";
    cin >> p.Problem;
		
}

void DisplayPatient()
{
	system("cls");
	ifstream inFile;
	int total=1;
	cout<<"\t\t\t\t\t\tPatient Current Record"<<endl;
	cout<<"\t\t\t***********************************************************";
	inFile.open("patient.txt");
	
	if(!inFile)
	{
		cout<<"No Data Recorded....";
		inFile.close();
	}
	else
	{
		inFile>>p.FirstName>>p.LastName>>p.Age>>p.Gender>>p.ContactNo>>p.Problem;
		while (!inFile.eof())
		{
			
            cout << "\n\n\t\t\t No.: " << total++ << endl;
			cout << "\n\t\t\t Patient First Name : "<<p.FirstName<<endl;
            cout << "\n\t\t\t Patient Last Name: "<<p.LastName<<endl;
            cout << "\n\t\t\t Patient Age: "<<p.Age<<endl;
            cout << "\n\t\t\t Gender: "<<p.Gender<<endl;
            cout << "\n\t\t\t Patient Contact No : "<<p.ContactNo<<endl;
		    cout << "\n\t\t\t Patient Problem : "<<p.Problem<<endl;
			cout << "\t\t\t-------------------------------------------------";	
    	inFile>>p.FirstName>>p.LastName>>p.Age>>p.Gender>>p.ContactNo>>p.Problem;
		} 
		if (total == 1)
        {

            cout << "\n\n\t\t\t\tNo Data is Present..." << endl;
        }
        
        getchar(); getchar();
        MainMenu();
	}
 inFile.close();
    	
}

void SearchPatient()
{
	system("cls");
    ifstream inFile;
    int found = 0;
    string filename = "patient.txt";
    inFile.open(filename.c_str());
    
    if (!inFile)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Patient Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
        MainMenu();
    }
    else
    {
    	string firstName, lastName;
    	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Patient Search Table --------------------------------------------" << endl;
        cout<< "\n\n\t\t\tEnter the firstname of the patient : ";
        cin>>firstName;
        cout<< "\n\t\t\tEnter the lastname of the patient : ";
        cin>>lastName;
        
        Uppercase(firstName, &firstName);
        Uppercase(lastName, &lastName);
        
        inFile>>p.FirstName>>p.LastName>>p.Age>>p.Gender>>p.ContactNo>>p.Problem;
        
        while (!inFile.eof())
        {
        	
            if (firstName == p.FirstName && lastName == p.LastName)
            {
        
				cout << "\n\n\t\t\t Patient Firstname : "<<p.FirstName<<endl;
	            cout << "\n\t\t\t Patient Lastname: "<<p.LastName<<endl;
	            cout << "\n\t\t\t Patient Age: "<<p.Age<<endl;
	            cout << "\n\t\t\t Gender: "<<p.Gender<<endl;
	            cout << "\n\t\t\t Patient Contact No : "<<p.ContactNo<<endl;
			    cout << "\n\t\t\t Patient Problem : "<<p.Problem<<endl;
			    getchar();
	
				inFile.close();
				getchar();    
				MainMenu();	 
	        }
			inFile>>p.FirstName>>p.LastName>>p.Age>>p.Gender>>p.ContactNo>>p.Problem;
        }
        inFile.close();
	}
	
	cout << "\n\t\t\t Patient Record Not Found....";
	getchar();  getchar(); 
	MainMenu();	 
}

void EditPatient(void)
{
	
	system("cls");
	ifstream inFile;
	ofstream outFile;
	string firstname, lastname;
	string filename1 = "patient.txt", filename2 = "editpatient.txt";
	int found = 0;
	
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Edit Patient Details ------------------------------------------" << endl ;
    
	cout << "\n\n\t\tEnter the firstname of the patient you want to edit : ";
    cin >> firstname;
    cout << "\n\t\tEnter the lastname of the patient you want to edit : ";
    cin >> lastname;
    Uppercase(firstname, &firstname);
    Uppercase(lastname, &lastname);
    system("cls");
    
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Edit Patient Details ------------------------------------------" << endl ;
    
	inFile.open(filename1.c_str());
	
    if(inFile.fail())
	{
        cout << "The file was not successfully opened\n"
             << " Please check that the file currently exists."
             << endl;
        MainMenu();
    }
    else
    {
	    outFile.open(filename2.c_str()); 
		if(outFile.fail())
		{
		cout << "The file was not successfully opened" << endl;
		}
		
		inFile >> p.FirstName >> p.LastName >> p.Age >> p.Gender >> p.ContactNo >> p.Problem; 
	    while (!inFile.eof())
	    {
			if ( firstname != p.FirstName || lastname != p.LastName )
		  	{
		    	outFile << " " << p.FirstName << " " << p.LastName << " " << p.Age << " " << p.Gender << " " << p.ContactNo << " " << p.Problem << "\n";
			}
			else
			{
				cout << "\n\n\t\t\tEnter Patient First Name : ";
			    cin >> p.FirstName;
			    cout << "\n\t\t\tEnter Patient Last Name: ";
			    cin >> p.LastName;
			    cout << "\n\t\t\tEnter Patient Age: ";
			    cin >> p.Age;
			    cout << "\n\t\t\tEnter Patient Gender [M/F]: ";
			    cin >> p.Gender;
			    
			 	while ( p.Gender != 'M' && p.Gender != 'F' )
			 	{
			 		cout << "\n\t\tEnter M/F only...\n\n";
			    	cout << "\n\t\t\tEnter Patient Gender [M/F]: ";
			    	cin >> p.Gender;
				}
			    
			    
			    cout << "\n\t\t\tEnter Patient Contact No : ";
			    cin >> p.ContactNo;
			    cout << "\n\t\t\tEnter Patient Problem : ";
			    cin >> p.Problem;
			    
			    for( i=0; i<=20; i++){
					p.FirstName[i] = toupper(p.FirstName[i]);
				}
			
			    for( i=0; i<=20; i++){
					p.LastName[i] = toupper(p.LastName[i]);
				}
			    
	            outFile << " " << p.FirstName << " " << p.LastName << " " << p.Age << " " << p.Gender << " " << p.ContactNo << " " << p.Problem << endl;
	            found++;
	            cout << "\n\n\t\t\tPatient Details have been successfully updated...";
			}
			inFile >> p.FirstName >> p.LastName >> p.Age >> p.Gender >> p.ContactNo >> p.Problem; 
		}
		
		if (found == 0)
	    {
	    	cout << "\n\n\t\t\tPatient Details Are Not Found....";
	    }
	    
	    inFile.close();
		outFile.close();
	    remove("patient.txt");
	    
	    getchar();
	    rename("editpatient.txt", "patient.txt");
	    
	    getchar();
	    getchar();
	    MainMenu();

	}
}

void DeletePatient(void)
{
	system("cls");
	ifstream inFile;
	ofstream outFile;
	string firstname, lastname;
	string filename1 = "patient.txt", filename2 = "deletepatient.txt";
	int found = 0;
	
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Patient Record ------------------------------------------" << endl ;
    
	cout << "\n\n\t\tEnter Patient Firstname to delete : ";
    cin >> firstname;
    cout << "\n\t\tEnter Patient Lastname to delete : ";
    cin >> lastname;
    Uppercase(firstname, &firstname);
    Uppercase(lastname, &lastname);
    
    system("cls");
    
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Patient Record ------------------------------------------" << endl ;
    
	inFile.open(filename1.c_str());
	
    if(inFile.fail())
	{
        cout << "The file was not successfully opened\n"
             << " Please check that the file currently exists."
             << endl;
        MainMenu();
    }
    else
    {
	    outFile.open(filename2.c_str()); 
		if(outFile.fail())
		{
		cout << "The file was not successfully opened" << endl;
		}
		
		inFile >> p.FirstName >> p.LastName >> p.Age >> p.Gender >> p.ContactNo >> p.Problem; 
		
	    while (!inFile.eof())
	    {
			if ( firstname != p.FirstName || lastname != p.LastName )
		  	{
		    	outFile << " " << p.FirstName << " " << p.LastName << " " << p.Age << " " << p.Gender << " " << p.ContactNo << " " << p.Problem << "\n";
			}
			else if(firstname == p.FirstName && lastname == p.LastName)
			{
				cout << "\n\n\t\t\t Patient Firstname : "<<p.FirstName<<endl;
		        cout << "\n\t\t\t Patient Lastname: "<<p.LastName<<endl;
		        cout << "\n\t\t\t Patient Age: "<<p.Age<<endl;
		        cout << "\n\t\t\t Gender: "<<p.Gender<<endl;
		        cout << "\n\t\t\t Patient Contact No : "<<p.ContactNo<<endl;
				cout << "\n\t\t\t Patient Problem : "<<p.Problem<<endl;
		        cout << "\n\n\t\t\tPatient Record has been deleted...";
		        found++;
			}

			inFile >> p.FirstName >> p.LastName >> p.Age >> p.Gender >> p.ContactNo >> p.Problem; 
		}
		
		if (found == 0)
	    {
	    	cout << "\n\n\t\t\tPatient Record Cannot Be Found....";
	    }

	    inFile.close();
		outFile.close();
	    remove("patient.txt");
	    getchar();
	    rename("deletepatient.txt", "patient.txt");
	    
	    getchar();
	    getchar();
	    MainMenu();

	}
	
}

void Ex_it(void)
{
	system("cls");
	cout << "\n\t\t\tThank Your For Using This System ! " << endl;
	getchar();
	exit(1);

}

void Uppercase(string name, string *p)
{
	
	for( i=0; i <= name.length(); i++ )
   {
   	name[i]= ::toupper(name[i]);
   }
   
   *p = name;
}










