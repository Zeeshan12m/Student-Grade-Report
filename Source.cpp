#include <iostream>
using namespace std;
int main(){
	system("color 90");
	cout << "===================================================================================================================================================================================================================" << endl;
	cout << "										STUDENT GRADING SYSTEM																	" << endl;
	const int maxSize = 50;
	int rollNumbers[maxSize];
	float computerScienceMarks[maxSize];
	float mathematicsMarks[maxSize];
	double percentages[maxSize];
	char grades[maxSize];
	int count = 0;
	char choice;
	do {
		if (count >= maxSize) {
			cout << "Array limit reached. Exiting the program." << endl;
			break;
		}
		cout << "\nEnter Roll Number: ";
		cin >> rollNumbers[count];

		cout << "Enter Marks for Computer Science (out of 100): ";
		cin >> computerScienceMarks[count];
		while (computerScienceMarks[count] > 100){
			cout << "Please Enter number 1 to 100 Only! ";
			cin >> computerScienceMarks[count];
		}
		cout << "Enter Marks for Mathematics (out of 100): ";
		cin >> mathematicsMarks[count];
		while (mathematicsMarks[count] > 100){
			cout << "Please Enter number 1 to 100 Only! ";
			cin >> mathematicsMarks[count];
		}
		percentages[count] = (computerScienceMarks[count] + mathematicsMarks[count]) / 2;

		if (percentages[count] > 90) {
			grades[count] = 'A';
		}
		else if (percentages[count] >= 75 && percentages[count] <= 90) {
			grades[count] = 'B';
		}
		else if (percentages[count] >= 60 && percentages[count] < 75) {
			grades[count] = 'C';
		}
		else if (percentages[count] >= 50 && percentages[count] < 60) {
			grades[count] = 'D';
		}
		else {
			grades[count] = 'F';
		}

		count++;

		cout << "Press 'Y' to enroll more students or Press 'N' (Y/N): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "\nStudent Data:\n";
	for (int i = 0; i < count; i++)
	{
		cout << "Roll Number: " << rollNumbers[i] << endl;
		cout << "Computer Science Marks: " << computerScienceMarks[i] << endl;
		cout << "Mathematics Marks: " << mathematicsMarks[i] << endl;
		cout << "Percentage: " << percentages[i] << endl;
		cout << "Grade: " << grades[i] << endl << endl;
	}

	while (choice == 'N' || choice == 'n')
	{
		int option;
		cout << "Press 1 to update roll no for a particular student\n";
		cout << "Press 2 to update marks of a particular student for CS\n";
		cout << "Press 3 to update marks of CS for all students who are already enrolled.\n";
		cout << "Press 4 to update marks for Mathematics.\n";
		cout << "Press 5 to update marks of Mathematics for all students who are already enrolled.\n";
		cout << "Press 6 to sort the data\n";
		cout << "Press 7 to delete the record of a particular student.\n";
		cout << "Press 8 to show updated results\n";
		cout << "Enter your choice:\n ";
		cin >> option;

		switch (option) {
		case 1: {
					int rollToUpdate;
					cout << "Enter the Roll Number of the student to update: ";
					cin >> rollToUpdate;

					for (int i = 0; i < count; i++) {
						if (rollNumbers[i] == rollToUpdate) {
							cout << "Enter the new Roll Number: ";
							cin >> rollNumbers[i];
							cout << "Roll Number updated successfully.\n";
							break;
						}
					}
					break;
		}
		case 2: {
					int rollToUpdate;
					cout << "Enter the Roll Number of the  particular student to update Computer Science marks: ";
					cin >> rollToUpdate;

					for (int i = 0; i < count; i++) {
						if (rollNumbers[i] == rollToUpdate) {
							cout << "Enter the new CS marks (<= 100): ";
							cin >> computerScienceMarks[i];
							cout << "CS marks updated successfully.\n";
							break;
						}
					}
					break;
		}
		case 3: {
					for (int i = 0; i < count; i++) {
						cout << "Enter new Computer Science marks for Roll Number " << rollNumbers[i] << " (<= 100): ";
						cin >> computerScienceMarks[i];
					}
					cout << "CS marks updated for all students.\n";
					break;
		}
		case 4: {
					int rollToUpdate;
					cout << "Enter the Roll Number of the particular student to update Mathematics marks: ";
					cin >> rollToUpdate;

					for (int i = 0; i < count; i++) {
						if (rollNumbers[i] == rollToUpdate) {
							cout << "Enter the new Mathematics marks (<= 100): ";
							cin >> mathematicsMarks[i];
							cout << "Mathematics marks updated successfully.\n";
							break;
						}
					}
					break;
		}
		case 5: {
					for (int i = 0; i < count; i++) {
						cout << "Enter new Mathematics marks for Roll Number " << rollNumbers[i] << " (<= 100): ";
						cin >> mathematicsMarks[i];
					}
					cout << "Mathematics marks updated for all students.\n";
					break;
		}
		case 6: {
					// Sorting the data based on percentage in ascending order
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = 0; j < count - i - 1; j++) {
							if (percentages[j] > percentages[j + 1]) {
								swap(percentages[j], percentages[j + 1]);
								swap(rollNumbers[j], rollNumbers[j + 1]);
								swap(computerScienceMarks[j], computerScienceMarks[j + 1]);
								swap(mathematicsMarks[j], mathematicsMarks[j + 1]);
								swap(grades[j], grades[j + 1]);
							}
						}
					}
					cout << "Data sorted based on percentage in ascending order.\n";
					for (int i = 0; i < count ; i++)
					{
						cout << "Roll Number: " << rollNumbers[i] << endl;
						cout << "Computer Science Marks: " << computerScienceMarks[i] << endl;
						cout << "Mathematics Marks: " << mathematicsMarks[i] << endl;
						cout << "Percentage: " << percentages[i] << endl;
						cout << "Grade: " << grades[i] << endl << endl;
					}
					break;
		}
		case 7: {
					int rollToDelete;
					cout << "Enter the Roll Number of the student to delete: ";
					cin >> rollToDelete;

					int indexToDelete = -1;
					for (int i = 0; i < count; i++) {
						if (rollNumbers[i] == rollToDelete) {
							indexToDelete = i;
							break;
						}
					}

					if (indexToDelete != -1) {
						// Shift elements to remove the deleted record
						for (int i = indexToDelete; i < count - 1; i++) {
							rollNumbers[i] = rollNumbers[i + 1];
							computerScienceMarks[i] = computerScienceMarks[i + 1];
							mathematicsMarks[i] = mathematicsMarks[i + 1];
							percentages[i] = percentages[i + 1];
							grades[i] = grades[i + 1];
						}

						count--;
						cout << "Record deleted successfully.\n";
					}
					else {
						cout << "Student not found with the given Roll Number.\n";
					}

					break;
		}
		case 8: {
					for (int i = 0; i < count ; i++){
						cout << "Roll Number: " << rollNumbers[i] << endl;
						cout << "Computer Science Marks: " << computerScienceMarks[i] << endl;
						cout << "Mathematics Marks: " << mathematicsMarks[i] << endl;
						cout << "Percentage: " << percentages[i] << endl;
						cout << "Grade: " << grades[i] << endl << endl;
					}
					break;
	        	}
		default:
		{
				   cout << "Invalid choice. Please try again.\n";
				   break;
		}
		}
		cout << "Press 'N' to continue or Press 'Y' to exit the program (Y/N)? ";
		cin >> choice;
	}
	return 0;
}