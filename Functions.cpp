//Functions.cpp : This file contains the definitions for functions and methods
#include <iostream>
#include <stdexcept>
#include "Functions.h"

//The push_front function adds an element to the front of the linked list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& data_item) {

   Node* node = new Node(data_item);

   //Checking if the linked list is empty; if it is, then sets both the head
   //and tail to point to the new element
   if (head == nullptr) {
       head = tail = node;
   }

   else {

        node->next = head;
        head = node;

   }

   //Increments the number of items in the linked list
   num_items++;

}

//The push_back function adds an element to the back of the linked list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& data_item) {

    Node* node = new Node(data_item);

    //Checking if the linked list is empty; if it is, then sets both the head
   //and tail to point to the new element
    if (tail == nullptr) {
        head = tail = node;
    }
    else {

        tail->next = node;
        tail = node;

    }

    num_items++;

}

//The pop_front function deletes the first item in the linked list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {

    //Checking if the list is emtpy; if it is, throws an error since there isn't
    //anything in the linked list to delete
    if (head == nullptr) {
        throw std::runtime_error("Nothing to pop");
    }

    //Copies the head pointer into a temporary one so the head can switch and
    //the original head gets deleted
    Node* temp = head;
    head = head->next;
    delete temp;
    //Decrements the number of items in the linked list
    num_items--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

//The pop_back function deletes the last item in the linked list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {

    //Checking if the list is emtpy; if it is, throws an error since there isn't
    //anything in the linked list to delete
    if (tail == nullptr) {
        throw std::runtime_error("Nothing to pop");
    }

    //Checking if the list only has one item, in which case both the head and tail
    //would point to the same element and would both have to be set to null once
    //it gets deleted
    if (head == tail) {

        delete head;
        head = tail = nullptr;

    }
    else {

        //Finds the tail
        Node* current = head;

        while (current->next != tail) {
        current = current->next;
        }

        //Deletes it and sets it to null
        delete tail;
        tail = current;
        tail->next = nullptr;

    }

    num_items--;

}

//The front function returns the data of the head pointer
template <typename Item_Type>
const Item_Type& SingleLinkedList<Item_Type>::front() const {

    //Checks if the list is empty
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }

    return head->data;

}

//The front function returns the data of the tail pointer
template <typename Item_Type>
const Item_Type& SingleLinkedList<Item_Type>::back() const {

    //Checks if the list is empty
    if (tail == nullptr) {
        throw std::runtime_error("List is empty");
    }

    return tail->data;

}

//The empty function returns whether or not the linked list is empty
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() const {
    return num_items == 0;
}

//The insert function takes an index and a value and inserts it into the linked list
template <typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& data_item) {

    //Checks if the wanted index is greater than the size of the linked list
    if (index >= num_items) {
        push_back(data_item);
    }
    //Checks if the wanted index is zero
    else if (index == 0) {
        push_front(data_item);
    }
    else {

        //Creates a new pointer with entered value
        Node* new_node = new Node(data_item);
        Node* current = head;

        //Finds the correct location in the linked list
        for (size_t i = 1; i < index; i++) {
            current = current->next;
        }

        //Inserts it and sets the new value's pointer to the next item
        new_node->next = current->next;
        current->next = new_node;
        num_items++;

        }
}

//The remove function takes an index and removes the value found at that location
//and returns true if it was successful or false if it wasn't
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {

    //Checks if the entered index is greater than the size of the linked list
    //and returns false
    if (index >= num_items) {
        return false;
    }

    //Checks if the index is zero; if it is, calls the pop_front function
    if (index == 0) {
        pop_front();
    }
    else {

        //Creates a temporary pointer used to cycle through the linked list
        Node* current = head;

        //Finds the correct location 
        for (size_t i = 1; i < index; i++) {
            current = current->next;
        }

        //Shifts the pointers around with another temporary pointer and deletes the target value
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        num_items--;

    }

    //Returns true with a successful operation
    return true;

}

//The find function locates a specified value within the linked list
template <typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& data_item) const {

    //Creates a temporary pointer used to cycle through the linked list
    Node* current = head;
    size_t index = 0;

    //Searches for the target value
    while (current != nullptr) {
        if (current->data == data_item) {
            return index;
        }

        current = current->next;
        index++;

    }

    //If unsuccessful returns the size of the linked list
    return num_items;

}

//Defines functions for the derived classes Professional and Nonprofessional from Employee
//These functions calculate their weekly earnings, healthcare contributions, and vacation days
double Professional::calcSalary() const { return hoursWorked * hourlyRate; }
double Professional::calcHealthCare() const { return 0.125 * calcSalary(); } // 1/8 of the salary
int Professional::calcVacationDays() const { return 21; }
double Nonprofessional::calcSalary() const { return hoursWorked * hourlyRate; }
double Nonprofessional::calcHealthCare() const { return 0.1 * calcSalary(); } // 1/10 of the salary
int Nonprofessional::calcVacationDays() const { return hoursWorked / 10; } // 1/10 of the hours worked