#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
using namespace std;


template <class Item>
class node
{
private:
    Item data;
    node* link;
public:

    node(Item init_data, node* init_link)
    {
        data = init_data;
        link = init_link;
    }


    Item get_data() { return data; }
    node* get_link() { return link; }

    void set_data(Item new_data) { data = new_data; }
    void set_link(node* new_link) { link = new_link; }

};

template <class Item>
void list_head_insert(node<Item>*& head_ptr, Item data)
{
    head_ptr = new node<Item>(data, head_ptr);
}

template <class Item>
void list_insert(node<Item>*& previous_ptr, Item data)
{
    node<Item>* insert_ptr;
    insert_ptr = new node<Item>(data, previous_ptr->get_link());
    previous_ptr->set_link(insert_ptr);
    previous_ptr = insert_ptr;
}

template <class Item>
void list_head_remove(node<Item>*& head_ptr)
{
    node<Item>* remove_ptr;
    remove_ptr = head_ptr;
    head_ptr = head_ptr->get_link();
    delete remove_ptr;
}

template <class Item>
void list_remove(node<Item>* previous_ptr)
{
    node<Item>* remove_ptr;
    remove_ptr = previous_ptr->get_link();
    previous_ptr->set_link(remove_ptr->get_link());
    delete remove_ptr;
}



template <class Item>
node<Item>* list_search(node<Item>* head_ptr, Item target)
{
    node<Item>* MyNode;
    for (MyNode = head_ptr; MyNode != NULL; MyNode = MyNode->get_link())
        if (target == MyNode->get_data())
            return MyNode;

    return NULL;
}
template <class Item>
void list_clear(node<Item>*& head_ptr)
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);

}
template <class Item>
void list_copy(node<Item>* source_ptr, node<Item>*& head_ptr)
{
    node<Item>* tail_ptr = NULL;

    if (source_ptr == NULL)
        return;

    list_head_insert(head_ptr, source_ptr->get_data());
    tail_ptr = head_ptr;

    source_ptr = source_ptr->get_link();
    while (source_ptr != NULL)
    {
        list_insert(tail_ptr, source_ptr->get_data());
        source_ptr = source_ptr->get_link();
    }
}


template<class Item>
void print(node<Item>* link) {
    if (link == NULL) {
        cout << "The list is Empty !!\n";
    }
    cout << "\nThe LinkedList is : [";
    while (link != NULL) {
        
        
        cout << "\n----------------------\n\n";
        cout <<"The name is :" << link->get_data().name << "\n";
        cout << "The age is :" << link->get_data().age << "\n";
        cout << "The id is :" << link->get_data().id << "\n";
        cout << "\n----------------------\n\n";
        link = link->get_link();
    }
    cout << " ]\n";
}


#endif // LINKEDLIST_H_INCLUDED
