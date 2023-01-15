/***********************************************************************************************************/
/* ESAME DI PROGRAMMAZIONE PROCEDURALE - SESSIONE INVERNALE 2022/2023					   */
/*													   */
/* Programma che, in base alla scelta eseguita dall'utente, esegue le congetture di Beal, Collatz e Cramer */
/*                                                                                                         */
/* Autori: Biagi Alessio (Matricola: 322735) e Fabbri Nicole (Matricola: 321119)                           */
/***********************************************************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/********************************/
/* Dichiarazione delle funzioni */
/********************************/

int leggi_scelta(int);
int beal(void);
int collatz(void);
int cramer(void);
int numprimo(int);


/***********************************/
/* Definizione delle funzioni      */
/***********************************/

/* Definizione della funzione main */
int main()
{
	/* Dichiarazione delle variabili locali alla funzione */
	int scelta = 0,	/* Input: valore corrispondente alla scelta della congettura effettuata dall'utente. 				 */
	    opzione;	/* Lavoro: variabile che memorizza il valore di input 'scelta' e permette di selezionare l'opzione nello switch. */

	/* Acquisizione della scelta della congettura dell'utente */
	opzione = leggi_scelta(scelta);

	/* Selezione della congettura */
	switch(opzione)
	{
		 case 1:
		 /*Congettura di Beal*/
		 {
		 	beal();
		 	break;
		 }
		 case 2:
		 /*Congettura di Collatz*/
		 {
			collatz();
		 	break;
		 }

		 case 3:
		 /*Congettura di Cramer*/
		 {
		     cramer();
		     break;	 
		 }
    	}
return(0);
}

/* Definizione della funzione per leggere la scelta effettuata dall'utente */
int leggi_scelta(int scelta)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int esito_lettura, 		 /*Lavoro: esito della scanf.	 	        */
	    acquisizione_errata;	 /*Lavoro: esito complessivo dell'acquisizione. */
	
	/* Richiesta della scelta dell'utente */
	do
	{
		printf("Quale congettura vuoi verificare? \n");
		printf("1. Congettura di Beal \n");
		printf("2. Congettura di Collatz \n");
		printf("3. Congettura di Cramer \n");
		printf("Inserisci il numero della congettura desiderata: ");
		esito_lettura = scanf("%d",
		                      &scelta);
		
		/* Validazione stretta del valore inserito */
		acquisizione_errata = esito_lettura = scelta>3;
		if(acquisizione_errata)
			printf("Il valore inserito non è valido \n");
	 	while (getchar() !='\n');
	}
	while(acquisizione_errata);

return(scelta);
}

/*Definizione della funzione per eseguire la congettura di Beal*/
int beal(void)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int  parametri[5], 		/* Input:  array contenente i parametri dell'espressione.   */
             esito_lettura,		/* Lavoro: esito della scanf. 			      	    */
             acquisizione_errata,	/* Lavoro: esito complessivo dell'acquisizione. 	    */
             c_parametri,		/* Lavoro: contatore dei parametri dell'espressione.        */
	     c_primi,			/* Lavoro: contatore dei numeri primi.                      */
             fatt_primi = 0;		/* Output: fattore primo in comune. 			    */
	char elementi[6] = {'a',
                            'b',
                            'c',
                            'x',
                            'y',
                            'z'};	/* Output: messaggio della posizione corrente dell'array.    */
	

	/* Inserimento dei dati. */
	for(c_parametri = 0;
            c_parametri < 6;
            c_parametri++)
    	{
		do 
		{
			if(c_parametri <=2)
				printf("Digita il valore %c >=1: ",
                        	       elementi[c_parametri]);	
			else
               	 		printf("Digita il valore %c >=3: ",
                        	       elementi[c_parametri]);
                        
			esito_lettura = scanf("%d",
                                   	      &parametri[c_parametri]);
                        

	      		/* Validazione stretta dei valori inseriti */	
			if(c_parametri == 0 || c_parametri<=2)
				acquisizione_errata = esito_lettura !=1 || parametri[c_parametri]<1;
			else
				acquisizione_errata = esito_lettura !=1 || parametri[c_parametri]<3;
			
			if(acquisizione_errata)
				printf("Valore non accettabile \n");
			while(getchar() != '\n');
        	}
		while (acquisizione_errata);
    	}

	/* Ricerca del fattore primo in comune */
	for(c_primi =1 ; 
	    c_primi <= parametri[0] && 
	    c_primi <= parametri[1] && 
	    c_primi <= parametri[2]; 
	    c_primi++)
	{
		if(parametri[0] % c_primi ==0 && 
	           parametri[1] % c_primi ==0 && 
		   parametri[2] % c_primi ==0)
			fatt_primi = c_primi;
	    
	}

	/* Communicazione degli esiti all'utente */
	if(pow(parametri[0],parametri[3])+pow(parametri[1],parametri[4])==pow(parametri[2],parametri[5]))
		printf("La congettura di Beal è verificata. \nIl fattore comune tra %d, %d e %d è: %d\n",
	               parametri[0], parametri[1], parametri[2], fatt_primi);

	else
		printf("La congettura di Beal non è verificata \nIl fattore comune tra %d, %d e %d è: %d\n",
	               parametri[0], parametri[1], parametri[2], fatt_primi);

return(0);
}

/*Definizione della funzione per eseguire la congettura di Collatz*/
int collatz(void)
{
	/* Dichiarazione delle variabili locali alla funzione */
	int n = 0, 		/* Input/Output: variabile dell'espressione    */
	    esito_lettura,
	    acquisizione_errata;

	/* Inserimento del dato */
	do
	{
		printf("Inserisci numero: ");
		esito_lettura = scanf("%d",
	      		      	      &n);

		acquisizione_errata = esito_lettura != 1;
			
		/* Calcolo con validazione stretta e communicazione dell'esito */
		while(n != 1)
		{
			if((n % 2) == 0)
			{
				n=n/2;
				printf("\n %d \n",
				       n);
			}
			else
			{
				n=(n*3)+1;
				printf("\n %d \n",
				       n);

			}
		}

	}	
	while(acquisizione_errata);

return(0);
}

/*Definizione della funzione per eseguire la congettura di Cramer*/
int cramer(void)
{
    /* Dichiarazione delle variabili locali alla funzione */
    	int    variabili[]={0,0}, 	/* Input:  Array contenente i due numeri primi        		*/
               esito_lettura,	  	/* Lavoro: esito della scanf. 		              		*/
               acquisizione_errata,	/* Lavoro: esito complessivo dell'acquisizione.       		*/
               contatore,		/* Lavoro: contatore delle variabili dell'espressione 		*/
	       risultato_a = 0,		/* Lavoro: controllo numero primo del primo parametro 		*/		      
	       risultato_b,		/* Lavoro: controllo numero primo del secondo parametro 	*/
	       v_assoluto;		/* Output: valore assoluto della differenza dei due parametri   */
    	double log_naturale;		/* Output: logaritmo naturale del più piccolo dei due parametri */
    
	/* Richiesta dei dati */
    	printf("Inserisci due numeri primi =>11 e consecutivi:\n");
    
	/* Inserimento dei dati */
    	for(contatore = 0;
	    contatore < 2;
            contatore++)
    	{
        	do
        	{   
			esito_lettura = scanf("%d",
                                              &variabili[contatore]);
                        
		        /* Validazione stretta dei dati */	
            		acquisizione_errata = esito_lettura !=1 || variabili[contatore]<11;
			
			if(acquisizione_errata)
				printf("Valore non accettabile, riprova.\n");
			else
				risultato_a = numprimo(variabili[contatore]);
            
            
			if(risultato_a==0)
            		{
				printf("Il numero inserito non è primo.\n");
				acquisizione_errata=1;
            		}
            
			if(risultato_a==1 &&
                           contatore==1)
			{
				risultato_b=numprimo(variabili[contatore]);
				
				if(risultato_b==0)
				{
					printf("Il numero inserito non è primo.\n");
					acquisizione_errata=1;
				}
                
				if(variabili[0]>variabili[1])
				{
					printf("I due numeri non sono consecutivi.");
					acquisizione_errata=1;
				}
			}
			while(getchar() !='\n');
		}
		while(acquisizione_errata);
	}
    
	/* Calcolo degli output */
	v_assoluto = abs(variabili[1] - variabili[0]);
	
	log_naturale=pow(log(variabili[0]),2);
	
	/* Communicazione degli esiti */
	if(v_assoluto<log_naturale)
		printf("La congettura è verificata.\n");
	else
		printf("La congettura non è verificata.\n");
	
	printf("Il valore assoluto della differenza dei due numeri è: %d\n",
               v_assoluto);
	
	printf("Il valore del quadrato del logaritmo del più piccolo dei 2 numeri è: %f\n",
               log_naturale);

return (0);
}

/* Definizione della funzione per controllare se un numero è primo */
int numprimo(int n)
{
	/* Dichiarazione delle variabili locali */
	int c = 0,		/* Lavoro: contatore dei divisori */
	    divisore = 1,	/* Lavoro: valore dei divisori	  */
	    esito = 1;		/* Output: esito del controllo	  */
        
	/* Calcolo dei divisori */
	while(c<3 && 
	      divisore<=n/2)
	{
		if(n % divisore == 0)
			c++;
		divisore++;
	}
    
	if(c > 2)
		esito = 0;

return (esito);
}
