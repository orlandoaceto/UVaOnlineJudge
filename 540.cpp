#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q[1001];
    queue<int> qt;
    map<int,int> team;
    int t, i, j, n, elem, elemTeam;
    string c;
    int sc = 1;
   
   
    while(scanf("%d", &t) > 0)
    {
        if(t == 0) break;
        team.clear();
        while(!qt.empty())qt.pop();
        
        for(i = 1; i <= t; i++)
        {
        	  //printf("team %d\n", i);
            while(!q[i].empty())q[i].pop();
            scanf("%d", &n);
            for(j = 0; j < n; j++)
            {
                scanf("%d", &elem);
                team[elem] = i;
            }
        }
        printf("Scenario #%d\n", sc++);
        while(true)
        {
            cin>>c;
            if(c == "ENQUEUE")
            {
               scanf(" %d\n", &elem);
               elemTeam = team[elem];
               //printf("ENQUEUE %d in team %d\n", elem, elemTeam);
               if(q[elemTeam].empty())
               {
                   qt.push(elemTeam);
               }
               q[elemTeam].push(elem);
            }
            else if(c == "DEQUEUE")
            {
            	//printf("DEQUEUE\n");
               elemTeam = qt.front();
               printf("%d\n", q[elemTeam].front());
               q[elemTeam].pop();
               if(q[elemTeam].empty()) qt.pop();
            }
            else
            {
            	printf("\n"); 
            	break;
            }
        }
       
    }
}
