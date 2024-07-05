#include"RegistrationOfApplicationUser.h"
#include<iostream>
using namespace std;



int main()
{
    Registration reg;
    string username, password, gender, cnic;
    int choice, age;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "3. Display All Users\n";
        cout << "4. Switch User\n";
        cout << "5. Send Notification Reminder\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (reg.loginUser(username, password))
            {
                cout << "Login successful!\n";
                reg.sendNotificationReminder();
                reg.displayGoals();
                int goal1, goal2;
                cout << "Enter the numbers of your two selected goals: ";
                cin >> goal1 >> goal2;
                reg.suggestWorkoutPlans(goal1, goal2);
            }
            else
            {
                cout << "Invalid username or password.\n";
            }
            break;
        case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;
            cout << "Enter CNIC: ";
            cin >> cnic;
            if (reg.signUpUser(username, password, age, gender, cnic))
            {
                cout << "Sign up successful!\n";
            }
            else
            {
                cout << "Username already exists.\n";
            }
            break;
        case 3:
            reg.displayAllUsers();
            break;
        case 4:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (reg.switchUser(username, password))
            {
                cout << "Switched user successfully!\n";
                reg.sendNotificationReminder();
                reg.displayGoals();
                int goal1, goal2;
                cout << "Enter the numbers of your two selected goals: ";
                cin >> goal1 >> goal2;
                reg.suggestWorkoutPlans(goal1, goal2);
            }
            else
            {
                cout << "Invalid username or password.\n";
            }
            break;
        case 5:
            reg.sendNotificationReminder();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
