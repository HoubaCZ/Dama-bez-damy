#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int vlastni_figurka_c(int figurky[], int po){	//tato funkce slou�� ke zji�t�n� zde figurka, kterou chce u�ivatel vy�adit je stejn� s jakou hraje on
	int back=0;
	for(int i = 8;i<16;i++){
		if(figurky[i]==po){
			back = 1;
		}	
	}
	return back;
}
int vlastni_figurka_b(int figurky[], int po){	//tato funkce slou�� ke zji�t�n� zde figurka, kterou chce u�ivatel vy�adit je stejn� s jakou hraje on
	int back=0;
	for(int i = 0;i<8;i++){
		if(figurky[i]==po){
			back = 1;
		}	
	}
	return back;
}
int hraci_pole_f(int figurky[], int pred, int pohnuti){
	int ven = 0;
	int okraj1[] = {5,13,21,29,1,9,17,25}, okraj2[] = {4,12,20,28,8,16,24,32};				//Hodnoty okraj�
	for(int i = 0; i<8; i++){ 					
				if(okraj1[i] == pred){
					for(int j = 0; j<8; j++){
						if(okraj2[j] == figurky[pohnuti]){
							ven = 1;
					}
					}
				}
				if(okraj2[i] == pred){
					for(int j = 0; j<8; j++){
						if(okraj1[j] == figurky[pohnuti]){
							ven = 1;
					}
					}
			}
			}
	return ven;
}
int misto_obsazene_f(int figurky[], int po){
	int misto_obsazene = 0;
	for(int i = 0; i<16;i++){
		if(figurky[i]==po) misto_obsazene = 1;
	}
	return misto_obsazene;
}
int vyrazeni_b(int sude_liche, int figurka, int pohnuti){ 	//tato funkce slou�� k vypoctu toho kam se ma figurka posunout
	if(sude_liche%2==0){					
				if(pohnuti == 1){
					figurka -= 5;
					return figurka;
				}
				else if(pohnuti == 2){
					figurka -= 4;
					return figurka;
				}
			}
	else if(sude_liche%2==1){
				if(pohnuti == 1){
					figurka -= 4;
					return figurka;
				}
				else if(pohnuti == 2){
					figurka -= 3;
					return figurka;
				}
			}
}
int vyrazeni_c(int sude_liche, int figurka, int pohnuti){	//tato funkce slou�� k vypoctu toho kam se ma figurka posunout
	if(sude_liche%2==0){					
				if(pohnuti == 1){
					figurka += 3;
					return figurka;
				}
				else if(pohnuti == 2){
					figurka += 4;
					return figurka;
				}
			}
	else if(sude_liche%2==1){
				if(pohnuti == 1){
					figurka += 4;
					return figurka;
				}
				else if(pohnuti == 2){
					figurka += 5;
					return figurka;
				}
			}
}
int sudealiche(int pozice){ //tato funkce je pro ur�en� sud�ho a lich�ho ��dku pro spr�vn� pohnut� figurkou
	int sude_liche;
	if(pozice>=1 and pozice<=4){
				sude_liche=1;
			}
	if(pozice>=5 and pozice<=8){
				sude_liche=2;
			}
	if(pozice>=9 and pozice<=12){
				sude_liche=1;
			}
	if(pozice>=13 and pozice<=16){
				sude_liche=2;
			}
	if(pozice>=17 and pozice<=20){
				sude_liche=1;
			}
	if(pozice>=21 and pozice<=24){
				sude_liche=2;
			}
	if(pozice>=25 and pozice<=28){
				sude_liche=1;
			}
	if(pozice>=29 and pozice<=32){
				sude_liche=2;
			}
	return sude_liche;
}
int main(){
	
	int figurky[] = {25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8};	//pole pro v�echny figurky 0-7 b�l� 8-15 �ern�
	int figurky_z[] = {29,30,31,32,1,2,3,4};//p�vodn� m�sta v�ech figurek
	int pozice=0;    											//prom�nn� ve kter� je ur�eno kter� pozice se moment�ln� printuje
	int pohnuti=0;												//prom�nn� kde je ulo�eno jakou figurkou chce hr�� pohnout
	int pohnuti_policko=0;										//prom�nn� kde je ulo�eno kam se hr�� chce pohnout
	int pred=0, po=0, x=0, y=0;									//pomocn� prom�nn�
	int pohnuti_rozhodnuti, misto_obsazene;						//pomocn� prom�nn�
	int bile_cerne=1; 											//prom�nn� co st��d� b�l�ho a �ern�ho hr��e
	int rozhodnuti_hra=0;										//prom�nn� pro vybr�n� hry
	int konec_b[] = {1,2,3,4};									//konec �achovnice z pohledu b�l�ch
	int konec_c[] = {29,30,31,32};								//konec �achovnice z pohledu �ern�ch
	int body_b=0, body_c=0, figurky_b=0, figurky_c=0;			//prom�nn� pro po�et bod�
	int pocet_figurek_b=0, pocet_figurek_c=0;	
	int figurky_pred;											//pomocn� prom�nn� pro spr�vn� po��t�n� kolik figurek je vy�azen�ch
	
	pred_rozhodnuti_hra:
	printf("Chcete hrat normalne, 1, nebo na body, 2?");
	scanf("%d", &rozhodnuti_hra);
	if(rozhodnuti_hra != 1 and rozhodnuti_hra != 2) goto pred_rozhodnuti_hra;
	
	
	

start:
	system("cls");
	if(rozhodnuti_hra==2){
		printf("Hrac bily ma: %d bodu.\n",body_b);
		printf("Hrac cerny ma: %d bodu.\n\n",body_c);
	}
	for(int j=0;j<4;j++){										//for loop printuje hrac� pole + figurky na spr�vn�m m�st�
	
		for(int i=0;i<4;i++){
			pozice++;
			printf("%c%c", 178,178);
			if(pozice==figurky[8]){
				printf("c1");
				goto skip;
			}
			if(pozice==figurky[9]){
				printf("c2");
				goto skip;
			}
			if(pozice==figurky[10]){
				printf("c3");
				goto skip;
			}
			if(pozice==figurky[11]){
				printf("c4");
				goto skip;
			}
			if(pozice==figurky[12]){
				printf("c5");
				goto skip;
			}
			if(pozice==figurky[13]){
				printf("c6");
				goto skip;
			}
			if(pozice==figurky[14]){
				printf("c7");
				goto skip;
			}
			if(pozice==figurky[15]){
				printf("c8");
				goto skip;
			}
			if(pozice==figurky[0]){
				printf("b1");
				goto skip;
			}
			if(pozice==figurky[1]){
				printf("b2");
				goto skip;
			}
			if(pozice==figurky[2]){
				printf("b3");
				goto skip;
			}
			if(pozice==figurky[3]){
				printf("b4");
				goto skip;
			}
			if(pozice==figurky[4]){
				printf("b5");
				goto skip;
			}
			if(pozice==figurky[5]){
				printf("b6");
				goto skip;
			}
			if(pozice==figurky[6]){
				printf("b7");
				goto skip;
			}
			if(pozice==figurky[7]){
				printf("b8");
				goto skip;
			}
			printf("  ");
		skip:;
		}
		
		printf("\n");
		
		for(int i=0;i<4;i++){
			pozice++;
			if(pozice==figurky[8]){
				printf("c1");
				goto skip1;
			}
			if(pozice==figurky[9]){
				printf("c2");
				goto skip1;
			}
			if(pozice==figurky[10]){
				printf("c3");
				goto skip1;
			}
			if(pozice==figurky[11]){
				printf("c4");
				goto skip1;
			}
			if(pozice==figurky[12]){
				printf("c5");
				goto skip1;
			}
			if(pozice==figurky[13]){
				printf("c6");
				goto skip1;
			}
			if(pozice==figurky[14]){
				printf("c7");
				goto skip1;
			}
			if(pozice==figurky[15]){
				printf("c8");
				goto skip1;
			}
			if(pozice==figurky[0]){
				printf("b1");
				goto skip1;
			}
			if(pozice==figurky[1]){
				printf("b2");
				goto skip1;
			}
			if(pozice==figurky[2]){
				printf("b3");
				goto skip1;
			}
			if(pozice==figurky[3]){
				printf("b4");
				goto skip1;
			}
			if(pozice==figurky[4]){
				printf("b5");
				goto skip1;
			}
			if(pozice==figurky[5]){
				printf("b6");
				goto skip1;
			}
			if(pozice==figurky[6]){
				printf("b7");
				goto skip1;
			}
			if(pozice==figurky[7]){
				printf("b8");
				goto skip1;
			}
			printf("  ");
			skip1:
			printf("%c%c", 178,178);
			
		}
		
			printf("\n");
			
	}
	printf("\n");
	printf("\n");
	
	if(rozhodnuti_hra==1){		//hra 1
		pred:;
		
		if(bile_cerne==1){												//pohyb pro b�l� figurky
			printf("Jakou figurkou chcete pohnout?(1 pro b1,2 pro b2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti--;
			
			if(figurky[pohnuti]<-8){
					printf("Figurka je vyrazena.\n");
					goto pred;
				}
				
			if(pohnuti>-1 and pohnuti<8);							//kontra v�b�ru spr�vn� figurky
			else{
				printf("Spatna figurka\n");
				goto pred;
			} 
		
			pred = figurky[pohnuti];
	
			printf("Chcete se pohnout, vyradit figurku, nebo vratit zpet na druhou stranu sachovnice (zadejte 1 pro pohnuti, 2 pro vyrazeni a 3 pro vraceni zpet.)");
			scanf("%d", &pohnuti_rozhodnuti);
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral spr�vn�
				printf("\nSpatne zadana hodnota.\n");
				goto pred;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){											//Norm�ln� pohnut�
	
				printf("Na jake policko chcete pohnout? Doleva nahoru 1, doprava nahoru 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral spr�vn�
					printf("Spatne zadana hodnota.\n");
					goto pred;
				} 
			
				po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
					printf("Misto kam se chcete pohnout je obsazene\n");				//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
					figurky[pohnuti] = pred;
					goto pred;
				}
			
				figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
	
				if(hraci_pole_f(figurky, pred, pohnuti) == 1){
					printf("Figurka nemuze odejit z hraciho pole.\n");
					figurky[pohnuti] = pred;
					goto pred;	
				}
				if(figurky[pohnuti]<=0){
					printf("Nemuzete odejit z hraciho pole.\n");
					figurky[pohnuti]=pred;
					goto pred;
				}
				
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
				for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_1;
					
				}
//***************************************************************************************************************************************
				else if(pohnuti_rozhodnuti==2){							//Vy�azov�n� figurek
					printf("Na jakem policku je figurka co chcete vyradit? Doleva nahoru 1, nebo doprava nahoru 2.");
					scanf("%d", &pohnuti_policko);
					po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
					
					if(misto_obsazene_f(figurky, po) == 1){
						if(vlastni_figurka_b(figurky,po)==1){
							printf("Nemuzete vyradit vlastni figurku.\n");
							goto pred;
						}
						figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(misto_obsazene_f(figurky, vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko)) == 1){
							printf("Za figurkou co chcete vyradit se nachazi dalsi figurka\n");
							figurky[pohnuti] = pred;
							goto pred;
						}
						figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(hraci_pole_f(figurky, pred, pohnuti) == 1){
							printf("Figurka nemuze odejit z hraciho pole.\n");
							figurky[pohnuti] = pred;
							goto pred;	
						}
				
						for(int i = 8; i<16; i++){						//loop zkontroluje jestli je na policku figurka bilych a pokud ano tak nastavi jeji hodnotu na -10, 
							if(figurky[i]==po) figurky[i]=-10;			//co� ji vy�ad� z �achovnice
						}

					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
				for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_1;
					
				}
//***************************************************************************************************************************************				
				else{
					po = figurky[pohnuti]+28;
					if(po>32){
						printf("Nemuzete se vratit, kdyz nejste na konci.\n");
						goto pred;
					}
					if(misto_obsazene_f(figurky, po) == 1){										//pokud je pol��ko kam se chce hr�� pohnout obsazen�
						printf("Nemuzete se vratit, protoze misto je obsazene\n");				//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]+28;
				}
			
			bile_cerne++;
		}
//***************************************************************************************************************************************		
		else{ 															//pohyb pro �ern� figurky
			printf("Jakou figurkou chcete pohnout?(1 pro c1,2 pro c2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti+=7;
			pred = figurky[pohnuti];
			
			if(figurky[pohnuti]<-8){
					printf("Figurka je vyrazena.\n");
					goto pred;
				}
				
			if(pohnuti>7 and pohnuti<16);
			else{
				printf("Spatna figurka\n");
				goto pred;
			} 
		
			printf("Chcete se pohnout, vyradit figurku, nebo vratit zpet na druhou stranu sachovnice (zadejte 1 pro pohnuti, 2 pro vyrazeni a 3 pro vraceni zpet.)");
			scanf("%d", &pohnuti_rozhodnuti);
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral spr�vn�
				printf("\nSpatne zadana hodnota.\n");
				goto pred;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){
	
				printf("Na jake policko chcete pohnout? Doleva dolu 1, doprava dolu 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral spr�vn�
					printf("Spatne zadana hodnota.\n");
					goto pred;
				} 
			
				po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
					printf("Misto kam se chcete pohnout je obsazene\n");				//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
					figurky[pohnuti] = pred;
					goto pred;
				}
			
				figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
	
				if(hraci_pole_f(figurky, pred, pohnuti) == 1){
				printf("Figurka nemuze odejit z hraciho pole.\n");
				figurky[pohnuti] = pred;
				goto pred;	
				}
				if(figurky[pohnuti]>32){
					printf("Nemuzete odejit z hraciho pole.\n");
					goto pred;
				}
				
				
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
				for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_1;
					
				}
//***************************************************************************************************************************************	
				else if(pohnuti_rozhodnuti==2){								//vy�azov�n� figurek
					printf("Na jakem policku je figurka co chcete vyradit? Doleva dolu 1, nebo doprava dolu 2.");
					scanf("%d", &pohnuti_policko);
					po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
					
					if(misto_obsazene_f(figurky, po) == 1){
						if(vlastni_figurka_c(figurky,po)==1){
							printf("Nemuzete vyradit vlastni figurku.\n");
							goto pred;
						}
						figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(misto_obsazene_f(figurky, vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko)) == 1){
							printf("Za figurkou co chcete vyradit se nachazi dalsi figurka\n");
							figurky[pohnuti] = pred;
							goto pred;
						}
						figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(hraci_pole_f(figurky, pred, pohnuti) == 1){
							printf("Figurka nemuze odejit z hraciho pole.\n");
							figurky[pohnuti] = pred;
							goto pred;	
						}
					
						for(int i = 0; i<8; i++){						//loop zkontroluje jestli je na policku figurka cernych a pokud ano tak nastavi jeji hodnotu na -10, 
							if(figurky[i]==po) figurky[i]=-10;			//co� ji vy�ad� z �achovnice
						}
					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
				for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_1;
						
				}
//***************************************************************************************************************************************	
				else{
					po = figurky[pohnuti]-28;
					if(po<1){
						printf("Nemuzete se vratit, kdyz nejste na konci.\n");
						goto pred;
					}
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]-28;
				}
			bile_cerne--;
		}
		}
	
//***************************************************************************************************************************************	
//***************************************************************************************************************************************
//***************************************************************************************************************************************
	
	else{						//hra 2
		pred_2:;
		
	
		if(bile_cerne==1){											//pohyb pro b�l� figurky
			printf("Jakou figurkou chcete pohnout?(1 pro b1,2 pro b2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti--;
		
			if(pohnuti>-1 and pohnuti<8);							//kontra v�b�ru spr�vn� figurky
			else{
				printf("Spatna figurka\n");
				goto pred_2;
			}
				if(figurky[pohnuti]<-8){
					printf("Figurka je vyrazena.\n");
					goto pred_2;
				}

			pred = figurky[pohnuti];
	
			printf("Chcete se pohnout, vyradit figurku, nebo vratit zpet na druhou stranu sachovnice (zadejte 1 pro pohnuti, 2 pro vyrazeni a 3 pro vraceni zpet.)");
			scanf("%d", &pohnuti_rozhodnuti);
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral spr�vn�
				printf("\nSpatne zadana hodnota.\n");
				goto pred_2;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){											//Norm�ln� pohnut�
	
				printf("Na jake policko chcete pohnout? Doleva nahoru 1, doprava nahoru 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral spr�vn�
					printf("Spatne zadana hodnota.\n");
					goto pred_2;
				} 
			
				po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
					printf("Misto kam se chcete pohnout je obsazene\n");				//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
					figurky[pohnuti] = pred;
					goto pred_2;
				}
			
				figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
	
				if(hraci_pole_f(figurky, pred, pohnuti) == 1){
					printf("Figurka nemuze odejit z hraciho pole.\n");
					figurky[pohnuti] = pred;
					goto pred_2;	
				}
				if(figurky[pohnuti]<=0){
					printf("Nemuzete odejit z hraciho pole.\n");
					figurky[pohnuti]=pred;
					goto pred_2;
				}
				
				
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
					for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_2;
					

				}
//***************************************************************************************************************************************				
				else if(pohnuti_rozhodnuti==2){
					printf("Na jakem policku je figurka co chcete vyradit? Doleva nahoru 1, nebo doprava nahoru 2.");
					scanf("%d", &pohnuti_policko);
					po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
					
					if(misto_obsazene_f(figurky, po) == 1){
						if(vlastni_figurka_b(figurky,po)==1){
							printf("Nemuzete vyradit vlastni figurku.\n");
							goto pred_2;
						}
						figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(misto_obsazene_f(figurky, vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko)) == 1){
							printf("Za figurkou co chcete vyradit se nachazi dalsi figurka\n");
							figurky[pohnuti] = pred;
							goto pred_2;
						}
						figurky[pohnuti] = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(hraci_pole_f(figurky, pred, pohnuti) == 1){
							printf("Figurka nemuze odejit z hraciho pole.\n");
							figurky[pohnuti] = pred;
							goto pred_2;	
						}
				
						for(int i = 8; i<16; i++){						//loop zkontroluje jestli je na policku figurka bilych a pokud ano tak nastavi jeji hodnotu na -10, 
							if(figurky[i]==po) figurky[i]=-10;			//co� ji vy�ad� z �achovnice
						}

					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred_2;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
					for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_2;
					
				}
//***************************************************************************************************************************************
				else{
					po = figurky[pohnuti]+28;
					if(po>32){
						printf("Nemuzete se vratit, kdyz nejste na konci.\n");
						goto pred;
					}
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]+28;
					body_b++;
				}
			
			bile_cerne++;
		}

//***************************************************************************************************************************************
		else{ 															//pohyb pro �ern� figurky
			printf("Jakou figurkou chcete pohnout?(1 pro c1,2 pro c2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti+=7;
			pred = figurky[pohnuti];
			
			if(figurky[pohnuti]<-8){
					printf("Figurka je vyrazena.\n");
					goto pred_2;
				}
				
			if(pohnuti>7 and pohnuti<16);
			else{
				printf("Spatna figurka\n");
				goto pred_2;
			} 
		
			printf("Chcete se pohnout, vyradit figurku, nebo vratit zpet na druhou stranu sachovnice (zadejte 1 pro pohnuti, 2 pro vyrazeni a 3 pro vraceni zpet.)");
			scanf("%d", &pohnuti_rozhodnuti);
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral spr�vn�
				printf("\nSpatne zadana hodnota.\n");
				goto pred_2;
			} 
		
//***************************************************************************************************************************************
			if(pohnuti_rozhodnuti == 1){
	
				printf("Na jake policko chcete pohnout? Doleva dolu 1, doprava dolu 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral spr�vn�
					printf("Spatne zadana hodnota.\n");
					goto pred_2;
				} 
			
				po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
					printf("Misto kam se chcete pohnout je obsazene\n");				//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
					figurky[pohnuti] = pred;
					goto pred_2;
				}
			
				figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
	
				if(hraci_pole_f(figurky, pred, pohnuti) == 1){
				printf("Figurka nemuze odejit z hraciho pole.\n");
				figurky[pohnuti] = pred;
				goto pred_2;	
				}
				if(figurky[pohnuti]>32){
					printf("Nemuzete odejit z hraciho pole.\n");
					goto pred_2;
				}
				
				
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
					for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_2;
					
				}
//***************************************************************************************************************************************
				else if(pohnuti_rozhodnuti==2){								//vy�azov�n� figurek
					printf("Na jakem policku je figurka co chcete vyradit? Doleva dolu 1, nebo doprava dolu 2.");
					scanf("%d", &pohnuti_policko);
					po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
					
					if(misto_obsazene_f(figurky, po) == 1){
						if(vlastni_figurka_c(figurky,po)==1){
							printf("Nemuzete vyradit vlastni figurku.\n");
							goto pred_2;
						}
						figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(misto_obsazene_f(figurky, vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko)) == 1){
							printf("Za figurkou co chcete vyradit se nachazi dalsi figurka\n");
							figurky[pohnuti] = pred;
							goto pred_2;
						}
						figurky[pohnuti] = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
						if(hraci_pole_f(figurky, pred, pohnuti) == 1){
							printf("Figurka nemuze odejit z hraciho pole.\n");
							figurky[pohnuti] = pred;
							goto pred_2;	
						}
					
						for(int i = 0; i<8; i++){						//loop zkontroluje jestli je na policku figurka cernych a pokud ano tak nastavi jeji hodnotu na -10, 
							if(figurky[i]==po) figurky[i]=-10;			//co� ji vy�ad� z �achovnice
						}
					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred_2;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zb�v� figurek, pro ukon�en� hry
						if(figurky[i]<-8) pocet_figurek_b++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
				figurky_pred=pocet_figurek_c;
				pocet_figurek_c=0;
					for(int i = 8;i<16;i++){
						if(figurky[i]<-8) pocet_figurek_c++;
						if(pocet_figurek_b<pred) pred=pocet_figurek_b;
					}
					if(pocet_figurek_b>= 8 or pocet_figurek_c>= 8) goto konec_hry_2;	
				}
//***************************************************************************************************************************************
				else{
					po = figurky[pohnuti]-28;
					if(po<1){
						printf("Nemuzete se vratit, kdyz nejste na konci.\n");
						goto pred;
					}
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je pol��ko kam se chce hr�� pohnout obsazen�
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hr�� se vr�t� zp�t k v�b�ru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]-28;
					body_c++;
				}
			bile_cerne--;
		}
		}
		
	
	pozice=0; //dulezite
	
	goto start;
	
	konec_hry_2:;
	system("cls");
	printf("Hra byla dokoncena.\n", body_b, body_c);
	if(body_b>body_c) printf("K viteztvi gratulujeme bilemu hraci.\n");
	else printf("K viteztvi gratulujeme cernemu hraci.\n");
	system("PAUSE");
	
	
	
	
	konec_hry_1:;
	system("cls");
	printf("Hra byla dokoncena.\n");
	if(pocet_figurek_b >= 8){
		printf("K viteztvi gratulujeme cernemu hraci.\n");
	}
	if(pocet_figurek_c >= 8){
		printf("K viteztvi gratulujeme bilemu hraci.\n");
	}
	system("PAUSE");
}  // KONEC MAINU
