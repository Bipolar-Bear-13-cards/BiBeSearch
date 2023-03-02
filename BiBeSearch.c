#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 struct string { 
 char str[5000]; 
 int l; 
};
struct mans{
	int a;
	struct mans * next;
};
char * my_strcat(char* s, int n){	
	int t=strlen(s);
	for (int i = 0; i < n; i++)
		s[t+i]='#'+i;
	s[t+n]='\0';
	return s;
}

struct mans * bouer (struct string * rex, char * k, int dp){//ìîäèôèöèðîâàííûé àëãîðèòì Áîóåðà - Ìóðà
 struct mans * eins = NULL;
 struct mans * end; //óêàçàòåëè íà ïåðâûé è ïîñëåäíèé ýëåìåíòû ñïèñêà\
 àäðåñîâ ïîäñòðîê, óäîâëåòâîðÿþùèõ óñëîâèþ
 int f = strlen(k); //äëèíà êëþ÷åâîé ñòðîêè
 int n = f - (f * dp / 100 );//ìèíèìàëüíîå ÷èñëî íåñîâïàäàþùèõ ñèìâîëîâ,\
 ïðè êîòîðîì ôèêñèðóåòñÿ íåñîâïàäåíèå.
 int j = f - 1;//èíäåêñ òåêóùåãî ñèìâîëà êëþ÷åâîé ñòðîêè
 int p = f - n; //èíäåêñ òåêóùåãî ñèìâîëà òåêñòà
 int y;//ïåðåìåííàÿ äëÿ êîëè÷åñòâà íåñîâïàâøèõ ñèìâîëîâ\
 òåêóùåé ïîäñòðîêè è êëþ÷åâîé ïîäñòðîêè
 int u; //ïåðåìåííàÿ äëÿ ñìåùåíèÿ êëþ÷åâîé ñòðîêè îòíîñèòåëüíî òåêñòà
 while (p<rex->l+n-1){
  y = 0;
  u = f - (n - 1);
  for (int i = 1; i<=n; i++){
   if (k[j]!=rex->str[p])
    y++;
   for (int e=1; e<u; e++){
    if (rex->str[p]==k[j-e])
	 u = e;
   }
   j--;
   p--;  
  }
  while ((k[j]!='\0')&&(y<n)){
   if (k[j]!=rex->str[p])
    y++;
   j--;
   p--;
  }
  if (y<n){
	  if (eins == NULL){
				eins = (struct mans *)malloc(sizeof(struct mans));
				eins->a = p + 1;
				eins->next = NULL;
				end = eins;
	  }
	  else{
				end->next = (struct mans *)malloc(sizeof(struct mans));
				end->next->a = p + 1;
				end->next->next = NULL;
				end = end->next;
	  }
  }
  p = p + (f - 1 - j) + u;
  j = f - 1;
 }
 return eins;
}

int * prefiks(char * s, int n){
	int t = strlen(s);    
	int * p = (int*)malloc(t*sizeof(int)); //ìàññèâ äëèí ñóôôèêñîâ,\
    èìåþùèõ < n ñîâïàäåíèé 
	int * a = (int*)malloc(t*sizeof(int)); //ìàññèâ êîëëè÷åñòâ ñîâïàäåíèé äëÿ \
	ïîäñòðîê
	for (int e = 0; e < t; e++)//îáíóëåíèå ìàññèâà
		a[e] = 0;
    p[0] = 0;
	int k = 0; //òåêóùèé ýëåìåíò ìàññèâà p
	int j = 0; //òåêóùåå êîëè÷åñòâî íåñîâïàäåíèé
	int y; 
	int r; //ñ÷¸ò÷èêè äëÿ ïðîâåðêè ñóôôèêñà è ïðåôèêñà íà\
    êîëè÷åñòâî ñîâïàäåíèé è íåñîâïàäåíèé â ñëó÷àå èçìåíåíèÿ k âíóòðè\
    öèêëà while
	int g = 0; //òåêóùåå êîëè÷åñòâî ñîâïàäåíèé
	int u = -1; //íîìåð ïîñëåäíåãî ñîâïàäåíèÿ
    for (int i = 1; i < t+n; i++){
	     ((k == 0)&&(j != 0)) ? (j = 0) : 1; 
		 (s[k] != s[i])? j++ : 1;
         while ((k > 0) && (j >= n)){
			((u != -1)&&(p[u+1] != p[p[u]-1] + 1)&&(i != u+1)) ? (i = u + 1, k = p[u]) : 1;
			k = p[k-1];
			j = (s[k]!=s[i])? 1 : 0;
			u = -1;
			if (n != 1){
			    y = 0;
			    r = i - k;
			    g = 0;
				while ((j < n)&&(y <= k-1)){
					(s[y]!=s[r])? j++ : (g++, u = r);
					y++;
					r++;
				}
			}
			else{
                g = k;
                (g != 0) ? (u = i - 1) : 1;		
            }	
		 } 
		 (s[k]==s[i]) ? (g++, u = i) : 1;
          a[i-k] = g;     
		 (j < n) ? k++ : 1;
          p[i] = k;
    }
	free (p);
	return a;
}
struct mans * knut(char * k, struct string * T, int dp){
    struct mans * eins = NULL;
    struct mans * end; //óêàçàòåëè íà ïåðâûé è ïîñëåäíèé ýëåìåíòû ñïèñêà\
    àäðåñîâ ïîäñòðîê, óäîâëåòâîðÿþùèõ óñëîâèþ   
	int pl = strlen(k); //äëèíà êëþ÷åâîé ñòðîêè
	int n = pl - (pl * dp / 100 );//ìèíèìàëüíîå ÷èñëî íåñîâïàäàþùèõ ñèìâîëîâ, \
	ïðè êîòîðîì ôèêñèðóåòñÿ íåñîâïàäåíèå
	char x[pl];
	strcpy(x,k);
    int * p = prefiks(strcat(my_strcat(x, n), T->str), n); //ìàññèâ ðàçìåðîì\
    ñî ñòðîêó, êîòîðàÿ âõîäèò â ôóíêöèþ prefix â êà÷åñòâå ïåðâîãî àðãóìåòà.\
    Ñîäåðæèò êîëëè÷åñòâà ñîâïàäåíèé äëÿ ïîäñòðîê
    for (int i = 0;  i<T->l; i++){
      if (p[pl + i + n] >= pl-n+1){
		if (eins == NULL){
				eins = (struct mans *)malloc(sizeof(struct mans));
				eins->a = i;
				eins->next = NULL;
				end = eins;
	    }
	    else{
				end->next = (struct mans *)malloc(sizeof(struct mans));
				end->next->a = i;
				end->next->next = NULL;
				end = end->next;
	    }
      }
    }
	free (p);
	return eins;
}
int main(int argc, char *argv[]) 
{ 
 struct string * rex; 
 struct mans * eins = NULL;
 struct mans * rexis;
 rex = (struct string *)malloc(sizeof(struct string)); 
 char k[1000]; 
 int dp = 101;
 int b = 1;
 char fn[10];
 FILE *suf;
 int t;
 while (b!=0){ 
  printf("\nvyberite punkt menyu:\n0 - zavershit' programmu\n1 - schitat' \
  dannye iz konsoli\n2 - schitat' dannye iz fajla\n3 - vyvesti\
  vvedyonnyj tekst i klyuchevuyu stroku\n4 - poisk s pomoshch'yu\
  modificirovannogo algoritma Bouera - Mura\n5 - poisk s\
  pomoshch'yu modificirovannogo algoritma Knuta-Morrisa-Pratta\n6 - vyvesti\
  rezul'tiruyushchij spisok adresov v fajl\n");
  scanf("%d",&b);  
  if (b == 1){
         printf ("Vvedite tekst: ");
         scanf("%s", rex->str);
         rex->l = strlen(rex->str);
         while ((dp > 100)||(dp < 0)){
		         printf ("\nVvedite chislo v procentah: ");
		         scanf("%d",&dp);
         }
         printf ("\nVvedite iskomuyu podstroku: ");
         scanf ("%s", k);
         t = strlen (k);
         while ((t * dp / 100) + 1 > rex->l){
		        printf ("\nVvedite iskomuyu podstroku: ");
		        scanf ("%s", k);
                t = strlen (k);
         }
  }
  if (b == 2){
			printf ("\nVvedite imya fajla: ");
			scanf ("%s", fn);
			suf = fopen(fn,"r");
			if (!suf) {
				printf ("error\n"); 
				break;
			}
			if (!fgets (rex->str, sizeof(rex->str),suf)) {
				printf ("error\n"); 
				fclose(suf); 
				break;
			}
			rex->l = strlen(rex->str);
			if (fscanf (suf, "%d\n", &dp) == EOF) {
				printf ("error\n"); 
				fclose(suf); 
				break;
			}
			if (!fgets(k, sizeof(k), suf)) {
				printf ("error\n"); 
				fclose(suf); 
				break;
			}
			if ((dp > 100)||(dp < 0)) {
				printf ("error\n"); 
				fclose(suf); 
				break;
			}
			t = strlen (k);
			if ((t * dp / 100) + 1 > rex->l) {
				printf ("error\n"); 
				fclose(suf); 
				break;
			}
			fclose(suf);
 }
  if (b==3){ 
   printf ("\n%s",rex->str); 
   printf ("\n%s",k); 
  }
  if (b==4){
         eins = bouer(rex,k,dp);
         rexis = eins;
         while (rexis!=NULL){
				printf("\nadres %d", rexis->a);
				rexis = rexis->next;
         }
  }
  if (b==5){   
		 printf ("Prover'te, chtoby vo vvedyonnyh vami strokah ne bylo sleduyushchih\
         simvolov: ");
         printf ("%c", '#');
         for (int i = 1; i < (t - (t * dp / 100 )); i++)
	        printf(", %c",'#'+i);
         printf ("\n");     
		 eins = knut(k, rex, dp);
		 rexis = eins;
         while (rexis!=NULL){
				printf("\nadres %d", rexis->a);
				rexis = rexis->next;
         }
  }
  if (b == 6){
		  printf ("\nVvedite imya fajla: ");
		  scanf ("%s", fn);
		  suf = fopen(fn,"w");
		  if (!suf) {
				printf ("error\n"); 
				break;
		  }
		  rexis = eins;
		  while (rexis!=NULL){
				fprintf(suf, "adres %d\n", rexis->a);
				rexis = rexis->next;
         }
		 fclose (suf);
  }
 } 
 while (eins!=NULL){
	 rexis = eins;
	 eins = eins->next;
	 free (rexis);
 }
 return 0;
}
