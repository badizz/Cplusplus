#include <iostream>
#include <climits> // integerin alabileceði bir maksimum var.

using namespace std;
/*  badizz™ */
#define MAX_NUM 201

int g[MAX_NUM][MAX_NUM];

int n;
int e;
int q;
int d[MAX_NUM]; // uzaklýðý yazdýrmak için tanýmladýk
bool v[MAX_NUM]; // 0 yada 1 olacak.Ýþaretlenmiþ yada iþaretlenmemiþ olduðunu anlamak için

int get_min()
{
	int min=INT_MAX, min_idx; // minimumu ve minimumun indeksini tutan deðiþken tanýmladýk
	
	for(int i=1 ; i <=n ; ++i)
	{
		if ( d[i] < min   &&  !v[i] )
		{
			min = d[i];
			min_idx = i;
		}
	}
return min_idx;
}

void dijikstra(int s)
{
	int visited=0 , u , new_dist;
	for ( int i=1 ; i <=n ; ++i)
	{
		d[i] = INT_MAX;
		v[i] = 0;
	}

	d[s]=0; // kendisine olan uzaklýðý sýfýrladýk
	
	while (visited < n)
	{
		u = get_min();
		v[u]=1;
		
		for (int i=1 ; i<=n ; ++i)
		{
			if( g[u][i] >  -1  &&  !v[i] )
			{
				new_dist = d[u] + g[u][i];
				if ( new_dist < d[i] ) // d[i] önceki uzaklýk
					d[i] = new_dist;
			}
			
		}
		++visited;
	}//bir counter tutarýz, hepsi visited olduðu zaman bu counter , n'e eþit olur
/*  badizz™ */
}

int main ()
{
	int a,b,w; // node 1  , node 2 , ve aðýrlýk tanýmladýk
	cin >> n >> e >> q; 	
	
	for (int i=1 ; i<=n ; ++i)
	{
		for (int j=1 ; j <=n ; ++j)
		{
			g[i][j] = -1;
		}
	}
	
	for ( int i=0 ; i<e ; ++i)
	{
		cin >> a >> b >> w;
		g[a][b]=w;
		g[b][a]=w;
	}
	
	for ( int i=0 ; i<q ; ++i)
	{
		cin >> a >> b ; // sorgularý aldýk
		dijikstra(a);
		if ( d[b] == INT_MAX)
			cout << "-" << endl;
		else
		cout << d[b] << endl;//   a  için bir dijkstra hesaplamamýz gerekiyor
	}
/*  badizz™ */	
	return 0;
}
