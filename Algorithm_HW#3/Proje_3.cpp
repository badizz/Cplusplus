#include <iostream>
#include <time.h>
#include <cstdlib>
#include <climits>
#define MAX_NUM 201
using namespace std;

/*  badizz� */

int n,e,g[MAX_NUM][MAX_NUM];
bool d [MAX_NUM];

void set_edge(int x,int y,int value)
{
	// gelen parametrelere 1 atayacak
	g[x][y] = value;
	g[y][x] = value;
}

void add_edge(int x,int y,int value)
{
	// sildi�imiz edgeleri, di�er taraflara da simetrik olarak ekledik...
	g[x][y] += value;
	if ( x != y) // e�er x ve y birbirine e�itse 2 tarafada ekledi�imiz i�in fazladan eklemi� oluruz. o y�zden bunu ifle kontrol ettik
		g[y][x] += value;
}

int mincut()
{
	int del_vertex =0; // �u ana kadar hi� vertex silinmedi
	int a,b;
	int del_edge=0;
	// bir vertexi delete edersek d[] dizinine bakarak anlayaca��z
	
	// bu for d[] dizisini ilk halini 0 yap�yor
	for ( int i =1 ; i<= n ; ++i)
		d[i]=0;
	
	srand(time(NULL));
		
	while (del_vertex < n-2 )  // n-2 olma nedeni, 2 vertex kalana kadar devam etmesi laz�m	
	{
		a = 1 + rand() % n ; // 0 la n-1 aras�nda bir de�er �retir +1 ekleriz 0 la n  aras� olur
		b = 1 + rand() % n ; 	
	
		if ( g[a][b] == 0   || d[a] || d[b]  ) // Burada e�er a ile b do�ru se�ilemediyse veyaaa  ikisinden biri silindiyse bu ad�m� atlamam�z� sa�l�yoruz...
			continue; 
		
		del_edge += g[a][b];
		set_edge(a,b,0); 
		
		// �imdide bir d�ng� olu�turup sildi�imiz vertexin , edgelerini di�er yollara ekliyoruz
		
		for ( int i = 1 ; i <=n ; ++i)
		{
			add_edge(a,i, g[b][i]);
		}
	d[b]=1;
	del_vertex++; // i�lem sonunda bir vertex silindi�i i�in ,silinen vertexler de�i�kenini 1 artt�rd�k
	
	
	}	
	
return  e - del_edge;	
/*  badizz� */	
}

	// ka� edge sildi�imizi ve ka� vertex kald���n� tutuyoruz
	// en son 2 vertex kald��� zamana kadar en son ka� edge silinmi�se
	// onu d�nd�rece�iz
int main ()
{
	int a,b,w; // node 1  , node 2 , ve a��rl�k tan�mlad�k
	cin >> n >> e; 	
	
	for (int i=1 ; i<=n ; ++i)
	{
		for (int j=1 ; j <=n ; ++j)
		{
			g[i][j] = 0;
		}
	}
	
	for ( int i=0 ; i<e ; ++i)
	{
		cin >> a >> b ;
		set_edge(a,b,1);
	}
	
	cout << mincut() << endl;
	
	return 0;/*  badizz� */
}
