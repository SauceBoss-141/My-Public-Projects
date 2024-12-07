#ifndef list342_H_
#define list342_H_
#include <iostream>
#include <fstream> 
using namespace std;
/*
Templated Linked List class 
Can store objects of 1 type
*/
template<class T>
class List342{
    public:
    List342();
    List342(const List342<T>&other);
    ~List342();
    bool BuildList(const string file_name);
    bool Insert( T* obj);
    bool Remove(const T target, T& result);
    bool Peek(const T target,  T& result)const ;
    int Size()const;
    void DeleteList();
    bool Merge(List342& list1);
    List342<T> operator+(const List342 &other)const;
    List342<T> &operator+=(const List342 &other);
    template<typename U>
    friend ostream& operator<<(ostream& stream, const List342<U>& list);
    bool operator==(const List342& other)const;
    bool operator!=(const List342& other)const;
    List342& operator=(const List342& source);
    private:
    struct Node{
    T *data_= nullptr;
    Node *next_ = nullptr;
    };
    int size_ ;
    Node *head_;
};
template <class T>
List342<T>::List342()
{
   this-> size_ =0;
   this->head_ = nullptr;
}
template<class T>
List342<T>::List342(const List342<T>&other){
    this-> size_ =0;
   this->head_ = nullptr;
    *this = other;
}
/*
Deconstructor 
Deletes all dynamic memory associated with the list.
*/
template<class T>
List342<T>::~List342(){
   DeleteList();
}
template <class T>
bool List342<T>::BuildList(const string file_name)
{   ifstream ifs;
    ifs.open(file_name);
    if(!ifs.is_open()){
        ifs.close();
        return false;
    }
    T obj;
    while(ifs>>obj){
        Insert(&obj);
    }
    ifs.close();
    return true;
}
/*
Inserts data into list into acending order
*/
template <class T>
bool List342<T>::Insert(T *obj)
{   if(obj == nullptr){
    return false;
    }
    if(head_ == nullptr){
        head_ = new Node();
        head_->data_ = new T(*obj);
        size_++;
        return true;
    }else if(*(head_->data_) >= *(obj)){
      if(*obj == *(head_->data_)){
        return false;
      }
      Node *temp = new Node();
      temp->data_ =new T(*obj);
      temp->next_ = head_;
      head_ = temp;
      size_++;
      return true;
    }else{
        Node *temp = head_;
        while((temp->next_ != nullptr) && (*(temp->next_->data_) < *obj)){
            temp = temp ->next_;
        }
        if(temp->next_ != nullptr){
            if(*obj == *(temp->next_->data_)){
            return false;
        }
            Node *insertMe= new Node();
            insertMe->data_ = new T(*obj);
            insertMe->next_= temp->next_;
            temp->next_ = insertMe;
            size_++;
            return true;
        }else{
            Node *insertMe = new Node();
            insertMe->data_= new T(*obj);
            temp->next_ = insertMe;
            size_++;
            return true;
        }
    }
    return false;
}
template <class T>
bool List342<T>::Remove(T target, T &result)
{  
    if(head_ == nullptr) return false;
    Node *temp = head_;
    if (*(temp->data_) == target){
        result = *(temp->data_);
        delete(head_->data_);
        Node *temptemp = temp->next_;
        delete(head_);
        head_ = temptemp;
        size_--;
        return true;
    }else{

        while(temp->next_ != nullptr){
            if(*(temp->next_->data_) == target){
                result = *(temp->next_->data_);
                delete(temp->next_->data_);
                Node *temptemp = temp->next_->next_;
                delete(temp->next_);
                temp->next_ = temptemp;
                size_--;
                return true;
            }else{
                temp = temp->next_;
            }
        }
    }
    return false;
}
template <class T>
bool List342<T>::Peek( T target,  T &result) const
{    Node *temp = head_;
    if (*(temp->data_) == target){
        result =  T(*temp->data_);
        return true;
    }else{
        while(temp->next_ != nullptr){
            if(*(temp->next_->data_) == target){
                result = T(*(temp->next_->data_));
                return true;
            }else{
                temp = temp->next_;
            }
        }
    }
    return false;
}
template <class T>
int List342<T>::Size() const
{
    return this->size_;
}
/*
Delete slist entirely
deletes the object stored as well
*/
template <class T>
void List342<T>::DeleteList()
{
    while(head_!= nullptr){
        delete head_->data_;
        Node *temp = head_->next_;
        delete(head_);
        head_ = temp;  
    } 
    size_=0; 
}
template <class T>
bool List342<T>::Merge(List342 &list1)
{   
    if(*this== list1){
        return false;
    }
    Node *buffer = new Node();
    buffer->next_= head_;
    Node *current = buffer;
    while(current->next_ != nullptr){
            while(list1.head_ != nullptr && *(current->next_->data_)>(*(list1.head_->data_) )){
                   //Node *temp = new Node();
                   //temp->data_ = new T(*other_current->data_);
                   Node*temp =list1.head_;
                   list1.head_=temp->next_;
                   temp->next_=current->next_;
                   current->next_ = temp;
                   size_++;
                   list1.size_--;
            }
            while(list1.head_ != nullptr && *(current->next_->data_)==(*(list1.head_->data_))){
                Node *temp = list1.head_->next_;
                delete list1.head_->data_;
                delete list1.head_;
               list1.head_ = temp;
               list1.size_--;
            }
            current = current ->next_;
    }
    current->next_=list1.head_;
    list1.head_=nullptr;
    this-> head_=buffer->next_;
    size_+=list1.size_;
    list1.size_ = 0;
    delete buffer;
    return true;
}
template <class T>
List342<T> List342<T>::operator+(const List342 &other)const
{   List342<T> temp;
    temp = *this;
    temp+= other;
    return temp;
}
template <class T>
List342<T> &List342<T>::operator+=(const List342 &other)
{   Node *buffer = new Node();
    buffer->next_= head_;
    Node *current = buffer;
    Node *other_current = other.head_;
    while(current->next_ != nullptr){
            while(other_current != nullptr && *(current->next_->data_)>(*(other_current->data_) )){
                   Node *temp = new Node();
                   temp->data_ = new T(*other_current->data_);
                   temp->next_=current->next_;
                   current->next_ = temp; 
                   current = current->next_;
                   other_current = other_current->next_;
                   size_++;
            }
            while(other_current != nullptr && *(current->next_->data_)==(*(other_current->data_))){
                other_current = other_current->next_;
            }
            current = current ->next_;       
    }
    while(other_current != nullptr){
            Node * temp = new Node();
            temp->data_ = new T(*other_current->data_);
            temp->next_ = current->next_;
            current->next_ = temp;
            current = current->next_;
            other_current = other_current->next_;
            size_++;
    }
    this-> head_=buffer->next_;
    delete buffer;
    return *this;
}
template <class T>
bool List342<T>::operator==(const List342<T> &other) const
{   if(size_ != other.size_){
    return false;
    }
    Node *current = head_;
    Node *other_current=head_;
    while(current != nullptr){
        if((*(current->data_))!=(*(other_current->data_))){
            return false;
        }else{
            current = current->next_;
            other_current = other_current ->next_;
        }
    }

    return  true;
}
template <class T>
bool List342<T>::operator!=(const List342 &other) const
{
    return not(*this == other);
}
/*
Assignmnet operator
Creates deep copy
*/
template <class T>
List342<T> &List342<T>::operator=(const List342<T> &source)
{
    if(*this == source){
        return *this;
    }
    DeleteList();
    if(source.head_ == nullptr){
        return *this;
    }
    Node *d_node = new Node;
    d_node->data_ = new T(*((source.head_)->data_));
    head_=d_node;
    size_++;
    Node * s_node =(source.head_)->next_;
    while(s_node != nullptr){
        d_node->next_ = new Node;
        d_node = d_node->next_;
        d_node->data_ = new T(*(s_node->data_));
        s_node = s_node->next_;
        size_++;
    }
    return *this;
}
template <class U>
ostream &operator<<(ostream &stream, const List342<U> &list)
{   
    auto temp = list.head_;
    while(temp!= nullptr){
        stream << *(temp->data_);
        temp = temp->next_;
    }
    return stream;
}
#endif