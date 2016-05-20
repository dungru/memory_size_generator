#ifndef         _EVENT_H  
#define         _EVENT_H

#define         INVALID_TYPE    (-1)
#define         INVALID_TIME    (-1.0)

#include <iostream>
using namespace std;

#include        <stdlib.h>
#include        "mydef.h"


class Event {
 private:
        int                eventType;    /* eventType=1 for ARRIVAL,=2 for CREDIT_RESERVATION ,=3 for CREDIT_CONSUMED , =4 RANDOM_CHECK*/
        double             allocate_size;      /* event time stamp             */
        int                arrivalType ;
        Event*             next;           /* pointer to next event node   */
        static Event*      freeList;       /* pointer to free event list   */
        
 public:
        Event() { eventType=0; /* constructor  */
                  allocate_size=0;
                  arrivalType = 0 ;
                  next      = NULL;
                }
        Event(const int,const double ,const int);
                   
        void    initNode( const int,
                          const double, /* event node initialization    */
                          const int
                         ); /*  setup allocate_size,old     */
        void    insNext( Event*);       /* insert the event node next   */
                                        /*  to the current node         */
        void    delNext();              /* delete the event node next   */
                                        /*  to the current node         */
        Event*  getNext()               /* get the pointer to the next  */
                { return next; }        /*  event node                  */
        double  get_allocate_size()      /* get the allocate_size of current node*/
                { return allocate_size; }
       
        int     getEventType() {return eventType;}
        int     getArrivalType(){return arrivalType;}
        
        void  setEventType(int t) {eventType=t; }
        void  setarrivalType(int s){arrivalType=s;}    /* set arrivalType      */
        void  set_allocate_size(double t)        /* set allocate_size             */
              { allocate_size=t;}
        void  setNext(Event *E) { next=E;}
        void*   operator new(size_t);   /* new operator of class Event  */
        void    operator delete( void*, /* delete operator of class     */
                                 size_t);/* Event                       */
        friend ostream& operator<<( ostream&,   /* print the content    */
                                    Event&);    /*  of the event node   */
        ~Event() { delete next;}            
           /*        destructor                   */ 
};
                
#endif

