/*:::::::8 Queens problem using steepest ascent Hill Climbing:::::::::::
    Initial state: Random orientation of queens on board (1 on each column)
    Evaluation function: No. of attacking pair of queens
    Terminal State: Local Minima / Global Minima
*/

#include<bits/stdc++.h>
#define MX 8
#define pb push_back
using namespace std;
vector<int> board;

void print_state(vector<int> v)
{
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(v[j]==i)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int attacking_pairs(vector<int> v)
{
    int cnt=0;
    for(int i=0; i<7; i++)
    {
        for(int j=i+1; j<=7; j++)
        {
            if(v[i]==v[j])
                cnt++;
            else if(abs(v[i]-v[j])==abs(i-j))
                cnt++;
        }
    }
    return cnt;
}

vector<int> generate_successor(vector<int>v)
{
    vector<int> u=v;
    vector<int> ans;
    int cnt=0;
    int mn=1000;
    for(int i=0; i<=7; i++)
    {
        for(int j=0; j<=7; j++)
        {
            if(v[i]!=j)
            {
                cnt++;
                u[i]=j;
                int temp=attacking_pairs(u);
                if(temp<mn)
                {
                    mn=temp;
                    ans=u;
                }
            }
        }
        u[i]=v[i];
    }
    return ans;
}

vector<int> hill_climbing(vector<int> current)
{
    while(true)
    {
        vector<int> neighbor=generate_successor(current);
        if(attacking_pairs(current)<=attacking_pairs(neighbor))
            return current;
        current=neighbor;
    }

}

int main()
{

    srand(time(NULL));  //For random number based on time elapsed

    for(int i=0; i<=7; i++)
    {
        int x = rand()%8; // Generating random number in range 0 to 7
        board.pb(x);
    }

    printf("Randomly taken initial state:\n");
    print_state(board);

    vector<int> ans = hill_climbing(board);
    int cnt=attacking_pairs(ans);
    if(cnt==0)
        printf("\nGlobal Minima:\n");
    else
        printf("\nLocal Minima:\n");
    print_state(ans);
    printf("Attacking pairs = %d\n", cnt);

    return 0;
}
