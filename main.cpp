#include<iostream>
#include<fstream>
using namespace std;

class student
{
protected:
    char name[40];
    char roll[10];
    char dep[50];
    char batch[50];
    void get()
    {
        cout<<"\nEnter the name: ";
        cin>>name;
        cout<<"Enter the roll number: ";
        cin>>roll;
        cout<<"Enter the department: ";
        cin>>dep;
        cout<<"Enter the batch: ";
        cin>>batch;
    }

};

class cgpa:protected student
{
private:
    char subname[10][20];
    char subcode[10][20];
    float gpa[10];
    float credit[10];
    float totalcredit;
    float subg[10];
    float total,grade;
    int n;

public:
    void getgpa();
    void file();

};


void  cgpa::getgpa()
{
    get();
    totalcredit =0;
    total=0;
    cout<<"Total no of subjects: ";
    cin>>n;
    for(int j=0; j<n; j++)
    {
        cout<<"\nEnter the subject name: ";
        cin>>subname[j];
        cout<<"Enter the subject code: ";
        cin>>subcode[j];
        cout<<"Enter the subject credit: ";
        cin>>credit[j];
        cout<<"Enter the subject GPA: ";
        cin>>gpa[j];
        totalcredit=totalcredit+credit[j];
        subg[j]=gpa[j]*credit[j];
        total=subg[j]+total;
    }
    grade=total/totalcredit;
    cout<<"\n\nGRADE POINT AVERAGE(GPA) = "<<grade<<endl<<endl;

    fstream x("CLASS MARKSHEET",ios::app|ios::out);
    x<<endl<<name<<"\t"<<roll<<"\t     "<<grade<<"\t"<<endl;
    x.close();
}
void cgpa::file()
{
    getgpa();
    ofstream y(roll);
    y<<"\nName: "<<name;
    y<<"\nRoll Number: "<<roll;
    y<<"\nDepartment: "<<dep;
    y<<"\nBatch : "<<batch;
    y<<"\n\n\n  Subject name\t  \t Subject code\t \tSubject credit\t \t Subject GPA";
    for(int j=0; j<n; j++)
    {
        y<<"\n\t";
        y<<subname[j];
        y<<"\t\t\t"<<subcode[j];
        y<<"\t\t\t" ;
        y<<credit[j];
        y<<"\t\t\t" ;
        y<<gpa[j];
    }
    y<<"\n\nTOTAL CREDITS = "<<totalcredit;
    y<<"\n\nGRADE POINT AVERAGE(GPA) = "<<grade;
    y.close();
}



int main()
{
    int choice;
    char roll[20];
    char c;
    while(1)
    {
        cout<<"\n Enter 1:INPUT\n Enter 2:SEARCH\n Enter 3:DISPLAY\n Enter 4:EXIT\n";
        cout<<"\n\nEnter the choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cgpa s1;
            s1.file();
            break;


        case 2:
        {
            cout<<"Input the Roll number: ";
            cin>>roll;
            ifstream x(roll);
            if(x)
            {
              while(x)
               {
                   x.get(c);
                   cout<<c;
               }
            }
            else
             cout<<"The entered roll number is not found"<<endl;


            break;
        }

        case 3:
        {
            char c;
            ifstream x("CLASS MARKSHEET");
            while(x)
            {
                x.get(c);
                cout<<c;
            }
            break;
        }

        case 4:
            cout<<"Program terminated successfully."<<endl;
            exit(0);
            break;

        default :
            cout<<"Invalid input,Try Again."<<endl;
            break;
        }
    }
    return 0;
}
