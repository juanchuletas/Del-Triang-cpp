#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include<iostream>
template<class T> class LinkedList{
    protected: //Protected because inheritaded classes must acces to data members of LList
        T item;
        LinkedList *next; //Pointing to the next node in the list
    public:
        //Default Constructor
        LinkedList();
        LinkedList(T&);
        LinkedList(T&, LinkedList*);
        //Copy Constructor
        LinkedList(const LinkedList&);
        //Member function operator
        const T& operator()() const;
        //Methods
        const LinkedList* readNext() const;
        LinkedList& last();
        int length() const;
        int search(Vertex<T> &);
        void append(T&);
        void insertNextItem(T&);
        void insertFirstItem(T&);
        void dropNextItem();
        void dropFirstItem();
        void dropSelectedItem(T&);
        //void print(const LinkedList&);
        //Assignment operator
        const LinkedList& operator=(const LinkedList&);
        //Destructor
        ~LinkedList();
        T& getItem(){
            return item;
        //Indeed, with this operator, the user can write "list[]" to obtain a constan reference to the 
        //first item in the linked list "list"
        }
};

//Default Constructor
template<class T>
LinkedList<T>::LinkedList()
    :next{0}{
        // With this constructor the user can write commands like:
        // LinkedList<double> list; to create an empty list
    }
//Another Constructor
template<class T>
LinkedList<T>::LinkedList(T& item_in)
    :item{item_in}{
            next = 0;
        //We define a more meaningful constructor that takes two arguments
        // type T to specify the first item, and a pointer -to-linked-list to define the 
        // rest ofthe constructed list
        //In particular, when the second argument in this constructor is missing
        // it is assumed to be zero  (meaningless) pointer

        //This way the user can write commands like:
        // LinkedList <double> list(1.0) to construct a "list" with only de item with value 1
    }
    template<class T>
    LinkedList<T>::LinkedList(T& item_in, LinkedList* N)
            :item{item_in},next{N}{

            }    
    //Copy Constructor: 
    //The recursive pattern of the linked list is particulary useful in the copy constructor defined below
    // One only needs to copy the first item in the linked list(Using the copy contructor of the T class) and to 
    // use recursion to copy the tail
    template<class T>
    LinkedList<T>::LinkedList(const LinkedList& list)
        :item{list()},next{list.next ? new LinkedList(*list.next):0}{
            //WHAT THE FUCK WAS THAT!!!????
            // in other way, the code: next{list.next ? new LinkedList(*list.next):0}
            //Can be written in this way:
            /*if(list.next){
                next = new LinkedList(*list.next):
            }
            else
            {
                next = 0;
            }*/
            /* In fact, everything is done in the initialization list: first, the first item in ’l’,
            ”l()”, is copied into ”item”, the first item in the constructed list. Then, the
            tail of ’l’, pointed at by ”l.next”, is copied recursively into a new tail, whose
            address is stored in ”next”. This completes the copying of the entire linked
            list ’l’ into a new linked list, as required.*/

        }
   
    //The first item in the linked list can be read(although not changed) and used in the definitios of
    // ordinary (nonmember, nonfriend) functions through the public member function "operator()"
    template<class T>
    const T& LinkedList<T>::operator()() const{
        return item;
        //Indeed, with this operator, the user can write "list()" to obtain a constan reference to the 
        //first item in the linked list "list"
    }
    
    //The rest of the linked list can be read (although not changed) through the following public function
    template<class T>
    const LinkedList<T> *
    LinkedList<T>::readNext() const{
        return next;
        //Indeed, with this function the user can write "list.readNext()" to have the address of the linked list that 
        //contains the tail of "list"
    }
    //Return last item;
    template<class T>
    LinkedList<T>&
    LinkedList<T>::last(){
        return next ? next->last() : *this;
        /*The code above can be expressed as
        if(next){
            return next->last()
        }
        else{
            return *this;
        }
        */
    }
    //Lenght of the list
    template<class T>
    int LinkedList<T>::length() const{
        return next ? next->length() + 1 : 1;
        /*
            if(next){
                return next->length() + 1;
            }
            else{
                return 1;
            }
        */
    }
    //Append a new item at the end of the list
    template<class T>
    void LinkedList<T>::append(T& input_item){
        last().next = new LinkedList(input_item);
    }
    //Inserting new items
    template<class T>
    void LinkedList<T>::insertNextItem(T& new_item)
    {
        next = new LinkedList(new_item,next);
    }
    //Insert at first
    template<class T>
    void LinkedList<T>::insertFirstItem(T& new_item)
    {
        next = new LinkedList(item,next);
        item = new_item;
        
    }
    //Drop next item
    template<class T>
    void LinkedList<T>::dropNextItem()
    {
        if(next){
            if(next->next)
            {
                LinkedList<T>*aux = next;
                next = next->next;
                aux->item.~T();
            }
            else{
                delete next;
                next = 0;
            }
        }
        else{
            std::cout<<"Error: cannot drop nonexisting next item"<<std::endl;
        }
    }
    //Drop First Item
    template<class T>
    void LinkedList<T>::dropFirstItem()
    {
        //If there is a second item in the linkedlist
        if(next)
        {
            //A duplicate copy of it is stored in the first item in the current list
            item = next->item;
            //Then the "dropNextItem()" in invoked to drop the second duplicate copy
            dropNextItem();
        }
        else
        {
            std::cout<<"Error: cannot drop the only item\n";
        }
    }
    template<class T>
    void LinkedList<T>::dropSelectedItem(T& target){
        printf("DROP METHOD\n");
        int count = 1;
        if(this->item==target){
            printf("Match the %d item\n",count);
            dropFirstItem();
        }
        else{
            while(next!=0){
                count++;
                if(next->item==target){
                    printf("BITCH is the %d item \n",count);
                    dropNextItem();
                }
                next = next->next;
            }
        }
    }
    //Assignment operator
    template<class T>
    const LinkedList<T>&
    LinkedList<T>::operator=(const LinkedList<T>&list)
    {
        if(this!=&list)
        {
            item = list();
            if(next){
                if(list.next)
               {
                   *next = *list.next;
               }
               else
               {
                   delete next;
                   next = 0;
               }

            }
            else{
                if(list.next){next = new LinkedList(*list);}
            }
        }
        return *this;
    }
    //Print the list
    template<class T>
    void print(const LinkedList<T>&list)
    {
        std::cout<<"Item: "<<std::endl;
        print(list());
        if(list.readNext())
            print(*list.readNext());
    }
     //The Destructor-----
    template<class T>
    LinkedList<T>::~LinkedList(){
        std::cout<<"Destructor Called"<<std::endl;
        delete next;
        next = 0;
        /*The recursive structure of the linked list is also useful in the destructor.
        Indeed, once the pointer ”next” is deleted, the destructor is invoked automat-
        ically to destroy recursively the entire tail. Then, the destructor of the ’T’
        class is invoked implicitly to destroy the first item, ”item”, as well:*/
    }
    //-----
    #endif