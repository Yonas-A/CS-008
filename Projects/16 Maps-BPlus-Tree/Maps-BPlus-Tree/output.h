#ifndef MAP_N_MULTIMAP_OUTPUT_H
#define MAP_N_MULTIMAP_OUTPUT_H


/*
 Last login: Tue May 26 23:36:24 on ttys000
 yonas@Yonas-MBP ~ % source /var/folders/bm/_2024b_x6z1c4jyzshs0j6xr0000gn/T/tmpSrLPTb
    =   =   = pair struct test =   =   =   =
    =   =   =   FINAL TREE    =   =   =   =
     [May | 30]
     [Mar | 31]
 [Mar | 31]
     [Jun | 30]
     [Jan | 31]
 [Jan | 31]
     [Feb | 28]
     [Apr | 31]


    =   =   = EXITING pair test =   =   =   =

    =   =   = current tree  =   =   =   =
 [Betty | Blue]


    =   =   = current tree  =   =   =   =
 [Jack | Yellow]
 [Betty | Blue]


    =   =   = current tree  =   =   =   =
     [Tom | Red]
     [Jack | Yellow]
 [Jack | Yellow]
     [Betty | Blue]


    =   =   = current tree  =   =   =   =
     [Tom | Red]
     [Li | Black]
 [Li | Black]
     [Jack | Yellow]
 [Jack | Yellow]
     [Betty | Blue]


    =   =   = current tree  =   =   =   =
     [Tom | Red]
     [Li | Black]
 [Li | Black]
     [Joe | Violet]
     [Jack | Yellow]
 [Jack | Yellow]
     [Betty | Blue]


    =   =   = current tree  =   =   =   =
     [Tom | Red]
     [Li | Black]
 [Li | Black]
     [Joe | Violet]
     [Jack | Yellow]
 [Jack | Yellow]
     [Betty | Blue]
     [Beth | Purple]


    =   =   = current tree  =   =   =   =
         [Tom | Red]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Yellow]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


 testing + operator for pair in case of duplicates

    =   =   = current tree  =   =   =   =
         [Tom | Red]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


    =   =   =   FINAL TREE    =   =   =   =
         [Tom | Red]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


 m [ PAUL ] =  Red

         [Tom | Red]
         [PAUL | Red]
     [PAUL | ]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


 Red   calling PALU WITH operator []
         [Tom | Red]
         [PAUL | Red]
     [PAUL | ]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


 chainging [ PAUL ] =  Red to Sapphire

         [Tom | Red]
         [PAUL | Sapphire]
     [PAUL | ]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Joe | Violet]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]


 erase Joe

         [Tom | Red]
         [PAUL | Sapphire]
     [PAUL | ]
         [Lily | Pink]
     [Lily | Pink]
         [Li | Black]
 [Li | Black]
         [Jack | Burgundy]
     [Jack | Yellow]
         [Betty | Blue]
         [Beth | Purple]



    =   = EXITING simple map test =   =   =

 =   =   =  map accessors test =   =   =   =

    =   =   =   Map    =   =   =   =
     [May | 30]
     [Mar | 31]
 [Mar | 31]
     [Jun | 30]
     [Jan | 31]
 [Jan | 31]
     [Feb | 28]
     [Apr | 31]


 m [ jan ] = 21
         [jan | 21]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 31]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]


 m[ Jan ]: 31
 m.at(Jan): 31
         [jan | 21]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 31]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]


 m.at(feb):  = 29
         [jan | 21]
         [feb | 29]
     [feb | 0]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 31]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]


 m[ Jan ]: 1101
    =   =   =   =    Final Tree =   =   =   =   =
         [jan | 21]
         [feb | 29]
     [feb | 0]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 1101]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]


 =  =  = EXITING map accessors test =  =  =

 =   =   =  map iterators test =   =   =   =

    =   =   =   Map    =   =   =   =

     [May | 30]
     [Mar | 31]
 [Mar | 31]
     [Jun | 30]
     [Jan | 31]
 [Jan | 31]
     [Feb | 28]
     [Apr | 31]


 Map Iterators print
 [Apr | 31]->[Feb | 28]->[Jan | 31]->[Jun | 30]->[Mar | 31]->[May | 30]->|||

 =   =   = EXITING map iterators test =   =   =   =

 =   =   =  map modifiers test =   =   =   =

 m.get( September ) 0
         [Septemeber | 0]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 31]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]



 m.erase ( July )
         [Septemeber | 0]
         [May | 30]
     [May | 30]
         [Mar | 31]
 [Mar | 31]
         [Jun | 30]
         [Jan | 31]
     [Jan | 31]
         [Feb | 28]
         [Apr | 31]



 m.clear( )
    =   =   =   Map    =   =   =   =



 =   =   = EXITING map modifiers test =   =   =   =

 =   =   =  map operations test =   =   =   =


 =   =   =   = Map =   =   =   =   =

     [May | 30]
     [Mar | 31]
 [Mar | 31]
     [Jun | 30]
     [Jan | 31]
 [Jan | 31]
     [Feb | 28]
     [Apr | 31]



 m.find( Apr ):  Apr | 31
 m.find( Jun ):  Jun | 30
 m.contains( (Jun, 30 )     contains true

 =   =   = EXITING map operations test =   =   =   =

 Press <RETURN> to close this window...

 // =============================================================================================
 // =============================================================================================
 // =============================================================================================
 // =============================================================================================
 
 //             M  U   L   T   I   M   A   P       O   U   T   P   U   T
 
 // =============================================================================================
 // =============================================================================================
 // =============================================================================================
 // =============================================================================================
 
 

 Last login: Tue May 26 23:36:39 on ttys001
 yonas@Yonas-MBP ~ % source /var/folders/bm/_2024b_x6z1c4jyzshs0j6xr0000gn/T/tmpX4NHmv
 =   =   =  multi pair struct test =   =   =   =


 =   =   =   = Tree =   =   =   =   =

     [Math | 90  89  93  22  34  32  ]
     [Chem | 190  809  93  56  ]
 [Chem | 190  809  93  56  ]
     [CS | 90  89  93  56  ]
 [CS | 90  89  93  56  ]
     [Bio | 31  28  31  31  30  ]
     [Art | 10  34  89  ]



 =   =   =  EXITING multi pair test =   =  =

 =   =   = simple multimap test =   =   =   =


    =   =   =   TREE    =   =   =   =
     [Tom | Job: Officer  color: Green  Sport: Sprint    ]
     [Li | Job: CEO  color: Yellow  Sport: Golf    ]
 [Li | Job: CEO  color: Yellow  Sport: Golf    ]
     [Joe | Job: BIOLOGIST  color: Black  Sport: diving    ]
     [Jack | Job: Pilot  color: Blue  Sport: Bowling    ]
 [Jack | Job: Pilot  color: Blue  Sport: Bowling    ]
     [Betty | Job: Pilot  color: Blue  Sport: Bowling    ]
     [Beth | Job: President  color: Pink  Sport: Soccer    ]


 inserting Jack with a different discription
 Jack: Job: Officer  color: Green  Sport: Sprint

    =   =   =   TREE    =   =   =   =
     [Tom | Job: Officer  color: Green  Sport: Sprint    ]
     [Li | Job: CEO  color: Yellow  Sport: Golf    ]
 [Li | Job: CEO  color: Yellow  Sport: Golf    ]
     [Joe | Job: BIOLOGIST  color: Black  Sport: diving    ]
     [Jack | Job: Officer  color: Green  Sport: Sprint    ]
 [Jack | Job: Pilot  color: Blue  Sport: Bowling    ]
     [Betty | Job: Pilot  color: Blue  Sport: Bowling    ]
     [Beth | Job: President  color: Pink  Sport: Soccer    ]


 =   =   = EXITING simple multimap test =   =   =   =

 =   =   =  multimap accessors test =   =   =   =

 [Math | 90  89  93  22  34  32    ]




 =   =   =   = Final MMap =   =   =   =   =

     [Math | 90  89  93  22  34  32    ]
     [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
     [CS | 90  89  93  56    ]
 [CS | 90  89  93  56    ]
     [Bio | 31  28  31  31  30    ]
     [Art | 10  34  89    ]




     [Math | 90  89  93  22  34  32    ]
     [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
     [CS | 90  89  93  56    ]
 [CS | 90  89  93  56    ]
     [Bio | 31  28  31  31  30    ]
     [Art | 10  34  89    ]



 m[history]:

         [Math | 90  89  93  22  34  32    ]
         [History | ]
     [History | ]
         [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
         [CS | 90  89  93  56    ]
     [CS | 90  89  93  56    ]
         [Bio | 31  28  31  31  30    ]
         [Art | 10  34  89    ]



 =  =  = EXITING multimap accessors test =  =  =

 =   =   =  multimap iterators test =   =   =   =

    =   =   =   MULTIMAP =   =   =   =

     [Math | 90  89  93  22  34  32    ]
     [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
     [CS | 90  89  93  56    ]
 [CS | 90  89  93  56    ]
     [Bio | 31  28  31  31  30    ]
     [Art | 10  34  89    ]



 Multimap Iterators print Map print

 [Art | 10  34  89    ]->[Bio | 31  28  31  31  30    ]->[CS | 90  89  93  56    ]->[Chem | 190  809  93  56    ]->[Math | 90  89  93  22  34  32    ]->|||

 =   =   = EXITING  multimap iterators test =   =   =   =

 =   =   =  multimap modifiers test =   =   =   =


 =   =   =   = Final MMap =   =   =   =   =

     [Math | 90  89  93  22  34  32    ]
     [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
     [CS | 90  89  93  56    ]
 [CS | 90  89  93  56    ]
     [Bio | 31  28  31  31  30    ]
     [Art | 10  34  89    ]



 get( History ):
         [Math | 90  89  93  22  34  32    ]
         [History | ]
     [History | ]
         [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
         [CS | 90  89  93  56    ]
     [CS | 90  89  93  56    ]
         [Bio | 31  28  31  31  30    ]
         [Art | 10  34  89    ]



 m.erase ( Math )
         [History | ]
     [History | ]
         [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
         [CS | 90  89  93  56    ]
     [CS | 90  89  93  56    ]
         [Bio | 31  28  31  31  30    ]
         [Art | 10  34  89    ]



 m.clear( )
    =   =   =   MultiMap    =   =   =   =



 =   =   = EXITING multimap modifiers test =   =   =   =

 =   =   =  test multimap operation  =   =   =   =


 =   =   =   = Final MMap =   =   =   =   =

     [Math | 90  89  93  22  34  32    ]
     [Chem | 190  809  93  56    ]
 [Chem | 190  809  93  56    ]
     [CS | 90  89  93  56    ]
 [CS | 90  89  93  56    ]
     [Bio | 31  28  31  31  30    ]
     [Art | 10  34  89    ]



 m.find( Math )Math | 90  89  93  22  34  32
 m.contains( Art )
 contains true
 =   =   = EXITING multimap operation test =   =   =   =

 Press <RETURN> to close this window...


 
 
 
 

 */
#endif // MAP_N_MULTIMAP_OUTPUT_H
