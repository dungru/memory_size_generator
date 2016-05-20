#include        "event.h"
#include <iostream>
 using namespace std;
#define         CHUNK           (30)    /* number of event nodes per    */
                                        /*  system allocation           */
Event* Event::freeList = NULL;          /* initial free list to empty   */
        
Event::Event(const int t,const double size1 , const int s) {
        allocate_size=size1;
        eventType=t;
        arrivalType = s ;
        next = NULL;               /* next pointer is null         */
}        
        
void Event::initNode( const int Etype,const double size1,const int s){
        eventType=Etype;
        allocate_size    = size1;           /* setup node allocate_size */
        arrivalType = s ;
        next         =NULL ;             /* next piointer is null         */

}

void Event::insNext( Event *nextNode) {

	if(nextNode != NULL) {
                 next = nextNode;     
        }
        else next=NULL; 
}

void Event::delNext() {
        Event   *ptr;
        
        if ( (ptr = next) != NULL) {    /* if next is NULL, do nothing  */
            next = next->next;          /* next pointer points to the   */
                                        /*  next next event node        */
            delete ptr;                 /* delete the next event node   */
        }
}
ostream& operator<<( ostream& os, Event& node) {
        return os << "allocate_size: "<< node.allocate_size
                  <<"  EventType: "<<node.eventType
                  << "\n";
}
 
void* Event::operator new(size_t size) {
 register Event* ptr;
        
        if (freeList == NULL) {         /* is the free list empty?      */
            freeList  = ptr             /* yes, allocate CHUNK of node  */
                      = (Event*) new char[CHUNK * size];
            while (ptr != &freeList[CHUNK-1]) { /* while the last node  */
                                                /*  does not reach      */
                ptr->next = ptr + 1;    /* setup the next pointer       */
                ++ptr;                  /* skip to the next node        */
            }
            ptr->next = NULL;           /* set the next pointer of the  */
                                        /*  last node to NULL           */
        }
        ptr      = freeList;            /* get 1st node from free list  */
        freeList = freeList->next;      /* free list start from 2nd node*/
        ptr->next = NULL;               /* Changed By Lin Phone */
        return(ptr);
}
 
void Event::operator delete( void* ptr, size_t size) {
        ((Event*) ptr)->next = freeList;
        freeList = (Event*) ptr;
}
            

