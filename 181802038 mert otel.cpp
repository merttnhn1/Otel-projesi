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
	setlocale(LC_ALL,"Turkish");//t�rk�e karakterler projeye eklenir
	ofstream dosyayaz;//dosya a�mam�z� ya da a��k dosyaya veri giri�i yapmam�z� sa�layan yap�
	ifstream dosyaoku;//varolan dosyay� a��p veri �ekmeyi sa�layan yap�
	back://program�n ba�lang�� noktas�
	cout<<"    MERT OTEL\nAdmin �ifre : ";
	string sifre="mtkmtk99";//programa giri� yap�lmas� i�in istenen do�ru �ifre
	string girilensifre;//klavyeden girilip do�ru olan �ifre ile k�yaslanacak �ifre
	string odasil;
	cin>>girilensifre;
	int anamenusecim;
	bool giriskontrol=false;//giri� yap�ld�ktan sonra devam�nda gelecek i�lemlerin ba�l� ger�ekle�ece�i parametre
	int i;
	if(girilensifre==sifre)//e�er ki giri� do�ru ise bir sonraki sayfaya y�nlendirilir
	{
		
		for(i=0;i<6;i++)//estetik g�zellik katmak ad�na yap�lan basit bir iterasyon :)
		{
			if(i%3==0)
			{
				system("cls");
				cout<<"Ba�ar�yla giri� yapt�n�z!";
			}
			sleep(1);//yaz�n�n direk ekrandan gitmesini engelleyip 1 saniye beklemesini sa�layan komut
			cout<<".";
		}
		giriskontrol=true;//giri� sa�lan�rsa true de�eri al�r ve devam�nda ger�ekle�ecek olan i�lem bu true de�ere ba�l� ger�ekle�ir
	}
	else
	{
		system("cls");//konsol ekran�nda temizleme yap�lmas�n� sa�layan komut
		cout<<"Giri� Hatal� !";
		sleep(2);
		system("cls");
		goto back;//e�er ki giri� hatal� ise d�n�lmesi gereken program�n ba�lang�� noktas�na d�nd�r�l�r
	}
	int secim,odasecim;
	int z=1;
	int t;
	string aradegisken,aradegisken2;//aradegisken okuma i�lemi yap�l�rken i�ine alaca�� karakter ile kontrol yap�lmas�n� sa�layacak de�i�ken
	string musteriad2,musterisoyad2,tcno2,musterino2;
	int musterisecim;
	bool musteriadkontrol=false,musterisoyadkontrol=false,tcnokontrol=false,musterinokontrol=false;
	bool odanokontrol=false;//odano stringinde katar kontrol edilir ve n�merik karakter olmayan karakter var ise i�lem iptal edilmesini sa�layan parametre
	bool odabrutkontrol=false;//odabrut stringinde katar kontrol edilir ve n�merik olmayan karakter var ise i�lem iptal edilir.
	bool odasilkontrol=false;//odasil stringinde katar kontrol edilir ve n�merik olmayan karakter tespit edilir ise i�lem iptal edilir.
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
		cout<<"1)Oda i�lemleri";
		cout<<endl<<"2)M��teri ��lemleri";
		cout<<endl<<"3)��k��";
		cout<<endl<<"��leminizi se�iniz : ";
		cin>>secim;//klavyeden se�im girilir
		switch(secim)//klavyeden girilen se�im ka� ise ona g�re i�lem yap�l�r
		{
			case 1://klavyeden girilecek olan say� 1 ise
				system("cls");
				cout<<"    MERT OTEL\n";
				cout<<endl<<"1)Oda Ekle\n";
				cout<<"2)Oda Sil\n";
				cout<<"3)Odalar� Listele\n";
				cout<<"4)Bir �st men�ye ��k\n";
				cout<<"��leminizi se�iniz : ";
				cin>>odasecim;
				switch(odasecim)
				{//oda se�iminin switchinin ba�lad��� nokta
					case 1://Oda ekleme i�lemi buradan ba�lamaktad�r.
						back2:
						system("cls");
						cout<<"Oda Numaras� Giriniz(3 Haneli) : ";
						cin>>odano;
						if(odano.length()!=3)
						{
							system("cls");
							cout<<"Girmi� oldu�unuz ifade 3 karakter de�ildir.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							goto back2;//girilen karakter say�s� 3 de�ilse back2 etiketine d�ner
						}
						for(i=0;i<odano.length();i++)
						{
							if(isdigit(odano[i])==0)odanokontrol=true;
							if(odanokontrol)break;
						}
						if(odanokontrol)
						{
							system("cls");
							cout<<"Girilen karakterlerde hatal� tu�lama yap�lm��t�r.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							odanokontrol=false;
							goto back2;//girilen tu�lamada n�merik olmayan karakter var ise ba�a d�ner i�lem
						}
						back3:
						system("cls");
						cout<<"Odan�n �cretini giriniz(4 Haneli) : ";
						cin>>odabrut;
						if(odabrut.length()!=4)
						{
							system("cls");
							cout<<"Oda �creti 4 haneli de�ildir.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							goto back3;
							
						}
						for(i=0;i<odabrut.length();i++)
						{
							if(isdigit(odabrut[i])==0)odabrutkontrol=true;//n�merik olmayan karakter var ise parametre true de�erini al�r
							if(odabrutkontrol)break;
						}
						if(odabrutkontrol)
						{
							system("cls");
							cout<<"Girilen karakterlerde hatal� tu�lama yap�lm��t�r.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
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
									cout<<"Girmi� oldu�unuz oda Numaras� bulunmaktad�r!";
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
						cout<<"Oda Kay�t ��lemi tamamland�!";
						sleep(3);
						system("cls");
						cout<<"Ana men�ye d�nmek ister misiniz?\n1)Evet\n2)Hay�r\nSe�im : ";
						cin>>anamenusecim;
						if(anamenusecim==1)
						{
							system("cls");
							goto back11;
						}
						else if(anamenusecim==2)
						{
							cout<<"Programdan ��k�� yapmak i�in herhangi bir tu�a bas�n�z!";
						}
						else
						{
							cout<<"��lem anla��lamad�. Program kapat�ld�. ��k�� yapmak i�in herhangi bir tu�a bas�n�z!";
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
						cout<<"Kayd�n� silmek istedi�iniz oda numaras�n� \ngiriniz";
						cout<<" (3 Haneli) : ";
						cin>>odasil;
						if(odasil.length()!=3)
						{
							system("cls");
							cout<<"Giri�iniz 3 haneli de�ildir.\n";
							cout<<"L�tfen giri�inizi tekrarlay�n�z...";
							sleep(3);
							goto geri;
							
						}
						for(i=0;i<odasil.length();i++)
						{
							if(isdigit(odasil[i])==0)odasilkontrol=true;
							if(odasilkontrol)
							{
								system("cls");
								cout<<"Katar say�s� uyu�muyor.\n";
								cout<<"L�tfen tekrar giri� yap�n�z...";
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
						cout<<"��leminiz ba�ar�yla tamamland�.";
						sleep(2);
						system("cls");
						cout<<"Ana men�ye y�nlendiriliyorsunuz!";
						sleep(2);
						goto back11;
						break;
						
						
						
						
						
						
					
					
					
					case 3:	
						cout<<"    MERT OTEL\nOdaNo  Br�t\n";
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
						cout<<"Ana men�ye y�nlendiriliyorsunuz..";
						sleep(3);
						system("cls");
						goto back11;
						break;
						
					default : 
					system("cls");
					cout<<"��leminiz anla��lamad�.\n��k�� yapmak i�in herhangi bir tu�a bas�n�z!";
					break;
				}//oda se�iminin switchinin bitti�i nokta 
					
					
			
			
			case 2 : //m��teri i�lemleri case inin ba�lang�� noktas�		
				system("cls");
				
				cout<<"    MERT OTEL";
				cout<<"\n1)M��teri Ekle\n";
				cout<<"2)M��teri Sil\n";
				cout<<"3)M��terileri Listele\n";
				cout<<"4)�st men�ye git\n��leminizi se�iniz : ";
				cin>>musterisecim;
				switch(musterisecim)
				{
					case 1:
						beri1:
						system("cls");
						
						cout<<"M��teri Ad : ";
						cin>>musteriad;
						for(i=0;i<musteriad.length();i++)
						{
							if(isalpha(musteriad[i])==0) musteriadkontrol=true;
							if(musteriadkontrol)break;
						}
						if(musteriadkontrol)
						{
							system("cls");
							cout<<"Girmi� oldu�unuz isimde ingilizce karakterler ile uyumsuz karakterler mevcuttur.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							musteriadkontrol=false;
							goto beri1;
						
						}
						beri2:
						system("cls");
						cout<<"M��teri Soyad : ";
						cin>>musterisoyad;
						for(i=0;i<musterisoyad.length();i++)
						{
							if(isalpha(musterisoyad[i])==0) musterisoyadkontrol=true;
							if(musterisoyadkontrol)break;
						}
						if(musterisoyadkontrol)
						{
							system("cls");
							cout<<"Girmi� oldu�unuz soyisimde ingilizce karakterler ile uyumsuz karakterler mevcuttur.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							musterisoyadkontrol=false;
							goto beri2;
						}
						beri3:
						system("cls");
						cout<<"11 Haneli T�rkiye Cumhuriyeti Kimlik Numaras� Tu�lay�n : ";
						cin>>tcno;
						if(tcno.length()!=11) 
						{
							system("cls");
							cout<<"Girmi� oldu�unuz numara 11 haneli de�ildir.\n";
							cout<<"L�tfen tekrar tu�lama yap�n�z...";
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
							cout<<"Girmi� oldu�unuz tu�lamada n�merik olmayan karakterler mevcuttur.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
							sleep(3);
							tcnokontrol=false;
							system("cls");
							goto beri3;
						}
						beri4:
						system("cls");
						cout<<"5 Haneli M��teri numaran�z� tu�lay�n�z : ";
						cin>>musterino;
						if(musterino.length()!=5)
						{
							system("cls");
							cout<<"Yapm�� oldu�unuz tu�lama 5 karakter i�ermemektedir.\n";
							cout<<"L�tfen tekrar giri� yap�n�z...";
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
							cout<<"Yapm�� oldu�unuz tu�lamada n�merik olmayan karakterler mevcuttur.";
							cout<<"\nL�tfen tekrar giri� yap�n�z...";
							sleep(3);
							musterinokontrol=false;
							goto beri4;
						}
						system("cls");
						dosyayaz.open("C:\\Users\\yazar\\Desktop\\musteriKayit.txt",ios::app);
						dosyayaz<<musteriad<<" "<<musterisoyad<<" "<<tcno<<" "<<musterino<<"/"<<"\n";
						dosyayaz.close();
						cout<<"M��teri kaydedildi.";
						sleep(2);
						cout<<"\nAna men�ye d�nmek istiyor musunuz?";
						cout<<"\n1)Evet\n2)Hay�r\n��leminizi se�iniz : ";
						cin>>musterianamenu;
						if(musterianamenu==1)goto back11;
						else 
						{
							system("cls");
							cout<<"Program kapat�ld�.\n��k�� yapmak i�in herhangi bir tu�a bas�n�z!";
						};
						break;
						
					
					
					case 2:
						system("cls");
						cout<<"M��teri Ad : ";
						cin>>musteriad;
						system("cls");
						cout<<"M��teri Soyad : ";
						cin>>musterisoyad;
						system("cls");
						cout<<"T.C. Kimlik Numaras� giriniz : ";
						cin>>tcno;
						system("cls");
						cout<<"M��teri No. giriniz : ";
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
						cout<<"M��teri silme i�lemi ba�ar�yla tamamland�.";
						cout<<"\nAna men�ye d�nmek istiyor musunuz?";
						cout<<"\n1)Evet\n2)Hay�r\n��leminizi se�iniz : ";
						cin>>musterisecim;
						if(musterisecim==1)
						{
							system("cls");
							cout<<"��lem tamamland�.\nAna men�ye y�nlendiriliyorsunuz.";
							sleep(2);
							system("cls");
							goto back11;
						}
						else cout<<"Program kapat�ld�. ��k�� yapmak i�in herhangi bir tu�a bas�n�z.";
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
				cout<<"��k�� yapmak i�in herhangi bir tu�a bas�n�z.";
				break;				
		}
	}
}
