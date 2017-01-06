#include <iostream>


using namespace std;

	int Max_Sub_Array(int arr[],int n)
	{
		int ans(0),sum(0);  // 2 değişken atadık.Maximum ve Answer şeklinde.
	
		for (int i =0 ; i <n ; ++i)
		{							// Diziyi baştan sona kadar tararken aşağıdaki adımları gerçekleştiriyoruz.
			if (sum + arr[i] > 0)   // Başlangıçta 0 değerini atadığımız sum ile dizimizin i. elemanını topluyoruz
				sum += arr[i];		// Eğer toplamımız 0 dan büyükse sum değişkenimize dizimizin i.elemanını ekliyoruz.
			else					// Değilse ise sum değişkenimizi sıfırlıyoruz
				sum=0;				// Bunları yapma amacımız ise şöyle özetlenebilir.Eğer sum + arr[i] ifadesi sıfırdan düşük olursa
		ans = max(ans,sum);			// Demek ki arr[i] elemanı negatif bir sayıdır ve toplamı düşürdüğünden bunu alt diziye almamalıyız
		}							// Bu şekilde tüm diziyi tarıyoruz ve en sonunda Ans veya Sum değişkenimizden bize büyük olanı döndürüyoruz.
	return ans;						// Dönen cevap verilen dizide ki en büyük toplamlı alt diziyi hesaplar.
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
