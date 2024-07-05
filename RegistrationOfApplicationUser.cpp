#include "RegistrationOfApplicationUser.h"


Registration::Registration() : currentUserIndex(-1)
{
    loadUsers();
}

void Registration::loadUsers()
{
    ifstream file("users.txt");
    if (!file.is_open())
    {
        cerr << "Error opening users.txt file" << endl;
        return;
    }

    string username, password, gender, cnic;
    int age, streak;
    time_t lastLoginTime;
    while (file >> username >> password >> age >> gender >> cnic >> streak >> lastLoginTime)
    {
        usernames.push_back(username);
        passwords.push_back(password);
        ages.push_back(age);
        genders.push_back(gender);
        cnics.push_back(cnic);
        streaks.push_back(streak);
        lastLoginTimes.push_back(lastLoginTime);
    }
    file.close();
}

void Registration::saveUsers()
{
    ofstream file("users.txt", ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing users data" << endl;
        return;
    }

    for (size_t i = 0; i < usernames.size(); ++i)
    {
        file << usernames[i] << " " << passwords[i] << " " << ages[i] << " "
            << genders[i] << " " << cnics[i] << " " << streaks[i] << " "
            << lastLoginTimes[i] << endl;
    }
    file.close();
}

bool Registration::loginUser(const string& username, const string& password)
{
    for (size_t i = 0; i < usernames.size(); ++i)
    {
        if (usernames[i] == username && passwords[i] == password)
        {
            currentUserIndex = i;
            updateStreak();
            return true;
        }
    }
    return false;
}

bool Registration::signUpUser(const string& username, const string& password, int age, const string& gender, const string& cnic)
{
    for (string& existingUsername : usernames)
    {
        if (existingUsername == username)
        {
            return false; // Username already exists
        }
    }
    usernames.push_back(username);
    passwords.push_back(password);
    ages.push_back(age);
    genders.push_back(gender);
    cnics.push_back(cnic);
    streaks.push_back(0);
    lastLoginTimes.push_back(time(0));
    saveUsers();
    return true;
}

void Registration::displayGoals()
{
    cout << "Select 2 goals from the following:\n";
    cout << "1. Weight Loss\n";
    cout << "2. Muscle Gain\n";
    cout << "3. Endurance\n";
    cout << "4. Flexibility\n";
}

void Registration::suggestWorkoutPlans(int goal1, int goal2)
{
    cout << "Workout Plan for your selected goals:\n";
    if (goal1 == 1 || goal2 == 1)
    {
        cout << "- Cardio exercises\n";
        cout << "- Low-carb diet\n";
    }
    if (goal1 == 2 || goal2 == 2)
    {
        cout << "- Strength training\n";
        cout << "- High-protein diet\n";
    }
    if (goal1 == 3 || goal2 == 3)
    {
        cout << "- Long-distance running\n";
        cout << "- Interval training\n";
    }
    if (goal1 == 4 || goal2 == 4)
    {
        cout << "- Yoga\n";
        cout << "- Stretching exercises\n";
    }
}

void Registration::displayAllUsers()
{
    cout << "Registered Users:\n";
    for (size_t i = 0; i < usernames.size(); ++i)
    {
        cout << "Username: " << usernames[i] << ", Age: " << ages[i]
            << ", Gender: " << genders[i] << ", CNIC: " << cnics[i]
            << ", Streak: " << streaks[i] << endl;
    }
}

bool Registration::switchUser(const string& username, const string& password)
{
    return loginUser(username, password);
}

void Registration::updateStreak()
{
    if (currentUserIndex == -1) return;

    time_t now = time(0);
    double seconds = difftime(now, lastLoginTimes[currentUserIndex]);
    if (seconds >= 86400 && seconds < 172800)
    {
        streaks[currentUserIndex]++;
    }
    else if (seconds >= 172800)
    {
        streaks[currentUserIndex] = 0;
    }
    lastLoginTimes[currentUserIndex] = now;
    saveUsers();
}

void Registration::sendNotificationReminder()
{
    if (currentUserIndex != -1)
    {
        cout << "Reminder: Don't forget to complete your workout today!\n";
    }
}