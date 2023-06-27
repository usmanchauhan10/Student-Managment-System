/*******************************************************************************
********************************************************************************
**                                                                            **
**	     /////////////////////////////////////////////                        **
**      ///////// Student Managment System //////////                         **
**     /////////////////////////////////////////////                          **
**                                                                            **
**  Copyright (C) 2022-2023 Umar & it's Team.                                 **
**  This Program is create by Umar and it's team during their                 **
**  BS Computer Science Degree 1st Semester. This Program is for              **
**	Educational Purpose.                                                      **
**                                                                            **
**  Code can be used without permission, for educational purpose.             **
**                                                                            **
**  You should have received a copy of the Program.                           **
**                                                                            **
********************************************************************************
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std; 

////////////////////////////////////////////
// User Defined Functions Declaretion /////
//////////////////////////////////////////

int login (int second_choice);  // to read login data
int regin (int second_choice);  // to store registration data
string encrypt (string data);  // to encrypt data
string decrypt (string data);  // to decrypt data
int afterCommaString (string fileAddress, string input, int commaNum); // to read a string after specified comma
int adminp(); // To Check Admins, where needed



/////////////////////
// MAIN Function ///
///////////////////

int main(){
	
	// Variables for Choice
	char starting_choice, second_choice;
	int startingChoice_count = 0;
	
	// Sstarting message
	cout << "\n\n\n\n";
	cout << "                                    =     =  =======  =======" << endl;
	cout << "                                    =     =  =     =  =" <<endl;
	cout << "                                    =     =  =     =  =   ===" <<endl;
	cout << "                                    =     =  =     =  =     =" << endl;
	cout << "                                    =======  =======  =======" << endl << endl;
	cout << "              ********************   STUDENT MANAGMENT SYSTEM   ********************" << endl;
	cout << "              ******************** Developed by  UMR Developers ********************" << endl;
	cout << endl << endl;
	choice_label:
	cout << "******************************************" << endl;
	cout << "** Select one option for the follwing:  **" << endl;
	cout << "**                                      **" << endl;
	cout << "** Press 1 for, Login                   **" << endl;
	cout << "** Press 2 for, Registration            **" << endl;
	cout << "** Press 3 for, Exit                    **" << endl;
	cout << "******************************************" << endl;
		
	starting_choice = getch();
	
	// Checking input/choices of user.
		
        	if (starting_choice == '1' || starting_choice == '2' || starting_choice == '3'){
        		
        		switch(starting_choice) {
        			
				  case '1':
				  	
				  	// Move to login function
				  	system("cls");
				  	cout << "Press 1, for Student Login \nPress 2, for Teacher Login\nPress 3, for Back\n";
				  	second_choice = getch();
				  	
				  	if(second_choice == '1' || second_choice == '2'){
				    	login(second_choice);
				    	break;
					}
					
					// For Going Back
	 
					if (second_choice == '3'){
						system("cls");
						goto choice_label;
					}
					
				    break;
				    
				  case '2':
				  	
					// Move to registration function;
					int reginReturn;
					reginReturn0:
					system("cls");
					if (adminp() == 0){
					system("cls");
					  	cout << "Press 1, for Student Registration \nPress 2, for Teacher Registration\nPress 3, for Back\n";
					  	second_choice = getch();
					  	
					  	if(second_choice == '1' || second_choice == '2'){
					     	reginReturn = regin(second_choice);
					     	if(reginReturn == 0){
					     		system("cls");
					     		goto reginReturn0;
							 }
					    	break;
						}
					}
					
					// For Going Back
	 
					if (second_choice == '3'){
						system("cls");
						goto choice_label;
					}
					
				    break;
				    
				 case '3':
				 	
				 	return 0;
				 	break;
				}
			}else {
				
				system("cls");
				cout << "Invalid Input" << endl << "--------------------------"<< endl;
				if (startingChoice_count >= 3){
					return 0;
				}
				startingChoice_count++;
				goto choice_label;
			}
				
//        }
        
	return 0;
}











/////////////////////////////////////
// Registration functionality //////
///////////////////////////////////

int regin (int second_choice){
	
	string fullName, rollNo, empId, email, username, password;
	
	char userInput;
	
	
	
	//For student registration
			
	if (second_choice == '1'){
		
		system("cls");
		cout << "Student Registration Portal\n";
		cout << "Press Enter, to Continue OR Press ESC, to Back\n";
		
		userInput = getch();
		
		if (int(userInput) == 27){
			cout << "esc detected";
			return 0;
		}
		anotherStudent:
	  	system("cls");
	  	cout << "Enter Full Name : ";
	  	getline(cin >> ws, fullName);
	  	
	  	cout << "Enter Your Roll No : ";
	  	cin >> rollNo;
	  	cout << "Enter Your Email : ";
	  	cin >> email;
	  	cout << "Enter Username : ";
	  	cin >> username;
	  	cout << "Enter Password : ";
	  	cin >> password;
	  	
	  	fstream studentFile;
		studentFile.open("data\\studentlog.csv", ios::app);
		
		if (!studentFile.is_open()){
			cout << "File not opened.";
		}

	  	studentFile << encrypt(fullName) << ", " << encrypt(rollNo) << ", " << encrypt(email) << ", " << encrypt(username) << ", " << encrypt(password) << "," << endl;
	  	
	  	cout << endl << "Are you want to register another student? (y/n)" << endl;
	  	if (getch() == 'y'){
	  		goto anotherStudent;
		  }
	  	
	  	studentFile.close();  
	}

	//For teacher registration

	if (second_choice == '2'){
	  	system("cls");
	  	cout << "Enter Full Name : ";
	  	getline(cin >> ws, fullName);
	  	cout << "Enter Your Employee ID : ";
	  	cin >> empId;
	  	cout << "Enter Your Email : ";
	  	cin >> email;
	  	cout << "Enter Username : ";
	  	cin >> username;
	  	cout << "Enter Password : ";
	  	cin >> password;
			  	
	  	fstream teacherFile;
		teacherFile.open("data\\teacherlog.csv", ios::app);
		
		if (!teacherFile.is_open()){
			cout << "File not opened.";
		}

	  	teacherFile << encrypt(fullName) << ", " << encrypt(empId) << ", " << encrypt(email) << ", " << encrypt(username) << ", " << encrypt(password) << "," << endl;
	  	teacherFile.close();  
	}  
	
	return 1;
}











////////////////////////////
// login functionality ////  
//////////////////////////

int login (int second_choice){
	
	string fileAddress, username, password;
	int fileUsername, filePassword;
			
	// For Studnet login
		
	if (second_choice == '1'){
		
	  	system("cls");
	  	stdusernamepasswordagain:
	  	cout << "Enter Username : ";
	  	cin >> username;
	  	cout << "Enter Password : ";
	  	cin >> password;
	  	
	  	fstream studentFile;
	  	fileAddress = "data\\studentlog.csv";
		studentFile.open(fileAddress, ios::in);
		
		if (!studentFile.is_open()){
			cout << "Student\'s Data File is Missing";
		}

		//to verify the username by comparing file
		fileUsername = afterCommaString(fileAddress, encrypt(username), 3);
		filePassword = afterCommaString(fileAddress, encrypt(password), 4);
		
		if (fileUsername == 0){
			//to verify the password by comparing file		
			if (filePassword == 0){
				cout << "Login Successfully" << endl;
				system("pause");
				return 0;
			}else if(filePassword == 1){
				system("cls");
				cout << "Invalid Password. Try Again" << endl << "--------------------------"<< endl;
				goto stdusernamepasswordagain;
			}
		}else if(fileUsername == 1){
			system("cls");
			cout << "Invalid Username. Try Again" << endl << "--------------------------"<< endl;
			goto stdusernamepasswordagain;
		}else {
			return 1;
		}
	 
	  	studentFile.close();  
	  	
	}  
		
	// For Teacher login
		
	if (second_choice == '2'){
	  	system("cls");
	  	teachusernamepasswordagain:
	  	cout << "Enter Username : ";
	  	cin >> username;
	  	cout << "Enter Password : ";
	  	cin >> password;
	  	
	  	fstream teacherFile;
	  	fileAddress = "data\\teacherlog.csv";
		teacherFile.open(fileAddress, ios::in);
		if (!teacherFile.is_open()){
			cout << "File not opened.";
		}

		//to verify the username by comparing file
		fileUsername = afterCommaString(fileAddress, username, 3);
		filePassword = afterCommaString(fileAddress, password, 4);
		
		if (fileUsername == 0){
			//to verify the password by comparing file		
			if (filePassword == 0){
				system("cls");
				cout << "Login Successfully" << endl;
				system("pause");
				return 0;
			}else if(filePassword == 1){
				system("cls");
				cout << "Invalid Password. Try Again" << endl << "--------------------------"<< endl;
				goto teachusernamepasswordagain;
			}
		}else if(fileUsername == 1){
			system("cls");
			cout << "Invalid Username. Try Again" << endl << "--------------------------"<< endl;
			goto teachusernamepasswordagain;
		}else {
			return 1;
		}
	
		teacherFile.close();  
	} 
	
	return 1; 
		
}











////////////////////////////////
// Encryption functionality ///
//////////////////////////////

string encrypt (string data){
	int num = data.length();
	for(int i = 0; (i < num && data[i] != '\0'); i++){
        data[i] = data[i] + 87;	//the key for encryption is 6 that is added to ASCII value
		data[i] = data[i] - 1;  //the key for encryption is 56 that is subtracted to ASCII value
	}

//    cout << "\nEncrypted string: " << data << endl;
	
	return data;
}











///////////////////////////////////
// Decryption functionality //////
/////////////////////////////////

string decrypt (string data){
	
	int num = data.length();
	for(int i = 0; (i < num && data[i] != '\0'); i++){
        data[i] = data[i] - 87;
		data[i] = data[i] + 1; 
	}

    cout << "\nDecrypted string: " << data << endl;
	
	return data;
}











////////////////////////////////////////////////////////
// Function to read string after specified comma //////
//////////////////////////////////////////////////////

int afterCommaString (string fileAddress, string input, int commaNum){
	string output;
	fstream file;
	file.open(fileAddress, ios::in);
	
	string line;
	
	if(!file.is_open()){
		cout << "File not oopen";
	}
	
	while (!file.eof()){
		getline(file, line);
		

		int lineLength = line.length();
		int index = 0, commaCount = 0;

		while (index < lineLength){

			if (line[index] == ','){
				commaCount++;
			}
			
			if (commaCount == commaNum){
				index++;
				output = "";
				
				while(line[index]!= ','){
					output += line[index];
					index++;
				}
				if (output == input){
						goto output;
				}
				break;
			}
			index++;
		}
	}
	if (output != input){
		output = "";
		return 1;
	}
	output:
	return 0;
}











//////////////////////
// Admin Panel //////
////////////////////

int adminp(){
	
	string adminUsername, adminPassword;
		
	cout << "***************************************" << endl;
	cout << "************* Admin Panel *************" << endl;
	cout << "***************************************" << endl << endl;
	cout << "Enter Username : ";
	cin >> adminUsername;
	cout << "Enter Password : ";
	cin >> adminPassword;
	
	if (adminUsername == "admin" && adminPassword == "admin"){
		cout << "Login Successfully";
		return 0;
	}
	
	return 1;
}
