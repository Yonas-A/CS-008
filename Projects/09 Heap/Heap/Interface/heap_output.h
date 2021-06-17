#ifndef HEAP_OUTPUT_H
#define HEAP_OUTPUT_H

/*
Last login: Sat Apr  4 17:49:01 on ttys000
yonas@Yonas-MBP ~ % source /var/folders/bm/_2024b_x6z1c4jyzshs0j6xr0000gn/T/tmpfGhhkJ

    . . . . . . . . . . TOP . . . . . . . . . .



[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 4
- - Inserting 4
[4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 54
- - Inserting 54
[54]
    [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 12
- - Inserting 12
    [12]
[54]
    [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 45
- - Inserting 45
    [12]
[54]
    [45]
        [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 58
- - Inserting 58
    [12]
[58]
        [45]
    [54]
        [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 94
- - Inserting 94
    [58]
        [12]
[94]
        [45]
    [54]
        [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 95

        [58]
    [94]
        [12]
[95]
        [45]
    [54]
        [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 38

        [58]
    [94]
        [12]
[95]
        [45]
    [54]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 5

        [58]
    [94]
        [12]
[95]
        [45]
    [54]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 42

        [58]
    [94]
        [12]
[95]
        [45]
            [42]
    [54]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 73

        [58]
    [94]
        [12]
[95]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 95

        [58]
    [95]
        [94]
            [12]
[95]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 2

        [58]
    [95]
            [2]
        [94]
            [12]
[95]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 93

        [93]
            [58]
    [95]
            [2]
        [94]
            [12]
[95]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [95]

        [93]
    [94]
            [2]
        [58]
            [12]
[95]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [95]

        [58]
    [93]
        [58]
            [12]
[94]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [94]

        [12]
    [58]
        [58]
[93]
            [45]
        [54]
            [42]
    [73]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [93]

        [12]
    [58]
        [58]
[73]
        [45]
            [42]
    [54]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [73]

        [12]
    [58]
        [42]
[58]
        [45]
    [54]
            [5]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [58]

        [12]
    [42]
        [12]
[58]
        [45]
    [54]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 101
- - Inserting 101
        [12]
    [42]
        [12]
[101]
        [45]
    [58]
            [38]
        [54]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 2
- - Inserting 2
        [12]
    [42]
        [12]
[101]
        [45]
            [2]
    [58]
            [38]
        [54]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 101
- - Inserting 101
        [12]
    [42]
        [12]
[101]
            [45]
        [58]
            [2]
    [101]
            [38]
        [54]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    i
: 23
- - Inserting 23
        [12]
    [42]
        [23]
            [12]
[101]
            [45]
        [58]
            [2]
    [101]
            [38]
        [54]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [101]

        [12]
    [42]
        [23]
[101]
            [12]
        [45]
            [2]
    [58]
            [38]
        [54]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [101]

        [12]
    [42]
        [23]
[58]
        [45]
            [2]
    [54]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 90

        [12]
    [42]
        [23]
[90]
            [45]
        [54]
            [2]
    [58]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 11

        [12]
    [42]
        [23]
            [11]
[90]
            [45]
        [54]
            [2]
    [58]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    r
       Inserting: 35

        [12]
    [42]
            [23]
        [35]
            [11]
[90]
            [45]
        [54]
            [2]
    [58]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    rp
       Inserting: 37

        [37]
            [12]
    [42]
            [23]
        [35]
            [11]
[90]
            [45]
        [54]
            [2]
    [58]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    -- item erased: [90]

        [37]
    [42]
            [23]
        [35]
            [11]
[58]
            [12]
        [45]
            [2]
    [54]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [58]

        [37]
    [42]
        [35]
            [11]
[54]
            [12]
        [23]
            [2]
    [45]
            [12]
        [38]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [54]

        [37]
    [42]
        [35]
[45]
            [12]
        [23]
            [2]
    [38]
            [11]
        [12]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [45]

        [12]
    [37]
        [35]
[42]
        [23]
            [2]
    [38]
            [11]
        [12]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [42]

        [12]
    [37]
        [35]
[38]
        [12]
    [23]
            [11]
        [12]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [38]

        [12]
    [35]
        [23]
[37]
        [12]
    [23]
        [12]
            [4]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    p
-- item erased: [37]

        [12]
    [23]
        [11]
[35]
        [12]
    [23]
        [12]


=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    c



=========================

[R]andom   [I]nsert    [C]lear    [P]op    [Q]uit:    q



=========================


 . . . . . . . . . . END  . . . . . . . . . .

Press <RETURN> to close this window...





 */

#endif // HEAP_OUTPUT_H
