#include <iostream>


using namespace std;

	int Max_Sub_Array(int arr[],int n)
	{
		int ans(0),sum(0);  // 2 de�i�ken atad�k.Maximum ve Answer �eklinde.
	
		for (int i =0 ; i <n ; ++i)
		{							// Diziyi ba�tan sona kadar tararken a�a��daki ad�mlar� ger�ekle�tiriyoruz.
			if (sum + arr[i] > 0)   // Ba�lang��ta 0 de�erini atad���m�z sum ile dizimizin i. eleman�n� topluyoruz
				sum += arr[i];		// E�er toplam�m�z 0 dan b�y�kse sum de�i�kenimize dizimizin i.eleman�n� ekliyoruz.
			else					// De�ilse ise sum de�i�kenimizi s�f�rl�yoruz
				sum=0;				// Bunlar� yapma amac�m�z ise ��yle �zetlenebilir.E�er sum + arr[i] ifadesi s�f�rdan d���k olursa
		ans = max(ans,sum);			// Demek ki arr[i] eleman� negatif bir say�d�r ve toplam� d���rd���nden bunu alt diziye almamal�y�z
		}							// Bu �ekilde t�m diziyi tar�yoruz ve en sonunda Ans veya Sum de�i�kenimizden bize b�y�k olan� d�nd�r�yoruz.
	return ans;						// D�nen cevap verilen dizide ki en b�y�k toplaml� alt diziyi hesaplar.
	}								

int main()

{
	int n;
	cin >> n;
	int a[n];
	
	for ( int i =0 ;  i<n ; i++)
	{
		cin >> a[i];
	}
	cout << Max_Sub_Array(a,n);/*
	if ( k != 0 )
		cout <<k;
	else
		for ()*/
}
