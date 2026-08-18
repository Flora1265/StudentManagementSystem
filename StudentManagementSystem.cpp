#include <iostream>
#include <vector>
using namespace std;

class student
{
    private:
    
    int grade;
    int ID;
    string name;
    string status;


    public:


    student(int grade,int ID, string name,string status)
    {
        this -> grade = grade;
        this -> ID = ID;
        this-> name = name;
        this -> status = status;

    }
    int getgrade(){

        return grade;

    }

    string getStatus()
    {
        return status;
    };

    
    string getName()
    {
        return name;
    }

    int getID()
    {
        return ID;
    }
    
    string updateGrade(bool pass)
    {
         
        

        if (pass ){

             grade ++;

            return "passed . new grade" + to_string(grade);

            
        }
        else {
        return " failed .retained " + to_string(grade);
    }
        
        
    
    }

    void  changeStatus(bool active)
    {

        if (active){
            status = "active";

            cout<<"status = active  "  << endl;
        }
        else{
        status = "suspended";
        cout<<"student suspended. "  <<endl;}

    }
    
    void displayStudent()
    {
        cout<<"student name:  "   << name << endl ;
        cout<<"student grade:  "   << grade << endl;
        cout<<"student status:  "  << status<< endl ;
        cout<<"student ID:  "  << ID << endl;



    }


};

class school 
{
   private:
    vector<student>students;
    public:

   vector<student> getStudents()
{
    return students;
}

    void addStudent( student S1)
    {
        students.push_back (S1);
    }



void removeStudent(int ID)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == ID)
        {
            students.erase(students.begin() + i);
            break;
        }
    }
}



void SearchStudent(int ID){
    for(int i = 0 ; i < students.size(); i ++){
        if(students[i].getID() == ID ){
            
             cout <<"book found at position  "  << i << endl ;
              students[i].displayStudent();

              return;

        }
    }
    cout<< " book not found. "  << endl;
}

void changeStudentStatus(int ID,bool active){

    for(int i = 0 ; i < students.size(); i ++){
        if(students[i].getID() == ID ){
            students[i].changeStatus( active);

            return;
        }

}
}

void displayStudents(){
    for(int i = 0 ; i< students.size() ; i++){

     students[i].displayStudent();


    }
}
};

int main(){
student student1(2,333,"Flora","active");
student student2(4,1265,"HIRWA","active");

school Myschool;
    

Myschool.addStudent(student1);
Myschool.addStudent(student2);

Myschool.displayStudents();

Myschool.changeStudentStatus(333, false);

Myschool.displayStudents();

}