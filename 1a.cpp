#include <bits/stdc++.h>

using namespace std ;

void swap(int *a, int *b)
{
    int t = *a ;
    *a = *b ;
    *b = t ;
}

int main(int argc, char const **argv)
{
    srand(time(NULL)) ;
    int n ;
    string s ;
    int lower = 1 ;
    int upper = 100 ;
    int small, big ;
    int counts = 0 ;
    int bingo = 0 ;
    while(1)
    {
        try
        {
            cin >> n ;
            if(n < 1 || n > 100)
            {
                cin.clear() ;
                cin.ignore() ;
                throw "The number should be between 1 ~ 100" ;
            }
        }
        catch(const char *s) { cout << s << endl ; }
        if(n >= 1 && n <= 100) break ;
    }
    small = (rand() % 100) + 1 ;
    big = (rand() % 100) + 1 ;
    if(small > big) swap(&small, &big) ;
    counts++ ;
    while(counts <= 4)
    {
        if(counts == 4) small = big = (rand() % (upper - lower + 1)) + lower ;
        if(small == n && big == n)
        {
            bingo = 1 ;
            cout << "Anwser is (" << n << ", " << n << ")" << endl ;
            break ;
        }
        cout << "(" << small << ", " << big << ")" << endl ;
        flag_s :
        cin >> s ;
        if(s == "below")
        {
            upper = small ;
            small = (rand() % (upper - lower + 1)) + lower ;
            big = (rand() % (upper - lower + 1)) + lower ;
            if(small > big) swap(&small, &big) ;
        }
        else if(s == "within")
        {
            lower = small ;
            upper = big ;
            small = (rand() % (upper - lower + 1)) + lower ;
            big = (rand() % (upper - lower + 1)) + lower ;
            if(small > big) swap(&small, &big) ;
        }
        else if(s == "above")
        {
            lower = big ;
            small = (rand() % (upper - lower + 1)) + lower ;
            big = (rand() % (upper - lower + 1)) + lower ;
            if(small > big) swap(&small, &big) ;
        }
        else
        {
            cout << "Input below, within or above" << endl ;
            goto flag_s ;
        }
        counts++ ;
    }
    if(!bingo) cout << "Program lose" << endl ;
    return 0 ;
}
