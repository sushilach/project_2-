#include <iostream>
#include <vector>
#include <algorithm>

struct User {
    std::string name;
    int age;
    std::vector<std::string> interests;

    User(const std::string& n, int a, const std::vector<std::string>& i)
        : name(n), age(a), interests(i) {}
};

std::vector<User> users;

void addUser() {
    std::string name;
    int age;
    std::vector<std::string> interests;

    std::cout << "Enter user's name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter user's age: ";
    std::cin >> age;
    std::cin.ignore(); // Ignore newline character

    std::cout << "Enter user's interests (type 'done' to finish):" << std::endl;
    std::string interest;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin >> std::ws, interest);
        if (interest == "done") {
            break;
        }
        interests.push_back(interest);
    }

    users.emplace_back(name, age, interests);
}

void matchUsers() {
    std::cout << "Matching users based on age:" << std::endl;
    for (size_t i = 0; i < users.size(); ++i) {
        std::cout << "For user " << users[i].name << " (Age: " << users[i].age << "):" << std::endl;
        std::vector<std::string> matchedUsers;

        for (size_t j = 0; j < users.size(); ++j) {
            if (i != j && users[i].age == users[j].age) {
                matchedUsers.push_back(users[j].name);
            }
        }

        if (matchedUsers.empty()) {
            std::cout << "No matches found." << std::endl;
        } else {
            std::cout << "Matches: ";
            for (size_t k = 0; k < matchedUsers.size(); ++k) {
                const std::string& matchedUser = matchedUsers[k];
                std::cout << matchedUser << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    int numUsers;
    std::cout << "Enter the number of users: ";
    std::cin >> numUsers;
    std::cin.ignore(); // Ignore newline character

    for (int i = 0; i < numUsers; ++i) {
        std::cout << "User " << i + 1 << ":" << std::endl;
        addUser();
    }

    matchUsers();

    return 0;
}
