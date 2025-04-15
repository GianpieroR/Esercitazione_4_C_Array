#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp" 

using namespace std;

int main()
{
	// Specifico il nome del file di input  
	string inputFile = "data.txt";		
	
	// dimensione asset n 
	size_t numAsset;	

	// Capitale iniziale S 
	double CapitaleIn;
	
	// Puntatori a memoria dinamica per i vettori dei pesi e dei rendimenti  
	double* pesi = nullptr;
	double* rendimenti  = nullptr;
	
	// Variabili che conterranno i risultati  
	double rendimentoTot;		//Valore del rendimento totale
	double SFinale;			   //Valore finale del portafoglio 
	
	// Chiamo la funzione LetturaDati
	LetturaDati(inputFile, numAsset, CapitaleIn, pesi, rendimenti);
	
	// Chiamo la funzione ProdottoScalare e calcolo il rendimento complessivo 
	rendimentoTot = ProdottoScalare(numAsset, pesi, rendimenti);
	
	// Chiamo la funzione ValoreTot e calcolo il guadagno finale 
	SFinale = ValoreTot(rendimentoTot, CapitaleIn);
	
	// Esporto i risultati e li stampo 
	ScritturaRisultati("result.txt", numAsset, pesi, rendimenti, CapitaleIn, rendimentoTot, SFinale);
	
	// libero la memoria dinamica allocata per i vettori , per evitare memory leak 
	
	delete [] pesi;
	delete [] rendimenti;
    return 0;
}