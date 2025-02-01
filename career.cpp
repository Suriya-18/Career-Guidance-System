#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Structure to store career role details
struct CareerRole {
    string name;
    vector<string> required_skills;
    vector<string> famous_personalities;
};

// Function to display career fields
void displayFields(map<string, vector<CareerRole>> &careerMap) {
    cout << "\nAvailable Career Fields:\n";
    for (const auto &field : careerMap) {
        cout << "- " << field.first << endl;
    }
}

// Function to display available roles in a selected field
void displayRoles(vector<CareerRole> &roles) {
    cout << "\nAvailable Roles:\n";
    for (int i = 0; i < roles.size(); i++) {
        cout << i + 1 << ". " << roles[i].name << endl;
    }
}

// Function to display details of a selected role
void displayRoleDetails(CareerRole &role) {
    cout << "\nRole: " << role.name << endl;
    cout << "Required Skills:\n";
    for (const string &skill : role.required_skills) {
        cout << "- " << skill << endl;
    }
    cout << "Famous Personalities:\n";
    for (const string &person : role.famous_personalities) {
        cout << "- " << person << endl;
    }
}

int main() {
    // Career Data
    map<string, vector<CareerRole>> careerMap;

    // Adding IT career options
    careerMap["IT"] = {
        {"Software Engineer", {"Programming", "Problem-Solving", "Data Structures"}, {"Bill Gates", "Linus Torvalds"}},
        {"Data Scientist", {"Machine Learning", "Statistics", "Python"}, {"Andrew Ng", "Yann LeCun"}}
    };

    // Adding Media career options
    careerMap["Media"] = {
        {"Journalist", {"Writing", "Investigation", "Communication"}, {"Barkha Dutt", "Ravish Kumar"}},
        {"Filmmaker", {"Storytelling", "Editing", "Cinematography"}, {"Christopher Nolan", "Steven Spielberg"}}
    };

    // Adding Sports career options
    careerMap["Sports"] = {
        {"Cricketer", {"Batting", "Bowling", "Fitness"}, {"Virat Kohli", "Sachin Tendulkar"}},
        {"Footballer", {"Dribbling", "Passing", "Fitness"}, {"Lionel Messi", "Cristiano Ronaldo"}}
    };

    string chosenField;
    int roleChoice;

    // Display available career fields
    displayFields(careerMap);
    
    // Get user input for career field
    cout << "\nEnter a career field to explore: ";
    cin >> chosenField;

    // Check if the field exists
    if (careerMap.find(chosenField) != careerMap.end()) {
        // Display available roles
        displayRoles(careerMap[chosenField]);

        // Get user input for role selection
        cout << "\nEnter the role number to view details: ";
        cin >> roleChoice;

        if (roleChoice > 0 && roleChoice <= careerMap[chosenField].size()) {
            displayRoleDetails(careerMap[chosenField][roleChoice - 1]);
        } else {
            cout << "Invalid choice!" << endl;
        }
    } else {
        cout << "Career field not found!" << endl;
    }

    return 0;
}
