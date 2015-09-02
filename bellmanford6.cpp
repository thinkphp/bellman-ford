#include <cstdio>
#include <vector>
#include <deque>
#define oo 1<<30
#define MAX 50001
#define pb push_back

using namespace std;

struct nod {
       int y, 
           c;
};

vector <nod> V[ MAX ];

deque <int> QUEUE;

int n,
    m,
    dist[ MAX ],
    count[ MAX ];

//prototypes functions

void read();
void solve();
int BellmanFord();

int main() {

    read();
    solve();

    return (0);
}

void solve() {

    freopen("bellmanford.out","w", stdout);

    if( BellmanFord() ) {

        for(int i = 2; i <= n; i++) {

            printf("%d ", dist[ i ]); 
        }

    } else {
 
           printf("%s","Ciclu negativ!"); 
    }

    fclose( stdout );
};

void read() {

     freopen("bellmanford.in","r", stdin);

     scanf("%d %d", &n, &m);

     int x, 
         c;

     nod t;

     for(int i = 1; i <= m; i++) {

         scanf("%d %d %d", &x, &t.y, &t.c);

         V[ x ].pb( t );
     }

     fclose( stdin );
};

int BellmanFord() {

    for(int i = 2; i <= n; i++) 

                               dist[ i ] = oo;
    dist[ 1 ] = 0;

    QUEUE.pb( 1 );

    while( !QUEUE.empty() ) {

            int x = QUEUE.front();

            if( dist[ x ] != oo ) {

                 for(int i = 0; i < V[ x ].size(); i++) {

                     int y = V[ x ][ i ].y,

                         c = V[ x ][ i ].c;

                         if( dist[ y ] > dist[ x ] + c ) {

                             dist[ y ] = dist[ x ] + c;

                             QUEUE.pb( y );

                             if(++count[ y ] > n - 1) return 0;  
                         }
                 }
            }

            QUEUE.pop_front();
    } 

    return 1; 
};