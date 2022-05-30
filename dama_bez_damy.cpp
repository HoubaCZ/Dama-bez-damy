#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int vlastni_figurka_c(int figurky[], int po){	//tato funkce slouží ke zjištìní zde figurka, kterou chce uživatel vyøadit je stejná s jakou hraje on
	int back=0;
	for(int i = 8;i<16;i++){
		if(figurky[i]==po){
			back = 1;
		}	
	}
	return back;
}
int vlastni_figurka_b(int figurky[], int po){	//tato funkce slouží ke zjištìní zde figurka, kterou chce uživatel vyøadit je stejná s jakou hraje on
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
	int okraj1[] = {5,13,21,29,1,9,17,25}, okraj2[] = {4,12,20,28,8,16,24,32};				//Hodnoty okrajù
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
int vyrazeni_b(int sude_liche, int figurka, int pohnuti){ 	//tato funkce slouží k vypoctu toho kam se ma figurka posunout
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
int vyrazeni_c(int sude_liche, int figurka, int pohnuti){	//tato funkce slouží k vypoctu toho kam se ma figurka posunout
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
int sudealiche(int pozice){ //tato funkce je pro urèení sudého a lichého øádku pro správné pohnutí figurkou
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
	
	int figurky[] = {25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8};	//pole pro všechny figurky 0-7 bílé 8-15 èerné
	int figurky_z[] = {29,30,31,32,1,2,3,4};//pùvodní místa všech figurek
	int pozice=0;    											//promìnná ve které je urèeno které pozice se momentálnì printuje
	int pohnuti=0;												//promìnná kde je uloženo jakou figurkou chce hráï pohnout
	int pohnuti_policko=0;										//promìnná kde je uloženo kam se hráè chce pohnout
	int pred=0, po=0, x=0, y=0;									//pomocné promìnné
	int pohnuti_rozhodnuti, misto_obsazene;						//pomocné promìnné
	int bile_cerne=1; 											//promìnná co støídá bílého a èerného hráèe
	int rozhodnuti_hra=0;										//promìnná pro vybrání hry
	int konec_b[] = {1,2,3,4};									//konec šachovnice z pohledu bílých
	int konec_c[] = {29,30,31,32};								//konec šachovnice z pohledu èerných
	int body_b=0, body_c=0, figurky_b=0, figurky_c=0;			//promìnné pro poèet bodù
	int pocet_figurek_b=0, pocet_figurek_c=0;	
	int figurky_pred;											//pomocná promìnná pro správné poèítání kolik figurek je vyøazených
	
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
	for(int j=0;j<4;j++){										//for loop printuje hrací pole + figurky na správném místì
	
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
		
		if(bile_cerne==1){												//pohyb pro bílé figurky
			printf("Jakou figurkou chcete pohnout?(1 pro b1,2 pro b2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti--;
			
			if(figurky[pohnuti]<-8){
					printf("Figurka je vyrazena.\n");
					goto pred;
				}
				
			if(pohnuti>-1 and pohnuti<8);							//kontra výbìru správné figurky
			else{
				printf("Spatna figurka\n");
				goto pred;
			} 
		
			pred = figurky[pohnuti];
	
			printf("Chcete se pohnout, vyradit figurku, nebo vratit zpet na druhou stranu sachovnice (zadejte 1 pro pohnuti, 2 pro vyrazeni a 3 pro vraceni zpet.)");
			scanf("%d", &pohnuti_rozhodnuti);
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral správnì
				printf("\nSpatne zadana hodnota.\n");
				goto pred;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){											//Normální pohnutí
	
				printf("Na jake policko chcete pohnout? Doleva nahoru 1, doprava nahoru 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral správnì
					printf("Spatne zadana hodnota.\n");
					goto pred;
				} 
			
				po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
					printf("Misto kam se chcete pohnout je obsazene\n");				//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
				else if(pohnuti_rozhodnuti==2){							//Vyøazování figurek
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
							if(figurky[i]==po) figurky[i]=-10;			//což ji vyøadí z šachovnice
						}

					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
					if(misto_obsazene_f(figurky, po) == 1){										//pokud je políèko kam se chce hráè pohnout obsazené
						printf("Nemuzete se vratit, protoze misto je obsazene\n");				//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]+28;
				}
			
			bile_cerne++;
		}
//***************************************************************************************************************************************		
		else{ 															//pohyb pro èerné figurky
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
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral správnì
				printf("\nSpatne zadana hodnota.\n");
				goto pred;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){
	
				printf("Na jake policko chcete pohnout? Doleva dolu 1, doprava dolu 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral správnì
					printf("Spatne zadana hodnota.\n");
					goto pred;
				} 
			
				po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
					printf("Misto kam se chcete pohnout je obsazene\n");				//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
				else if(pohnuti_rozhodnuti==2){								//vyøazování figurek
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
							if(figurky[i]==po) figurky[i]=-10;			//což ji vyøadí z šachovnice
						}
					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
		
	
		if(bile_cerne==1){											//pohyb pro bílé figurky
			printf("Jakou figurkou chcete pohnout?(1 pro b1,2 pro b2 atd.)");
			scanf("%d",&pohnuti);
			pohnuti--;
		
			if(pohnuti>-1 and pohnuti<8);							//kontra výbìru správné figurky
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
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral správnì
				printf("\nSpatne zadana hodnota.\n");
				goto pred_2;
			} 
//***************************************************************************************************************************************				
			if(pohnuti_rozhodnuti == 1){											//Normální pohnutí
	
				printf("Na jake policko chcete pohnout? Doleva nahoru 1, doprava nahoru 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral správnì
					printf("Spatne zadana hodnota.\n");
					goto pred_2;
				} 
			
				po = vyrazeni_b(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
					printf("Misto kam se chcete pohnout je obsazene\n");				//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
							if(figurky[i]==po) figurky[i]=-10;			//což ji vyøadí z šachovnice
						}

					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred_2;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
						figurky[pohnuti] = pred;
						goto pred;
					}
					figurky[pohnuti]=figurky[pohnuti]+28;
					body_b++;
				}
			
			bile_cerne++;
		}

//***************************************************************************************************************************************
		else{ 															//pohyb pro èerné figurky
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
			
			if(pohnuti_rozhodnuti != 1 and pohnuti_rozhodnuti != 2 and pohnuti_rozhodnuti != 3){			//kontrola jestli uzivatel vybral správnì
				printf("\nSpatne zadana hodnota.\n");
				goto pred_2;
			} 
		
//***************************************************************************************************************************************
			if(pohnuti_rozhodnuti == 1){
	
				printf("Na jake policko chcete pohnout? Doleva dolu 1, doprava dolu 2, pro vaceni zpet zadejte jakekoli jine cislo.");
				scanf("%d", &pohnuti_policko);
			                                      
				if(pohnuti_policko != 1 and pohnuti_policko != 2){					//kontrola jestli uzivatel vybral správnì
					printf("Spatne zadana hodnota.\n");
					goto pred_2;
				} 
			
				po = vyrazeni_c(sudealiche(figurky[pohnuti]),figurky[pohnuti],pohnuti_policko);
				
				if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
					printf("Misto kam se chcete pohnout je obsazene\n");				//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
				else if(pohnuti_rozhodnuti==2){								//vyøazování figurek
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
							if(figurky[i]==po) figurky[i]=-10;			//což ji vyøadí z šachovnice
						}
					}
					else{
						printf("Na tomto policku zadna figurka neni.\n");
						goto pred_2;
					}
					
					
				figurky_pred=pocet_figurek_b;
				pocet_figurek_b=0;
				for(int i = 0;i<8;i++){											//kontrola kolik zbývá figurek, pro ukonèení hry
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
					if(misto_obsazene_f(figurky, po) == 1){									//pokud je políèko kam se chce hráè pohnout obsazené
						printf("Nemuzete se vratit, protoze misto je obsazene\n");			//hráè se vrátí zpìt k výbìru toho, kam se chce pohnout
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
