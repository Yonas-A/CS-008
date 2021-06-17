// CLASSES implemented: bool_source, averager, runway

// INVARIANT for the bool_source ADT:
//   1. The member variable probability is the appoximate probability that
//      query( ) returns true.

// INVARIANT for the averager ADT:
//   1. The member variable count indicates how many numbers the averager has
//      been given.
//   2. The member variable sum is the sum of all the numbers that the
//      averager has been given.

// INVARIANT for the runway class:
//   1. The member variable landing_time is the time required for a plane
//      to land and takeoff_time is the time for a plane to takeoff
//   2. The member varible runway_time_left is 0 if the runway is not busy;
//      otherwise it is the number of seconds until the runway is free.

#include "../Airport_Simulation/Airport_Sim/airport_sim.h"
#include <iostream>
#include <assert.h>    // Provides assert
#include <stdlib.h>    // Provides rand, RAND_MAX, size_t

using namespace  std;

namespace  airport_simulation
{

    bool_source::bool_source(double p)  //uses: assert.h
    {
        assert( p >= 0);
        assert( p <= 1);
        probability = p;
    }

    bool bool_source::query( ) const    // uses stdlib.n
    {
        return (rand( ) < probability * RAND_MAX);
    }

    averager::averager( )
    {
        count = 0;
        sum = 0;
    }

    void averager::next_number(double value)
    {
        ++count;
        sum += value;
    }

    double averager::average( ) const   //uses assert.h
    {
        assert( how_many_numbers( ) > 0);
        return sum/count;
    }

    runway::runway(unsigned int arrival,unsigned int departure )
    {
        landing_time = arrival;
        takeoff_time = departure;

        runway_time_left = 0;
    }

    void runway::one_second()
    {
        const bool debug = false;
        if(debug)
            cout << "o_s(): Runway_time_left 1: " << runway_time_left << endl;

        if( is_busy( ))
        {
            --runway_time_left;
            if(debug)
                cout << "o_s(): busy Runway_time_left 2: " << runway_time_left << endl;
        }
    }

    void runway::start_service( Service_type s_type)
    {
        bool debug = false;

        if(debug)
            cout << "start_service( ): " ;

        assert( ! is_busy( ) );

        if( s_type ==  LANDING )
        {
            runway_time_left = landing_time;
            if(debug)
                cout << "Landing:  " << landing_time << endl;
        }

        else //if (s_type == TAKEOFF )
        {
            runway_time_left = takeoff_time;
            if(debug)
                cout << "Takeoff:  " << takeoff_time << endl;
        }

    }

}

