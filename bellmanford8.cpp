#include <cstdio>
#include <vector>
#include <queue>
#define oo 1<<30
#define MAX 50001
#define pb push_back

using namespace std;

vector < pair<int, int> > V[ MAX ];

queue <int> QUEUE;

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
};


void read() {

     freopen("bellmanford.in","r", stdin);

     scanf("%d %d", &n, &m);

     int x, 
         y,
         c;

     for(int i = 1; i <= m; i++) {

         scanf("%d %d %d", &x, &y, &c);

         V[ x ].pb( make_pair( y, c ) );
     }

     fclose( stdin );
};

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

int BellmanFord() {

    for(int i = 2; i <= n; i++) 

                               dist[ i ] = oo;
    dist[ 1 ] = 0;

    QUEUE.push( 1 );

    while( !QUEUE.empty() ) {

            int x = QUEUE.front();

            if( ++count[ x ] > n - 1 ) return 0;  

            QUEUE.pop();

            if( dist[ x ] != oo ) {

                 for(int i = 0; i < V[ x ].size(); i++) {

                     int y = V[ x ][ i ].first,

                         c = V[ x ][ i ].second;

                         if( dist[ y ] > dist[ x ] + c ) {

                             dist[ y ] = dist[ x ] + c;

                             QUEUE.push( y );
                         }
                 }
            }


    } 

    return 1; 
};