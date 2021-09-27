#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    Node();                       // Default constructor
    explicit Node(T data);       // Single argument constructor
    Node(T data, Node<T> *next);   // Constructor with next pointer
    ~Node();                    // Destructor

    T getData();
    void setData(T data);

    Node<T> *getNext() {
        return next_;
    };

    void setNext(Node<T> *next) {
        next_ = next;
    };

private:
    T data_;
    Node<T> *next_;
};

template<typename T>
Node<T>::Node(): data_(T()), next_(nullptr) {} // default empty value for type T (might be int, string, etc.)

template<typename T>
Node<T>::Node(T data) : data_(data) {
    cout << "Single argument Node with data: " << data_ << " created" << endl;
}

template<typename T>
Node<T>::~Node() {
    cout << "Node deleted" << endl;
}

template<typename T>
Node<T>::Node(T data, Node<T> *next) : data_(data), next_(next){
    cout << "New node with pointer created" << endl;
}

template<typename T>
T Node<T>::getData() {
    return data_;
}

template<typename T>
void Node<T>::setData(T data) {
    data_ = data;
}

template<typename T>
class LinkedList{
public:
    LinkedList();                                               //Default constructor
    LinkedList(const LinkedList<T> &other);                     // Copy constructor
    ~LinkedList();                                              // Destructor

//    intList                                   intList2
    LinkedList<T> & operator = (const LinkedList<T> &other) {       // Copy assignment
        Node<T> *current;
        Node<T> *temp = other.head_;
        while (temp != nullptr) {
            pushTail(temp->getData());
            current = temp;
            temp = current->getNext();
        }
        return *this;
    };


    T operator [](int index);                                   // subscript operator
     //ostream operator
    friend ostream &operator<<(ostream &os, const LinkedList<T> &list) {
        os << list.toString();
        return os;
    }

    string toString() const {
        Node<T> *node = head_;
        if(node == nullptr) {
            return "List empty";
        }
        string result;
        while(true){
            if(node == nullptr) break;
            result += std::to_string(node->getData()) + ((node->getNext() == nullptr) ? "" : "->");
            node = node->getNext();
        }
        return result;
    }
    // Methods (push, pop, clear)
    void pushHead(T i) {
        Node<T> *node = new Node<T>(i);
        node->setNext(nullptr);
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
            size_++;
        } else {
            node->setNext(head_);
            head_ = node;
            size_++;
        }
    }

    void pushTail(T data){
        auto *temp = new Node<T>(data);
        auto *current = head_;
        temp->setNext(nullptr);
        if (head_ == nullptr) {
            head_ = temp;
            tail_ = temp;
            size_++;
        }
        else {
            while (current && current->getNext()) {
                current = current->getNext();
            }
            current->setNext(temp);
            size_++;
        }
    };

    T popHead() {
        auto *temp = new Node<T>;
        auto *toDel = new Node<T>;
        auto val = new T;
        if (head_ == nullptr) {
            cout << "The list is empty!" << endl;
        }
        else {
            temp = head_->getNext();
            toDel = head_;
            head_ = temp;
            *val = toDel->getData();
            free(toDel);
            size_--;
        }
        return *val;
    }

    T popTail() {
        auto *temp = new Node<T>;
        auto *current = new Node<T>;
        auto val = new T;
        current = head_;
        temp = head_;
        if (head_ == nullptr) {
            cout << "The list is empty" << endl;
        }
        while (current->getNext() != nullptr) {
            temp = current;
            current = current->getNext();
        }
        temp->setNext(nullptr);
        *val = current->getData();
        free(current);
        size_--;
        return *val;
    }

    T popAtPos(int pos) {
        Node<T> *current;
        Node<T> *toDel;
        int val;

        if (head_ == NULL) {
            printf("The list is empty\n");
        }
        current = head_;
        toDel = head_;

        for (int i = 1; i <= pos; i++) {
            current = toDel;
            toDel = toDel->getNext();

            if(current == NULL)
                break;
        }
        if (current != NULL){
            if(toDel == head_)
                head_ = head_->getNext();

            current->setNext(toDel->getNext());
            val = toDel->getData();
            toDel->setNext(nullptr);
            delete(toDel);
            size_--;
        }
        else
            printf("Cannot delete node at that position");

        return val;
    }

    T peekAtPos(int pos) {
        int val;
        Node<T> *stnode;
        Node<T> *temp;
        stnode = head_;
        if(stnode == nullptr) {
            printf("The list is empty\n");
        }
        temp = stnode;
        for(int i = 1; i <= pos; i++) {
            temp = temp->getNext();

            if(temp == nullptr)
                break;
        }
        if (temp != nullptr){
            val = temp->getData();
        }
        return val;
    }

    void print(){
        Node<T> *temp = head_;
        if (head_ == nullptr){
            cout<<"List is empty"<<endl;
        }
        else{
            cout<<"Linked List: ";
            while (temp != nullptr){
                cout<<temp->getData()<<"->";
                temp = temp->getNext();
            }
            cout<<"NULL"<<endl;
            cout << "Size: " << size_ << endl;
        }
    }

    void clearList() {
        Node<T> *current = new Node<T>;
        Node<T> *next = new Node<T>;
        current = head_;

        while(head_ != nullptr) {
            next = head_->getNext();
            delete(head_);
            head_ = next;
            size_--;
        }
    }

private:
    Node<T> *head_;
    Node<T> *tail_;
    int size_;
};

template<typename T>
LinkedList<T>::LinkedList()  {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
    head_ = other;
    tail_ = other;
    size_ = 1;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    cout << "LL with size: " << size_ << " deleted" << endl;
}

template<typename T>
T LinkedList<T>::operator[](int index) {
    return peekAtPos(index);
}




int main() {

    LinkedList<int> intList;
    cout << "\nPushing values at the head of Linked List: " << endl;
    intList.pushHead(10);
    intList.pushHead(20);
    intList.pushHead(30);

    intList.print();

    cout << "\nPushing values at the tail of Linked List: " << endl;
    intList.pushTail(40);
    intList.pushTail(50);
    cout << "\nPushing values at the head of Linked List: " << endl;
    intList.pushHead(0);
    intList.pushHead(66);
    intList.print();

    cout << "\nPopping value from head: " << intList.popHead() << endl;
    intList.print();

    cout << "\nPopping value from tail: " << intList.popTail() << endl;
    intList.print();

    cout << "\nPopping value from position 4 with value: " << intList.popAtPos(4) << endl;
    intList.print();

    cout << "\nPeeking at node[2] with value: " << intList.peekAtPos(2) << endl;
    cout << "\nPeeking at node[2] using 'operator'. Value: " << intList[2] << endl;

    LinkedList<int> intList2;
    intList2 = intList;
    cout << "\nLinked List 2 : " << endl;
    intList2.print();
    cout << "\nPeeking at intList2 @node[2] using 'operator'. Value: " << intList2[2] << "\n" << endl;

    cout << intList << endl;

//    cout << "\nClear all nodes from the list: " << endl;
//    intList.clearList();
//    intList.print();

    return 0;
}
