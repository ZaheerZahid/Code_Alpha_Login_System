#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter new username: "; cin >> username;
    cout << "Enter new password: "; cin >> password;
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;
    ifstream file(username + ".txt");
    if(!file){ cout << "User not found!\n"; return; }
    getline(file, u); getline(file, p);
    if(u==username && p==password) cout << "Login Successful! Welcome " << username << endl;
    else cout << "Wrong Password!\n";
}

int main() {
    int choice;
    while(true){
        cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        if(choice==1) registerUser();
        else if(choice==2) loginUser();
        else if(choice==3) break;
    }
    return 0;
}