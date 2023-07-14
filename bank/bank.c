#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
	char phone[50];
	char password[50];
	float balance;
};

int main()
{
    float yatirilanpara,paracekme, paragonderme, kredicekme, borcodeme, dovizodeme, yatirim, faturaodeme, sigortaislemleri;
	int islem, secim;
	FILE *fp;
	 /*Bu işaretçi, dosyanın bellekteki adresini tutar ve dosyayla ilgili işlemlerin yapılmasını sağlar. İşaretçi, dosya işlemleri 
	 için kullanılan C standart kütüphanesi fonksiyonlarına (örneğin, fopen, fread, fwrite, fclose vb.) bir referans olarak kullanılır*/
	char dosyaadi[50], phone[50], pword[50];
	struct user kullanici;
    char cont='y';
    float miktar;
    int havaleno;
	
	printf("\n Hangi islemi yapmak istersiniz?");
	printf("\n\n 1. Hesap olusturun..");
	printf("\n 2. Hesabiniza giris yapin..");
	
	printf("\n\n Seciminiz: \t");
	scanf("%d", &islem);
	
	if(islem ==1)
	{
		system("clear");
		printf("Telefon numaranizi giriniz:\t");
		scanf("%s", kullanici.phone);
		printf("\nSifrenizi giriniz:\t");
		scanf("%s", kullanici.password);
		kullanici.balance=0;
		strcpy(dosyaadi, kullanici.phone);
		fp=fopen(strcat(dosyaadi,".dat"),"w");
		fwrite(&kullanici,sizeof(struct user),1,fp);
		if(fwrite!=0)
		{
			printf("\n\nHesap basariyla olusturuldu..");
		}
		else
		{
			printf("\n\nBir sorun olustu, tekrar deneyin..");
		}
        fclose(fp);
	}
	if(islem == 2)
    {
        system("clear");
        printf("\nTelefon numarasi:\t");
        scanf("%s",phone);
        printf("\nSifre:\t");
        scanf("%s",pword);
        strcpy(dosyaadi,phone);
        fp=fopen(strcat(dosyaadi,".dat"),"r");
        if(fp==NULL)
        {
            printf("\nGecersiz sifre..");
        }
        else
        {

        }
        fread(&kullanici,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,kullanici.password))
        {
            while (cont == 'y')
            {
                system("clear");
                
                printf("\n1.Para Yatirma");
                printf("\n2.Para Cekme");
                printf("\n3.Para Gonderme");
                printf("\n4.Kredi Cekme");
                printf("\n5.Borc Odeme");
                printf("\n6.Doviz Odeme");
                printf("\n7.Yatirim");
                printf("\n8.Fatura Odeme");
                printf("\n9.Sigorta Islemleri");
                printf("\n10.Cikis");
                printf("\nLutfen yapmak istediginiz islemi seciniz:\t");
                scanf("%d", &secim);

                switch (secim)
                {
                 case 1:
                    printf("\n10-50000TL arasinda ne kadar yatirmak istersiniz? ");
                    scanf("%f", &yatirilanpara);
                    
                    if (yatirilanpara >= 10 && yatirilanpara <= 50000) 
                    {
                        printf("Para yatirma isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    
                    default:
                        printf("Gecersiz secim.\n");
                    break;

                case 2:
                    printf("\n10-50000TL arasinda ne kadar cekmek istersiniz? ");
                    scanf("%f", &paracekme);
                    
                    if (paracekme >= 10 && paracekme <= 50000) 
                    {
                        printf("Para cekme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                case 3:
                    printf("\n10-50000TL arasinda ne kadar gondermek istersiniz? ");
                    scanf("%f", &paragonderme);

                    printf("Gondermek istediginiz hesabin numarasini giriniz.");
                    scanf("%d",havaleno);
                    
                    if (paragonderme >= 10 && paragonderme <= 50000) 
                    {
                        printf("Para gonderme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 4:
                        printf("\n10-50000TL arasinda ne kadar kredi cekmek istersiniz? ");
                    scanf("%f", &kredicekme);
                    
                    if (kredicekme >= 10 && kredicekme <= 50000) 
                    {
                        printf("Kredi cekme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 5:
                        printf("\n10-50000TL arasinda ne kadar borcunuz var? ");
                    scanf("%f", &borcodeme);
                    
                    if (borcodeme >= 10 && borcodeme <= 50000) 
                    {
                        printf("Borc odeme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 6:
                        printf("\n10-50000TL arasinda ne kadar doviz odemek istersiniz? ");
                    scanf("%f", &dovizodeme);
                    
                    if (dovizodeme >= 10 && dovizodeme <= 50000) 
                    {
                        printf("Doviz odeme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 7:
                        printf("\n10-50000TL arasinda ne kadar yatirim yapmak istersiniz? ");
                    scanf("%f", &yatirim);
                    
                    if (yatirim >= 10 && yatirim <= 50000) 
                    {
                        printf("Yatirim yapma isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 8:
                        printf("\n10-50000TL arasinda ne kadarlik bir fatura odemek istersiniz? ");
                    scanf("%f", &faturaodeme);
                    
                    if (faturaodeme >= 10 && faturaodeme <= 50000) 
                    {
                        printf("Fatura odeme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 9:
                        printf("\n10-50000TL arasinda ne kadarlik sigorta odemek istersiniz? ");
                    scanf("%f", &sigortaislemleri);
                    
                    if (sigortaislemleri >= 10 && sigortaislemleri <= 50000) 
                    {
                        printf("Sigorta odeme isleminiz basarili.\n");
                    } 
                    else 
                    {
                        printf("Gecersiz giris. Lutfen 10-50000TL arasinda bir deger girin.\n");
                    }
                    break;
                    case 10:

                    printf("Cikis yapmak istiyorsaniz bir sornaki soruya 'n' yazip cikabilirisiniz.");
                      



                }

                    printf("\nDevam etmek istiyor musunuz? (y/n): ");
                    scanf(" %c", &cont);
                }
                



        
            }
            else {
                printf("Gecersiz sifre.\n");
            }
        }
        return (0);
    }
    

    
