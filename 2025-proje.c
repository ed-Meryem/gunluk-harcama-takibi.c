#include <stdio.h>

void menuYazdir();
void yeniGunBaslat();
void harcamaEkle();
void ozetGoster();

int main() {
int secim=0;

do {  
    menuYazdir();  

    if (scanf("%d", &secim) != 1) {  
        while (getchar() != '\n');  
        printf("Hatali giris\n");  
    } else {  

        if (secim == 1) {  
            yeniGunBaslat();  
        }  
        else if (secim == 2) {  
            harcamaEkle();  
        }  
        else if (secim == 3) {  
            ozetGoster();  
        }  
        else if (secim == 4) {  
            printf("Programdan cikiliyor\n");  
        }  
        else {  
            printf("Hatali secim\n");  
        }  
    }  

} while (secim != 4);  

return 0;

}

void menuYazdir() {
printf("\n--- GUNLUK HARCAMA TAKIBI ---\n");
printf("1- Yeni Gun Baslat (Limit Gir)\n");
printf("2- Harcama Ekle\n");
printf("3- Bugunun Ozetini Goster\n");
printf("4- Cikis\n");
printf("Seciminiz: ");
}

void yeniGunBaslat() {
FILE *f;
float limit;

f = fopen("harcama.txt", "a");  

if (f == NULL) {  
    printf("Dosya acilamadi.\n");  
}  
else {  
    printf("Gunluk limit giriniz: ");  
    scanf("%f", &limit);  

    fprintf(f, "\nLIMIT %.2f\n", limit);  
    fclose(f);  

    printf("Yeni gun baslatildi.\n");  
}

}

void harcamaEkle() {
FILE *f;
char kategori[20];
float tutar;

f = fopen("harcama.txt", "a");  

if (f == NULL) {  
    printf("Once yeni gun baslatmalisiniz\n");  
}  
else {  
    printf("Kategori: ");  
    scanf("%19s", kategori);  

    printf("Tutar: ");  
    scanf("%f", &tutar);  

    fprintf(f, "%s %.2f\n", kategori, tutar);  
    fclose(f);  

    printf("Harcama eklendi.\n");  
}

}

void ozetGoster() {
FILE *f;
char kelime[20];
float limit = 0;
float tutar = 0;
float toplam = 0;

f = fopen("harcama.txt", "r");  

if (f == NULL) {  
    printf("Kayit yok.\n");  
}  
else {  
    while (fscanf(f, "%19s", kelime) == 1) {  

        if (kelime[0] == 'L') {  
            fscanf(f, "%f", &limit);  
            toplam = 0;   
        }  
        else {  
            fscanf(f, "%f", &tutar);  
            toplam += tutar;  
        }  
    }  

    fclose(f);  

    printf("\n--- BUGUNUN OZETI ---\n");  
    printf("Limit: %.2f\n", limit);  
    printf("Toplam Harcama: %.2f\n", toplam);  

    if (toplam > limit) {  
        printf("UYARI: Limit asildi!\n");  
    }  
    else {  
        printf("Durum: Limit icinde.\n");  
    }  
}

}
