#include <iostream>
#include <time.h>
#include <cstdlib>
#include <climits>
#define MAX_NUM 201
using namespace std;

/*  badizz™ */

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
	// sildiðimiz edgeleri, diðer taraflara da simetrik olarak ekledik...
	g[x][y] += value;
	if ( x != y) // eðer x ve y birbirine eþitse 2 tarafada eklediðimiz için fazladan eklemiþ oluruz. o yüzden bunu ifle kontrol ettik
		g[y][x] += value;
}

int mincut()
{
	int del_vertex =0; // þu ana kadar hiç vertex silinmedi
	int a,b;
	int del_edge=0;
	// bir vertexi delete edersek d[] dizinine bakarak anlayacaðýz
	
	// bu for d[] dizisini ilk halini 0 yapýyor
	for ( int i =1 ; i<= n ; ++i)
		d[i]=0;
	
	srand(time(NULL));
		
	while (del_vertex < n-2 )  // n-2 olma nedeni, 2 vertex kalana kadar devam etmesi lazým	
	{
		a = 1 + rand() % n ; // 0 la n-1 arasýnda bir deðer üretir +1 ekleriz 0 la n  arasý olur
		b = 1 + rand() % n ; 	
	
		if ( g[a][b] == 0   || d[a] || d[b]  ) // Burada eðer a ile b doðru seçilemediyse veyaaa  ikisinden biri silindiyse bu adýmý atlamamýzý saðlýyoruz...
			continue; 
		
		del_edge += g[a][b];
		set_edge(a,b,0); 
		
		// þimdide bir döngü oluþturup sildiðimiz vertexin , edgelerini diðer yollara ekliyoruz
		
		for ( int i = 1 ; i <=n ; ++i)
		{
			add_edge(a,i, g[b][i]);
		}
	d[b]=1;
	del_vertex++; // iþlem sonunda bir vertex silindiði için ,silinen vertexler deðiþkenini 1 arttýrdýk
	
	
	}	
	
return  e - del_edge;	
/*  badizz™ */	
}

	// kaç edge sildiðimizi ve kaç vertex kaldýðýný tutuyoruz
	// en son 2 vertex kaldýðý zamana kadar en son kaç edge silinmiþse
	// onu döndüreceðiz
int main ()
{
	int a,b,w; // node 1  , node 2 , ve aðýrlýk tanýmladýk
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
	
	return 0;/*  badizz™ */
}
