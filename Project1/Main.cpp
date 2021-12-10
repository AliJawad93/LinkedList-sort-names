#include<iostream>
#include"linkedlist.h"
#include<math.h>
using namespace std;

struct Student
{
    string  name;
    int age;
    int id;

};
template<class Item>
void Delete_with_age(node<Item>*& head, size_t age) {
    node<Item>* prev, * current;
    prev = NULL;
    current = head;
    do {
        if (prev == NULL && current->get_data().age >= age)
        {
            list_head_remove(head);
            current = head;
        }
        else  if (prev != NULL && current->get_data().age >= age)
        {
            list_remove(prev);
            current = prev->get_link();
        }
        else
        {
            prev = current;
            current = current->get_link();
        }
    } while (current != NULL);

}

template<class Item>
void insert_with_sort(node<Item>*& head, int num) {
    node<Item>* prev, * current, * temp;
    Student s;
    string more;
    int counter = 1;
    while (more != "NO")
    {
        cout << "\n***********************************\n\n";
        cout << "\nEnter the name:";
        cin >> s.name;
        cout << "Enter the Age:";
        cin >> s.age;
        cout << "Enter the Id:";
        cin >> s.id;

        if (head == NULL)
            head = new node<Student>(s, NULL);

        prev = NULL;
        current = head;

        if (counter != 1) {
        loop:
            if (current->get_data().name <= s.name)
            {
                if (current->get_link() == NULL)
                {
                    list_insert(current, s);
                }
                else
                {
                    prev = current;
                    current = current->get_link();
                    goto loop;
                }
            }
            else {
            loop2: if (current->get_data().name >= s.name) {
                
                list_head_insert(current, s);

                
                if (prev == NULL)
                    head = current;
                else { prev->set_link(current); }


            }
            else
            {
                prev = current;
                current = current->get_link();
                goto loop2;
            }
            }
        }

        if (num == counter) {
            cout << "\nDo You want to add new Student enter (YES or NO) :";
            cin >> more;
            if (more == "YES") {
                int n;
                cout << "\nenter number of student :";
                cin >> n;
                num += n;
            }
        }
        counter++;

    }//end loop

}

int main() {

    node<Student>* head = NULL;
    int num, choice = 0;
    size_t age;

    while (choice != 4)
    {
        cout << "1- insert Student \n";
        cout << "2- delete ages \n";
        cout << "3- print \n";
        cout << "4- Exit\n";
        cout << "Enter the number :";
        cin >> choice;

        switch (choice)
        {
        case 1: {
            cout << "Enter the number of the student :";
            cin >> num;
            insert_with_sort(head, num);
        } break;
        case 2: {
            cout << "\nEnter the number of age :";
            cin >> age;
            Delete_with_age(head, age);
        }break;
        case 3: {print(head); }break;
        default:
            break;
        }
    }



    return 0;

}