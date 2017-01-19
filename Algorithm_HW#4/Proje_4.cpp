#include <iostream>
#include <climits> // integerin alabilece�i bir maksimum var.

using namespace std;
/*  badizz� */
#define MAX_NUM 201

int g[MAX_NUM][MAX_NUM];

int n;
int e;
int q;
int d[MAX_NUM]; // uzakl��� yazd�rmak i�in tan�mlad�k
bool v[MAX_NUM]; // 0 yada 1 olacak.��aretlenmi� yada i�aretlenmemi� oldu�unu anlamak i�in

int get_min()
{
	int min=INT_MAX, min_idx; // minimumu ve minimumun indeksini tutan de�i�ken tan�mlad�k
	
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

	d[s]=0; // kendisine olan uzakl��� s�f�rlad�k
	
	while (visited < n)
	{
		u = get_min();
		v[u]=1;
		
		for (int i=1 ; i<=n ; ++i)
		{
			if( g[u][i] >  -1  &&  !v[i] )
			{
				new_dist = d[u] + g[u][i];
				if ( new_dist < d[i] ) // d[i] �nceki uzakl�k
					d[i] = new_dist;
			}
			
		}
		++visited;
	}//bir counter tutar�z, hepsi visited oldu�u zaman bu counter , n'e e�it olur
/*  badizz� */
}

int main ()
{
	int a,b,w; // node 1  , node 2 , ve a��rl�k tan�mlad�k
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
		cin >> a >> b ; // sorgular� ald�k
		dijikstra(a);
		if ( d[b] == INT_MAX)
			cout << "-" << endl;
		else
		cout << d[b] << endl;//   a  i�in bir dijkstra hesaplamam�z gerekiyor
	}
/*  badizz� */	
	return 0;
}
