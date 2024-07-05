#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class Registration
{
private:
    vector<string> usernames;
    vector<string> passwords;
    vector<int> ages;
    vector<string> genders;
    vector<string> cnics;
    vector<int> streaks;
    vector<time_t> lastLoginTimes;
    int currentUserIndex;

public:
    Registration();

    void loadUsers();

    void saveUsers();

    bool loginUser(const string& username, const string& password);

    bool signUpUser(const string& username, const string& password, int age, const string& gender, const string& cnic);

    void displayGoals();

    void suggestWorkoutPlans(int goal1, int goal2);
    void displayAllUsers();

    bool switchUser(const string& username, const string& password);

    void updateStreak();

    void sendNotificationReminder();
};

#endif

