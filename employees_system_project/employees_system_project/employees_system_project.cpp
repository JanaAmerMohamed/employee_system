#include <iostream>
using namespace std;
# include <string>

class Employee {
protected:
    string full_name;
    string email;
    string phone;
    string position;
    double salary;
public:
    Employee() {
    };
    Employee(string fn, string em, string ph, string post, double sal) {
        full_name = fn;
        email = em;
        phone = ph;
        position = post;
        salary = sal;
    }
    void setfull_name(string fn) {
        full_name = fn;
    }
    string getfull_name() {
        return full_name;
    }
    void setemail(string em) {
        email = em;
    }
    string getemail() {
        return email;
    }
    void setphone(string ph) {
        phone = ph;
    }
    string getphone() {
        return phone;
    }
    void setposition(string pos) {
        position = pos;
    }
    string getposition() {
        return position;
    }
    void setsalary(double sal) {
        salary = sal;
    }
    double getsalary() {
        return salary;
    }

    void display();
};
void Employee::display() {
    cout << "your name is:" << getfull_name() << endl;
    cout << "your email is:" << getemail() << endl;
    cout << "your phone is:" << getphone() << endl;
    cout << "your position is:" << getposition() << endl;
    cout << "your salary is:" << getsalary() << endl;
}
template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};

template <class T>
class EmployeeList {
    Node<T>* head;
public:
    EmployeeList() {
        head = NULL;
    }
    bool insert_employee(T e);
    bool edit_salary(double new_salary, string email);
    bool delete_employee(string email);
    void printall();
    bool update_info(string email);

};

template <class T>
bool EmployeeList <T>::insert_employee(T e) {
    Node <T>* newNode = new Node<T>(e);
    if (head == NULL) {
        cout << "there is no employee in the list." << endl;
        newNode->next = NULL;
        head = newNode;
        return false;
    }
    else {
        Node <T>* temp = head;
        Node <T>* ptr = NULL;
        while (temp != NULL) {
            if (e.getemail() == temp->data.getemail() && ptr == NULL) {
                ptr = head;
                cout << "the employee already exists" << endl;
                temp->data.display();
                break;

            }
            if (e.getemail() == temp->data.getemail() && ptr != NULL) {
                ptr = temp;
                cout << "the employee already exists" << endl;
                temp->data.display();
                break;
            }
            ptr = temp;
            temp = temp->next;

        }
        if (e.getemail() != ptr->data.getemail()) {
            newNode->next = NULL;
            ptr->next = newNode;
            return false;
        }
        return true;
    }
}

template <class T>
bool EmployeeList<T>::edit_salary(double new_salary, string email) {
    if (head == NULL) {
        cout << "there is no employee in the list so, no edit" << endl;
        return false;
    }
    else {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->data.getemail() == email) {
                temp->data.setsalary(new_salary);
                break;
            }
            temp = temp->next;
        }
        return true;
    }
}

template <class T>
bool EmployeeList <T>::delete_employee(string email) {
    bool x = false;
    if (head == NULL) {
        cout << "there is no employee in the list, so no delete" << endl;
        return false;
    }
    else {
        Node<T>* temp = head;
        Node<T>* ptr = NULL;
        while (temp != NULL) {
            if (email == temp->data.getemail() && temp == head) {
                head = head->next;
                delete temp;
                x = true;
                return x;
            }
            if (email == temp->data.getemail() && temp->next == NULL) {
                ptr->next = NULL;
                delete temp;
                x = true;
                return x;

            }

            if (email == temp->data.getemail() && temp != head && temp->next != NULL) {
                ptr->next = temp->next;
                delete temp;
                x = true;
                return x;
            }
            ptr = temp;
            temp = temp->next;
        }
        if (x == false) {
            cout << "employee doesn't exist" << endl;
            printall();
        }
    }
}

template <class T>
void EmployeeList <T>::printall() {
    Node<T>* temp = head;
    if (head == NULL) {
        cout << "there is no employee in the list" << endl;
    }
    else {
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
}

template <class T>
bool EmployeeList <T>::update_info(string email) {
    Node<T>* temp = head;
    while (temp != NULL) {
        if (email == temp->data.getemail()) {
            string attribute;
            cout << "name -> to edit name" << endl;
            cout << "salary -> to edit the salary" << endl;
            cout << "position -> to edit the position" << endl;
            cout << "phone -> to edit the phone" << endl;
            cout << "email -> to edit the email" << endl;
            cout << "entre the attributes to change:" << endl;
            cin >> attribute;
            if (attribute == "name") {
                string name_new;
                cout << "entre the edit name" << endl;
                cin >> name_new;
                temp->data.setfull_name(name_new);
            }
            if (attribute == "salary") {
                double salary_new;
                cout << "entre the edit salary" << endl;
                cin >> salary_new;
                temp->data.setsalary(salary_new);
            }
            if (attribute == "phone") {
                string phone_new;
                cout << "entre the edit phone" << endl;
                cin >> phone_new;
                temp->data.setphone(phone_new);
            }
            if (attribute == "email") {
                string email_new;
                cout << "entre the edit email" << endl;
                cin >> email_new;
                temp->data.setemail(email_new);
            }
            if (attribute == "position") {
                string position_new;
                cout << "entre the edit position" << endl;
                cin >> position_new;
                temp->data.setposition(position_new);
            }
            return true;
        }

        temp = temp->next;
    }
}
void message_list_info() {
    cout << endl << "=======================================" << endl;
    cout << "Welcome to the Employee Management System" << endl;
    cout << "Choose of the following to use the system features" << endl;
    cout << "0. update info of any attributes" << endl;
    cout << "1. Insert a new Employee" << endl;
    cout << "2. Edit employee's salary" << endl;
    cout << "3. Delete an employee" << endl;
    cout << "4. Print all employees" << endl;
    cout << "5. Close the program" << endl;
}
int main() {
    int number;
    EmployeeList< Employee> sll;
    while (number != 5) {
        message_list_info();
        cout << "please entre the number option: " << endl;
        cin >> number;
        string name;
        string email;
        string phone;
        string position;
        double salary;
        if (number == 1) {
            cout << "entre the name:" << endl;
            cin >> name;
            cout << "entre the email:" << endl;
            cin >> email;
            cout << "entre the phone:" << endl;
            cin >> phone;
            cout << "entre the position:" << endl;
            cin >> position;
            cout << "entre the salary:" << endl;
            cin >> salary;
            Employee obj1(name, email, phone, position, salary);
            sll.insert_employee(obj1);
            cout << "========printall the employee========" << endl;
            sll.printall();
        }

        if (number == 2) {
            string new_email;
            double new_salary;
            cout << "entre the email to edit:" << endl;
            cin >> new_email;
            cout << "entre the salary to edit:" << endl;
            cin >> new_salary;
            sll.edit_salary(new_salary, new_email);
            cout << "========printall the employee========" << endl;
            sll.printall();
        }

        if (number == 3) {
            string emaild;
            cout << "entre the email to delete" << endl;
            cin >> emaild;
            sll.delete_employee(emaild);
        }
        if (number == 4) {
            sll.printall();
        }
        if (number == 5) {
            cout << "THANK YOU,program closed" << endl;
            break;
        }
        if (number == 0) {
            string email1;
            cout << "entre the email to edit the attributes" << endl;
            cin >> email1;
            sll.update_info(email1);
            cout << "========printall the employee========" << endl;
            sll.printall();
        }
    }

    return 0;
}









