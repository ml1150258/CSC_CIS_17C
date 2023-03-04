/* 
 * File:   LinkedList.h
 * Author: Dr. Mark E. Lehr
 *      Purpose:  Implementation of the previous linked list functions
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

template<class T>
class LinkedList{
    private:
        struct Link{
            T data;         //Mainly for Objects
            Link *linkPtr;  //Self Reference which when utilized forms a linked list
        };
        Link *front,*next,*temp,*found;
        fndLst(const T&);  //Determine address of link that contains the data
    public:
        LinkedList(const T&);
        ~LinkedList();
        void prntLst();          //Print each data element in the list
        void  addLst(const T&);  //Add data at the end of the list
        int  findLst(const T&);  //Determine what link contains the data
        int   cntLst();          //How many elements are in the list
        T     getObj(int);       //Return the object
        T    &getPtr(int);       //Return the pointer to the object
};

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
template<class T>
LinkedList<T>::LinkedList(const T &data){
    //Think of this part as the constructor
    front=new Link;      //Allocate a link at the front of the list
    front->data=data;    //Initialize with data
    front->linkPtr=NULL; //At the moment not pointing it to anything
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Print the entire contents of the linked list
//Input -> front  The address to the front of the allocated list.
//Output-> Display the entire linked list.
template<class T>
void LinkedList<T>::prntLst(){
    next=front;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Deallocate the entire list from the front to the end.
//Input -> front  The address to the front of the allocated list.
//Output-> Deallocate and return a NULL for the linked list pointer.
template<class T>
LinkedList<T>::~LinkedList(){
    do{
       temp=front->linkPtr;   //Point to the next link in the list
       delete front;          //Delete the front of the list
       front=temp;            //Swap the front
    }while(front!=NULL);
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Add a link and data to the end of the list
//Input -> front  The address to the front of the allocated list.
//         data   Data to embed at the last link in the list
template<class T>
void LinkedList<T>::addLst(const T &data){
    //Go to the end of the list
    Link *end;
    temp=front; //Declare pointers used to step through the list
    do{
        end=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    //Now add to the end of the list
    Link *add=new Link;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    end->linkPtr=add;         //Point to the new end of the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<Object> number from the front where the data is found
template<class T>
int LinkedList<T>::findLst(const T &value){
    int n=0;                //Initialize the counter
    temp=front;             //Prepare to traverse the Link<Object>ed list
    do{
        n++;                //Increment the counter
        if(temp->data==value)return n;//Return where the data is found
        temp=temp->linkPtr; //Move to the next link
    }while(temp!=NULL);     //End when reaching the end of the linked list
    return 0;               //Not found then return a 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link<Object> address from the front where the data is found
template<class T>
LinkedList<T>::fndLst(const T &value){
    found=front;       //Set the cursor to move through the list
    do{
        if(found->data==value)return found;  //Address of data match
        found=found->linkPtr;                //Next link in the list
    }while(found!=NULL);                    //End of the list
    found=NULL;                           //Not found
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
template<class T>
int LinkedList<T>::cntLst(){
    int n=0;            //Initialize the counter
    temp=front;   //Set the cursor to the front
    do{
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }while(temp!=NULL); //Loop until the end is reached
    return n;           //Return the counter value
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
template<class T>
T LinkedList<T>::getObj(int indx){
    int n=0;                      //Initialize the counter
    temp=front;                   //Set the cursor to the front
    do{
        if(n==indx)return temp->data;
        n++;                      //Increment the counter
        temp=temp->linkPtr;       //Move to the next link
    }while(temp!=NULL);           //Loop until the end is reached
    return front->data;           //Return the counter value
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
template<class T>
T &LinkedList<T>::getPtr(int indx){
    int n=0;                      //Initialize the counter
    temp=front;                   //Set the cursor to the front
    do{
        if(n==indx)return temp->data;
        n++;                      //Increment the counter
        temp=temp->linkPtr;       //Move to the next link
    }while(temp!=NULL);           //Loop until the end is reached
    return front->data;           //Return the counter value
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890


#endif	/* LINKEDLIST_H */