#include<iostream>
#include<string>
#include<unordered_map>

class Student {
    protected:
	int index;
	std::string name;
	int physics_marks,chemistry_marks,maths_marks,optional_marks;
	float total;
	float avarage;
	char grade;


	Student(): index(0000),name(""),physics_marks(0),chemistry_marks(0),maths_marks(0),optional_marks(0){}

	Student(int index, std::string name, int physics_marks, int chemistry_marks, int maths_marks){
		this->index = index;
		this->name = name;
		this->physics_marks = physics_marks;
		this->chemistry_marks = chemistry_marks;
		this->maths_marks = maths_marks;
	}

    public:
	int getIndex(){
		return index;
	}
	std::string getName(){
		return name;
	}
	int getPhysics_marks(){
		return physics_marks;
	}
	int getChemistry_marks(){
		return chemistry_marks;
	}
	int getMaths_marks(){
		return maths_marks;
	}
	virtual float getOptional_marks()=0;
	float getTotal();
	float getAvarage();
	char getGrade();

};

class PracticalStudent : public Student {
	int practical_marks;
	int theory_marks;

	public:
	PracticalStudent(int index, std::string name, int physics_marks, int chemistry_marks, int maths_marks, int practical_marks, int theory_marks) : Student(index, name, physics_marks, chemistry_marks, maths_marks) {
		this->practical_marks = practical_marks;
		this->theory_marks = theory_marks;
	}

	int getPractical_marks(){
		return practical_marks;
	}
	int getTheory_marks(){
		return theory_marks;
	}
	float getOptional_marks(){
		return (practical_marks + theory_marks)/2.0 ;
	}

};

class TheoryStudent : public Student {
	int assignment_marks;
	int report_marks;
	int theory_marks;

	public:
	TheoryStudent(int index, std::string name, int physics_marks, int chemistry_marks, int maths_marks, int assignment_marks, int report_marks, int theory_marks) : Student(index, name, physics_marks, chemistry_marks, maths_marks) {
		this->assignment_marks = assignment_marks;
		this->report_marks = report_marks;
		this->theory_marks = theory_marks;
	}

	int getAssignment_marks(){
		return assignment_marks;
	}
	int getReport_marks(){
		return report_marks;
	}
	int getTtheory_marks(){
		return theory_marks;
	}
	float getOptional_marks(){
		return (assignment_marks + report_marks + theory_marks)/3 ;
	}
};

float Student :: getTotal(){
	total = physics_marks + chemistry_marks + maths_marks + getOptional_marks();
	return total;
}
float Student :: getAvarage(){
	avarage = getTotal() / 4.0;
	return avarage;
}
char Student :: getGrade(){
	if(avarage >= 75){
		grade = 'A';
	} else if(avarage >= 65){
		grade = 'B';
	} else if(avarage >= 55){
		grade = 'C';
	} else if(avarage >= 45){
		grade = 'S';
	} else{
		grade = 'F';
	}
	return grade;
}

//to add new record
void addNewRecords(std::unordered_map<int, PracticalStudent *> &practicalStudentList, std::unordered_map<int, TheoryStudent *> &theoryStudentList){
	int index;
	std::string name;
	int physics_marks;
	int chemistry_marks;
	int maths_marks;
	int optional_marks;
	char student_type;
	int practical_marks;
	int theory_marks;
	int assignment_marks;
	int report_marks;

	std::cout<<"\n Enter Student Details,\n";
	std::cout<<"\n\tIndex  : ";
	std::cin>>index;
	std::cout<<"\tName   : ";
	std::cin>>name;
	std::cout<<"\n Enter Student Marks,\n";
	std::cout<<"\n\tPhysics   : ";
	std::cin>>physics_marks;
	std::cout<<"\tChemistry : ";
	std::cin>>chemistry_marks;
	std::cout<<"\tMaths     : ";
	std::cin>>maths_marks;
	std::cout<<"\n Project => p | Research => r : ";
	std::cin>>student_type;
	std::cout<<"\n Enter Optional Subject Marks,\n";
	std::cout<<"\n\tTheory      : ";
	std::cin>>theory_marks;

	if(student_type == 'p'){
		std::cout<<"\tPractical   : ";
		std::cin>>practical_marks;

		PracticalStudent* practicalStudentObject = new PracticalStudent(index, name, physics_marks, chemistry_marks, maths_marks, theory_marks, practical_marks);
		practicalStudentList.insert(std::make_pair(practicalStudentObject->getIndex(),practicalStudentObject));

	} else {
		std::cout<<"\tAssignments : ";
		std::cin>>assignment_marks;
		std::cout<<"\tReport      : ";
		std::cin>>report_marks;

		TheoryStudent* theoryStudentObject = new TheoryStudent(index, name, physics_marks, chemistry_marks, maths_marks, theory_marks, assignment_marks, report_marks);
		theoryStudentList.insert(std::make_pair(theoryStudentObject->getIndex(),theoryStudentObject));
		}



}

//to view records
void viewRecords(std::unordered_map<int, PracticalStudent *> &practicalStudentList, std::unordered_map<int, TheoryStudent *> &theoryStudentList){

	std::cout << "\n \t\t ----------- STUDENT RECORDS -----------\n" << std::endl;
	std::cout<< "\nIndex  \tName \tPhysics \tChemistry \tMaths \tOptional \tTotal \tAvarage \tGrade\n" ;
    for (auto& data :  practicalStudentList ){
		std::cout << " " << data.first   << "   \t" << data.second->getName() << "   \t" << data.second->getPhysics_marks() << "   \t" << data.second->getChemistry_marks() << "  \t " << data.second->getMaths_marks() << "   \t" << data.second->getOptional_marks() << "   \t" << data.second->getTotal() << "  \t " << data.second->getAvarage() <<  "   \t" << data.second->getGrade()<<std::endl;
	}
    for (auto& data :  theoryStudentList ){
		std::cout << " " << data.first   << "   \t" << data.second->getName() << "   \t" << data.second->getPhysics_marks() << "   \t" << data.second->getChemistry_marks() << "  \t " << data.second->getMaths_marks() << "   \t" << data.second->getOptional_marks() << "   \t" << data.second->getTotal() << "  \t " << data.second->getAvarage() <<  "   \t" << data.second->getGrade()<<std::endl;
	}
}

//to search records
void searchRecords(std::unordered_map<int, PracticalStudent *> &practicalStudentList, std::unordered_map<int, TheoryStudent *> &theoryStudentList){

	int keyword;

	std::cout<<"\n Enter searched index : ";
	std::cin>>keyword;
	std::cout << "\n \t\t ----------- STUDENT RECORDS -----------\n" << std::endl;
	std::cout<< "\nIndex  \tName \tPhysics \tChemistry \tMaths \tOptional \tTotal \tAvarage \tGrade\n" ;

	if (practicalStudentList.find(keyword) != practicalStudentList.end()) {
        std::cout << " " << keyword   << "   \t" << practicalStudentList.at(keyword)->getName() << "   \t" << practicalStudentList.at(keyword)->getPhysics_marks() << "   \t" << practicalStudentList.at(keyword)->getChemistry_marks() << "  \t " << practicalStudentList.at(keyword)->getMaths_marks() << "   \t" << practicalStudentList.at(keyword)->getOptional_marks() << "   \t" << practicalStudentList.at(keyword)->getTotal() << "  \t " << practicalStudentList.at(keyword)->getAvarage() <<  "   \t" << practicalStudentList.at(keyword)->getGrade()<<std::endl;
	}


    else if(theoryStudentList.find(keyword) != theoryStudentList.end()){
        std::cout << " " << keyword   << "   \t" << theoryStudentList.at(keyword)->getName() << "   \t" << theoryStudentList.at(keyword)->getPhysics_marks() << "   \t" << theoryStudentList.at(keyword)->getChemistry_marks() << "  \t " << theoryStudentList.at(keyword)->getMaths_marks() << "   \t" << theoryStudentList.at(keyword)->getOptional_marks() << "   \t" << theoryStudentList.at(keyword)->getTotal() << "  \t " << theoryStudentList.at(keyword)->getAvarage() <<  "   \t" << theoryStudentList.at(keyword)->getGrade()<<std::endl;

    }
    else
    {std::cout<<"No any student with that index"<<std::endl;}
}


//to delete records
void deleteRecords(std::unordered_map<int, PracticalStudent *> &practicalStudentList, std::unordered_map<int, TheoryStudent *> &theoryStudentList){

	int indexToDelete;
	bool isDeleted;

	std::cout<<"\n Enter index to delete record : ";
	std::cin>>indexToDelete;

    if(practicalStudentList.find(indexToDelete) != practicalStudentList.end()){
    	practicalStudentList.erase(indexToDelete);
    	isDeleted = true;
	} else if(theoryStudentList.find(indexToDelete) != theoryStudentList.end()){
		theoryStudentList.erase(indexToDelete);
    	isDeleted = true;
	} else {
		std::cout<<"\n There isn't any student with this index.\n";
	}

	if(isDeleted == true){
		std::cout<<"\n Successfully removed the record with index " << indexToDelete << std::endl;
	}
}

int main(){
	int choice;
	std::unordered_map<int, PracticalStudent *> practicalStudentList;
	std::unordered_map<int, TheoryStudent *> theoryStudentList;

	while(choice != 5){
		std::cout<<"\n ---------------------------------";
		std::cout<<"\n|      STUDENT RECORD SYSTEM\t |";
		std::cout<<"\n|--------------------------------|";
		std::cout<<"\n|\t 1.Add new records       |";
		std::cout<<"\n|\t 2.View records          |";
		std::cout<<"\n|\t 3.Search records        |";
		std::cout<<"\n|\t 4.Delete records        |";
		std::cout<<"\n|\t 5.Exit                  |";
		std::cout<<"\n ---------------------------------";

		std::cout<<"\n\n Enter your choice : ";
		std::cin>>choice;

		switch(choice){
			case 1:
				addNewRecords(practicalStudentList, theoryStudentList);
				break;
			case 2:
				viewRecords(practicalStudentList, theoryStudentList);
				break;
			case 3:
				searchRecords(practicalStudentList, theoryStudentList);
				break;
			case 4:
				deleteRecords(practicalStudentList, theoryStudentList);
				break;
			case 5:
				std::cout<<"\n Thanks for join with us !!!\n";
				break;
			default:
				std::cout<<"\n Invalid choice, Enter correct choice....\n";
		}
	}

	return 0;
}
