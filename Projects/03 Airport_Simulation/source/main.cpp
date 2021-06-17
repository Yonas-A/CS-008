/*
 * Author: Yonas Adamu
 * Project: Airport simulation (landing and takeoff)
 * Purpose: using the concepts and algorithm of the car wash simulation
 *          write an airport simulation with landing given a priority over
 *          takeoff when processing on the runway
 *          project uses queue class that was made using a doubly linked
 *          list
 *
 */

#include <iostream>
#include <time.h>
#include <stdlib.h> // Provides EXIT_SUCCESS
#include "../../../Projects/!includes/Queue/queue.h"
#include "../Airport_Simulation/Airport_Sim/airport_sim.h"

using namespace std;
using namespace  airport_simulation;


const double takeoff_probability = 0.8;
const double landing_probability = 0.10;

const unsigned int time_to_land = 5;
const unsigned int time_to_take_off = 10;

const unsigned int fuel_limit = 15;
const unsigned int simulation_time = 100000;


void airport_sim( );
//Precondition:

void print_input();
//prints all the input conditions like takeoff_time, fuel_limit...

void print_output(averager &landing, averager &takeoff,
                  const unsigned int crashed_planes );
//prints all the outcome of the simulation


int main( )
{
    srand(time(nullptr));

    airport_sim( );

    return EXIT_SUCCESS;
}

void airport_sim( )
{
    /*const*/ bool debug = true;

    Queue <unsigned int> Landing_Q;   // Waiting planes queue for landing
    Queue <unsigned int> Takeoff_Q;   // waiting planes queue for takeoff

    unsigned int landing_next;       // A value taken from the queue
    unsigned int takeoff_next;       // A value taken from the queue

    bool_source Landing_bool ( landing_probability );
    bool_source Takeoff_bool ( takeoff_probability );

    unsigned int crash_counter = 0;

    averager Landing_averager;    // averager for the landing planes
    averager Takeoff_averager;    // averager for the takeoff planes

    runway Runway_ONE ( time_to_land, time_to_take_off);
    runway Runway_TWO ( time_to_land, time_to_take_off);

    unsigned int current_time;

    for (current_time  = 1; current_time <= simulation_time; ++current_time)
    {
        // Check whether a new plane has arrived.
        if( Landing_bool.query ( ) )
        {
            Landing_Q.Push(current_time);
        }

        // Check whether a new plane is ready for takeoff
        if( Takeoff_bool.query( ))
        {
            Takeoff_Q.Push( current_time);
        }

        if( ! Runway_ONE.is_busy( ) || ! Runway_TWO.is_busy())
        {
            debug = false;
            if(debug)
                cout << "Runway_ONE not busy" << endl;
            if ( ! Landing_Q.Empty( ))
            {
                if (current_time - Landing_Q.Front() > fuel_limit)
                {
                    debug = false;
                    if(debug)
                        cout << "NOT ENOUGH FUEL :  "
                             << current_time - Landing_Q.Front();
                    ++crash_counter;
                    Landing_Q.Pop();
                }

                else// ( current_time - Landing_Q.Front() <= fuel_limit )
                {
                    debug = false;
                    if(debug)
                        cout << "ENOUGH FUEL FOR LANDING: " <<
                                current_time - Landing_Q.Front() << endl;
                    landing_next = Landing_Q.Front( );
                    Landing_Q.Pop( );
                    Landing_averager.next_number(current_time - landing_next);
                    if(! Runway_ONE.is_busy())
                    Runway_ONE.start_service( LANDING );
                    else if(! Runway_TWO.is_busy())
                        Runway_TWO.start_service( LANDING);
//                    Runway_ONE.start_service( LANDING );
                }
            }

            else if( Landing_Q.Empty() && !Takeoff_Q.Empty())
            {
                debug = false;
                if(debug)
                    cout << "Takeoff preperation" << endl;
                takeoff_next = Takeoff_Q.Front();
                Takeoff_Q.Pop( );
                Takeoff_averager.next_number( current_time - takeoff_next);

                if(debug)
                {
                    cout << current_time -takeoff_next
                         << " Takeoff average" << endl;
                    cout << current_time  << "  "
                         << takeoff_next  << endl;
                }
                if(! Runway_ONE.is_busy())
                Runway_ONE.start_service( TAKEOFF );
                else if(! Runway_TWO.is_busy())
                    Runway_TWO.start_service( TAKEOFF);
            }
        }

        Runway_ONE.one_second();
        Runway_TWO.one_second();
    }



    {
    print_input() ;
    print_output(Landing_averager, Takeoff_averager, crash_counter );

    cout << "Planes in landing queue: "  << Landing_Q.Size() << endl;
    cout << "Planes in takeoff queue: " << Takeoff_Q.Size() <<  endl;
    }

}

void print_input()
{
    cout << "\t= = = =    INPUTS    = = = = " << endl <<  endl;
    cout << "Time to take off       : " << time_to_take_off << endl;
    cout << "Time to land           : " << time_to_land << endl;

    cout << "Probability of landing : " << landing_probability << endl;
    cout << "Probability of takeoff : " << takeoff_probability << endl;

    cout << "Fuel: time to crash    : " << fuel_limit << endl;
    cout << "Total simulation time  : " << simulation_time << endl;
}

void print_output( averager& L, averager& T,const unsigned int c_planes)
{
    cout << endl << "\t= = = =    OUTPUTS    = = = = " << endl <<  endl;

    cout << "Planes that landed     : " << L.how_many_numbers()  << endl;
    cout << "Planes that took off   : " << T.how_many_numbers() << endl;
    cout << "Planes that crashed    : " << c_planes << endl;


    if (L.how_many_numbers( ) > 0)
        cout << "Average waiting time to land     : " << L.average() <<  endl;

    if( T.how_many_numbers() > 0)
        cout  << "Average waiting time to take off: " << T.average() << endl;
}
