// FILE: airport_sim.h (part of the namespace airport_simulation)
// CLASSES PROVIDED: bool_source, averager, runway.

// CONSTRUCTOR for the bool_source class:
//   bool_source(double p = 0.5)
//     Precondition: 0 <= p <= 1.
//     Postcondition: The bool_source has been initialized so that p is the
//     approximate probability of returning true in any subsequent activation
//     of query( ).

// CONSTANT MEMBER FUNCTION for the bool_source class:
//   bool query( ) const
//     Postcondition: The return value is either true or false, with the
//     probability of a true value being approximately p (from the constructor).

// CONSTRUCTOR for the averager class:
//   averager( )
//     Postcondition: The averager has been initialized so that it
//     is ready to accept a sequence of numbers to average.

// MODIFICATION MEMBER FUNCTION for the averager class:
//   void next_number(double value)
//     Postcondition: The averager has accepted value as the next
//     number in the sequence of numbers which it is averaging.

// CONSTANT MEMBER FUNCTIONS for the averager class:
//   size_t how_many_numbers( ) const
//     Postcondition: The value returned is a count of how many
//     times next_number has been activated.

//   double average( ) const
//     Precondition: how_many_numbers > 0.
//     Postcondition: The value returned is the average of all the
//     numbers which have been given to the averager.

// CONSTRUCTOR for the runway class:
//     runway(unsigned int arrival = 60,unsigned int departure = 60 );
//     Precondition: The value of arrival is the number of seconds needed for
//     a completion of one landing cycle, and departure for one takeoff cycle
//     Postcondition: The runway has been initialized so that all
//     other member functions may be used.

// MODIFICATION MEMBER FUNCTIONS for the washer class:
//   void one_second( )
//     Postcondition: The washer has recorded (and simulated) the
//     passage of one more second of time.

//   void start_service( service_type s )
//     Precondition: The runway is not busy.
//     Postcondition: The run has started simulating either landing or takeoff
//     cycle based on the parameter given. Therefore, is_busy( ) will return
//     true until the required number of simulated seconds have occured.

// CONSTANT MEMBER FUNCTIONS for the washer class:
//   bool is_busy( ) const
//     Postcondition: Returns true if the runway is busy
//     (in a landing or takeoff cycle); otherwise returns false
//

#ifndef AIRPORT_SIM_H
#define AIRPORT_SIM_H

#include <iostream>
#include <cstdlib> // Provides std::size_t

using namespace  std;

enum Service_type {LANDING = 1, TAKEOFF = 2};

namespace airport_simulation
{
    class bool_source
    {
    public:

        bool_source(double p = 0.5); //CTOR
        bool query( ) const;         // CONSTANT function

    private:
        double probability;         // Probability of query( ) returning true
    };

    class averager
    {
    public:
        averager( );                            // CTOR

        void next_number(double value);         //MODIFICATION function

        std::size_t how_many_numbers( ) const   // CONSTANT functions
        {
            return count;
        }

        double average( ) const;

    private:
        std::size_t count;  // total number count given to the averager
        double sum;         // Sum of all the numbers given to the averager
    };

    class runway
    {
    public:

        runway(unsigned int arrival = 60,unsigned int departure = 60 );

        void one_second( );

        void start_service(Service_type );

        bool is_busy(  ) const   // const function
        {
            const bool debug = false;
            if(debug)
                cout << "is_busy(): runway_time_left: " << runway_time_left << endl;
            return ( runway_time_left > 0 );
        }

    private:

        unsigned int landing_time;  // seconds for a single landing
        unsigned int takeoff_time;  // seconds for a single takeoff

        unsigned int runway_time_left; // seconds until runway isn't busy

    };
}
#endif // AIRPORT_SIM_H
