#include<iostream>
#include<string>
#include<map>

using namespace std;

class User {
public:
	void AddUser(string name, string pass)
	{
		m[name] = pass;
	}
	User(string name, string pass)
	{
		AddUser(name, pass);
	}
	int login(string name, string pass)
	{
		if (m.find(name) == m.end() || m[name] != pass)
			return - 1;
		return 0;
	}
private:
	map<string, string> m;
};

int main() {
	char name[10], name1[10], pass[10], pass1[10];
	cin >> name >> pass >> name1 >> pass1;
	User user("LiWei", "liwei101");
	user.AddUser(name, pass);
	if (user.login(name1, pass1) >= 0)
	{
		cout << "Success Login!" << endl;
	}
	else {
		cout << "Login failed!" << endl;
	}
	return 0;
}