#include <stdio.h>
#include <stdlib.h>
#define DEFAULTSIZE 5

//@brief qsort icin karsilastirma fonksiyonu, pointerlar int e cevrilir ve farklari dondurulur
//@param A karsilastirma icin kullanilacak ilk pointer
//@param B karsilastirma icin kullanilacak ikinci pointer
//@return A ile B esitse 0, A B'den buyukse pozitif bir sayi, B A'dan buyukse negatif bir sayi dondurulur 
//Pozitif deger qsort'a A'nýn B'den sonra gelmesi gerektigini, negatif deger B'nin A'dan sonra gelmesi gerektigini gosterir
int compare(const void *a, const void *b) {
    return (*(int*)a -*(int*)b);
}

//@brief Ýkili arama islevi ile anahtarin girecegi kilit bulunur
//@param arr[] kilitlerin bulundugu dizi
//@param low aramanin baslayacagi indis
//@param high aramanin bitecegi indis
//@param key anahtarin buyuklugu
//return dizinin mid indisindindeki deger kilidin buyuklugunu simgeler, anahtar buyukluguyle eslesen deger varsa bu degerin indisi dondurulur yoksa -1 dondurulur
int binarySearch(int *locks, int low, int high, int key) {
    while (low <= high) 
	{
        int mid = low + (high - low) / 2;
        if (locks[mid] == key)
        {
        	return mid;
		}
        if (locks[mid] < key)
        {
        	low = mid + 1;
		}
        else
        {
        	high = mid - 1;
		}
    }
    return -1;
}

//@brief anahtar ve kilit dizileri sýralanýr, her anahtar icin binarysearch uygulanýr eslesen varsa ekrana yazdirir yoksa hangi anahtarin eslesmedigini ekrana yazdirir
//@param keys[] anahtarlarin bulundugu dizi
//@param locks [] kilitlerin bulundugu dizi
//@param N anahtar ve kilit sayisi
void findMatchingDoorandKey(int *keys, int *locks, int N) {
    qsort(keys, N, sizeof(int), compare);
    qsort(locks, N, sizeof(int), compare);
    int i, index;

    printf("Eslesen kapi ve anahtar ciftleri:\n");
    for (i = 0; i < N; i++) 
	{
        index = binarySearch(locks, 0, N - 1, keys[i]);
        if (index != -1) 
		{
            printf("Anahtar %d <-> Kapi %d\n", keys[i], locks[index]);
        } else 
		{
            printf("Anahtar %d bir kapi ile eslesmedi\n", keys[i]);
        }
    }
}

int main() {
    int N, i;
    int *keys, *locks;
    
    printf("Anahtar ve kilit sayisini girin(0 ve ondan kucuk bir sayi girilirse default buyukluk kullanilacaktir): ");
    scanf("%d", &N);
    if(N <= 0)
    {
    	N = DEFAULTSIZE;
	}
    
    keys = (int*) malloc(N*sizeof(int));
    locks = (int*) malloc(N*sizeof(int));

    printf("Anahtarlari sirasiyla girin:\n");
    for (i = 0; i < N; i++) 
	{
        scanf("%d", &keys[i]);
    }

    printf("Kilitleri sirasiyla girin:\n");
    for (i = 0; i < N; i++) 
	{
        scanf("%d", &locks[i]);
    }

    findMatchingDoorandKey(keys, locks, N);
    return 0;
}

