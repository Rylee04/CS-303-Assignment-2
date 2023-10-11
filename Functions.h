#include <string>
#pragma once
using namespace std;

//The SingleLinkedList class
//Contains the struct Node and declarations for the linked list functions
template <typename Item_Type>
class SingleLinkedList {

private:

    struct Node {

        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}

    };

    Node* head;
    Node* tail;
    int num_items;

public:

    SingleLinkedList();
    ~SingleLinkedList();

    void push_front(const Item_Type& data_item);
    void push_back(const Item_Type& data_item);
    void pop_front();
    void pop_back();
    const Item_Type& front() const;
    const Item_Type& back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& data_item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;

};

//Constructor
template <typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {};

//Destructor
template <typename Item_Type>
SingleLinkedList<Item_Type>::~SingleLinkedList() {
    while (head != nullptr) {

        Node* temp = head;
        head = head->next;

        delete temp;

    }
}

//The Employee class
//Contains common employee attributes such as name, ID, hourly rate, and hours worked
class Employee {

protected:

    string name;
    int employeeID;
    double hourlyRate;
    int hoursWorked;

public:

    //Constructor
    Employee(const string& name, int employeeID, double hourlyRate, int hoursWorked) : name(name), employeeID(employeeID), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    //Declaration for Employee functions
    virtual double calcSalary() const = 0; // Abstract function
    virtual double calcHealthCare() const = 0; // Abstract function
    virtual int calcVacationDays() const = 0; // Abstract function

};

//The Professional class derived from Employee
//Contains declarations for Professional specific functions
class Professional : public Employee {

public:

    //Constructor
    Professional(const string& name, int employeeID, double hourlyRate, int hoursWorked) : Employee(name, employeeID, hourlyRate, hoursWorked) {}

    double calcSalary() const override;
    double calcHealthCare() const override;
    int calcVacationDays() const override;

};

//The Nonprofessional class derived from Employee
//Contains declarations for Nonprofessional specific functions
class Nonprofessional : public Employee {

public:

    //Constructor
    Nonprofessional(const string& name, int employeeID, double hourlyRate, int hoursWorked) : Employee(name, employeeID, hourlyRate, hoursWorked) {}

    double calcSalary() const override;
    double calcHealthCare() const override;
    int calcVacationDays() const override;
    
};

