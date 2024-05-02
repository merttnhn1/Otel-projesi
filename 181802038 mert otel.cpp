#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cctype>
#include<clocale>
#include<unistd.h>
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Turkish");//türkçe karakterler projeye eklenir
	ofstream dosyayaz;//dosya açmamýzý ya da açýk dosyaya veri giriþi yapmamýzý saðlayan yapý
	ifstream dosyaoku;//varolan dosyayý açýp veri çekmeyi saðlayan yapý
	back://programýn baþlangýç noktasý
	cout<<"    MERT OTEL\nAdmin Þifre : ";
	string sifre="mtkmtk99";//programa giriþ yapýlmasý için istenen doðru þifre
	string girilensifre;//klavyeden girilip doðru olan þifre ile kýyaslanacak þifre
	string odasil;
	cin>>girilensifre;
	int anamenusecim;
	bool giriskontrol=false;//giriþ yapýldýktan sonra devamýnda gelecek iþlemlerin baðlý gerçekleþeceði parametre
	int i;
	if(girilensifre==sifre)//eðer ki giriþ doðru ise bir sonraki sayfaya yönlendirilir
	{
		
		for(i=0;i<6;i++)//estetik güzellik katmak adýna yapýlan basit bir iterasyon :)
		{
			if(i%3==0)
			{
				system("cls");
				cout<<"Baþarýyla giriþ yaptýnýz!";
			}
			sleep(1);//yazýnýn direk ekrandan gitmesini engelleyip 1 saniye beklemesini saðlayan komut
			cout<<".";
		}
		giriskontrol=true;//giriþ saðlanýrsa true deðeri alýr ve devamýnda gerçekleþecek olan iþlem bu true deðere baðlý gerçekleþir
	}
	else
	{
		system("cls");//konsol ekranýnda temizleme yapýlmasýný saðlayan komut
		cout<<"Giriþ Hatalý !";
		sleep(2);
		system("cls");
		goto back;//eðer ki giriþ hatalý ise dönülmesi gereken programýn baþlangýç noktasýna döndürülür
	}
	int secim,odasecim;
	int z=1;
	int t;
	string aradegisken,aradegisken2;//aradegisken okuma iþlemi yapýlýrken içine alacaðý karakter ile kontrol yapýlmasýný saðlayacak deðiþken
	string musteriad2,musterisoyad2,tcno2,musterino2;
	int musterisecim;
	bool musteriadkontrol=false,musterisoyadkontrol=false,tcnokontrol=false,musterinokontrol=false;
	bool odanokontrol=false;//odano stringinde katar kontrol edilir ve nümerik karakter olmayan karakter var ise iþlem iptal edilmesini saðlayan parametre
	bool odabrutkontrol=false;//odabrut stringinde katar kontrol edilir ve nümerik olmayan karakter var ise iþlem iptal edilir.
	bool odasilkontrol=false;//odasil stringinde katar kontrol edilir ve nümerik olmayan karakter tespit edilir ise iþlem iptal edilir.
	string odano,odabrut;
	char aradegiskenn;
	int musterianamenu;
	string musteriad,musterisoyad,tcno,musterino;
	string dosyaveri;
	int k=0;
	int arai1,arai2,arai3,arai4;
	back11:
	if(giriskontrol)
	{
		system("cls");
		cout<<"    MERT OTEL\n";
		cout<<"1)Oda iþlemleri";
		cout<<endl<<"2)Müþteri Ýþlemleri";
		cout<<endl<<"3)Çýkýþ";
		cout<<endl<<"Ýþleminizi seçiniz : ";
		cin>>secim;//klavyeden seçim girilir
		switch(secim)//klavyeden girilen seçim kaç ise ona göre iþlem yapýlýr
		{
			case 1://klavyeden girilecek olan sayý 1 ise
				system("cls");
				cout<<"    MERT OTEL\n";
				cout<<endl<<"1)Oda Ekle\n";
				cout<<"2)Oda Sil\n";
				cout<<"3)Odalarý Listele\n";
				cout<<"4)Bir üst menüye çýk\n";
				cout<<"Ýþleminizi seçiniz : ";
				cin>>odasecim;
				switch(odasecim)
				{//oda seçiminin switchinin baþladýðý nokta
					case 1://Oda ekleme iþlemi buradan baþlamaktadýr.
						back2:
						system("cls");
						cout<<"Oda Numarasý Giriniz(3 Haneli) : ";
						cin>>odano;
						if(odano.length()!=3)
						{
							system("cls");
							cout<<"Girmiþ olduðunuz ifade 3 karakter deðildir.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							goto back2;//girilen karakter sayýsý 3 deðilse back2 etiketine döner
						}
						for(i=0;i<odano.length();i++)
						{
							if(isdigit(odano[i])==0)odanokontrol=true;
							if(odanokontrol)break;
						}
						if(odanokontrol)
						{
							system("cls");
							cout<<"Girilen karakterlerde hatalý tuþlama yapýlmýþtýr.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							odanokontrol=false;
							goto back2;//girilen tuþlamada nümerik olmayan karakter var ise baþa döner iþlem
						}
						back3:
						system("cls");
						cout<<"Odanýn Ücretini giriniz(4 Haneli) : ";
						cin>>odabrut;
						if(odabrut.length()!=4)
						{
							system("cls");
							cout<<"Oda ücreti 4 haneli deðildir.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							goto back3;
							
						}
						for(i=0;i<odabrut.length();i++)
						{
							if(isdigit(odabrut[i])==0)odabrutkontrol=true;//nümerik olmayan karakter var ise parametre true deðerini alýr
							if(odabrutkontrol)break;
						}
						if(odabrutkontrol)
						{
							system("cls");
							cout<<"Girilen karakterlerde hatalý tuþlama yapýlmýþtýr.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							odabrutkontrol=false;
							goto back3;
						}
						dosyaoku.open("C:\\Users\\yazar\\Desktop\\odaKayit.txt");
						for(i=0;i<dosyaoku.eof();i++)
						{
							dosyaoku>>aradegisken[i];
							if(i%9==0 && i!=0)
							{
								if(odano[0]==aradegisken[0] && odano[1]==aradegisken[1]&&odano[2]==aradegisken[2]&&odano[3]==aradegisken[3])
								{
									system("cls");
									cout<<"Girmiþ olduðunuz oda Numarasý bulunmaktadýr!";
									sleep(3);
									odanokontrol=true;
								}
								if(odanokontrol)
								{
									goto back2;
									odanokontrol=false;
									
								}
								aradegisken.clear();
							}
						}
						dosyaoku.close();
						dosyayaz.open("C:\\Users\\yazar\\Desktop\\odaKayit.txt",ios::app);
						dosyayaz<<"\n"<<odano<<" "<<odabrut;
						dosyayaz.close();
						system("cls");
						cout<<"Oda Kayýt Ýþlemi tamamlandý!";
						sleep(3);
						system("cls");
						cout<<"Ana menüye dönmek ister misiniz?\n1)Evet\n2)Hayýr\nSeçim : ";
						cin>>anamenusecim;
						if(anamenusecim==1)
						{
							system("cls");
							goto back11;
						}
						else if(anamenusecim==2)
						{
							cout<<"Programdan çýkýþ yapmak için herhangi bir tuþa basýnýz!";
						}
						else
						{
							cout<<"Ýþlem anlaþýlamadý. Program kapatýldý. Çýkýþ yapmak için herhangi bir tuþa basýnýz!";
						};break;
					
					
					
					
					
					
					case 2:
						dosyaoku.open("C:\\Users\\yazar\\Desktop\\odaKayit.txt");
						while(!dosyaoku.eof())
						{
							dosyaoku>>aradegisken[k];
							k++;
						}
						dosyaoku.close();
						geri:
						system("cls");
						cout<<"Kaydýný silmek istediðiniz oda numarasýný \ngiriniz";
						cout<<" (3 Haneli) : ";
						cin>>odasil;
						if(odasil.length()!=3)
						{
							system("cls");
							cout<<"Giriþiniz 3 haneli deðildir.\n";
							cout<<"Lütfen giriþinizi tekrarlayýnýz...";
							sleep(3);
							goto geri;
							
						}
						for(i=0;i<odasil.length();i++)
						{
							if(isdigit(odasil[i])==0)odasilkontrol=true;
							if(odasilkontrol)
							{
								system("cls");
								cout<<"Katar sayýsý uyuþmuyor.\n";
								cout<<"Lütfen tekrar giriþ yapýnýz...";
								sleep(3);
								break;
							}
						}
						if(odasilkontrol)
						{
							odasilkontrol=false;
							goto geri;
						}
						for(i=0;i<aradegisken.length();i++)
						{
							if(i%8==0)
							{
								if(odasil[i]==aradegisken[i]&&odasil[i+1]==aradegisken[i+1]&&odasil[i+2]==aradegisken[i+2])
								{
									for(t=i;t<(i+8);t++)
									{
										aradegisken[t]=' ';
									}
								}
							}
						}
						dosyayaz.open("C:\\Users\\yazar\\Desktop\\odaKayit.txt",ios::app);
						for(i=0;i<aradegisken.length();i++)
						{
							if(i%8==0)
							{
								if(aradegisken[i]!=' ')
								{
									for(t=i;t<i+8;t++)
									{
										dosyayaz<<aradegisken[t];
										if(t==(i+2))dosyayaz<<" ";
										if(t==(i+7))dosyayaz<<"\n";
									}
								}
							}
						}
						dosyayaz.close();
						system("cls");
						cout<<"Ýþleminiz baþarýyla tamamlandý.";
						sleep(2);
						system("cls");
						cout<<"Ana menüye yönlendiriliyorsunuz!";
						sleep(2);
						goto back11;
						break;
						
						
						
						
						
						
					
					
					
					case 3:	
						cout<<"    MERT OTEL\nOdaNo  Brüt\n";
						dosyaoku.open("C:\\Users\\yazar\\Desktop\\odaKayit.txt");
						while(!dosyaoku.eof())
						{
							
							dosyaoku>>aradegiskenn;
							cout<<aradegiskenn;
							if(z%4==0 && z%8!=0)cout<<"    ";
							if( z%8==0)cout<<"\n";
							z++;
						}
						dosyaoku.close();
						break;
						
						
					case 4 : 
						system("cls");
						cout<<"Ana menüye yönlendiriliyorsunuz..";
						sleep(3);
						system("cls");
						goto back11;
						break;
						
					default : 
					system("cls");
					cout<<"Ýþleminiz anlaþýlamadý.\nÇýkýþ yapmak için herhangi bir tuþa basýnýz!";
					break;
				}//oda seçiminin switchinin bittiði nokta 
					
					
			
			
			case 2 : //müþteri iþlemleri case inin baþlangýç noktasý		
				system("cls");
				
				cout<<"    MERT OTEL";
				cout<<"\n1)Müþteri Ekle\n";
				cout<<"2)Müþteri Sil\n";
				cout<<"3)Müþterileri Listele\n";
				cout<<"4)Üst menüye git\nÝþleminizi seçiniz : ";
				cin>>musterisecim;
				switch(musterisecim)
				{
					case 1:
						beri1:
						system("cls");
						
						cout<<"Müþteri Ad : ";
						cin>>musteriad;
						for(i=0;i<musteriad.length();i++)
						{
							if(isalpha(musteriad[i])==0) musteriadkontrol=true;
							if(musteriadkontrol)break;
						}
						if(musteriadkontrol)
						{
							system("cls");
							cout<<"Girmiþ olduðunuz isimde ingilizce karakterler ile uyumsuz karakterler mevcuttur.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							musteriadkontrol=false;
							goto beri1;
						
						}
						beri2:
						system("cls");
						cout<<"Müþteri Soyad : ";
						cin>>musterisoyad;
						for(i=0;i<musterisoyad.length();i++)
						{
							if(isalpha(musterisoyad[i])==0) musterisoyadkontrol=true;
							if(musterisoyadkontrol)break;
						}
						if(musterisoyadkontrol)
						{
							system("cls");
							cout<<"Girmiþ olduðunuz soyisimde ingilizce karakterler ile uyumsuz karakterler mevcuttur.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							musterisoyadkontrol=false;
							goto beri2;
						}
						beri3:
						system("cls");
						cout<<"11 Haneli Türkiye Cumhuriyeti Kimlik Numarasý Tuþlayýn : ";
						cin>>tcno;
						if(tcno.length()!=11) 
						{
							system("cls");
							cout<<"Girmiþ olduðunuz numara 11 haneli deðildir.\n";
							cout<<"Lütfen tekrar tuþlama yapýnýz...";
							sleep(3);
							goto beri3;
						}
						for(i=0;i<11;i++)
						{
							if(isdigit(tcno[i])==0)tcnokontrol=true;
							if(tcnokontrol)break;
						}
						if(tcnokontrol)
						{
							system("cls");
							cout<<"Girmiþ olduðunuz tuþlamada nümerik olmayan karakterler mevcuttur.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							tcnokontrol=false;
							system("cls");
							goto beri3;
						}
						beri4:
						system("cls");
						cout<<"5 Haneli Müþteri numaranýzý tuþlayýnýz : ";
						cin>>musterino;
						if(musterino.length()!=5)
						{
							system("cls");
							cout<<"Yapmýþ olduðunuz tuþlama 5 karakter içermemektedir.\n";
							cout<<"Lütfen tekrar giriþ yapýnýz...";
							sleep(3);
							
							goto beri4;
						}
						for(i=0;i<5;i++)
						{
							if(isdigit(musterino[i])==0)musterinokontrol=true;
							if(musterinokontrol)break;
						}
						if(musterinokontrol)
						{
							system("cls");
							cout<<"Yapmýþ olduðunuz tuþlamada nümerik olmayan karakterler mevcuttur.";
							cout<<"\nLütfen tekrar giriþ yapýnýz...";
							sleep(3);
							musterinokontrol=false;
							goto beri4;
						}
						system("cls");
						dosyayaz.open("C:\\Users\\yazar\\Desktop\\musteriKayit.txt",ios::app);
						dosyayaz<<musteriad<<" "<<musterisoyad<<" "<<tcno<<" "<<musterino<<"/"<<"\n";
						dosyayaz.close();
						cout<<"Müþteri kaydedildi.";
						sleep(2);
						cout<<"\nAna menüye dönmek istiyor musunuz?";
						cout<<"\n1)Evet\n2)Hayýr\nÝþleminizi seçiniz : ";
						cin>>musterianamenu;
						if(musterianamenu==1)goto back11;
						else 
						{
							system("cls");
							cout<<"Program kapatýldý.\nÇýkýþ yapmak için herhangi bir tuþa basýnýz!";
						};
						break;
						
					
					
					case 2:
						system("cls");
						cout<<"Müþteri Ad : ";
						cin>>musteriad;
						system("cls");
						cout<<"Müþteri Soyad : ";
						cin>>musterisoyad;
						system("cls");
						cout<<"T.C. Kimlik Numarasý giriniz : ";
						cin>>tcno;
						system("cls");
						cout<<"Müþteri No. giriniz : ";
						cin>>musterino;
						dosyaoku.open("C:\\Users\\yazar\\Desktop\\musteriKayit.txt");
						for(i=0;!dosyaoku.eof();i++)
						{
							dosyaoku>>aradegisken[i];
						}
						dosyaoku.close();
						k=0;
						for(i=0;i<aradegisken.length();i++)
						{
							if(aradegisken[i]=='/')k++;
						}
						for(i=0,t=0,z=0;i<aradegisken.length()&&k!=0;i++,z++)
						{
							if(t==0)
							{
								musteriad2[i]=aradegisken[i];
								if(aradegisken[i]==' ')t++;
							}
							if(t==1)
							{
								musterisoyad2[z]=aradegisken[i];
								if(aradegisken[i]==' ')
								{
									t++;
									z=0;
								}
							}
							if(t==2)
							{
								tcno2[z]=aradegisken[i];
								t++;
								z=0;
							}
							if(t==3 && aradegisken[i]!='/')
							{
								musterino2[z]=aradegisken[i];
							}
							if(aradegisken[i]=='/')k--;
							if(musterino==musterino2 && musteriad==musteriad2 && musterisoyad==musterisoyad2 && tcno==tcno2)break;
							else arai1=i;
						}
						arai1++;
						for(i=arai1;;i++)
						{
							if(aradegisken[arai1]=='/')
							{
								aradegisken[arai1]=' ';
								break;
							}
							aradegisken[arai1]=' ';
						}
						dosyayaz.open("C:\\Users\\yazar\\Desktop\\musteriKayit.txt",ios::app);
						for(i=0;i<aradegisken.length();i++)
						{
							dosyayaz<<aradegisken[i];
							if(aradegisken[i]=='/') dosyayaz<<"\n"; 
						}
						dosyayaz.close();
						system("cls");
						cout<<"Müþteri silme iþlemi baþarýyla tamamlandý.";
						cout<<"\nAna menüye dönmek istiyor musunuz?";
						cout<<"\n1)Evet\n2)Hayýr\nÝþleminizi seçiniz : ";
						cin>>musterisecim;
						if(musterisecim==1)
						{
							system("cls");
							cout<<"Ýþlem tamamlandý.\nAna menüye yönlendiriliyorsunuz.";
							sleep(2);
							system("cls");
							goto back11;
						}
						else cout<<"Program kapatýldý. Çýkýþ yapmak için herhangi bir tuþa basýnýz.";
						break;
						
						
						case 3:
							dosyaoku.open("C:\\Users\\yazar\\Desktop\\musteriKayit.txt");
							for(i=0;!dosyaoku.eof();i++)
							{
								dosyaoku>>aradegisken[i];
							}
							dosyaoku.close();
							system("cls");
							cout<<"    MERT OTEL\n";
							for(i=0;i<aradegisken.length();i++)
							{
								cout<<aradegisken[i];
								if(aradegisken[i]=='/')cout<<endl;
							};break;
							
							
							
							case 4:
								goto back11;
								break;
				};break;																												
				case 3:
				system("cls");
				cout<<"Çýkýþ yapmak için herhangi bir tuþa basýnýz.";
				break;				
		}
	}
}
